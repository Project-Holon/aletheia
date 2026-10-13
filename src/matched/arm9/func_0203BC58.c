/*
 * function: GFL_NET_STATE_ChangeChangeoverMode
 * address:  0x0203BC58
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
 *   GFL_NET_STATE_ChangeoverRestart  0x0203BBB0  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ChangeChangeoverMode.c \
 *       --func GFL_NET_STATE_ChangeChangeoverMode --addr 0x0203BC58 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

extern void *GFL_NET_GetSession(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern void GFL_NET_STATE_ChangeoverRestart(u32 a);

void GFL_NET_STATE_ChangeChangeoverMode(u8 v56, u8 v53, const void *src)
{
    GFL_NET_GetSession();
    ((u8 *)_pNetState)[0x53] = v53;
    ((u8 *)_pNetState)[0x56] = v56;

    if (src != 0) {
        MI_CpuCopy8(src, ((u8 *)_pNetState) + 0x57, 6);
    } else {
        MI_CpuFill8(((u8 *)_pNetState) + 0x57, 0xFF, 6);
    }

    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203BBB0, 0, 0x406);
    GFL_NET_STATE_ChangeoverRestart((u32)((u8 *)_pNetState));
}
