/*
 * function: func_021BEFB8
 * address:  0x021BEFB8
 * packet:   pkt_ov172_021BEFB8
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      getmatrix (jpegdec.o)
 *
 * symbols:
 *   func_021BF690  0x021BF690  arm  ov172
 *   func_021BF0B0  0x021BF0B0  arm  ov172
 */

extern int func_021BF690(unsigned char *b, int *p, int n);
extern int func_021BF0B0(unsigned char *s, int *p, int ax, int cx);

void func_021BEFB8(unsigned char *g, short *d, int *p, int n)
{
    int ax;
    int cx;
    int i;
    int j;
    int m;
    int k;

    d[0] += func_021BF0B0(g, p, 0, func_021BF690(g, p, n));
    for (i = 63, j = 1; i > 0; i--) {
        cx = func_021BF690(g, p, n + 1);
        if (cx == 0) {
            for (; j < 64; j++)
                d[j] = 0;
            return;
        }
        m = cx >> 4;
        i -= m;
        if (j + m > 63)
            return;
        for (k = 0; k < m; k++)
            d[j++] = 0;
        d[j++] = func_021BF0B0(g, p, 0, cx & 0xf);
    }
}
