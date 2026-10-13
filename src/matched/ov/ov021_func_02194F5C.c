/*
 * function: TALKMSGWIN_GetTailBaseX
 * address:  0x02194F5C
 * packet:   pkt_ov021_02194F5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (no lr save), sole caller TALKMSGWIN_CalcTail.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void TALKMSGWIN_GetTailBaseX(int x, int w, int side, u16 *a, u16 *b)
{
    if (side == 0) {
        *a = x + 0x40;
        *b = *a + 0x10;
    } else {
        *b = x + w - 0x40;
        *a = *b - 0x10;
    }
}
