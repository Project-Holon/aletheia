/*
 * function: func_021FAEE4
 * address: 0x021FAEE4
 * packet: pkt_ov186_021FAEE4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB548 0x021FB548 thumb ov186
 */
#include "../include/Obj24819.h"
extern void func_021FB548(char *p, short *x, short *y);
void func_021FAEE4(char *p,int *out) { short x,y;func_021FB548(((struct Obj24819 *)p)->f8,&x,&y);out[0]=x;out[1]=y; }
