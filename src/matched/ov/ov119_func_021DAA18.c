/*
 * function: func_021DAA18
 * address: 0x021DAA18
 * packet: pkt_ov119_021DAA18
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA9F0 0x021DA9F0 thumb ov119
 */
#include "../include/Obj22730.h"
typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021D8E84(void *,int);
extern void func_021DA9F0(void *);
void func_021DAA18(char *p) {
 WIPE_SYS_Start((void *)4,0,0,0,6,1,((struct Obj22730 *)p)->f5F4);
 func_021D8E84(p,(int)func_021DA9F0);
}
