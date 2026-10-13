/*
 * function: GFL_NET_STATE_ChangeoverChildNegotiation
 * address:  0x0203B758
 * packet:   pkt_0203B6EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_HANDLE_CheckNegotiation  0x02039ACC  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeoverChildNegotiation.c \
 *       --func GFL_NET_STATE_ChangeoverChildNegotiation --addr 0x0203B758 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

extern void *GFL_NET_GetInitParam(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern int GFL_NET_HANDLE_CheckNegotiation(void);

void GFL_NET_STATE_ChangeoverChildNegotiation(void)
{
    GFL_NET_GetInitParam();
    if (GFL_NET_HANDLE_CheckNegotiation() == 0)
        return;

    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203B794, 0, 0x30E);
}
