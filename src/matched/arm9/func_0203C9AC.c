/*
 * function: GFL_NET_STATE_SetError
 * address:  0x0203C9AC
 * packet:   pkt_0203C9AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_SYSTEM_SetError  0x02039548  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_SetError.c \
 *       --func GFL_NET_STATE_SetError --addr 0x0203C9AC --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;
extern void GFL_NET_SYSTEM_SetError(void);

void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d)
{
    if (((u8 *)_pNetState) == 0)
        return;

    if ((u32)(a - 0x3ED) > 1)
        a = -a;

    *(u32 *)(((u8 *)_pNetState) + 0x30) = (u32)a;
    *(u32 *)(((u8 *)_pNetState) + 0x34) = b;
    *(u32 *)(((u8 *)_pNetState) + 0x38) = c;
    *(u32 *)(((u8 *)_pNetState) + 0x3C) = d;

    if (d != 0)
        GFL_NET_SYSTEM_SetError();
}
