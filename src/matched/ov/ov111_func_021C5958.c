/*
 * function: VIEWER_MAIN_CopyBg3
 * address:  0x021C5958
 * packet:   pkt_ov111_021C5958
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

void VIEWER_MAIN_CopyBg3(const u8 *src, u8 *dst)
{
    int i;

    for (i = 0; i < 0x3000; i++) {
        if ((src[i / 64 * 8 + (u8)(i / 8 % 8)] >> (u8)(i % 8)) & 1) {
            dst[i] = 7;
        }
    }
}
