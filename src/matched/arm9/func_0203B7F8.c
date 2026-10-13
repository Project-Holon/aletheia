/*
 * function: GFL_NET_STATE_ParentNegotiationWait
 * address:  0x0203B7F8
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
 *   GFL_NET_HANDLE_GetNegotiationNum  0x020399EC  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_ParentNegotiationWait.c \
 *       --func GFL_NET_STATE_ParentNegotiationWait --addr 0x0203B7F8 --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *_pNetState;

struct B794 {
    u8     pad_00[0x2C];
    void (*unk_2C)(u32);
};

extern void *GFL_NET_GetInitParam(void);
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
typedef signed int     s32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_GetNegotiationNum(u32 a);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern u32 GFL_NET_GetUserArg(void);

void GFL_NET_STATE_ParentNegotiationWait(struct B794 *p)
{
    GFL_NET_GetInitParam();

    GFL_NET_HANDLE_GetNetHandle(0xFF);
    if ((int)GFL_NET_HANDLE_GetNegotiationNum((u32)GFL_NET_HANDLE_GetCurrentHandle()) < 2)
        return;

    GFL_NET_SYSTEM_GetCurrentAid();

    if (p->unk_2C != 0) {
        p->unk_2C(GFL_NET_GetUserArg());
        p->unk_2C = 0;
    }

    GFL_NET_STATE_ChangeStateDebug((struct NetState *)((u8 *)_pNetState), (void *)0x0203C00C, 0, 0x33F);
}
