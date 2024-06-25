#include <stdint.h>
#include <inttypes.h>
struct instruction_bits {
	uint32_t length;
	uint32_t code;
};
struct instruction_bits avr_inst_ADC(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_ADD(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_ADIW(uint32_t d, uint32_t K);
struct instruction_bits avr_inst_AND(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_ANDI(uint32_t d, uint32_t K);
struct instruction_bits avr_inst_ASR(uint32_t d);
struct instruction_bits avr_inst_BCLR(uint32_t s);
struct instruction_bits avr_inst_BLD(uint32_t d, uint32_t b);
struct instruction_bits avr_inst_BRBC(uint32_t s, uint32_t k);
struct instruction_bits avr_inst_BRBS(uint32_t s, uint32_t k);
struct instruction_bits avr_inst_BRCC(uint32_t k);
struct instruction_bits avr_inst_BRCS(uint32_t k);
struct instruction_bits avr_inst_BREAK();
struct instruction_bits avr_inst_BREQ(uint32_t k);
struct instruction_bits avr_inst_BRGE(uint32_t k);
struct instruction_bits avr_inst_BRHC(uint32_t k);
struct instruction_bits avr_inst_BRHS(uint32_t k);
struct instruction_bits avr_inst_BRID(uint32_t k);
struct instruction_bits avr_inst_BRIE(uint32_t k);
struct instruction_bits avr_inst_BRLO(uint32_t k);
struct instruction_bits avr_inst_BRLT(uint32_t k);
struct instruction_bits avr_inst_BRMI(uint32_t k);
struct instruction_bits avr_inst_BRNE(uint32_t k);
struct instruction_bits avr_inst_BRPL(uint32_t k);
struct instruction_bits avr_inst_BRSH(uint32_t k);
struct instruction_bits avr_inst_BRTC(uint32_t k);
struct instruction_bits avr_inst_BRTS(uint32_t k);
struct instruction_bits avr_inst_BRVC(uint32_t k);
struct instruction_bits avr_inst_BRVS(uint32_t k);
struct instruction_bits avr_inst_BSET(uint32_t s);
struct instruction_bits avr_inst_BST(uint32_t d, uint32_t b);
struct instruction_bits avr_inst_CALL(uint32_t k);
struct instruction_bits avr_inst_CBI(uint32_t A, uint32_t b);
struct instruction_bits avr_inst_CLH();
struct instruction_bits avr_inst_CLI();
struct instruction_bits avr_inst_CLN();
struct instruction_bits avr_inst_CLS();
struct instruction_bits avr_inst_CLT();
struct instruction_bits avr_inst_CLV();
struct instruction_bits avr_inst_CLZ();
struct instruction_bits avr_inst_COM(uint32_t d);
struct instruction_bits avr_inst_CP(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_CPC(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_CPI(uint32_t d, uint32_t K);
struct instruction_bits avr_inst_CPSE(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_DEC(uint32_t d);
struct instruction_bits avr_inst_DES(uint32_t K);
struct instruction_bits avr_inst_EICALL();
struct instruction_bits avr_inst_EIJMP();
struct instruction_bits avr_inst_ELPM();
struct instruction_bits avr_inst_ELPM_d(uint32_t d);
struct instruction_bits avr_inst_ELPM_d_Z_inc(uint32_t d);
struct instruction_bits avr_inst_EOR(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_FMUL(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_FMULS(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_FMULSU(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_ICALL();
struct instruction_bits avr_inst_IJMP();
struct instruction_bits avr_inst_IN(uint32_t d, uint32_t A);
struct instruction_bits avr_inst_INC(uint32_t d);
struct instruction_bits avr_inst_JMP(uint32_t k);
struct instruction_bits avr_inst_LAC(uint32_t r);
struct instruction_bits avr_inst_LAS(uint32_t r);
struct instruction_bits avr_inst_LAT(uint32_t r);
struct instruction_bits avr_inst_LD_X(uint32_t d);
struct instruction_bits avr_inst_LD_X_inc(uint32_t d);
struct instruction_bits avr_inst_LD_dec_X(uint32_t d);
struct instruction_bits avr_inst_LD_Y(uint32_t d);
struct instruction_bits avr_inst_LD_Y_inc(uint32_t d);
struct instruction_bits avr_inst_LD_dec_Y(uint32_t d);
struct instruction_bits avr_inst_LD_Y_add_q(uint32_t d, uint32_t q);
struct instruction_bits avr_inst_LD_Z(uint32_t d);
struct instruction_bits avr_inst_LD_Z_inc(uint32_t d);
struct instruction_bits avr_inst_LD_dec_Z(uint32_t d);
struct instruction_bits avr_inst_LD_Z_add_q(uint32_t d, uint32_t q);
struct instruction_bits avr_inst_LDI(uint32_t d, uint32_t K);
struct instruction_bits avr_inst_LDS(uint32_t d, uint32_t k);
struct instruction_bits avr_inst_LDS_rc(uint32_t d, uint32_t k);
struct instruction_bits avr_inst_LPM();
struct instruction_bits avr_inst_LPM_d(uint32_t d);
struct instruction_bits avr_inst_LPM_d_Z_inc(uint32_t d);
struct instruction_bits avr_inst_LSL(uint32_t d);
struct instruction_bits avr_inst_LSR(uint32_t d);
struct instruction_bits avr_inst_MOV(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_MOVW(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_MUL(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_MULS(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_MULSU(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_NEG(uint32_t d);
struct instruction_bits avr_inst_NOP();
struct instruction_bits avr_inst_OR(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_ORI(uint32_t d, uint32_t K);
struct instruction_bits avr_inst_OUT(uint32_t A, uint32_t r);
struct instruction_bits avr_inst_POP(uint32_t d);
struct instruction_bits avr_inst_PUSH(uint32_t r);
struct instruction_bits avr_inst_RCALL(uint32_t k);
struct instruction_bits avr_inst_RET();
struct instruction_bits avr_inst_RETI();
struct instruction_bits avr_inst_RJMP(uint32_t k);
struct instruction_bits avr_inst_ROL(uint32_t d);
struct instruction_bits avr_inst_ROR(uint32_t d);
struct instruction_bits avr_inst_SBC(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_SBCI(uint32_t d, uint32_t K);
struct instruction_bits avr_inst_SBI(uint32_t A, uint32_t b);
struct instruction_bits avr_inst_SBIC(uint32_t A, uint32_t b);
struct instruction_bits avr_inst_SBIS(uint32_t A, uint32_t b);
struct instruction_bits avr_inst_SBIW(uint32_t d, uint32_t K);
struct instruction_bits avr_inst_SBR(uint32_t d, uint32_t K);
struct instruction_bits avr_inst_SBRC(uint32_t r, uint32_t b);
struct instruction_bits avr_inst_SBRS(uint32_t r, uint32_t b);
struct instruction_bits avr_inst_SEC();
struct instruction_bits avr_inst_SEH();
struct instruction_bits avr_inst_SEI();
struct instruction_bits avr_inst_SEN();
struct instruction_bits avr_inst_SER(uint32_t d);
struct instruction_bits avr_inst_SES();
struct instruction_bits avr_inst_SET();
struct instruction_bits avr_inst_SEV();
struct instruction_bits avr_inst_SEZ();
struct instruction_bits avr_inst_SLEEP();
struct instruction_bits avr_inst_SPM();
struct instruction_bits avr_inst_SPM_x();
struct instruction_bits avr_inst_SPM_x_Z_inc();
struct instruction_bits avr_inst_ST_X(uint32_t r);
struct instruction_bits avr_inst_ST_X_inc(uint32_t r);
struct instruction_bits avr_inst_ST_dec_X(uint32_t r);
struct instruction_bits avr_inst_ST_Y(uint32_t r);
struct instruction_bits avr_inst_ST_Y_inc(uint32_t r);
struct instruction_bits avr_inst_ST_dec_Y(uint32_t r);
struct instruction_bits avr_inst_ST_Y_add_q(uint32_t r, uint32_t q);
struct instruction_bits avr_inst_ST_Z(uint32_t r);
struct instruction_bits avr_inst_ST_Z_inc(uint32_t r);
struct instruction_bits avr_inst_ST_dec_Z(uint32_t r);
struct instruction_bits avr_inst_ST_Z_add_q(uint32_t r, uint32_t q);
struct instruction_bits avr_inst_STS(uint32_t k, uint32_t r);
struct instruction_bits avr_inst_STS_rc(uint32_t k, uint32_t r);
struct instruction_bits avr_inst_SUB(uint32_t d, uint32_t r);
struct instruction_bits avr_inst_SUBI(uint32_t d, uint32_t K);
struct instruction_bits avr_inst_SWAP(uint32_t d);
struct instruction_bits avr_inst_WDR();
struct instruction_bits avr_inst_XCH(uint32_t r);
enum instruction {
	AVR_INST_UNKNOWN,
	AVR_INST_ADC,
	AVR_INST_ADD,
	AVR_INST_ADIW,
	AVR_INST_AND,
	AVR_INST_ANDI,
	AVR_INST_ASR,
	AVR_INST_BCLR,
	AVR_INST_BLD,
	AVR_INST_BRBC,
	AVR_INST_BRBS,
	AVR_INST_BRCC,
	AVR_INST_BRCS,
	AVR_INST_BREAK,
	AVR_INST_BREQ,
	AVR_INST_BRGE,
	AVR_INST_BRHC,
	AVR_INST_BRHS,
	AVR_INST_BRID,
	AVR_INST_BRIE,
	AVR_INST_BRLO,
	AVR_INST_BRLT,
	AVR_INST_BRMI,
	AVR_INST_BRNE,
	AVR_INST_BRPL,
	AVR_INST_BRSH,
	AVR_INST_BRTC,
	AVR_INST_BRTS,
	AVR_INST_BRVC,
	AVR_INST_BRVS,
	AVR_INST_BSET,
	AVR_INST_BST,
	AVR_INST_CALL,
	AVR_INST_CBI,
	AVR_INST_CLH,
	AVR_INST_CLI,
	AVR_INST_CLN,
	AVR_INST_CLS,
	AVR_INST_CLT,
	AVR_INST_CLV,
	AVR_INST_CLZ,
	AVR_INST_COM,
	AVR_INST_CP,
	AVR_INST_CPC,
	AVR_INST_CPI,
	AVR_INST_CPSE,
	AVR_INST_DEC,
	AVR_INST_DES,
	AVR_INST_EICALL,
	AVR_INST_EIJMP,
	AVR_INST_ELPM,
	AVR_INST_ELPM_d,
	AVR_INST_ELPM_d_Z_inc,
	AVR_INST_EOR,
	AVR_INST_FMUL,
	AVR_INST_FMULS,
	AVR_INST_FMULSU,
	AVR_INST_ICALL,
	AVR_INST_IJMP,
	AVR_INST_IN,
	AVR_INST_INC,
	AVR_INST_JMP,
	AVR_INST_LAC,
	AVR_INST_LAS,
	AVR_INST_LAT,
	AVR_INST_LD_X,
	AVR_INST_LD_X_inc,
	AVR_INST_LD_dec_X,
	AVR_INST_LD_Y,
	AVR_INST_LD_Y_inc,
	AVR_INST_LD_dec_Y,
	AVR_INST_LD_Y_add_q,
	AVR_INST_LD_Z,
	AVR_INST_LD_Z_inc,
	AVR_INST_LD_dec_Z,
	AVR_INST_LD_Z_add_q,
	AVR_INST_LDI,
	AVR_INST_LDS,
	AVR_INST_LDS_rc,
	AVR_INST_LPM,
	AVR_INST_LPM_d,
	AVR_INST_LPM_d_Z_inc,
	AVR_INST_LSL,
	AVR_INST_LSR,
	AVR_INST_MOV,
	AVR_INST_MOVW,
	AVR_INST_MUL,
	AVR_INST_MULS,
	AVR_INST_MULSU,
	AVR_INST_NEG,
	AVR_INST_NOP,
	AVR_INST_OR,
	AVR_INST_ORI,
	AVR_INST_OUT,
	AVR_INST_POP,
	AVR_INST_PUSH,
	AVR_INST_RCALL,
	AVR_INST_RET,
	AVR_INST_RETI,
	AVR_INST_RJMP,
	AVR_INST_ROL,
	AVR_INST_ROR,
	AVR_INST_SBC,
	AVR_INST_SBCI,
	AVR_INST_SBI,
	AVR_INST_SBIC,
	AVR_INST_SBIS,
	AVR_INST_SBIW,
	AVR_INST_SBR,
	AVR_INST_SBRC,
	AVR_INST_SBRS,
	AVR_INST_SEC,
	AVR_INST_SEH,
	AVR_INST_SEI,
	AVR_INST_SEN,
	AVR_INST_SER,
	AVR_INST_SES,
	AVR_INST_SET,
	AVR_INST_SEV,
	AVR_INST_SEZ,
	AVR_INST_SLEEP,
	AVR_INST_SPM,
	AVR_INST_SPM_x,
	AVR_INST_SPM_x_Z_inc,
	AVR_INST_ST_X,
	AVR_INST_ST_X_inc,
	AVR_INST_ST_dec_X,
	AVR_INST_ST_Y,
	AVR_INST_ST_Y_inc,
	AVR_INST_ST_dec_Y,
	AVR_INST_ST_Y_add_q,
	AVR_INST_ST_Z,
	AVR_INST_ST_Z_inc,
	AVR_INST_ST_dec_Z,
	AVR_INST_ST_Z_add_q,
	AVR_INST_STS,
	AVR_INST_STS_rc,
	AVR_INST_SUB,
	AVR_INST_SUBI,
	AVR_INST_SWAP,
	AVR_INST_WDR,
	AVR_INST_XCH
};
