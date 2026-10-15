/*
 * function: GDS_SOCKET_InitTick
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
 *   OS_InitTick 0x02086FE8 arm
 *   gGdsSocket 0x021D9E40 data a4
 */

#include "../include/G_Clear.h"

extern int OS_IsTickAvailable(void);
extern void OS_InitTick(void);
extern struct Clear gGdsSocket;
int GDS_SOCKET_InitTick(void){if(!OS_IsTickAvailable())OS_InitTick();*(int*)(((char *)&gGdsSocket)+0x270)=16;return 1;}
