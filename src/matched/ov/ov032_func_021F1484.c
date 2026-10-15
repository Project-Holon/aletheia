/*
 * function: BEACON_VIEW_MoveEntryToSlot
 * address:  0x021F1484
 * packet:   pkt_ov032_021F1484
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_MoveEntryToSlot 0x021F1484 thumb
 *   BEACON_VIEW_SetEntryPosition 0x021F1218 thumb
 *   BEACON_VIEW_SetEntryVisible 0x021F0EA4 thumb
 *   BEACON_VIEW_StartEntrySlide 0x021F155C thumb
 */

typedef unsigned char u8;

extern void BEACON_VIEW_SetEntryPosition(char *p, short x, short y);
extern void BEACON_VIEW_SetEntryVisible(char *p, unsigned a);
extern void BEACON_VIEW_StartEntrySlide(char *p, u8 *e, int mode, u8 delay, int *r);

void BEACON_VIEW_MoveEntryToSlot(char *this, int a, u8 *b, u8 *c, void *s)
{
    int i;
    u8 *e;

    if (b != 0) {
        if (a == 0)
            b[2] = 5;
        else
            b[2] = 0;
        BEACON_VIEW_SetEntryPosition((char *)b, -13 * (1 - b[2]), -40 * (1 - b[2]));
        BEACON_VIEW_SetEntryVisible((char *)b, 1);
    }
    for (i = 0; i < 5; i++) {
        e = (u8 *)(this + 0x1b8) + i * 0x34;
        if (e[1] != 0xff) {
            if (c == 0 || e[0] != c[0])
                BEACON_VIEW_StartEntrySlide(this, e, a, 0, s);
        }
    }
}
