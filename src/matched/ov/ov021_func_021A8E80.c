/*
 * function: FIELD_MENU_MoveCursor
 * address:  0x021A8E80
 * packet:   pkt_ov021_021A8E80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FIELD_MENU_GetSlotIndex  0x021A8E78  thumb  ov021
 *   FIELD_MENU_CountLayoutButtons  0x021A8B84  thumb  ov021
 *   gFieldMenuCursorMoves     0x021D8C4C  data  ov021  a1
 *   gFieldMenuSlotCol     0x021D8B26  data  ov021  a1
 *   gFieldMenuSlotRow     0x021D8B27  data  ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct W {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20;
    u8 f21;
};

extern u8 gFieldMenuCursorMoves[][8][4];
extern u8 gFieldMenuSlotCol[];
extern u8 gFieldMenuSlotRow[];

extern int FIELD_MENU_GetSlotIndex(u32 a, u32 b);
extern int FIELD_MENU_CountLayoutButtons(int idx);

u32 FIELD_MENU_MoveCursor(struct W *w, u32 dir)
{
    u32 idx = FIELD_MENU_GetSlotIndex(w->f1E, w->f1F);
    u32 r = gFieldMenuCursorMoves[FIELD_MENU_CountLayoutButtons(w->f21) - 4][idx][dir];

    if (idx != r) {
        if (r == 0xFF) {
            w->f1F = 2;
            return 1;
        }
        if (r == 0xFE) {
            w->f1F = 1;
            return 1;
        }
        if (r != 6) {
            w->f1E = gFieldMenuSlotCol[r * 2];
        }
        w->f1F = gFieldMenuSlotRow[r * 2];
        return 1;
    }
    return 0;
}
