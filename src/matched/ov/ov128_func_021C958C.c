/*
 * function: func_021C958C
 * address: 0x021C958C
 * packet: pkt_ov128_021C958C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C6DF8 0x021C6DF8 thumb ov128
 *   func_021C9BEC 0x021C9BEC thumb ov128
 */
#include "../include/Obj10493.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C6DF8(u8 *p, u32 a);
extern void func_021C9BEC(void *, void *, void *, int, int, int);
extern void func_020061E4(u32 a);
void func_021C958C(char *p, void *q, void *r, int s) {
 int mode;
 ((struct Obj10493 *)p)->f4=0;
 func_021C6DF8(r,0);
 mode=(((struct Obj10493 *)p)->f8==2)?2:1;
 func_021C9BEC(p,q,r,mode,((struct Obj10493 *)p)->f0,s);
 func_020061E4(0x548);
}
