
#define MAX_INSTRUCTION_NAME_LENGTH 15
#define MAX_INSTRUCTION_LENGTH 32
#define MAX_PARAMETER_NUMBER 4
#define MAX_INSTRUCTION_NUMBER 256

struct parameter_description {
    static_assert(MAX_INSTRUCTION_LENGTH <= 32);
    char name;
    uint32_t bit_mask;
};

struct instruction_description {
    char name[MAX_INSTRUCTION_NAME_LENGTH+1];
    static_assert(MAX_PARAMETER_NUMBER <= UINT32_MAX);
    uint32_t parameter_number;
    struct parameter_description parameters[MAX_PARAMETER_NUMBER];
    static_assert(MAX_INSTRUCTION_LENGTH <= UINT32_MAX);
    uint32_t instruction_length;
    static_assert(MAX_INSTRUCTION_LENGTH <= 32);
    uint32_t instruction_opcode;
};

extern uint32_t insts_num;
extern struct instruction_description insts[MAX_INSTRUCTION_NUMBER];