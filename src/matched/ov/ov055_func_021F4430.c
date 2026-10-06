/*
 * function: func_021F4430
 * address: 0x021F4430
 * packet: pkt_ov055_021F4430
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F45A4 0x021F45A4 thumb ov055
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj07667.h"
extern void func_021F45A4(unsigned short *,unsigned int);
struct Rec;
typedef unsigned int   u32;
extern u32 func_02045C04(struct Rec *rec);
void func_021F4430(unsigned char *p) { int i; for (i=0;i<16;i++) func_021F45A4((unsigned short *)(p+16+i*8),((struct Obj07667 *)p)->fC); ((struct Obj07667 *)p)->fC=0; func_02045C04(((struct Obj07667 *)p)->f8); ((struct Obj07667 *)p)->f8=0; }
