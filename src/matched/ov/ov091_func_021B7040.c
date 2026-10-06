/*
 * function: func_021B7040
 * address: 0x021B7040
 * packet: pkt_ov091_021B7040
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02050ED4 0x02050ED4 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj20855.h"
extern void func_02050ED4(void);
extern unsigned int func_02048AC4(void *ptr);
extern void func_02046788(void);
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern void func_0207D63C(unsigned,unsigned,unsigned,unsigned,unsigned);
void func_021B7040(unsigned p) { func_02050ED4(); func_02048AC4((void *)(((struct Obj20855 *)p)->f258)); func_02046788(); func_020403F4(0); func_0207D63C(0x04000050,20,8,16,10); }
