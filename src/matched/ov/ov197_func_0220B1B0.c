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
 *   func_0220B774 0x0220B774 thumb
 *   func_0220B880 0x0220B880 thumb
 */

extern void B_BAG_MAIN_DrawLabels(char *);
extern void func_0220B774(char *);
extern void func_0220B880(char *);

void B_BAG_MAIN_DrawPage(char *a, int which)
{
    switch (which)
    {
    case 0:
        B_BAG_MAIN_DrawLabels(a);
        break;
    case 1:
        func_0220B774(a);
        break;
    case 2:
        func_0220B880(a);
        break;
    }
}
