#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <stdbool.h>

#include <unistd.h>
#include <fcntl.h>

#include "transport.h"

int fd;
uint32_t insts_num;
struct instruction_description insts[MAX_INSTRUCTION_NUMBER];

int parse_instructions();

#define READ_INST_RESULT_LAST_INSTRUCTION 1
#define READ_INST_RESULT_END_OF_FILE 2

int read_inst_name(char* name);
int read_inst_parameters(struct instruction_description* inst);
int read_inst_opcode(struct instruction_description* inst);

bool is_bit_mask_continuous(uint32_t bit_mask, uint32_t* start, uint32_t* length);
bool have_bit_mask_segment(uint32_t bit_mask, uint32_t* start, uint32_t* length);
uint32_t bitmask_continuous(uint32_t length);
uint32_t bitmask_one_number(uint32_t bitmask);

int output_header();
int output_program();
int output_assembler();

void show_usage(int argc, char** argv) {
    fprintf(stderr, "Usage: %s <h|c|a> <instructions_file>\n", argv[0]);
}

int main(int argc, char** argv) {
    int fun_res = 0;

    if (argc != 3) {
        show_usage(argc, argv);
        fun_res = -1;
        goto return_res;
    }

    if (argv[1][0] != 'h' && argv[1][0] != 'c' && argv[1][0] != 'a') {
        show_usage(argc, argv);
        fun_res = -1;
        goto return_res;
    }

    fd = open(argv[2], O_RDONLY);
    if (fd < 0) {
        perror("open");
        fun_res = -1;
        goto return_res;
    }

    {
        int ret = parse_instructions();
        if (ret != 0) {
            fprintf(stderr, "parse instructions fail\n");
            goto close_fd;
        }
    }
    
    if (argv[1][0] == 'h')
    {
        int ret = output_header();
        if (ret != 0) {
            fprintf(stderr, "output header fail\n");
            goto close_fd;
        }
    }
    else if (argv[1][0] == 'c') {
        int ret = output_program();
        if (ret != 0) {
            fprintf(stderr, "output program fail\n");
            goto close_fd;
        }
    }
    else if (argv[1][0] == 'a') {
        int ret = output_assembler();
        if (ret != 0) {
            fprintf(stderr, "output assembler fail\n");
            goto close_fd;
        }
    }

close_fd:
    {
        int ret = close(fd);
        if (ret != 0) {
            perror("close");
            fun_res = -1;
            goto return_res;
        }
    }

return_res:
    return fun_res;
}

int parse_instructions() {
    int fun_res = 0;

    uint32_t inst_index = 0;
    while (1)
    {
        struct instruction_description *inst = insts+inst_index;
        {
            int ret = read_inst_name(inst->name);
            if (ret < 0) {
                fun_res = -1;
                goto return_res;
            }
            else if (ret == READ_INST_RESULT_END_OF_FILE) {
                break;
            }
        }
        {
            int ret = read_inst_parameters(inst);
            if (ret < 0) {
                fun_res = -1;
                goto return_res;
            }
        }
        {
            int ret = read_inst_opcode(inst);
            if (ret < 0) {
                fun_res = -1;
                goto return_res;
            }
            else if (ret == READ_INST_RESULT_LAST_INSTRUCTION) {
                break;
            }
        }

        inst_index++;
    }
    insts_num = inst_index;

return_res:
    return fun_res;
}

int read_inst_name(char* name) {
    int fun_res = 0;

    char ch;
    int index = 0;

    while (1) {
        int ret = read(fd, &ch, 1);
        if (ret < 0) {
            perror("read");
            fun_res = -1;
            break;
        }
        else if (ret == 0) {
            fun_res = READ_INST_RESULT_END_OF_FILE;
            goto return_res;
        }
        if (ch == ' ') break;

        name[index++] = ch;
    }
    name[index] = '\0';

return_res:
    return fun_res;
}

int read_inst_parameters(struct instruction_description* inst) {
    int fun_res = 0;

    char ch[2];
    int index = 0;

    do {
        int ret = read(fd, ch, 1);
        if (ret < 0) {
            perror("read");
            fun_res = -1;
            goto return_res;
        }
        else if (ret == 0) {
            fprintf(stderr, "read not enough bytes\n");
            fun_res = -1;
            goto return_res;
        }
    } while (ch[0] == ' ');
    if (ch[0] == '~') {
        index = 0;
        goto return_parameters;
    }
    inst->parameters[index++].name = ch[0];

    {
        int ret = read(fd, &ch[1], 1);
        if (ret < 0) {
            perror("read");
            fun_res = -1;
            goto return_res;
        }
        else if (ret == 0) {
            fprintf(stderr, "read not enough bytes\n");
            fun_res = -1;
            goto return_res;
        }
    }

    while (ch[1] == ','){
        int ret = read(fd, ch, 2);
        if (ret < 0) {
            perror("read");
            fun_res = -1;
            goto return_res;
        }
        else if (ret == 0 || ret == 1) {
            fprintf(stderr, "read not enough bytes\n");
            fun_res = -1;
            goto return_res;
        }
        inst->parameters[index++].name = ch[0];
    }
    assert(ch[1] == ' ');

return_parameters:
    inst->parameter_number = index;

return_res:
    return fun_res;
}
int read_inst_opcode(struct instruction_description* inst) {
    int fun_res = 0;

    char str[MAX_INSTRUCTION_LENGTH];
    int index = 0;
    char ch;

    do {
        int ret = read(fd, &ch, 1);
        if (ret < 0) {
            perror("read");
            fun_res = -1;
            goto return_res;
        }
        else if (ret == 0) {
            fprintf(stderr, "Not enough bytes\n");
            fun_res = -1;
            goto return_res;
        }
    } while (ch == ' ');
    str[index++] = ch;

    while (1) {
        int ret = read(fd, &ch, 1);
        if (ret < 0) {
            perror("read");
            fun_res = -1;
            goto return_res;
        }
        else if (ret == 0) {
            fun_res = READ_INST_RESULT_LAST_INSTRUCTION;
            break;
        }
        if (ch == '\n') {
            break;
        }

        str[index++] = ch;
    }

    inst->instruction_length = index;

    inst->instruction_opcode = 0;
    for (int i = 0; i < inst->instruction_length; i++) {
        uint32_t bit_index = inst->instruction_length-i-1;
        char ch = str[i];

        if (ch == '1') {
            inst->instruction_opcode |= 1<<bit_index;
        }
        else if (ch == '0') {
        }
        else {
            int param_index = 0;
            for (param_index = 0; param_index < inst->parameter_number; param_index++) {
                struct parameter_description* param = &inst->parameters[param_index];
                if (ch == param->name) {
                    break;
                }
            }
            if (param_index == inst->parameter_number) {
                fprintf(stderr, "Unknown parameter %c in %s\n", ch, inst->name);
                fun_res = -1;
                goto return_res;
            }

            struct parameter_description* param = &inst->parameters[param_index];
            param->bit_mask |= 1<<bit_index;
        }
    }

return_res:
    return fun_res;
}


bool is_bit_mask_continuous(uint32_t bit_mask, uint32_t* start, uint32_t* length) {
    uint32_t index = 0;
    for (index = 0; index < 32; index++) {
        if ( (bit_mask >> index) & 1 ) {
            break;
        }
    }
    uint32_t s = index;
    for (index = s; index < 32; index++) {
        if ( (bit_mask >> index) & 1 ) {
        }
        else {
            break;
        }
    }

    if ( (bit_mask >> index) == 0 ) {
        *start = s;
        *length = index-s;
        return true;
    }

    return false;
}

bool have_bit_mask_segment(uint32_t bit_mask, uint32_t* start, uint32_t* length) {
    uint32_t index = *start;
    if ( (bit_mask >> *start) == 0 ) {
        return false;
    }
    for (index = *start; index < 32; index++) {
        if ( (bit_mask >> index) & 1 ) {
            break;
        }
    }
    uint32_t s = index;
    for (index = s; index < 32; index++) {
        if ( (bit_mask >> index) & 1 ) {
        }
        else {
            break;
        }
    }

    *start = s;
    *length = index - s;

    return true;
}

uint32_t bitmask_continuous(uint32_t length) {
    uint32_t bitmask = 0;
    assert(length <= 32);
    for (int i = 0; i < length; i++) {
        bitmask |= 1 << i;
    }
    return bitmask;
}
uint32_t bitmask_one_number(uint32_t bitmask) {
    uint32_t num = 0;
    for (int i = 0; i < 32; i++) {
        if ( bitmask & 1 ) {
            num++;
        }
        bitmask >>= 1;
    }

    return num;
}

int output_header() {
    int fun_res = 0;

    printf("#include <stdint.h>\n#include <inttypes.h>\n");
    printf("struct instruction_bits {\n"
            "\tuint32_t length;\n"
            "\tuint32_t code;"
            "\n};\n");
    for (int i = 0; i < insts_num; i++) {
        struct instruction_description* inst = &insts[i];
        printf("struct instruction_bits avr_inst_%s(", inst->name);
        if (inst->parameter_number > 0) {
            for (int j = 0; j < inst->parameter_number-1; j++) {
                printf("uint32_t %c, ", inst->parameters[j].name);
            }
            printf("uint32_t %c", inst->parameters[inst->parameter_number-1].name);
        }
        printf(");\n");
    }

    printf("enum instruction {\n");
    printf("\tAVR_INST_UNKNOWN,\n");
    if (insts_num > 0) {
        for (int i = 0; i < insts_num-1; i++) {
            struct instruction_description* inst = &insts[i];
            printf("\tAVR_INST_%s,\n", inst->name);
        }
        struct instruction_description* inst = &insts[insts_num-1];
        printf("\tAVR_INST_%s\n", inst->name);
    }
    printf("};\n");

    return fun_res;
}

int output_program() {
    int fun_res = 0;

    printf("//total instruction number is %"PRIu32"\n", insts_num);
    for (int i = 0; i < insts_num; i++) {
        struct instruction_description* inst = &insts[i];

        printf("struct instruction_bits avr_inst_%s(", inst->name);
        if (inst->parameter_number > 0) {
            for (int j = 0; j < inst->parameter_number-1; j++) {
                printf("uint32_t %c, ", inst->parameters[j].name);
            }
            printf("uint32_t %c", inst->parameters[inst->parameter_number-1].name);
        }
        printf(") {\n");

        {
            for (int param_index = 0;
                    param_index < inst->parameter_number;
                    param_index++) {
                struct parameter_description* param = &inst->parameters[param_index];
                uint32_t num = bitmask_one_number(param->bit_mask);
                printf("\tassert( (%c >> %"PRIu32") == 0);\n",
                        param->name, num);
            }
        }
        
        {
            printf("\tuint32_t code = 0b%0*b;\n", 
                    inst->instruction_length,
                    inst->instruction_opcode);
            {
                for (int param_index = 0; 
                        param_index < inst->parameter_number; 
                        param_index++) {
                    struct parameter_description* param = &inst->parameters[param_index];
                    
                    {
                        uint32_t start, length;
                        if (is_bit_mask_continuous(param->bit_mask, &start, &length)) {
                            printf("\tcode |= (%c<<%"PRIu32") & 0b%0*b;\n",
                                    param->name, start, inst->instruction_length, param->bit_mask);
                            continue;
                        }
                    }
                    {
                        uint32_t start = 0, length, total_length = 0;
                        while (have_bit_mask_segment(param->bit_mask, &start, &length)) {
                            printf("\tcode |= (%c&0b%0*b) << %"PRIu32";\n",
                                    param->name, length, bitmask_continuous(length) << total_length, start - total_length);
                            start+=length;
                            total_length += length;
                        }
                    }
                }
            }
            printf("\tstruct instruction_bits inst_bits = {%"PRIu32", code};\n"
                    "\treturn inst_bits;\n"
                    , 
                    inst->instruction_length);
        }

        printf("}\n\n");
    }
    
    return fun_res;
}

int output_assembler() {
    int fun_res = 0;

    printf("enum instruction read_inst() {\n");
    printf("\tconst char str[%d];\n", MAX_INSTRUCTION_NAME_LENGTH+1);
    printf("\tscanf(\"%%s\", str);\n");
    for (int i = 0; i < insts_num; i++) {
        struct instruction_description* inst = &insts[i];
        printf("\tif ( strcmp(str, \"%s\") == 0 ) {\n", inst->name);
        printf("\t\treturn AVR_INST_%s;\n", inst->name);
        printf("\t}\n");
    }
    printf("\treturn AVR_INST_UNKNONW;\n");
    printf("}\n");

    
    printf("uint32_t read_param() {\n");
    printf("\tuint32_t d;\n");
    printf("\tscanf(\"%\"PRIu32, &d);\n");
    printf("\treturn d;\n");
    printf("\t}\n");


    printf("struct instruction_bits assemble_one() {\n");
    printf("\tstruct instruction_bits inst_bits;\n");
    printf("\tenum instruction inst = read_inst();\n");
    printf("\tswitch (inst) {\n");
    for (int i = 0; i < insts_num; i++) {
        struct instruction_description* inst = &insts[i];
        printf("\tcase AVR_INST_%s:\n", inst->name);
        printf("\t{\n");
        for (int param_index = 0; 
                param_index < inst->parameter_number; 
                param_index++) {
            struct parameter_description* param = &inst->parameters[param_index];
            printf("\tuint32_t %c = read_param();\n", param->name);
        }
        printf("\tinst_bits = avr_inst_%s(", inst->name);
        if (inst->parameter_number > 0) {
            for (int param_index = 0; 
                    param_index < inst->parameter_number - 1; 
                    param_index++) {
                struct parameter_description* param = &inst->parameters[param_index];
                printf("%c,", param->name);
            }
            struct parameter_description* param = &inst->parameters[inst->parameter_number-1];
            printf("%c", param->name);
        }
        printf(");\n");
        printf("\tbreak;\n");
        printf("\t}\n");
    }
    printf("\tcase AVR_INST_UNKNOWN:\n");
    printf("\tdefault:\n");
    printf("\tinst_bits.length = 0;\n");
    printf("\tfprintf(stderr, \"Unknown instruction\");\n");
    printf("\t}\n");

    printf("\treturn inst_bits;\n");
    printf("}\n");

    return fun_res;
}

