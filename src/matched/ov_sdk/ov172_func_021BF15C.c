/*
 * function: func_021BF15C
 * address:  0x021BF15C
 * packet:   pkt_ov172_021BF15C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      decode_block (jpegdec.o)
 *
 * symbols:
 *   func_021BF1E0  0x021BF1E0  arm  ov172
 *   g_021C8B1C     0x021C8B1C  data
 *   g_021C726C     0x021C726C  data
 *   g_021C8B9C     0x021C8B9C  data
 */

extern short g_021C8B1C[5][64];
extern unsigned char g_021C726C[64];
extern short g_021C8B9C[64];
extern void func_021BF1E0(short *s, short *d, int n);

void func_021BF15C(short *d, short n)
{
    int i;
    int p;
    int q;

    for (q = 0, p = 0, i = 0; i < 64; i++, p++, q++) {
        g_021C8B1C[1][g_021C726C[q]] = g_021C8B1C[n][p];
    }
    if (n == 0) {
        func_021BF1E0(g_021C8B9C, d, 0);
    } else {
        func_021BF1E0(g_021C8B9C, d, 64);
    }
}
