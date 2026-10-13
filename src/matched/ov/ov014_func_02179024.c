/*
 * function: WIH_GetMeasureChannel
 * address: 0x02179024
 * packet: pkt_ov014_02179024
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data a4
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   WIH_PickRandomChannel 0x02179050 thumb ov014
 */

#include "../include/G_S.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern struct S *gWihWork;
extern void WIH_ChangeSysState(int);
extern int WIH_PickRandomChannel(u16);
u16 WIH_GetMeasureChannel(void) {
 WIH_ChangeSysState(1);
 *(u16 *)(((u8 *)gWihWork) + 0x1EAC) = WIH_PickRandomChannel(*(u16 *)(((u8 *)gWihWork) + 0x1EB0));
 return *(u16 *)(((u8 *)gWihWork) + 0x1EAC);
}
