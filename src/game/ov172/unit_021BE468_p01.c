/*
 * file:     unit_021BE468_p01.c
 * unit:     yes
 * function: func_021BEFB8, func_021BF0B0, func_021BF15C
 * address:  0x021BEFB8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BF690  0x021BF690  arm  ov172
 *   func_021BF610  0x021BF610  arm  ov172
 *   g_021C88F0     0x021C88F0  data
 *   func_021BF1E0  0x021BF1E0  arm  ov172
 *   g_021C8B1C     0x021C8B1C  data
 *   g_021C726C     0x021C726C  data
 *   g_021C8B9C     0x021C8B9C  data
 */
#include "../../matched/include/G_BCode2.h"

extern int func_021BF690(unsigned char *b, int *p, int n);
extern int func_021BF610(unsigned char *b, int *p);
extern void func_021BF1E0(short *s, short *d, int n);
void func_021BEFB8(unsigned char *g, short *d, int *p, int n);
int func_021BF0B0(unsigned char *s, int *p, int ax, int cx);
void func_021BF15C(short *d, short n);
extern struct BCode2 g_021C88F0;
extern short g_021C8B1C[5][64];
extern unsigned char g_021C726C[64];
extern short g_021C8B9C[64];


/*
 * sdk:      getmatrix (jpegdec.o)
 */
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


/*
 * sdk:      get_matrix_sub (libssp.TWL.HYB.a jpegdec.o)
 *
 * Reads the extra bits of a JPEG coefficient: a leading 0 bit means negative (subtract
 * 2^cx - 1), then cx - 1 more bits are shifted in, with a bounds check before each read.
 * g_021C88F0[2] is the jpegdec.o static SSPiInputDataSize (.bss +8 off the bcode2 anchor).
 * Earlier waves parked a cx<->i register 2-cycle (~230 spellings) as a front-end wall.
 * Closed 2026-10-01 (lane22): `cx--` written in each if/else arm (the image merges it after
 * the arms; a single cx-- after the if gives cx a fresh web and the low register), plus
 * `int i; int dx;` in the DWARF order (locals listed reverse: dx then i).
 */
int func_021BF0B0(unsigned char *s, int *p, int ax, int cx)
{
    int i;
    int dx;

    if (cx != 0) {
        dx = 0;
        if ((unsigned int)(*p + 1) >= ((unsigned int *)&g_021C88F0)[2])
            return dx;
        if (func_021BF610(s, p) == 0) {
            dx = (1 << cx) - 1;
            cx--;
        } else {
            ax = (ax << 1) | 1;
            cx--;
        }
        for (i = 0; i < cx; i++) {
            if ((unsigned int)(*p + 1) >= ((unsigned int *)&g_021C88F0)[2])
                return 0;
            ax = (ax << 1) | func_021BF610(s, p);
        }
        ax -= dx;
    }
    return ax;
}


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
