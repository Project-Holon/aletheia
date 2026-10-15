/*
 * function: BEACON_VIEW_RefreshTopEntry
 * address:  0x021F1268
 * packet:   pkt_ov032_021F1268
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_RefreshTopEntry 0x021F1268 thumb
 *   GAME_BEACON_ACCESSOR_TableGetRingIndex 0x021659F0 thumb ov010
 *   BEACON_VIEW_GetEntry 0x021F0F44 thumb
 *   BEACON_VIEW_PrintEntryFrames 0x021F1080 thumb
 */
#include "../include/Obj09797.h"
#include "../include/Obj13063.h"

typedef unsigned char u8;

extern int GAME_BEACON_ACCESSOR_TableGetRingIndex(u8 *q, int delta);
extern char *BEACON_VIEW_GetEntry(char *this, u8 id);
extern void BEACON_VIEW_PrintEntryFrames(char *this, char *e, int i, int j);

void BEACON_VIEW_RefreshTopEntry(char *this)
{
    int i;
    char *e;

    for (i = 0; i < ((struct Obj09797 *)this)->f7D; i++) {
        e = BEACON_VIEW_GetEntry(this, GAME_BEACON_ACCESSOR_TableGetRingIndex(*(u8 * *)&((struct Obj09797 *)this)->f3C, ((struct Obj09797 *)this)->f7C + i));
        if (((struct Obj13063 *)e)->f30 == 0 || ((struct Obj13063 *)e)->f2C != 0)
            BEACON_VIEW_PrintEntryFrames(this, e, 0, 0);
    }
}
