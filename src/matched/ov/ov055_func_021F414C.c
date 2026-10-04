/*
 * function: func_021F414C
 * address: 0x021F414C
 * packet: pkt_ov055_021F414C
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216DB4C 0x0216DB4C thumb ov010
 *   func_0216DC98 0x0216DC98 thumb ov010
 *   func_0216DAE0 0x0216DAE0 thumb ov010
 *   func_0216D5B4 0x0216D5B4 thumb ov010
 */
#include "../include/Obj07666.h"
extern void func_0216DB4C(unsigned int *,unsigned int);
extern void func_0216DC98(unsigned int *,unsigned int);
extern void func_0216DAE0(unsigned int *,unsigned int);
typedef unsigned short u16;
extern void func_0216D5B4(void *p, u16 v);
void func_021F414C(unsigned char *p) { func_0216DB4C(*(unsigned int * *)&((struct Obj07666 *)p)->fC,1); func_0216DC98(*(unsigned int * *)&((struct Obj07666 *)p)->fC,1); func_0216DAE0(*(unsigned int * *)&((struct Obj07666 *)p)->fC,1); func_0216D5B4((void *)(*(unsigned int *)&((struct Obj07666 *)p)->fC),2000); }
