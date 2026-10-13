/*
 * function: WIH_GetSharedDataAdr
 * address: 0x02179394
 * packet: pkt_ov014_02179394
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: existing matched 021793B8 follows the 36-byte leaf.
 * symbols:
 *   gWihWork 0x021797A8 data a4
 *   WM_GetSharedDataAddress 0x02090B18 arm
 */

#include "../include/G_S.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern struct S *gWihWork;
extern int WM_GetSharedDataAddress(void *info, void *buffer, u16 slot);
int WIH_GetSharedDataAdr(u16 slot)
{
    return WM_GetSharedDataAddress(((u8 *)gWihWork) + 0x1444, ((u8 *)gWihWork) + 0x1C64, slot);
}
