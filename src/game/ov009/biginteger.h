#ifndef GAME_OV009_BIGINTEGER_H
#define GAME_OV009_BIGINTEGER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of biginteger.c, prototypes copied from their definitions. */

#include "../types.h"

int count_digits(const unsigned short *p, int n);
int CPSi_big_sign(unsigned short *a, int digits);
void CPSi_big_add(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
void CPSi_big_add_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits);
void CPSi_big_negate(unsigned short *a, int digits);
void CPSi_big_sub(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
void CPSi_big_sub_small(unsigned short *c, unsigned short *a, unsigned short _b, int digits);
int CPSi_big_compare(unsigned short *a, unsigned short *b, int n);
void CPSi_big_add_part(unsigned short *a, unsigned long b, int i, int digits);
void CPSi_big_mult(unsigned short *c, unsigned short *a, unsigned short *b, int digits);
void CPSi_big_mult_small(unsigned short *c, unsigned short *a, unsigned short b, int digits);
void CPSi_big_sqr(unsigned short *c, unsigned short *a, int digits);
unsigned long long get48bits_1(unsigned short *p);
u64 get48bits_2(u16 *s);
u64 get48bits_3(u16 *s);
u64 get64bits(u16 *s);
void CPSi_big_div(u16 *c, u16 *a, u16 *b, u16 *r, int digits, u16 *work);
void CPSi_big_power(u16 *c, u16 *a, u16 *b, int digits, u16 *n);
void CPSi_big_montpower(unsigned short *c, unsigned short *m, unsigned short *e, int digits, unsigned short *n);
void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits);
void CPSi_char_from_big(unsigned char *d, unsigned short *s, int numbytes, int digits);
/* END mkheaders: generated region */

#endif
