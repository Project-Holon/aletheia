/*
 * function: GFL_NET_STATE_RecvExitCommand
 * address:  0x0203BE5C
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
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_RecvExitCommand.c \
 *       --func GFL_NET_STATE_RecvExitCommand --addr 0x0203BE5C --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
struct Entry;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

void GFL_NET_STATE_RecvExitCommand(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    GFL_NET_SendToHandle((void *)a4, 2, 0, 0);

    if (GFL_NET_SYSTEM_GetCurrentAid() != 0)
        return;

    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203BDEC, 0, 0x46C);
}
