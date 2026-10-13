/*
 * function: SHORTCUT_MENU_ClampListWindow
 * address:  0x021C5880
 * packet:   pkt_ov021_021C5880
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;
typedef unsigned int u32;

void SHORTCUT_MENU_ClampListWindow(u16 *a, u16 *b, u16 c)
{
    int s = *a + *b;

    if (c <= 5) {
        *b = s;
        *a = 0;
        return;
    }
    if (s <= 3) {
        *b = s;
        *a = 0;
        return;
    }
    if (s <= (int)c - 2 && s > 3) {
        *a = s - 3;
        *b = 3;
        return;
    }
    if (s == (int)c - 1) {
        *a = s - 4;
        *b = 4;
    }
}
