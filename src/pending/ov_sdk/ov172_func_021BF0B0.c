/*
 * function: func_021BF0B0
 * address:  0x021BF0B0
 * packet:   pkt_ov172_021BF0B0
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      get_matrix_sub (jpegdec.o)
 *
 * symbols:
 *   func_021BF610  0x021BF610  arm  ov172
 *   g_021C88F0     0x021C88F0  data
 */

extern unsigned int g_021C88F0[];
extern int func_021BF610(unsigned char *b, int *p);

int func_021BF0B0(unsigned char *s, int *p, int ax, int cx)
{
    int i;
    int dx;

    if (cx != 0) {
        dx = 0;
        if ((unsigned int)(*p + 1) >= g_021C88F0[2])
            return dx;
        if (func_021BF610(s, p) == 0) {
            dx = (1 << cx) - 1;
        } else {
            ax = (ax << 1) | 1;
        }
        cx--;
        for (i = 0; i < cx; i++) {
            if ((unsigned int)(*p + 1) >= g_021C88F0[2])
                return 0;
            ax = (ax << 1) | func_021BF610(s, p);
        }
        ax -= dx;
    }
    return ax;
}
