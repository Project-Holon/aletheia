/*
 * function: BEACON_VIEW_MoveEntryToPeer
 * address:  0x021F150C
 * packet:   pkt_ov032_021F150C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_MoveEntryToPeer 0x021F150C thumb
 *   BEACON_VIEW_SetEntryPosition 0x021F1218 thumb
 *   BEACON_VIEW_SetEntryVisible 0x021F0EA4 thumb
 *   BEACON_VIEW_StartEntrySlide 0x021F155C thumb
 *   BEACON_VIEW_MoveEntryToSlot 0x021F1484 thumb
 */

typedef unsigned char u8;

extern void BEACON_VIEW_SetEntryPosition(char *p, short x, short y);
extern void BEACON_VIEW_SetEntryVisible(char *p, unsigned a);
extern void BEACON_VIEW_StartEntrySlide(char *p, u8 *e, int mode, u8 delay, int *r);
extern void BEACON_VIEW_MoveEntryToSlot(char *this, int a, u8 *b, u8 *c, void *s);

void BEACON_VIEW_MoveEntryToPeer(u8 *this, u8 *p, void *s)
{
    int k;

    p[2] = 1;
    BEACON_VIEW_SetEntryPosition((char *)p, -208, 0);
    BEACON_VIEW_SetEntryVisible((char *)p, 1);
    k = 0;
    if (this[0x7b] != 0)
        k = 8;
    BEACON_VIEW_StartEntrySlide((char *)this, p, 2, (u8)k, s);
    BEACON_VIEW_MoveEntryToSlot((char *)this, 1, 0, p, s);
}
