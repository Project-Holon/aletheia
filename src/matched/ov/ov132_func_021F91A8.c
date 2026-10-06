/*
 * function: func_021F91A8
 * address: 0x021F91A8
 * packet: pkt_ov132_021F91A8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204A380 0x0204A380 arm
 *   func_021FAD0C 0x021FAD0C thumb ov132
 */
#include "../include/Obj10531.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern char *func_021FAD0C(char *p, char *base, unsigned index, unsigned char flag);
void func_021F91A8(char *p, u8 n, u8 mask){void *table;table=func_0204A380((void *)(((struct Obj10531 *)p)->f18),n+0x4b,0,((struct Obj10531 *)p)->f0);func_021FAD0C(((struct Obj10531 *)p)->fB0,table,0,mask);}
