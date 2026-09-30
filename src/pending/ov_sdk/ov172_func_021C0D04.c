/*
 * function: Yos_JpegEncoderForwardDct
 * address:  0x021C0D04
 * packet:   pkt_ov172_021C0D04
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: codegen. Algorithm is exact (both 1-D passes, the
 *   181/98/237/139/334 constants, the <<8/>>8/>>16 fixed-point scaling and
 *   the quantization `(c*q + 0x800) >> 12`), but the compiled register
 *   allocation cascades early. Compiled 844 vs original 840 after matching
 *   pass-1's term order; the pass-1 loop body itself is the same length as
 *   the original (292 bytes), so the only extra word is the LICM hoist
 *   `add lr, sp, #0x14` the original instead rematerialises per iteration
 *   (`add r7, sp, #0x14`). From there the induction variable colours r5
 *   instead of ip and nearly every instruction's register differs, so the
 *   byte diff stays large. Tried (each measured): pass-1 named a0..a7
 *   (DWARF names a0..a7/c0..c7/loop/dst/tmp), reordering tmp[8] to the
 *   listing's `(a5+a6)*181 + (a7<<8) + 98-term + 139-term` (844, from 848),
 *   a named `long *tp = tmp + loop` store block (worse, 856), inline store
 *   expressions, named o0..o7, t0..t3/d0..d3 temporaries, explicit even
 *   partials, and the natural transpose spelling `long tmp[8][8]` with
 *   `tmp[k][loop]` / `tmp[loop][j]` (identical to the flat form, no change).
 *   No relocations, so this cannot cap at MATCH; pure codegen near miss.
 *   See docs/idioms/indexed-form-keeps-the-table-base-recomputed.md
 *   (subscript already used).
 *
 * sdk:      Yos_JpegEncoderForwardDct (libssp.TWL.HYB.a jpegenc.o)
 */

static void Yos_JpegEncoderForwardDct(unsigned char *data, long *qtable, short *output)
{
    long a0, a1, a2, a3, a4, a5, a6, a7;
    long c0, c1, c2, c3, c4, c5, c6, c7;
    long loop, dst;
    long tmp[8][8];

    for (loop = 0; loop < 8; loop++) {
        a0 = data[loop + 0] + data[loop + 56] - 256;
        a7 = data[loop + 0] - data[loop + 56];
        a1 = data[loop + 8] + data[loop + 48] - 256;
        a6 = data[loop + 8] - data[loop + 48];
        a2 = data[loop + 16] + data[loop + 40] - 256;
        a5 = data[loop + 16] - data[loop + 40];
        a3 = data[loop + 24] + data[loop + 32] - 256;
        a4 = data[loop + 24] - data[loop + 32];

        tmp[0][loop] = ((a0 + a3) + (a1 + a2)) << 8;
        tmp[4][loop] = ((a0 + a3) - (a1 + a2)) << 8;
        tmp[2][loop] = ((a0 + (a1 - a2)) - a3) * 181 + ((a0 - a3) << 8);
        tmp[6][loop] = ((a0 - a3) << 8) - ((a0 + (a1 - a2)) - a3) * 181;
        tmp[1][loop] = (a5 + a6) * 181 + (a7 << 8) + ((a6 + a7) + (a4 + a5)) * 98
                     + (a6 + a7) * 139;
        tmp[5][loop] = ((a6 + a7) + (a4 + a5)) * 237 + (a7 << 8)
                     - (a5 + a6) * 181 - (a6 + a7) * 334;
        tmp[3][loop] = (a6 + a7) * 334 + (a7 << 8)
                     - (a5 + a6) * 181 - ((a6 + a7) + (a4 + a5)) * 237;
        tmp[7][loop] = (a5 + a6) * 181 + (a7 << 8)
                     - ((a6 + a7) + (a4 + a5)) * 98 - (a6 + a7) * 139;
    }

    for (loop = 0, dst = 0; loop < 8; loop++, dst += 8) {
        c0 = tmp[loop][0] + tmp[loop][7];
        c1 = tmp[loop][1] + tmp[loop][6];
        c2 = tmp[loop][2] + tmp[loop][5];
        c3 = tmp[loop][3] + tmp[loop][4];
        c4 = tmp[loop][3] - tmp[loop][4];
        c5 = tmp[loop][2] - tmp[loop][5];
        c6 = tmp[loop][1] - tmp[loop][6];
        c7 = tmp[loop][0] - tmp[loop][7];

        output[dst + 0] = ((((c0 + c3) + (c1 + c2) + 128) >> 8) * qtable[dst + 0] + 0x800) >> 12;
        output[dst + 1] = ((((c7 + c6) * 139 + ((c7 + c6) + (c4 + c5)) * 98 + (c6 + c5) * 181
                          + (c7 << 8) + 0x8000) >> 16) * qtable[dst + 1] + 0x800) >> 12;
        output[dst + 2] = (((((c0 + (c1 - c2)) - c3) * 181 + ((c0 - c3) << 8) + 0x8000) >> 16)
                          * qtable[dst + 2] + 0x800) >> 12;
        output[dst + 3] = ((((c7 + c6) * 334 + (c7 << 8) - (c6 + c5) * 181
                          - ((c7 + c6) + (c4 + c5)) * 237 + 0x8000) >> 16) * qtable[dst + 3] + 0x800) >> 12;
        output[dst + 4] = ((((c0 + c3) - (c1 + c2) + 128) >> 8) * qtable[dst + 4] + 0x800) >> 12;
        output[dst + 5] = (((((c7 + c6) + (c4 + c5)) * 237 + (c7 << 8) - (c6 + c5) * 181
                          - (c7 + c6) * 334 + 0x8000) >> 16) * qtable[dst + 5] + 0x800) >> 12;
        output[dst + 6] = ((((c0 - c3) << 8) - ((c0 + (c1 - c2)) - c3) * 181 + 0x8000) >> 16)
                          * qtable[dst + 6] + 0x800 >> 12;
        output[dst + 7] = ((((c6 + c5) * 181 + (c7 << 8) - ((c7 + c6) + (c4 + c5)) * 98
                          - (c7 + c6) * 139 + 0x8000) >> 16) * qtable[dst + 7] + 0x800) >> 12;
    }
}
