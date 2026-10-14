/*
 * function: GSYNC_MENU_AddPaletteEntries
 * address: 0x021D43B8
 * packet: pkt_ov123_021D43B8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: zero padding at 0x021D443E; next function at 0x021D4440.
 */
typedef unsigned short u16;
void GSYNC_MENU_AddPaletteEntries(u16 *p, const u16 *add, int n)
{
    int i, j;
    u16 *row;
    u16 r, g, b;
    for (i = 0; i < n; i++) {
        row = p + i * 16;
        for (j = 0; j < 16; j++) {
            r = row[j] & 31;
            g = (row[j] & 0x3e0) >> 5;
            b = (row[j] & 0x7c00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) r = 31;
            if (g > 31) g = 31;
            if (b > 31) b = 31;
            row[j] = r + (g << 5) + (b << 10);
        }
    }
}
