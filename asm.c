#include "instructions.h"

#include <string.h>
#include <assert.h>
#include <stdio.h>

enum instruction read_inst() {
	const char str[16];
	scanf("%s", str);
	if ( strcmp(str, "ADC") == 0 ) {
		return AVR_INST_ADC;
	}
	if ( strcmp(str, "ADD") == 0 ) {
		return AVR_INST_ADD;
	}
	if ( strcmp(str, "ADIW") == 0 ) {
		return AVR_INST_ADIW;
	}
	if ( strcmp(str, "AND") == 0 ) {
		return AVR_INST_AND;
	}
	if ( strcmp(str, "ANDI") == 0 ) {
		return AVR_INST_ANDI;
	}
	if ( strcmp(str, "ASR") == 0 ) {
		return AVR_INST_ASR;
	}
	if ( strcmp(str, "BCLR") == 0 ) {
		return AVR_INST_BCLR;
	}
	if ( strcmp(str, "BLD") == 0 ) {
		return AVR_INST_BLD;
	}
	if ( strcmp(str, "BRBC") == 0 ) {
		return AVR_INST_BRBC;
	}
	if ( strcmp(str, "BRBS") == 0 ) {
		return AVR_INST_BRBS;
	}
	if ( strcmp(str, "BRCC") == 0 ) {
		return AVR_INST_BRCC;
	}
	if ( strcmp(str, "BRCS") == 0 ) {
		return AVR_INST_BRCS;
	}
	if ( strcmp(str, "BREAK") == 0 ) {
		return AVR_INST_BREAK;
	}
	if ( strcmp(str, "BREQ") == 0 ) {
		return AVR_INST_BREQ;
	}
	if ( strcmp(str, "BRGE") == 0 ) {
		return AVR_INST_BRGE;
	}
	if ( strcmp(str, "BRHC") == 0 ) {
		return AVR_INST_BRHC;
	}
	if ( strcmp(str, "BRHS") == 0 ) {
		return AVR_INST_BRHS;
	}
	if ( strcmp(str, "BRID") == 0 ) {
		return AVR_INST_BRID;
	}
	if ( strcmp(str, "BRIE") == 0 ) {
		return AVR_INST_BRIE;
	}
	if ( strcmp(str, "BRLO") == 0 ) {
		return AVR_INST_BRLO;
	}
	if ( strcmp(str, "BRLT") == 0 ) {
		return AVR_INST_BRLT;
	}
	if ( strcmp(str, "BRMI") == 0 ) {
		return AVR_INST_BRMI;
	}
	if ( strcmp(str, "BRNE") == 0 ) {
		return AVR_INST_BRNE;
	}
	if ( strcmp(str, "BRPL") == 0 ) {
		return AVR_INST_BRPL;
	}
	if ( strcmp(str, "BRSH") == 0 ) {
		return AVR_INST_BRSH;
	}
	if ( strcmp(str, "BRTC") == 0 ) {
		return AVR_INST_BRTC;
	}
	if ( strcmp(str, "BRTS") == 0 ) {
		return AVR_INST_BRTS;
	}
	if ( strcmp(str, "BRVC") == 0 ) {
		return AVR_INST_BRVC;
	}
	if ( strcmp(str, "BRVS") == 0 ) {
		return AVR_INST_BRVS;
	}
	if ( strcmp(str, "BSET") == 0 ) {
		return AVR_INST_BSET;
	}
	if ( strcmp(str, "BST") == 0 ) {
		return AVR_INST_BST;
	}
	if ( strcmp(str, "CALL") == 0 ) {
		return AVR_INST_CALL;
	}
	if ( strcmp(str, "CBI") == 0 ) {
		return AVR_INST_CBI;
	}
	if ( strcmp(str, "CLH") == 0 ) {
		return AVR_INST_CLH;
	}
	if ( strcmp(str, "CLI") == 0 ) {
		return AVR_INST_CLI;
	}
	if ( strcmp(str, "CLN") == 0 ) {
		return AVR_INST_CLN;
	}
	if ( strcmp(str, "CLS") == 0 ) {
		return AVR_INST_CLS;
	}
	if ( strcmp(str, "CLT") == 0 ) {
		return AVR_INST_CLT;
	}
	if ( strcmp(str, "CLV") == 0 ) {
		return AVR_INST_CLV;
	}
	if ( strcmp(str, "CLZ") == 0 ) {
		return AVR_INST_CLZ;
	}
	if ( strcmp(str, "COM") == 0 ) {
		return AVR_INST_COM;
	}
	if ( strcmp(str, "CP") == 0 ) {
		return AVR_INST_CP;
	}
	if ( strcmp(str, "CPC") == 0 ) {
		return AVR_INST_CPC;
	}
	if ( strcmp(str, "CPI") == 0 ) {
		return AVR_INST_CPI;
	}
	if ( strcmp(str, "CPSE") == 0 ) {
		return AVR_INST_CPSE;
	}
	if ( strcmp(str, "DEC") == 0 ) {
		return AVR_INST_DEC;
	}
	if ( strcmp(str, "DES") == 0 ) {
		return AVR_INST_DES;
	}
	if ( strcmp(str, "EICALL") == 0 ) {
		return AVR_INST_EICALL;
	}
	if ( strcmp(str, "EIJMP") == 0 ) {
		return AVR_INST_EIJMP;
	}
	if ( strcmp(str, "ELPM") == 0 ) {
		return AVR_INST_ELPM;
	}
	if ( strcmp(str, "ELPM_d") == 0 ) {
		return AVR_INST_ELPM_d;
	}
	if ( strcmp(str, "ELPM_d_Z_inc") == 0 ) {
		return AVR_INST_ELPM_d_Z_inc;
	}
	if ( strcmp(str, "EOR") == 0 ) {
		return AVR_INST_EOR;
	}
	if ( strcmp(str, "FMUL") == 0 ) {
		return AVR_INST_FMUL;
	}
	if ( strcmp(str, "FMULS") == 0 ) {
		return AVR_INST_FMULS;
	}
	if ( strcmp(str, "FMULSU") == 0 ) {
		return AVR_INST_FMULSU;
	}
	if ( strcmp(str, "ICALL") == 0 ) {
		return AVR_INST_ICALL;
	}
	if ( strcmp(str, "IJMP") == 0 ) {
		return AVR_INST_IJMP;
	}
	if ( strcmp(str, "IN") == 0 ) {
		return AVR_INST_IN;
	}
	if ( strcmp(str, "INC") == 0 ) {
		return AVR_INST_INC;
	}
	if ( strcmp(str, "JMP") == 0 ) {
		return AVR_INST_JMP;
	}
	if ( strcmp(str, "LAC") == 0 ) {
		return AVR_INST_LAC;
	}
	if ( strcmp(str, "LAS") == 0 ) {
		return AVR_INST_LAS;
	}
	if ( strcmp(str, "LAT") == 0 ) {
		return AVR_INST_LAT;
	}
	if ( strcmp(str, "LD_X") == 0 ) {
		return AVR_INST_LD_X;
	}
	if ( strcmp(str, "LD_X_inc") == 0 ) {
		return AVR_INST_LD_X_inc;
	}
	if ( strcmp(str, "LD_dec_X") == 0 ) {
		return AVR_INST_LD_dec_X;
	}
	if ( strcmp(str, "LD_Y") == 0 ) {
		return AVR_INST_LD_Y;
	}
	if ( strcmp(str, "LD_Y_inc") == 0 ) {
		return AVR_INST_LD_Y_inc;
	}
	if ( strcmp(str, "LD_dec_Y") == 0 ) {
		return AVR_INST_LD_dec_Y;
	}
	if ( strcmp(str, "LD_Y_add_q") == 0 ) {
		return AVR_INST_LD_Y_add_q;
	}
	if ( strcmp(str, "LD_Z") == 0 ) {
		return AVR_INST_LD_Z;
	}
	if ( strcmp(str, "LD_Z_inc") == 0 ) {
		return AVR_INST_LD_Z_inc;
	}
	if ( strcmp(str, "LD_dec_Z") == 0 ) {
		return AVR_INST_LD_dec_Z;
	}
	if ( strcmp(str, "LD_Z_add_q") == 0 ) {
		return AVR_INST_LD_Z_add_q;
	}
	if ( strcmp(str, "LDI") == 0 ) {
		return AVR_INST_LDI;
	}
	if ( strcmp(str, "LDS") == 0 ) {
		return AVR_INST_LDS;
	}
	if ( strcmp(str, "LDS_rc") == 0 ) {
		return AVR_INST_LDS_rc;
	}
	if ( strcmp(str, "LPM") == 0 ) {
		return AVR_INST_LPM;
	}
	if ( strcmp(str, "LPM_d") == 0 ) {
		return AVR_INST_LPM_d;
	}
	if ( strcmp(str, "LPM_d_Z_inc") == 0 ) {
		return AVR_INST_LPM_d_Z_inc;
	}
	if ( strcmp(str, "LSL") == 0 ) {
		return AVR_INST_LSL;
	}
	if ( strcmp(str, "LSR") == 0 ) {
		return AVR_INST_LSR;
	}
	if ( strcmp(str, "MOV") == 0 ) {
		return AVR_INST_MOV;
	}
	if ( strcmp(str, "MOVW") == 0 ) {
		return AVR_INST_MOVW;
	}
	if ( strcmp(str, "MUL") == 0 ) {
		return AVR_INST_MUL;
	}
	if ( strcmp(str, "MULS") == 0 ) {
		return AVR_INST_MULS;
	}
	if ( strcmp(str, "MULSU") == 0 ) {
		return AVR_INST_MULSU;
	}
	if ( strcmp(str, "NEG") == 0 ) {
		return AVR_INST_NEG;
	}
	if ( strcmp(str, "NOP") == 0 ) {
		return AVR_INST_NOP;
	}
	if ( strcmp(str, "OR") == 0 ) {
		return AVR_INST_OR;
	}
	if ( strcmp(str, "ORI") == 0 ) {
		return AVR_INST_ORI;
	}
	if ( strcmp(str, "OUT") == 0 ) {
		return AVR_INST_OUT;
	}
	if ( strcmp(str, "POP") == 0 ) {
		return AVR_INST_POP;
	}
	if ( strcmp(str, "PUSH") == 0 ) {
		return AVR_INST_PUSH;
	}
	if ( strcmp(str, "RCALL") == 0 ) {
		return AVR_INST_RCALL;
	}
	if ( strcmp(str, "RET") == 0 ) {
		return AVR_INST_RET;
	}
	if ( strcmp(str, "RETI") == 0 ) {
		return AVR_INST_RETI;
	}
	if ( strcmp(str, "RJMP") == 0 ) {
		return AVR_INST_RJMP;
	}
	if ( strcmp(str, "ROL") == 0 ) {
		return AVR_INST_ROL;
	}
	if ( strcmp(str, "ROR") == 0 ) {
		return AVR_INST_ROR;
	}
	if ( strcmp(str, "SBC") == 0 ) {
		return AVR_INST_SBC;
	}
	if ( strcmp(str, "SBCI") == 0 ) {
		return AVR_INST_SBCI;
	}
	if ( strcmp(str, "SBI") == 0 ) {
		return AVR_INST_SBI;
	}
	if ( strcmp(str, "SBIC") == 0 ) {
		return AVR_INST_SBIC;
	}
	if ( strcmp(str, "SBIS") == 0 ) {
		return AVR_INST_SBIS;
	}
	if ( strcmp(str, "SBIW") == 0 ) {
		return AVR_INST_SBIW;
	}
	if ( strcmp(str, "SBR") == 0 ) {
		return AVR_INST_SBR;
	}
	if ( strcmp(str, "SBRC") == 0 ) {
		return AVR_INST_SBRC;
	}
	if ( strcmp(str, "SBRS") == 0 ) {
		return AVR_INST_SBRS;
	}
	if ( strcmp(str, "SEC") == 0 ) {
		return AVR_INST_SEC;
	}
	if ( strcmp(str, "SEH") == 0 ) {
		return AVR_INST_SEH;
	}
	if ( strcmp(str, "SEI") == 0 ) {
		return AVR_INST_SEI;
	}
	if ( strcmp(str, "SEN") == 0 ) {
		return AVR_INST_SEN;
	}
	if ( strcmp(str, "SER") == 0 ) {
		return AVR_INST_SER;
	}
	if ( strcmp(str, "SES") == 0 ) {
		return AVR_INST_SES;
	}
	if ( strcmp(str, "SET") == 0 ) {
		return AVR_INST_SET;
	}
	if ( strcmp(str, "SEV") == 0 ) {
		return AVR_INST_SEV;
	}
	if ( strcmp(str, "SEZ") == 0 ) {
		return AVR_INST_SEZ;
	}
	if ( strcmp(str, "SLEEP") == 0 ) {
		return AVR_INST_SLEEP;
	}
	if ( strcmp(str, "SPM") == 0 ) {
		return AVR_INST_SPM;
	}
	if ( strcmp(str, "SPM_x") == 0 ) {
		return AVR_INST_SPM_x;
	}
	if ( strcmp(str, "SPM_x_Z_inc") == 0 ) {
		return AVR_INST_SPM_x_Z_inc;
	}
	if ( strcmp(str, "ST_X") == 0 ) {
		return AVR_INST_ST_X;
	}
	if ( strcmp(str, "ST_X_inc") == 0 ) {
		return AVR_INST_ST_X_inc;
	}
	if ( strcmp(str, "ST_dec_X") == 0 ) {
		return AVR_INST_ST_dec_X;
	}
	if ( strcmp(str, "ST_Y") == 0 ) {
		return AVR_INST_ST_Y;
	}
	if ( strcmp(str, "ST_Y_inc") == 0 ) {
		return AVR_INST_ST_Y_inc;
	}
	if ( strcmp(str, "ST_dec_Y") == 0 ) {
		return AVR_INST_ST_dec_Y;
	}
	if ( strcmp(str, "ST_Y_add_q") == 0 ) {
		return AVR_INST_ST_Y_add_q;
	}
	if ( strcmp(str, "ST_Z") == 0 ) {
		return AVR_INST_ST_Z;
	}
	if ( strcmp(str, "ST_Z_inc") == 0 ) {
		return AVR_INST_ST_Z_inc;
	}
	if ( strcmp(str, "ST_dec_Z") == 0 ) {
		return AVR_INST_ST_dec_Z;
	}
	if ( strcmp(str, "ST_Z_add_q") == 0 ) {
		return AVR_INST_ST_Z_add_q;
	}
	if ( strcmp(str, "STS") == 0 ) {
		return AVR_INST_STS;
	}
	if ( strcmp(str, "STS_rc") == 0 ) {
		return AVR_INST_STS_rc;
	}
	if ( strcmp(str, "SUB") == 0 ) {
		return AVR_INST_SUB;
	}
	if ( strcmp(str, "SUBI") == 0 ) {
		return AVR_INST_SUBI;
	}
	if ( strcmp(str, "SWAP") == 0 ) {
		return AVR_INST_SWAP;
	}
	if ( strcmp(str, "WDR") == 0 ) {
		return AVR_INST_WDR;
	}
	if ( strcmp(str, "XCH") == 0 ) {
		return AVR_INST_XCH;
	}
return AVR_INST_UNKNOWN;
}
uint32_t read_param() {
	uint32_t d;
	scanf("%"PRIu32, &d);
	return d;
	}
struct instruction_bits assemble_one() {
	struct instruction_bits inst_bits;
	enum instruction inst = read_inst();
	switch (inst) {
	case AVR_INST_ADC:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_ADC(d,r);
	break;
	}
	case AVR_INST_ADD:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_ADD(d,r);
	break;
	}
	case AVR_INST_ADIW:
	{
	uint32_t d = read_param();
	uint32_t K = read_param();
	inst_bits = avr_inst_ADIW(d,K);
	break;
	}
	case AVR_INST_AND:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_AND(d,r);
	break;
	}
	case AVR_INST_ANDI:
	{
	uint32_t d = read_param();
	uint32_t K = read_param();
	inst_bits = avr_inst_ANDI(d,K);
	break;
	}
	case AVR_INST_ASR:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_ASR(d);
	break;
	}
	case AVR_INST_BCLR:
	{
	uint32_t s = read_param();
	inst_bits = avr_inst_BCLR(s);
	break;
	}
	case AVR_INST_BLD:
	{
	uint32_t d = read_param();
	uint32_t b = read_param();
	inst_bits = avr_inst_BLD(d,b);
	break;
	}
	case AVR_INST_BRBC:
	{
	uint32_t s = read_param();
	uint32_t k = read_param();
	inst_bits = avr_inst_BRBC(s,k);
	break;
	}
	case AVR_INST_BRBS:
	{
	uint32_t s = read_param();
	uint32_t k = read_param();
	inst_bits = avr_inst_BRBS(s,k);
	break;
	}
	case AVR_INST_BRCC:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRCC(k);
	break;
	}
	case AVR_INST_BRCS:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRCS(k);
	break;
	}
	case AVR_INST_BREAK:
	{
	inst_bits = avr_inst_BREAK();
	break;
	}
	case AVR_INST_BREQ:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BREQ(k);
	break;
	}
	case AVR_INST_BRGE:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRGE(k);
	break;
	}
	case AVR_INST_BRHC:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRHC(k);
	break;
	}
	case AVR_INST_BRHS:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRHS(k);
	break;
	}
	case AVR_INST_BRID:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRID(k);
	break;
	}
	case AVR_INST_BRIE:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRIE(k);
	break;
	}
	case AVR_INST_BRLO:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRLO(k);
	break;
	}
	case AVR_INST_BRLT:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRLT(k);
	break;
	}
	case AVR_INST_BRMI:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRMI(k);
	break;
	}
	case AVR_INST_BRNE:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRNE(k);
	break;
	}
	case AVR_INST_BRPL:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRPL(k);
	break;
	}
	case AVR_INST_BRSH:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRSH(k);
	break;
	}
	case AVR_INST_BRTC:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRTC(k);
	break;
	}
	case AVR_INST_BRTS:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRTS(k);
	break;
	}
	case AVR_INST_BRVC:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRVC(k);
	break;
	}
	case AVR_INST_BRVS:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_BRVS(k);
	break;
	}
	case AVR_INST_BSET:
	{
	uint32_t s = read_param();
	inst_bits = avr_inst_BSET(s);
	break;
	}
	case AVR_INST_BST:
	{
	uint32_t d = read_param();
	uint32_t b = read_param();
	inst_bits = avr_inst_BST(d,b);
	break;
	}
	case AVR_INST_CALL:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_CALL(k);
	break;
	}
	case AVR_INST_CBI:
	{
	uint32_t A = read_param();
	uint32_t b = read_param();
	inst_bits = avr_inst_CBI(A,b);
	break;
	}
	case AVR_INST_CLH:
	{
	inst_bits = avr_inst_CLH();
	break;
	}
	case AVR_INST_CLI:
	{
	inst_bits = avr_inst_CLI();
	break;
	}
	case AVR_INST_CLN:
	{
	inst_bits = avr_inst_CLN();
	break;
	}
	case AVR_INST_CLS:
	{
	inst_bits = avr_inst_CLS();
	break;
	}
	case AVR_INST_CLT:
	{
	inst_bits = avr_inst_CLT();
	break;
	}
	case AVR_INST_CLV:
	{
	inst_bits = avr_inst_CLV();
	break;
	}
	case AVR_INST_CLZ:
	{
	inst_bits = avr_inst_CLZ();
	break;
	}
	case AVR_INST_COM:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_COM(d);
	break;
	}
	case AVR_INST_CP:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_CP(d,r);
	break;
	}
	case AVR_INST_CPC:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_CPC(d,r);
	break;
	}
	case AVR_INST_CPI:
	{
	uint32_t d = read_param();
	uint32_t K = read_param();
	inst_bits = avr_inst_CPI(d,K);
	break;
	}
	case AVR_INST_CPSE:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_CPSE(d,r);
	break;
	}
	case AVR_INST_DEC:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_DEC(d);
	break;
	}
	case AVR_INST_DES:
	{
	uint32_t K = read_param();
	inst_bits = avr_inst_DES(K);
	break;
	}
	case AVR_INST_EICALL:
	{
	inst_bits = avr_inst_EICALL();
	break;
	}
	case AVR_INST_EIJMP:
	{
	inst_bits = avr_inst_EIJMP();
	break;
	}
	case AVR_INST_ELPM:
	{
	inst_bits = avr_inst_ELPM();
	break;
	}
	case AVR_INST_ELPM_d:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_ELPM_d(d);
	break;
	}
	case AVR_INST_ELPM_d_Z_inc:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_ELPM_d_Z_inc(d);
	break;
	}
	case AVR_INST_EOR:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_EOR(d,r);
	break;
	}
	case AVR_INST_FMUL:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_FMUL(d,r);
	break;
	}
	case AVR_INST_FMULS:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_FMULS(d,r);
	break;
	}
	case AVR_INST_FMULSU:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_FMULSU(d,r);
	break;
	}
	case AVR_INST_ICALL:
	{
	inst_bits = avr_inst_ICALL();
	break;
	}
	case AVR_INST_IJMP:
	{
	inst_bits = avr_inst_IJMP();
	break;
	}
	case AVR_INST_IN:
	{
	uint32_t d = read_param();
	uint32_t A = read_param();
	inst_bits = avr_inst_IN(d,A);
	break;
	}
	case AVR_INST_INC:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_INC(d);
	break;
	}
	case AVR_INST_JMP:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_JMP(k);
	break;
	}
	case AVR_INST_LAC:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_LAC(r);
	break;
	}
	case AVR_INST_LAS:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_LAS(r);
	break;
	}
	case AVR_INST_LAT:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_LAT(r);
	break;
	}
	case AVR_INST_LD_X:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LD_X(d);
	break;
	}
	case AVR_INST_LD_X_inc:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LD_X_inc(d);
	break;
	}
	case AVR_INST_LD_dec_X:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LD_dec_X(d);
	break;
	}
	case AVR_INST_LD_Y:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LD_Y(d);
	break;
	}
	case AVR_INST_LD_Y_inc:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LD_Y_inc(d);
	break;
	}
	case AVR_INST_LD_dec_Y:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LD_dec_Y(d);
	break;
	}
	case AVR_INST_LD_Y_add_q:
	{
	uint32_t d = read_param();
	uint32_t q = read_param();
	inst_bits = avr_inst_LD_Y_add_q(d,q);
	break;
	}
	case AVR_INST_LD_Z:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LD_Z(d);
	break;
	}
	case AVR_INST_LD_Z_inc:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LD_Z_inc(d);
	break;
	}
	case AVR_INST_LD_dec_Z:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LD_dec_Z(d);
	break;
	}
	case AVR_INST_LD_Z_add_q:
	{
	uint32_t d = read_param();
	uint32_t q = read_param();
	inst_bits = avr_inst_LD_Z_add_q(d,q);
	break;
	}
	case AVR_INST_LDI:
	{
	uint32_t d = read_param();
	uint32_t K = read_param();
	inst_bits = avr_inst_LDI(d,K);
	break;
	}
	case AVR_INST_LDS:
	{
	uint32_t d = read_param();
	uint32_t k = read_param();
	inst_bits = avr_inst_LDS(d,k);
	break;
	}
	case AVR_INST_LDS_rc:
	{
	uint32_t d = read_param();
	uint32_t k = read_param();
	inst_bits = avr_inst_LDS_rc(d,k);
	break;
	}
	case AVR_INST_LPM:
	{
	inst_bits = avr_inst_LPM();
	break;
	}
	case AVR_INST_LPM_d:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LPM_d(d);
	break;
	}
	case AVR_INST_LPM_d_Z_inc:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LPM_d_Z_inc(d);
	break;
	}
	case AVR_INST_LSL:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LSL(d);
	break;
	}
	case AVR_INST_LSR:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_LSR(d);
	break;
	}
	case AVR_INST_MOV:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_MOV(d,r);
	break;
	}
	case AVR_INST_MOVW:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_MOVW(d,r);
	break;
	}
	case AVR_INST_MUL:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_MUL(d,r);
	break;
	}
	case AVR_INST_MULS:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_MULS(d,r);
	break;
	}
	case AVR_INST_MULSU:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_MULSU(d,r);
	break;
	}
	case AVR_INST_NEG:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_NEG(d);
	break;
	}
	case AVR_INST_NOP:
	{
	inst_bits = avr_inst_NOP();
	break;
	}
	case AVR_INST_OR:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_OR(d,r);
	break;
	}
	case AVR_INST_ORI:
	{
	uint32_t d = read_param();
	uint32_t K = read_param();
	inst_bits = avr_inst_ORI(d,K);
	break;
	}
	case AVR_INST_OUT:
	{
	uint32_t A = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_OUT(A,r);
	break;
	}
	case AVR_INST_POP:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_POP(d);
	break;
	}
	case AVR_INST_PUSH:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_PUSH(r);
	break;
	}
	case AVR_INST_RCALL:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_RCALL(k);
	break;
	}
	case AVR_INST_RET:
	{
	inst_bits = avr_inst_RET();
	break;
	}
	case AVR_INST_RETI:
	{
	inst_bits = avr_inst_RETI();
	break;
	}
	case AVR_INST_RJMP:
	{
	uint32_t k = read_param();
	inst_bits = avr_inst_RJMP(k);
	break;
	}
	case AVR_INST_ROL:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_ROL(d);
	break;
	}
	case AVR_INST_ROR:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_ROR(d);
	break;
	}
	case AVR_INST_SBC:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_SBC(d,r);
	break;
	}
	case AVR_INST_SBCI:
	{
	uint32_t d = read_param();
	uint32_t K = read_param();
	inst_bits = avr_inst_SBCI(d,K);
	break;
	}
	case AVR_INST_SBI:
	{
	uint32_t A = read_param();
	uint32_t b = read_param();
	inst_bits = avr_inst_SBI(A,b);
	break;
	}
	case AVR_INST_SBIC:
	{
	uint32_t A = read_param();
	uint32_t b = read_param();
	inst_bits = avr_inst_SBIC(A,b);
	break;
	}
	case AVR_INST_SBIS:
	{
	uint32_t A = read_param();
	uint32_t b = read_param();
	inst_bits = avr_inst_SBIS(A,b);
	break;
	}
	case AVR_INST_SBIW:
	{
	uint32_t d = read_param();
	uint32_t K = read_param();
	inst_bits = avr_inst_SBIW(d,K);
	break;
	}
	case AVR_INST_SBR:
	{
	uint32_t d = read_param();
	uint32_t K = read_param();
	inst_bits = avr_inst_SBR(d,K);
	break;
	}
	case AVR_INST_SBRC:
	{
	uint32_t r = read_param();
	uint32_t b = read_param();
	inst_bits = avr_inst_SBRC(r,b);
	break;
	}
	case AVR_INST_SBRS:
	{
	uint32_t r = read_param();
	uint32_t b = read_param();
	inst_bits = avr_inst_SBRS(r,b);
	break;
	}
	case AVR_INST_SEC:
	{
	inst_bits = avr_inst_SEC();
	break;
	}
	case AVR_INST_SEH:
	{
	inst_bits = avr_inst_SEH();
	break;
	}
	case AVR_INST_SEI:
	{
	inst_bits = avr_inst_SEI();
	break;
	}
	case AVR_INST_SEN:
	{
	inst_bits = avr_inst_SEN();
	break;
	}
	case AVR_INST_SER:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_SER(d);
	break;
	}
	case AVR_INST_SES:
	{
	inst_bits = avr_inst_SES();
	break;
	}
	case AVR_INST_SET:
	{
	inst_bits = avr_inst_SET();
	break;
	}
	case AVR_INST_SEV:
	{
	inst_bits = avr_inst_SEV();
	break;
	}
	case AVR_INST_SEZ:
	{
	inst_bits = avr_inst_SEZ();
	break;
	}
	case AVR_INST_SLEEP:
	{
	inst_bits = avr_inst_SLEEP();
	break;
	}
	case AVR_INST_SPM:
	{
	inst_bits = avr_inst_SPM();
	break;
	}
	case AVR_INST_SPM_x:
	{
	inst_bits = avr_inst_SPM_x();
	break;
	}
	case AVR_INST_SPM_x_Z_inc:
	{
	inst_bits = avr_inst_SPM_x_Z_inc();
	break;
	}
	case AVR_INST_ST_X:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_ST_X(r);
	break;
	}
	case AVR_INST_ST_X_inc:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_ST_X_inc(r);
	break;
	}
	case AVR_INST_ST_dec_X:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_ST_dec_X(r);
	break;
	}
	case AVR_INST_ST_Y:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_ST_Y(r);
	break;
	}
	case AVR_INST_ST_Y_inc:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_ST_Y_inc(r);
	break;
	}
	case AVR_INST_ST_dec_Y:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_ST_dec_Y(r);
	break;
	}
	case AVR_INST_ST_Y_add_q:
	{
	uint32_t r = read_param();
	uint32_t q = read_param();
	inst_bits = avr_inst_ST_Y_add_q(r,q);
	break;
	}
	case AVR_INST_ST_Z:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_ST_Z(r);
	break;
	}
	case AVR_INST_ST_Z_inc:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_ST_Z_inc(r);
	break;
	}
	case AVR_INST_ST_dec_Z:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_ST_dec_Z(r);
	break;
	}
	case AVR_INST_ST_Z_add_q:
	{
	uint32_t r = read_param();
	uint32_t q = read_param();
	inst_bits = avr_inst_ST_Z_add_q(r,q);
	break;
	}
	case AVR_INST_STS:
	{
	uint32_t k = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_STS(k,r);
	break;
	}
	case AVR_INST_STS_rc:
	{
	uint32_t k = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_STS_rc(k,r);
	break;
	}
	case AVR_INST_SUB:
	{
	uint32_t d = read_param();
	uint32_t r = read_param();
	inst_bits = avr_inst_SUB(d,r);
	break;
	}
	case AVR_INST_SUBI:
	{
	uint32_t d = read_param();
	uint32_t K = read_param();
	inst_bits = avr_inst_SUBI(d,K);
	break;
	}
	case AVR_INST_SWAP:
	{
	uint32_t d = read_param();
	inst_bits = avr_inst_SWAP(d);
	break;
	}
	case AVR_INST_WDR:
	{
	inst_bits = avr_inst_WDR();
	break;
	}
	case AVR_INST_XCH:
	{
	uint32_t r = read_param();
	inst_bits = avr_inst_XCH(r);
	break;
	}
	case AVR_INST_UNKNOWN:
	default:
	inst_bits.length = 0;
	fprintf(stderr, "Unknown instruction");
	}
	return inst_bits;
}
