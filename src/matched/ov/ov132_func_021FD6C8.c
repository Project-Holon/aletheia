/*
 * function: STA_NET_NotifyHostKind4
 * address:  0x021FD6C8
 * packet:   pkt_021FD6C8
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUS_COMM_FUNC_SendCommandWait  0x021FCEA8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23291.h"
#include "../include/Obj23292.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 MUS_COMM_FUNC_SendCommandWait(int unused, int kind, u32 value, u32 id);

int STA_NET_NotifyHostKind4(u8 *p)
{
    void *q = ((struct Obj23291 *)p)->f140;
    return MUS_COMM_FUNC_SendCommandWait((int)p, 4, (u32)(((struct Obj23292 *)q)->f20), 0xff);
}
