/*
 * function: POKETRADE_PROC_ClearNetAutoExit
 * address: 0x021D89CC
 * packet: pkt_ov119_021D89CC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 */
#include "../include/Obj22698.h"
#include "../include/Obj22699.h"
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
typedef unsigned int   u32;
extern void GFL_NET_STATE_WifiDisconnect(u32 a);

void POKETRADE_PROC_ClearNetAutoExit(char *p)
{
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    GFL_NET_STATE_WifiDisconnect(0);
    ((struct Obj22699 *)(*(char * *)&((struct Obj22698 *)p)->f8))->f8 = 3;
}
