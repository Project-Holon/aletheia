/*
 * function: GFL_NET_SAVE_StepWaitSaveStart
 * address:  0x02010964
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepWaitSaveStart.c \
 *       --func GFL_NET_SAVE_StepWaitSaveStart --addr 0x02010964 --thumb --cc 1.1p1
 *
 * symbols:
 *   GAME_DATA_SaveMain  0x02012DD0  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_SAVE_SetStep  0x02010888  thumb
 *   GFL_NET_SAVE_StepWaitSync72  0x02010994  thumb
 */
#include "../include/Obj11240.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, u32 a, u32 b);
extern int  GAME_DATA_SaveMain(u8 *p);
extern u32  func_020056EC(u32 v);
extern void GFL_NET_SAVE_SetStep(u8 *p, u32 v);
extern void GFL_NET_SAVE_StepWaitSync72(u8 *p);

void GFL_NET_SAVE_StepWaitSaveStart(u8 *p)
{
    if (GAME_DATA_SaveMain((u8 *)((struct Obj11240 *)p)->fC) == 1) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x72, 8);
        ((struct Obj11240 *)p)->f10 = func_020056EC(0x3c);
        GFL_NET_SAVE_SetStep(p, (u32)GFL_NET_SAVE_StepWaitSync72);
    }
}
