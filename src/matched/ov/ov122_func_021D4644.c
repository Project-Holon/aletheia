/*
 * function: INTRUDE_COMM_VIEW_BrightenPalette
 * address: 0x021D4644
 * packet: pkt_ov122_021D4644
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero padding bytes at 021D46CA, next function 021D46CC.
 */
typedef unsigned short u16;
void INTRUDE_COMM_VIEW_BrightenPalette(u16 *p, const u16 *add, int count)
{
    int i, j;
    for (i = 0; i < count; i++) {
        u16 *q = p + i * 16;
        for (j = 0; j < 16; j++) {
            u16 color = q[j];
            u16 r = color & 31;
            u16 g = (color & 0x3e0) >> 5;
            u16 b = (color & 0x7c00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) r = 31;
            if (g > 31) g = 31;
            if (b > 31) b = 31;
            q[j] = r + (g << 5) + (b << 10);
        }
    }
}
