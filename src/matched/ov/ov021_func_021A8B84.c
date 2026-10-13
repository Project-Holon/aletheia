/*
 * function: FIELD_MENU_CountLayoutButtons
 * address:  0x021A8B84
 * packet:   pkt_ov021_021A8B84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFieldMenuLayouts  0x021D8D24  data  a4
 */

extern const int gFieldMenuLayouts[][7];
int FIELD_MENU_CountLayoutButtons(int idx)
{
    int i;
    int n;
    i = 0;
    n = 0;
    for (; gFieldMenuLayouts[idx][i] != 0; i++) {
        if (gFieldMenuLayouts[idx][i] != 7) {
            n++;
        }
    }
    return n;
}
