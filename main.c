#include "instructions.h"

#include <stdio.h>

struct instruction_bits assemble_one();

int main(void) {
    while (1)
    {
        struct instruction_bits inst_bits = assemble_one();
        if (inst_bits.length > 0)
        {
            printf("0b%0*b\n", inst_bits.length, inst_bits.code);
        }
    }
    return 0;
}
