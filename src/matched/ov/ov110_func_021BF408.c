/*
 * function: func_021BF408
 * address: 0x021BF408
 * packet: pkt_ov110_021BF408
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAD20 0x021BAD20 thumb ov110
 *   func_021BEDD0 0x021BEDD0 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj04451.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_021BAD20(u8 *,unsigned);
extern unsigned func_021BEDD0(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
int func_021BF408(u8 *p,u8 *q) {
 u16 n=((struct Obj04451 *)q)->f0;
 ((struct Obj04451 *)q)->f0=func_021BAD20(p,((struct Obj04451 *)q)->f2);
 ((struct Obj04451 *)q)->f8=0;
 if(n!=((struct Obj04451 *)q)->f0) GFL_USE_PlaySeDefaultVolume(0x548);
 if((int)func_021BEDD0(q)<((struct Obj04451 *)q)->f4-2) return 2;
 q[6]=0; return 3;
}
