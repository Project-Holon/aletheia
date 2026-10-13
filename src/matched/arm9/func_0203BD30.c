/*
 * function: GFL_NET_STATE_SetChangeoverMode
 * address:  0x0203BD30
 * packet:   pkt_0203BD30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState      0x021469DC  data
 *   GFL_NET_GetSession   0x0203D788  arm
 *   GFL_NET_STATE_ChangeStateDebug   0x0203AD80  arm
 *   GFL_NET_STATE_ChangeoverStopChildDevice   0x0203BCE0  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_SetChangeoverMode.c \
 *       --func GFL_NET_STATE_SetChangeoverMode --addr 0x0203BD30 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

extern void *GFL_NET_GetSession(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern void GFL_NET_STATE_ChangeoverStopChildDevice(u8 *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);

void GFL_NET_STATE_SetChangeoverMode(u32 a0, u32 a1, u8 *a2)
{
    GFL_NET_GetSession();

    ((u8 *)_pNetState)[0x53] = (u8)a1;
    ((u8 *)_pNetState)[0x56] = (u8)a0;

    if (a2 != 0)
        MI_CpuCopy8(a2, ((u8 *)_pNetState) + 0x57, 6);
    else
        MI_CpuFill8(((u8 *)_pNetState) + 0x57, 0xFF, 6);

    if (((u8 *)_pNetState)[0x56] == 2)
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203B48C, 0, 0x430);

    if (((u8 *)_pNetState)[0x56] == 1) {
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203BCE0, 0, 0x438);
        GFL_NET_STATE_ChangeoverStopChildDevice(((u8 *)_pNetState));
    }
}
