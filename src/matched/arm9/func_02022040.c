/*
 * function: func_02022040
 * address:  0x02022040
 * packet:   pkt_02022040
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;

void func_02022040(u16 *pal, int n, const u8 *table)
{
    int i;
    int r, g, b;
    u8 v;

    for (i = 0; i < n; i++) {
        r = *pal & 0x1f;
        g = (*pal >> 5) & 0x1f;
        b = (*pal >> 10) & 0x1f;
        v = table[(r * 76 + g * 151 + b * 29) >> 8];
        *pal = (v << 10) | (v << 5) | v;
        pal++;
    }
}
