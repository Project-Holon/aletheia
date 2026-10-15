/*
 * function: BEACON_VIEW_ShowTouchedRow
 * address: 0x021F1F00
 * packet: pkt_ov032_021F1F00
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_BEACON_ACCESSOR_TableGetRingIndex 0x021659F0 thumb ov010
 *   BEACON_VIEW_GetEntry 0x021F0F44 thumb ov032
 *   BEACON_VIEW_StartWindowATask 0x021F1F34 thumb ov032
 *   BEACON_VIEW_PlaySe 0x021F0DD8 thumb ov032
 */
#include "../include/Obj13066.h"

typedef unsigned char u8;
extern int GAME_BEACON_ACCESSOR_TableGetRingIndex(u8 *q, int delta);
extern u8 *BEACON_VIEW_GetEntry(u8 *p, int a);
extern void BEACON_VIEW_StartWindowATask(char *p, u8 *q, int *r);
extern void BEACON_VIEW_PlaySe(unsigned int a);
void BEACON_VIEW_ShowTouchedRow(char *p, int a)
{
    u8 *q;
    u8 index;
    index = GAME_BEACON_ACCESSOR_TableGetRingIndex(*(u8 * *)&((struct Obj13066 *)p)->f3C, a + ((struct Obj13066 *)p)->f7C);
    q = BEACON_VIEW_GetEntry((u8 *)p, index);
    BEACON_VIEW_StartWindowATask(p, q, (int *)(p + 0xa8));
    BEACON_VIEW_PlaySe(0x54c);
}
