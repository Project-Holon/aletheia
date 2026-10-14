/*
 * function: RESEARCH_COMMON_InitTouchRects
 * address:  0x021C0D88
 * packet:   pkt_ov217_021C0D88
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C3F48  0x021C3F48  data  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern const u8 d_021C3F48[];

void RESEARCH_COMMON_InitTouchRects(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        p[i * 4 + 0xE] = d_021C3F48[i * 4];
        p[i * 4 + 0xF] = d_021C3F48[i * 4 + 1];
        p[i * 4 + 0xC] = d_021C3F48[i * 4 + 2];
        p[i * 4 + 0xD] = d_021C3F48[i * 4 + 3];
    }
}
