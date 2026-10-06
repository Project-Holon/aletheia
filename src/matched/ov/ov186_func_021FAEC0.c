/*
 * function: func_021FAEC0
 * address: 0x021FAEC0
 * packet: pkt_ov186_021FAEC0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 */
#include "../include/Obj14454.h"
extern int func_021FB7B0(void *p, int i);
extern void func_021FB514(char *p, short x, int y);
void func_021FAEC0(char *p,unsigned index) { short x=(short)func_021FB7B0((void *)(((struct Obj14454 *)p)->fC),0);func_021FB514(((struct Obj14454 *)p)->f8,x,(short)(169-(index<<4))); }
