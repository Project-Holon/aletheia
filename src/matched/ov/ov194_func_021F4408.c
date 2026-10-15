/*
 * function: NAMEIN_GRAPHIC_GetIconMode
 * address:  0x021F4408
 * packet:   pkt_021F4408
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

int NAMEIN_GRAPHIC_GetIconMode(int x, int y)
{
    switch (x) {
    case 0:
    case 5:
    case 6:
    case 7:
        return 0;
    case 1: return 3;
    case 2: return 4;
    case 3: return 1;
    case 4: return y == 0xffff ? 5 : 2;
    default: return 0;
    }
}
