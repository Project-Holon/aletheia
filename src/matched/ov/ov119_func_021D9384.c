/*
 * function: POKETRADE_PROC_RecvPeerHalf
 * address: 0x021D9384
 * packet: pkt_ov119_021D9384
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj22719.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
void POKETRADE_PROC_RecvPeerHalf(u32 a, u32 b, short *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            ((struct Obj22719 *)base)->f107E = *src;
    }
}
