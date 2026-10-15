/*
 * function: GFL_NET_SAVE_StepProgress
 * address:  0x02010A04
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepProgress.c \
 *       --func GFL_NET_SAVE_StepProgress --addr 0x02010A04 --thumb --cc 1.1p1
 *
 * symbols:
 *   GAME_DATA_SaveMain  0x02012DD0  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_SAVE_SetStep  0x02010888  thumb
 *   GFL_NET_SAVE_StepFinish  0x02010A3C  thumb
 */
#include "../include/Obj06855.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, u32 a, u32 b);
extern int  GAME_DATA_SaveMain(u8 *p);
extern void GFL_NET_SAVE_SetStep(u8 *p, u32 v);
extern void GFL_NET_SAVE_StepFinish(u8 *p);

void GFL_NET_SAVE_StepProgress(u8 *p)
{
    if (((struct Obj06855 *)p)->f0 != 0) {
        ((void (*)(u32)) * (u32 *)p)(((struct Obj06855 *)p)->f4);
    }
    if (GAME_DATA_SaveMain(*(u8 * *)&((struct Obj06855 *)p)->fC) == 2) {
        *(u32 *)&((struct Obj06855 *)p)->fC = 0;
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x74, 8);
        GFL_NET_SAVE_SetStep(p, (u32)GFL_NET_SAVE_StepFinish);
    }
}
