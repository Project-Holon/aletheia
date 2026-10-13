/*
 * function: BTL_NET_GetServerCmd
 * address: 0x021D4C6C
 * packet: pkt_ov093_021D4C6C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 */
#include "../include/Obj21214.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *gBtlNet;
u16 BTL_NET_GetServerCmd(u8 **out)
{
    u8 *p = gBtlNet + 0x38;
    *out = p;
    return ((struct Obj21214 *)p)->fBB8;
}
