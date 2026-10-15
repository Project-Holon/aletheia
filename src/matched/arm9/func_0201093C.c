/*
 * function: GFL_NET_SAVE_StepBegin
 * address:  0x0201093C
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_StepBegin.c \
 *       --func GFL_NET_SAVE_StepBegin --addr 0x0201093C --thumb --cc 1.1p1
 *
 * symbols:
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_SAVE_SetStep  0x02010888  thumb
 *   GFL_NET_SAVE_StepWaitSaveStart  0x02010964  thumb
 */
#include "../include/Obj15613.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, u32 a, u32 b);
extern int GAME_DATA_SaveStart(int a0);
extern void GFL_NET_SAVE_SetStep(u8 *p, u32 v);
extern void GFL_NET_SAVE_StepWaitSaveStart(u8 *p);

void GFL_NET_SAVE_StepBegin(u8 *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x71, 8) != 0) {
        GAME_DATA_SaveStart(((struct Obj15613 *)p)->fC);
        GFL_NET_SAVE_SetStep(p, (u32)GFL_NET_SAVE_StepWaitSaveStart);
    }
}
