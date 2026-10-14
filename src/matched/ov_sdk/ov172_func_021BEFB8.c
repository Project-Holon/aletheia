/*
 * function: getmatrix
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
 *   hloadbit  0x021BF690  arm  ov172
 *   get_matrix_sub  0x021BF0B0  arm  ov172
 */

extern int hloadbit(unsigned char *b, int *p, int n);
extern int get_matrix_sub(unsigned char *s, int *p, int ax, int cx);

void getmatrix(unsigned char *g, short *d, int *p, int n)
{
    int ax;
    int cx;
    int i;
    int j;
    int m;
    int k;

    d[0] += get_matrix_sub(g, p, 0, hloadbit(g, p, n));
    for (i = 63, j = 1; i > 0; i--) {
        cx = hloadbit(g, p, n + 1);
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
        d[j++] = get_matrix_sub(g, p, 0, cx & 0xf);
    }
}
