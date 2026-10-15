/*
 * function: GFL_NET_SAVE_StepDelay
 * address:  0x020109B8
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepDelay.c \
 *       --func GFL_NET_SAVE_StepDelay --addr 0x020109B8 --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_SAVE_SetStep  0x02010888  thumb
 *   GFL_NET_SAVE_StepWaitSync73  0x020109E0  thumb
 */
#include "../include/Obj11241.h"

typedef unsigned char u8;
typedef signed int    s32;
typedef unsigned int  u32;

struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, u32 a, u32 b);
extern void GFL_NET_SAVE_SetStep(u8 *p, u32 v);
extern void GFL_NET_SAVE_StepWaitSync73(u8 *p);

void GFL_NET_SAVE_StepDelay(u8 *p)
{
    s32 v = (s32)((struct Obj11241 *)p)->f10 - 1;

    ((struct Obj11241 *)p)->f10 = (u32)v;
    if (v < 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x73, 8);
        GFL_NET_SAVE_SetStep(p, (u32)GFL_NET_SAVE_StepWaitSync73);
    }
}
