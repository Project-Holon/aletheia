/*
 * function: func_021BF0B0
 * address:  0x021BF0B0
 * packet:   pkt_ov172_021BF0B0
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      get_matrix_sub (libssp.TWL.HYB.a jpegdec.o)
 *
 * symbols:
 *   func_021BF610  0x021BF610  arm  ov172
 *   g_021C88F0     0x021C88F0  data
 *
 * Reads the extra bits of a JPEG coefficient: a leading 0 bit means negative (subtract
 * 2^cx - 1), then cx - 1 more bits are shifted in, with a bounds check before each read.
 * g_021C88F0[2] is the jpegdec.o static SSPiInputDataSize (.bss +8 off the bcode2 anchor).
 * Earlier waves parked a cx<->i register 2-cycle (~230 spellings) as a front-end wall.
 * Closed 2026-10-01 (lane22): `cx--` written in each if/else arm (the image merges it after
 * the arms; a single cx-- after the if gives cx a fresh web and the low register), plus
 * `int i; int dx;` in the DWARF order (locals listed reverse: dx then i).
 */

#include "../include/G_BCode2.h"

extern struct BCode2 g_021C88F0;
extern int func_021BF610(unsigned char *b, int *p);

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
