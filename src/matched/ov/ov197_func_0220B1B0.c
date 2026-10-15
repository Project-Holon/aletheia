/*
 * function: B_BAG_MAIN_DrawPage
 * address:  0x0220B1B0
 * packet:   pkt_0220B1B0
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   B_BAG_MAIN_DrawLabels 0x0220B248 thumb
 *   B_BAG_MAIN_DrawItemsPage 0x0220B774 thumb
 *   B_BAG_MAIN_DrawOtherPage 0x0220B880 thumb
 */

extern void B_BAG_MAIN_DrawLabels(char *);
extern void B_BAG_MAIN_DrawItemsPage(char *);
extern void B_BAG_MAIN_DrawOtherPage(char *);

void B_BAG_MAIN_DrawPage(char *a, int which)
{
    switch (which)
    {
    case 0:
        B_BAG_MAIN_DrawLabels(a);
        break;
    case 1:
        B_BAG_MAIN_DrawItemsPage(a);
        break;
    case 2:
        B_BAG_MAIN_DrawOtherPage(a);
        break;
    }
}
