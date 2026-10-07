/*
 * function: func_02179394
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
 *   g_021797A8 0x021797A8 data a4
 *   func_02090B18 0x02090B18 arm
 */

#include "../include/G_S.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern struct S *g_021797A8;
extern int func_02090B18(void *info, void *buffer, u16 slot);
int func_02179394(u16 slot)
{
    return func_02090B18(((u8 *)g_021797A8) + 0x1444, ((u8 *)g_021797A8) + 0x1C64, slot);
}
