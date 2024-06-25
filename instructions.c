#include "instructions.h"

#include <assert.h>

//total instruction number is 141
struct instruction_bits avr_inst_ADC(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0001110000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ADD(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0000110000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ADIW(uint32_t d, uint32_t K) {
	assert( (d >> 2) == 0);
	assert( (K >> 6) == 0);
	uint32_t code = 0b1001011000000000;
	code |= (d<<4) & 0b0000000000110000;
	code |= (K&0b1111) << 0;
	code |= (K&0b110000) << 2;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_AND(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0010000000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ANDI(uint32_t d, uint32_t K) {
	assert( (d >> 4) == 0);
	assert( (K >> 8) == 0);
	uint32_t code = 0b0111000000000000;
	code |= (d<<4) & 0b0000000011110000;
	code |= (K&0b1111) << 0;
	code |= (K&0b11110000) << 4;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ASR(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001010000000101;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BCLR(uint32_t s) {
	assert( (s >> 3) == 0);
	uint32_t code = 0b1001010010001000;
	code |= (s<<4) & 0b0000000001110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BLD(uint32_t d, uint32_t b) {
	assert( (d >> 5) == 0);
	assert( (b >> 3) == 0);
	uint32_t code = 0b1111100000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (b<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRBC(uint32_t s, uint32_t k) {
	assert( (s >> 3) == 0);
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111010000000000;
	code |= (s<<0) & 0b0000000000000111;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRBS(uint32_t s, uint32_t k) {
	assert( (s >> 3) == 0);
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111000000000000;
	code |= (s<<0) & 0b0000000000000111;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRCC(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111010000000000;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRCS(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111000000000000;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BREAK() {
	uint32_t code = 0b1001010110011000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BREQ(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111000000000001;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRGE(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111010000000100;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRHC(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111010000000101;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRHS(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111000000000101;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRID(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111010000000111;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRIE(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111000000000111;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRLO(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111000000000000;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRLT(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111000000000100;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRMI(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111000000000010;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRNE(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111010000000001;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRPL(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111010000000010;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRSH(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111010000000000;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRTC(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111010000000110;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRTS(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111000000000110;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRVC(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111010000000011;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BRVS(uint32_t k) {
	assert( (k >> 7) == 0);
	uint32_t code = 0b1111000000000011;
	code |= (k<<3) & 0b0000001111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BSET(uint32_t s) {
	assert( (s >> 3) == 0);
	uint32_t code = 0b1001010000001000;
	code |= (s<<4) & 0b0000000001110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_BST(uint32_t d, uint32_t b) {
	assert( (d >> 5) == 0);
	assert( (b >> 3) == 0);
	uint32_t code = 0b1111101000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (b<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CALL(uint32_t k) {
	assert( (k >> 22) == 0);
	uint32_t code = 0b10010100000011100000000000000000;
	code |= (k&0b11111111111111111) << 0;
	code |= (k&0b1111100000000000000000) << 3;
	struct instruction_bits inst_bits = {32, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CBI(uint32_t A, uint32_t b) {
	assert( (A >> 5) == 0);
	assert( (b >> 3) == 0);
	uint32_t code = 0b1001100000000000;
	code |= (A<<3) & 0b0000000011111000;
	code |= (b<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CLH() {
	uint32_t code = 0b1001010011011000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CLI() {
	uint32_t code = 0b1001010011111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CLN() {
	uint32_t code = 0b1001010010101000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CLS() {
	uint32_t code = 0b1001010011001000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CLT() {
	uint32_t code = 0b1001010011101000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CLV() {
	uint32_t code = 0b1001010010111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CLZ() {
	uint32_t code = 0b1001010010011000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_COM(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001010000000000;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CP(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0001010000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CPC(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0000010000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CPI(uint32_t d, uint32_t K) {
	assert( (d >> 4) == 0);
	assert( (K >> 8) == 0);
	uint32_t code = 0b0011000000000000;
	code |= (d<<4) & 0b0000000011110000;
	code |= (K&0b1111) << 0;
	code |= (K&0b11110000) << 4;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_CPSE(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0001000000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_DEC(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001010000001010;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_DES(uint32_t K) {
	assert( (K >> 4) == 0);
	uint32_t code = 0b1001010000001011;
	code |= (K<<4) & 0b0000000011110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_EICALL() {
	uint32_t code = 0b1001010100011001;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_EIJMP() {
	uint32_t code = 0b1001010000011001;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ELPM() {
	uint32_t code = 0b1001010111011000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ELPM_d(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000000110;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ELPM_d_Z_inc(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000000111;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_EOR(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0010010000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_FMUL(uint32_t d, uint32_t r) {
	assert( (d >> 3) == 0);
	assert( (r >> 3) == 0);
	uint32_t code = 0b0000001100001000;
	code |= (d<<4) & 0b0000000001110000;
	code |= (r<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_FMULS(uint32_t d, uint32_t r) {
	assert( (d >> 3) == 0);
	assert( (r >> 3) == 0);
	uint32_t code = 0b0000001110000000;
	code |= (d<<4) & 0b0000000001110000;
	code |= (r<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_FMULSU(uint32_t d, uint32_t r) {
	assert( (d >> 3) == 0);
	assert( (r >> 3) == 0);
	uint32_t code = 0b0000001110001000;
	code |= (d<<4) & 0b0000000001110000;
	code |= (r<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ICALL() {
	uint32_t code = 0b1001010100001001;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_IJMP() {
	uint32_t code = 0b1001010000001001;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_IN(uint32_t d, uint32_t A) {
	assert( (d >> 5) == 0);
	assert( (A >> 6) == 0);
	uint32_t code = 0b1011000000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (A&0b1111) << 0;
	code |= (A&0b110000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_INC(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001010000000011;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_JMP(uint32_t k) {
	assert( (k >> 22) == 0);
	uint32_t code = 0b10010100000011000000000000000000;
	code |= (k&0b11111111111111111) << 0;
	code |= (k&0b1111100000000000000000) << 3;
	struct instruction_bits inst_bits = {32, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LAC(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000000110;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LAS(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000000101;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LAT(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000000111;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_X(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000001100;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_X_inc(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000001101;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_dec_X(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000001110;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_Y(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1000000000001000;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_Y_inc(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000001001;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_dec_Y(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000001010;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_Y_add_q(uint32_t d, uint32_t q) {
	assert( (d >> 5) == 0);
	assert( (q >> 6) == 0);
	uint32_t code = 0b1000000000001000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (q&0b111) << 0;
	code |= (q&0b11000) << 7;
	code |= (q&0b100000) << 8;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_Z(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1000000000000000;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_Z_inc(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000000001;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_dec_Z(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000000010;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LD_Z_add_q(uint32_t d, uint32_t q) {
	assert( (d >> 5) == 0);
	assert( (q >> 6) == 0);
	uint32_t code = 0b1000000000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (q&0b111) << 0;
	code |= (q&0b11000) << 7;
	code |= (q&0b100000) << 8;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LDI(uint32_t d, uint32_t K) {
	assert( (d >> 4) == 0);
	assert( (K >> 8) == 0);
	uint32_t code = 0b1110000000000000;
	code |= (d<<4) & 0b0000000011110000;
	code |= (K&0b1111) << 0;
	code |= (K&0b11110000) << 4;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LDS(uint32_t d, uint32_t k) {
	assert( (d >> 5) == 0);
	assert( (k >> 16) == 0);
	uint32_t code = 0b10010000000000000000000000000000;
	code |= (d<<20) & 0b00000001111100000000000000000000;
	code |= (k<<0) & 0b00000000000000001111111111111111;
	struct instruction_bits inst_bits = {32, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LDS_rc(uint32_t d, uint32_t k) {
	assert( (d >> 4) == 0);
	assert( (k >> 7) == 0);
	uint32_t code = 0b1010000000000000;
	code |= (d<<4) & 0b0000000011110000;
	code |= (k&0b1111) << 0;
	code |= (k&0b1110000) << 4;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LPM() {
	uint32_t code = 0b1001010111001000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LPM_d(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000000100;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LPM_d_Z_inc(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000000101;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LSL(uint32_t d) {
	assert( (d >> 10) == 0);
	uint32_t code = 0b0000110000000000;
	code |= (d<<0) & 0b0000001111111111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_LSR(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001010000000110;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_MOV(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0010110000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_MOVW(uint32_t d, uint32_t r) {
	assert( (d >> 4) == 0);
	assert( (r >> 4) == 0);
	uint32_t code = 0b0000000100000000;
	code |= (d<<4) & 0b0000000011110000;
	code |= (r<<0) & 0b0000000000001111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_MUL(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001110000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_MULS(uint32_t d, uint32_t r) {
	assert( (d >> 4) == 0);
	assert( (r >> 4) == 0);
	uint32_t code = 0b0000001000000000;
	code |= (d<<4) & 0b0000000011110000;
	code |= (r<<0) & 0b0000000000001111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_MULSU(uint32_t d, uint32_t r) {
	assert( (d >> 3) == 0);
	assert( (r >> 3) == 0);
	uint32_t code = 0b0000001100000000;
	code |= (d<<4) & 0b0000000001110000;
	code |= (r<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_NEG(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001010000000001;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_NOP() {
	uint32_t code = 0b0000000000000000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_OR(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0010100000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ORI(uint32_t d, uint32_t K) {
	assert( (d >> 4) == 0);
	assert( (K >> 8) == 0);
	uint32_t code = 0b0110000000000000;
	code |= (d<<4) & 0b0000000011110000;
	code |= (K&0b1111) << 0;
	code |= (K&0b11110000) << 4;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_OUT(uint32_t A, uint32_t r) {
	assert( (A >> 6) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b1011100000000000;
	code |= (A&0b1111) << 0;
	code |= (A&0b110000) << 5;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_POP(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001000000001111;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_PUSH(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000001111;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_RCALL(uint32_t k) {
	assert( (k >> 12) == 0);
	uint32_t code = 0b1101000000000000;
	code |= (k<<0) & 0b0000111111111111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_RET() {
	uint32_t code = 0b1001010100001000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_RETI() {
	uint32_t code = 0b1001010100011000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_RJMP(uint32_t k) {
	assert( (k >> 12) == 0);
	uint32_t code = 0b1100000000000000;
	code |= (k<<0) & 0b0000111111111111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ROL(uint32_t d) {
	assert( (d >> 10) == 0);
	uint32_t code = 0b0001110000000000;
	code |= (d<<0) & 0b0000001111111111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ROR(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001010000000111;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SBC(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0000100000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SBCI(uint32_t d, uint32_t K) {
	assert( (d >> 4) == 0);
	assert( (K >> 8) == 0);
	uint32_t code = 0b0100000000000000;
	code |= (d<<4) & 0b0000000011110000;
	code |= (K&0b1111) << 0;
	code |= (K&0b11110000) << 4;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SBI(uint32_t A, uint32_t b) {
	assert( (A >> 5) == 0);
	assert( (b >> 3) == 0);
	uint32_t code = 0b1001101000000000;
	code |= (A<<3) & 0b0000000011111000;
	code |= (b<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SBIC(uint32_t A, uint32_t b) {
	assert( (A >> 5) == 0);
	assert( (b >> 3) == 0);
	uint32_t code = 0b1001100100000000;
	code |= (A<<3) & 0b0000000011111000;
	code |= (b<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SBIS(uint32_t A, uint32_t b) {
	assert( (A >> 5) == 0);
	assert( (b >> 3) == 0);
	uint32_t code = 0b1001101100000000;
	code |= (A<<3) & 0b0000000011111000;
	code |= (b<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SBIW(uint32_t d, uint32_t K) {
	assert( (d >> 2) == 0);
	assert( (K >> 6) == 0);
	uint32_t code = 0b1001011100000000;
	code |= (d<<4) & 0b0000000000110000;
	code |= (K&0b1111) << 0;
	code |= (K&0b110000) << 2;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SBR(uint32_t d, uint32_t K) {
	assert( (d >> 4) == 0);
	assert( (K >> 8) == 0);
	uint32_t code = 0b0110000000000000;
	code |= (d<<4) & 0b0000000011110000;
	code |= (K&0b1111) << 0;
	code |= (K&0b11110000) << 4;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SBRC(uint32_t r, uint32_t b) {
	assert( (r >> 5) == 0);
	assert( (b >> 3) == 0);
	uint32_t code = 0b1111110000000000;
	code |= (r<<4) & 0b0000000111110000;
	code |= (b<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SBRS(uint32_t r, uint32_t b) {
	assert( (r >> 5) == 0);
	assert( (b >> 3) == 0);
	uint32_t code = 0b1111111000000000;
	code |= (r<<4) & 0b0000000111110000;
	code |= (b<<0) & 0b0000000000000111;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SEC() {
	uint32_t code = 0b1001010000001000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SEH() {
	uint32_t code = 0b1001010001011000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SEI() {
	uint32_t code = 0b1001010001111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SEN() {
	uint32_t code = 0b1001010000101000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SER(uint32_t d) {
	assert( (d >> 4) == 0);
	uint32_t code = 0b1110111100001111;
	code |= (d<<4) & 0b0000000011110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SES() {
	uint32_t code = 0b1001010001001000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SET() {
	uint32_t code = 0b1001010001101000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SEV() {
	uint32_t code = 0b1001010000111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SEZ() {
	uint32_t code = 0b1001010000011000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SLEEP() {
	uint32_t code = 0b1001010110001000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SPM() {
	uint32_t code = 0b1001010111101000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SPM_x() {
	uint32_t code = 0b1001010111101000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SPM_x_Z_inc() {
	uint32_t code = 0b1001010111111000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_X(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000001100;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_X_inc(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000001101;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_dec_X(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000001110;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_Y(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1000001000001000;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_Y_inc(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000001001;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_dec_Y(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000001010;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_Y_add_q(uint32_t r, uint32_t q) {
	assert( (r >> 5) == 0);
	assert( (q >> 6) == 0);
	uint32_t code = 0b1000001000001000;
	code |= (r<<4) & 0b0000000111110000;
	code |= (q&0b111) << 0;
	code |= (q&0b11000) << 7;
	code |= (q&0b100000) << 8;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_Z(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1000001000000000;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_Z_inc(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000000001;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_dec_Z(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000000010;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_ST_Z_add_q(uint32_t r, uint32_t q) {
	assert( (r >> 5) == 0);
	assert( (q >> 6) == 0);
	uint32_t code = 0b1000001000000000;
	code |= (r<<4) & 0b0000000111110000;
	code |= (q&0b111) << 0;
	code |= (q&0b11000) << 7;
	code |= (q&0b100000) << 8;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_STS(uint32_t k, uint32_t r) {
	assert( (k >> 16) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b10010010000000000000000000000000;
	code |= (k<<0) & 0b00000000000000001111111111111111;
	code |= (r<<20) & 0b00000001111100000000000000000000;
	struct instruction_bits inst_bits = {32, code};
	return inst_bits;
}

struct instruction_bits avr_inst_STS_rc(uint32_t k, uint32_t r) {
	assert( (k >> 7) == 0);
	assert( (r >> 4) == 0);
	uint32_t code = 0b1010100000000000;
	code |= (k&0b1111) << 0;
	code |= (k&0b1110000) << 4;
	code |= (r<<4) & 0b0000000011110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SUB(uint32_t d, uint32_t r) {
	assert( (d >> 5) == 0);
	assert( (r >> 5) == 0);
	uint32_t code = 0b0001100000000000;
	code |= (d<<4) & 0b0000000111110000;
	code |= (r&0b1111) << 0;
	code |= (r&0b10000) << 5;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SUBI(uint32_t d, uint32_t K) {
	assert( (d >> 4) == 0);
	assert( (K >> 8) == 0);
	uint32_t code = 0b0101000000000000;
	code |= (d<<4) & 0b0000000011110000;
	code |= (K&0b1111) << 0;
	code |= (K&0b11110000) << 4;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_SWAP(uint32_t d) {
	assert( (d >> 5) == 0);
	uint32_t code = 0b1001010000000010;
	code |= (d<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_WDR() {
	uint32_t code = 0b1001010110101000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

struct instruction_bits avr_inst_XCH(uint32_t r) {
	assert( (r >> 5) == 0);
	uint32_t code = 0b1001001000000100;
	code |= (r<<4) & 0b0000000111110000;
	struct instruction_bits inst_bits = {16, code};
	return inst_bits;
}

