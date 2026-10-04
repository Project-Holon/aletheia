/*
 * function: func_022004F0
 * address: 0x022004F0
 * packet: pkt_ov135_022004F0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022009A4 0x022009A4 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_0204B92C 0x0204B92C arm
 *   func_021F4F90 0x021F4F90 thumb ov135
 */
#include "../include/Obj02863.h"
struct Obj;
extern void func_022009A4(unsigned char *,unsigned,unsigned,unsigned,unsigned);extern void func_021F4E98(void *,unsigned,unsigned);extern void func_0204B92C(struct Obj *,unsigned);extern void func_021F4F90(void *);
int func_022004F0(unsigned char *p) {func_022009A4(p,4,1,0,0xf0f);func_021F4E98(p,10,6);func_0204B92C(*(struct Obj * *)&((struct Obj02863 *)p)->fBF4,1);func_021F4F90(p);return 2;}
