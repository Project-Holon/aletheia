/*
 * function: B_BAG_MAIN_DrawItemsPage
 * address:  0x0220B774
 * packet:   pkt_0220B774
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   B_BAG_MAIN_DrawPocket 0x0220B520 thumb
 *   B_BAG_MAIN_DrawInfoBox 0x0220B6C4 thumb
 *   B_BAG_MAIN_DrawHeader 0x0220B584 thumb
 */

extern void B_BAG_MAIN_DrawPocket(char *p);
extern void B_BAG_MAIN_DrawInfoBox(char *p);
extern void B_BAG_MAIN_DrawHeader(char *p);

void B_BAG_MAIN_DrawItemsPage(char *a)
{
    B_BAG_MAIN_DrawPocket(a);
    B_BAG_MAIN_DrawInfoBox(a);
    B_BAG_MAIN_DrawHeader(a);
}