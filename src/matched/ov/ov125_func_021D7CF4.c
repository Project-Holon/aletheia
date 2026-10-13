/*
 * function: func_021D7CF4
 * address: 0x021D7CF4
 * packet: pkt_ov125_021D7CF4
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   OS_IsTickAvailable 0x02087058 arm
 *   func_02086FE8 0x02086FE8 arm
 *   d_021D9E40 0x021D9E40 data a4
 */

#include "../include/G_Clear.h"

extern int OS_IsTickAvailable(void);
extern void func_02086FE8(void);
extern struct Clear d_021D9E40;
int func_021D7CF4(void){if(!OS_IsTickAvailable())func_02086FE8();*(int*)(((char *)&d_021D9E40)+0x270)=16;return 1;}
