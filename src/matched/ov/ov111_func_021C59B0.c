/*
 * function: VIEWER_MAIN_CopyBg6
 * address:  0x021C59B0
 * packet:   pkt_ov111_021C59B0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

void VIEWER_MAIN_CopyBg6(const u8 *src, u8 *dst)
{
    int i, j;
    int v;

    for (i = 0; i < 0x600; i++) {
        v = 0;
        for (j = 0; j < 8; j++) {
            v |= (src[i * 8 + j] & 1) << j;
        }
        dst[i] = v;
    }
}
