/*
 * function: BTL_ADAPTER_GetRecvCommand
 * address:  0x021EEBE8
 * packet:   pkt_ov093_021EEBE8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_NET_HasServerCmd  0x021D4C60  thumb  ov093
 *   BTL_NET_GetServerCmd  0x021D4C6C  thumb  ov093
 */
#include "../include/Obj21627.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[4];
    u32 w4;
    u32 w8;
    u8 st : 4;
    u8 hi : 4;
    u8 f0d;
    u8 mode;
    u8 f0f;
    u16 h10;
    u16 h12;
    u8 d[1];
} W;

extern u8 BTL_NET_HasServerCmd(void);
extern u16 BTL_NET_GetServerCmd(u8 **out);

u8 BTL_ADAPTER_GetRecvCommand(W *p)
{
    u8 *q;

    if (p->hi != 0) {
        if (BTL_NET_HasServerCmd() != 0) {
            BTL_NET_GetServerCmd(&q);
            return ((struct Obj21627 *)q)->f0;
        }
        return 0;
    }
    if (p->st == 0)
        return p->h10;
    return 0;
}
