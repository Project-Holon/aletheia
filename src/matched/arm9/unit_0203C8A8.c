/*
 * unit:     yes
 * function: GFL_NET_STATE_WifiStartMatch
 * address:  0x0203C8A8
 * packet:   pkt_0203C65C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_SYSTEM_IsDeviceReady  0x020392EC  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_STATE_WifiMatchStart  0x0203C864  arm
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   UI_SetSoftResetInhibitGlobal  0x0203516C  arm
 *
 * 140 bytes, three functions.  The middle one, 0x0203C8E8, is a 16-byte leaf
 * that saves nothing and so carries no label in the generated listing; the
 * per-function file for 0x0203C8A8 therefore reported an `EXACT*`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203C8A8.c \
 *       --addr 0x0203C8A8 --arm --cc 1.1p1
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

extern void *GFL_NET_GetSession(void);
extern void GFL_NET_STATE_WifiMatchStart(void);
extern int  GFL_NET_SYSTEM_IsDeviceReady(void);
extern void *GFL_NET_GetInitParam(void);
extern void UI_SetSoftResetInhibitGlobal(u32 a);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_WifiStartMatch(void)
{
    if (GFL_NET_SYSTEM_IsDeviceReady() != 0)
        return;

    GFL_NET_GetInitParam();
    UI_SetSoftResetInhibitGlobal(1);
    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203C864, 0, 0x760);
}

void GFL_NET_STATE_SetAutoExit(u8 v)
{
    if (((u8 *)_pNetState) != 0)
        ((u8 *)_pNetState)[0x4F] = v;
}

void GFL_NET_STATE_SetLoginOption(u8 v)
{
    u8 *s = GFL_NET_GetSession();

    if (((u8 *)_pNetState) != 0)
        ((u8 *)_pNetState)[0x50] = v;

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x8C))(v);
}
