/*
 * function: GFL_NET_STATE_DeviceInitialize
 * address:  0x0203AFCC
 * packet:   pkt_0203AF40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  +0018 PC24 GFL_NET_STATE_InitWork -- `label`: the only branch to 0x0203AD8C
 *           anywhere in the image is this call, so the site has no witness
 *           outside 0203AFCC..0203B018 and stays wildcarded.
 *           +0044 ABS32 GFL_NET_STATE_DeviceInitialized -- the word is the previous function's
 *           address; its only two occurrences in the image are the pool words
 *           inside this very range (0x0203B010 here and 0x0203AFC0 in
 *           GFL_NET_STATE_DeviceInitialized), so `label` (no branch reaches it) and `literal`
 *           (self-witness) both refuse.  Filing GFL_NET_STATE_DeviceInitialized as an EXACT
 *           manifest entry converts this site to `matched` and leaves
 *           GFL_NET_STATE_InitWork as the only cap.
 *           Every concrete byte of the body and of the pool words reproduces
 *           (76 of 76; dsi/1.1p1).
 *
 * symbols:
 *   UI_SetKeepAwakeFlagsGlobal  0x02034F84  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_InitWork  0x0203AD8C  arm
 *   GFL_NET_STATE_DeviceInitialized  0x0203AF40  arm
 */

#include "../include/G_Sys.h"

typedef unsigned int u32;

extern void UI_SetKeepAwakeFlagsGlobal(u32 a);
extern void GFL_NET_STATE_InitWork(u32 a0);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
struct Rec;
extern void GFL_NET_STATE_DeviceInitialized(struct Rec *p);
extern struct Sys *_pNetState;

void GFL_NET_STATE_DeviceInitialize(void *a, u32 b)
{
    UI_SetKeepAwakeFlagsGlobal(4);
    GFL_NET_STATE_InitWork((u32)a);
    ((u32 *)_pNetState)[0xb] = b;
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u32 *)_pNetState), (void *)GFL_NET_STATE_DeviceInitialized, 0, 0x13F);
}
