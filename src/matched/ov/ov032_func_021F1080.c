/*
 * function: BEACON_VIEW_PrintEntryFrames
 * address:  0x021F1080
 * packet:   pkt_ov032_021F1080
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_PrintEntryFrames  0x021F1080  thumb
 *   GAME_BEACON_GetReceivedFramesByTrainerId  0x02026D48  thumb
 *   BEACON_VIEW_DrawEntryText  0x021F2144  thumb  ov032
 */
#include "../include/Obj00225.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 GAME_BEACON_GetReceivedFramesByTrainerId(u16 v);
extern void BEACON_VIEW_DrawEntryText(char *p, char *q, void *text, u16 col, u32 a4);

void BEACON_VIEW_PrintEntryFrames(char *p, char *q, int r, int t)
{
    u8 c;

    c = (GAME_BEACON_GetReceivedFramesByTrainerId(((struct Obj00225 *)q)->f6) >= 0x2a30) ? 1 : 0;
    if (c == ((struct Obj00225 *)q)->f5 && r == 0) {
        return;
    }
    ((struct Obj00225 *)q)->f5 = c;
    if (c != 0) {
        BEACON_VIEW_DrawEntryText(p, q, (void *)(*(int *)&((struct Obj00225 *)q)->f24), 0xca0, t);
    } else {
        BEACON_VIEW_DrawEntryText(p, q, (void *)(*(int *)&((struct Obj00225 *)q)->f24), 0x3c60, t);
    }
}
