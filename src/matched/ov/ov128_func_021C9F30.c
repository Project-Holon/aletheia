/*
 * function: func_021C9F30
 * address: 0x021C9F30
 * packet: pkt_ov128_021C9F30
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj10496.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
void func_021C9F30(char *p,u32 index) {u32 i;void *q;char *base;base=p+index*4;for(i=0;i<((struct Obj10496 *)base)->f2C;i++){func_02043B5C(func_02045770(**(void ** *)&((struct Obj10496 *)base)->fC),0);q=**(void ** *)&((struct Obj10496 *)base)->fC;func_020456F8(q);func_02041B6C(func_02045730(q));}}
