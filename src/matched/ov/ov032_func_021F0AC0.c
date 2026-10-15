/*
 * function: BEACON_VIEW_ShowRecordCount
 * address:  0x021F0AC0
 * packet:   pkt_ov032_021F0AC0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_ShowRecordCount  0x021F0AC0  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   BEACON_VIEW_SetupMessageText  0x021F0A98  thumb  ov032
 *   BEACON_VIEW_DrawWindowText  0x021F201C  thumb  ov032
 */
#include "../include/Obj00007.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct WordSet;
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void BEACON_VIEW_SetupMessageText(char *p, unsigned a);
extern void BEACON_VIEW_DrawWindowText(char *p, char *q, void *text, u16 x, u8 y, u8 a5, u16 col, u32 a7);

void BEACON_VIEW_ShowRecordCount(char *p)
{
    WORDSET_SetSlotNumber((struct WordSet *)(*(int *)&((struct Obj00007 *)p)->f110), 0, ((struct Obj00007 *)p)->f7B, 2, 1, 1);
    BEACON_VIEW_SetupMessageText(p, 0);
    BEACON_VIEW_DrawWindowText(p, p + 0x110 + 0x94, (void *)(*(int *)&((struct Obj00007 *)p)->f11C), 4, 0, 1, 0x3DC1, 0);
}
