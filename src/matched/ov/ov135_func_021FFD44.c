/*
 * function: func_021FFD44
 * address: 0x021FFD44
 * packet: pkt_ov135_021FFD44
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4EA0 0x021F4EA0 thumb ov135
 */
#include "../include/Obj10591.h"
extern void func_021F4EA0(void *,int,int);
void func_021FFD44(char *p) {int i;for(i=0;i<8;i++) {unsigned a=(unsigned)p+i*4;void *v=((struct Obj10591 *)a)->fD0C;if(v) func_021F4EA0(v,((struct Obj10591 *)a)->fEC4,((struct Obj10591 *)a)->fEC6);}}
