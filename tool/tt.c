#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>

#define MAX_STATUS_NUMBER 32
#define MAX_OPERAND_NUMBER 32
#define MAX_MEMORY_SPACE_NUMBER 8
#define MAX_OPERATOR_NUMBER 32
#define MAX_STACK_OPERAND_NUMBER 2
#define MAX_FLAG_AFFECT_NUMBER 4


#define MAX_NAME_LENGTH 15
#define MAX_VAL_LENGTH 7

struct var {
    char name[MAX_NAME_LENGTH+1];
    char val[MAX_VAL_LENGTH+1];
};

struct name {
    char name[MAX_NAME_LENGTH+1];
};

uint32_t sreg_length;
struct name sreg[MAX_STATUS_NUMBER];

uint32_t operand_number;
struct name operands[MAX_OPERAND_NUMBER];

uint32_t memory_space_number;
struct name memory_spaces[MAX_MEMORY_SPACE_NUMBER];

uint32_t operator_number;
struct var operators[MAX_OPERATOR_NUMBER];

uint32_t stack_operand_number;
struct name stack_operands[MAX_STACK_OPERAND_NUMBER];

uint32_t flag_affect_number;
struct var flag_affects[MAX_FLAG_AFFECT_NUMBER];


int fd;

int read_until_colon(const char** str);
int read_sreg();
int read_operand();
int read_memory_space();
int read_operator();
int read_stack();
int read_flags();

int main(void) {
    int fun_res = 0;
    fd = open("instruction_set_nomenclature", O_RDONLY);
    if (fd < 0) {
        perror("open");
        fun_res = -1;
        goto return_res;
    }

    while (1) {
        const char* str;
        {
            int ret = read_until_colon(&str);
            if (ret != 0) {
                fprintf(stderr, "read head fail\n");
                fun_res = -1;
                goto return_res;
            }
        }
        if (strcmp(str, "SREG") == 0) {
            read_sreg();
        }
        else if (strcmp(str, "Operands") == 0) {
            read_operand();
        }
        else if (strcmp(str, "MemorySpace") == 0) {
            read_memory_space();
        }
        else if (strcmp(str, "Operator") == 0) {
            read_operator();
        }
        else if (strcmp(str, "Stack") == 0) {
            read_stack();
        }
        else if (strcmp(str, "Flags") == 0) {
            read_flags();
        }
    }

return_res:
    return fun_res;
}

int read_vars(struct var* vars, uint32_t* length) {
    int fun_res = 0;
    while (1) {
        const char* name;
        {
            int ret = read_until_colon(&name);
        }
    }
    return fun_res;
}

int read_names(struct name* names, uint32_t* length) {
    int fun_res = 0;

    int index = 0;
    while (1) {
        char ch;
        while (1) {
            {
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
            }

            if (ch != ' ') {
                break;
            }
        }
        if (ch == '\n') {
            break;
        }

        char* name = names[index].name;
        int j = 0;
        while (1) {
            {
                int ret = read(fd, &ch, 1);
                if (ret < 0) {
                    perror("read");
                    fun_res = -1;
                    goto return_res;
                }
                else if (ret == 0) {
                    fprintf(stderr, "not enough bytes\n");
                    fun_res = -1;
                    goto return_res;
                }
            }
            if (ch == ' ') {
                break;
            }
            else if (ch == '\n') {
                break;
            }
            name[j++] = ch; 
        }
        name[j] = '\0';
        if (ch == '\n') {
            break;
        }
    }

return_res:
    return fun_res;
}

int read_sreg() {
    int fun_res = 0;

    uint32_t status_num;
    {
        int ret = read_names(sreg, &status_num);
        if (ret != 0) {
            fprintf(stderr, "read names fail\n");
            fun_res = -1;
            goto return_res;
        }
    }
    sreg_length = status_num;

return_res:
    return fun_res;
}
int read_operand() {
    int fun_res = 0;

    uint32_t operand_num;
    {
        int ret = read_names(operands, &operand_num);
        if (ret != 0) {
            fprintf(stderr, "read names fail\n");
            fun_res = -1;
            goto return_res;
        }
    }
    operand_number = operand_num;

return_res:
    return fun_res;
}
int read_memory_space() {
    int fun_res = 0;

    uint32_t mem_sp_num;
    {
        int ret = read_names(memory_spaces, &mem_sp_num);
        if (ret != 0) {
            fprintf(stderr, "read names fail\n");
            fun_res = -1;
            goto return_res;
        }
    }
    memory_space_number = mem_sp_num;

return_res:
    return fun_res;
}
int read_operator() {
    int fun_res = 0;

    uint32_t operator_num;
    {
        int ret = read_vars(operators, &operator_num);
        if (ret != 0) {
            fprintf(stderr, "read vars fail\n");
            fun_res = -1;
            goto return_res;
        }
    }
    operator_number = operator_num;

return_res:
    return fun_res;
}
int read_stack() {
    int fun_res = 0;

    uint32_t stack_operand_num;
    {
        int ret = read_names(stack_operands, &stack_operand_num);
        if (ret != 0) {
            fprintf(stderr, "read names fail\n");
            fun_res = -1;
            goto return_res;
        }
    }
    stack_operand_number = stack_operand_num;

return_res:
    return fun_res;
}
int read_flags() {
    int fun_res = 0;

    uint32_t flag_affect_num;
    {
        int ret = read_vars(flag_affects, &flag_affect_num);
        if (ret != 0) {
            fprintf(stderr, "read vars fail\n");
            fun_res = -1;
            goto return_res;
        }
    }
    flag_affect_number = flag_affect_num;

return_res:
    return fun_res;
}

static char str_until_colon[256];
int read_until_colon(const char** str) {
    int fun_res = 0;

    int index = 0;
    while (1) {
        char ch;
        {
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
            if (ch == ':') {
                break;
            }
            else if (ch == ' ' || ch == '\n') {
                fprintf(stderr, "Error space\n");
                fun_res = -1;
                goto return_res;
            }
            str_until_colon[index++] = ch;
        }
    }

    str_until_colon[index] = '\0';
    *str = str_until_colon;

return_res:
    return fun_res;
}
