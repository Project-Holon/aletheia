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
 * lane 06 (2026-10-01): 739 -> 600 B, size 844 -> 828. DWARF has no a4, so a4 is a
 *   single-use local the optimiser forward-substituted, which means BOTH passes use a0..a7
 *   for the butterflies and c0..c7 for eight temporaries (P1=(a5+a6)*181, a1+a2, a0+a3,
 *   the even 181 product and the 98/237/139/334 products), computed before the stores:
 *   the image does every odd-part multiply before the first tmp store, and statement order
 *   is kept across stores. Flat tmp[64], qtable[loop*8+k] (image indexes it by loop<<5),
 *   pass-1 store order 0,32,16,48,8,40,24,56, and the 40/24 rows spelled (a7<<8) - P1 +-.
 *   Inert: which of T1/T3/D0/D1 are named, declaration order. Residue: frame 0x110 vs
 *   0x114 (image spills one more temp: P4 in pass 1, P1 in pass 2) and the scheduling of
 *   T3/T4/D0 in pass 2; loop var colours r8 vs ip.
 *
 * sdk:      Yos_JpegEncoderForwardDct (libssp.TWL.HYB.a jpegenc.o)
 */

static void Yos_JpegEncoderForwardDct(unsigned char *data, long *qtable, short *output)
{
    long tmp[64];
    long dst;
    long loop;
    long a0, a1, a2, a3, a4, a5, a6, a7;
    long c0, c1, c2, c3, c4, c5, c6, c7;

    for (loop = 0; loop < 8; loop++) {
        a0 = data[loop + 0] + data[loop + 56] - 256;
        a1 = data[loop + 8] + data[loop + 48] - 256;
        a2 = data[loop + 16] + data[loop + 40] - 256;
        a3 = data[loop + 24] + data[loop + 32] - 256;
        a4 = data[loop + 24] - data[loop + 32];
        a5 = data[loop + 16] - data[loop + 40];
        a6 = data[loop + 8] - data[loop + 48];
        a7 = data[loop + 0] - data[loop + 56];

        c0 = (a5 + a6) * 181;
        c1 = a1 + a2;
        c2 = a0 + a3;
        c3 = ((a0 + (a1 - a2)) - a3) * 181;
        c4 = ((a6 + a7) + (a4 + a5)) * 98;
        c5 = ((a6 + a7) + (a4 + a5)) * 237;
        c6 = (a6 + a7) * 139;
        c7 = (a6 + a7) * 334;

        tmp[loop + 0] = (c2 + c1) << 8;
        tmp[loop + 32] = (c2 - c1) << 8;
        tmp[loop + 16] = c3 + ((a0 - a3) << 8);
        tmp[loop + 48] = ((a0 - a3) << 8) - c3;
        tmp[loop + 8] = c0 + (a7 << 8) + c4 + c6;
        tmp[loop + 40] = (a7 << 8) - c0 + c5 - c7;
        tmp[loop + 24] = (a7 << 8) - c0 - c5 + c7;
        tmp[loop + 56] = c0 + (a7 << 8) - c4 - c6;
    }

    for (loop = 0, dst = 0; loop < 8; loop++, dst += 8) {
        a0 = tmp[dst + 0] + tmp[dst + 7];
        a1 = tmp[dst + 1] + tmp[dst + 6];
        a2 = tmp[dst + 2] + tmp[dst + 5];
        a3 = tmp[dst + 3] + tmp[dst + 4];
        a4 = tmp[dst + 3] - tmp[dst + 4];
        a5 = tmp[dst + 2] - tmp[dst + 5];
        a6 = tmp[dst + 1] - tmp[dst + 6];
        a7 = tmp[dst + 0] - tmp[dst + 7];

        c0 = (a5 + a6) * 181;
        c1 = a1 + a2;
        c2 = a0 + a3;
        c3 = ((a0 + (a1 - a2)) - a3) * 181;
        c4 = ((a6 + a7) + (a4 + a5)) * 98;
        c5 = ((a6 + a7) + (a4 + a5)) * 237;
        c6 = (a6 + a7) * 139;
        c7 = (a6 + a7) * 334;

        output[dst + 0] = ((((c2 + c1) + 128) >> 8) * qtable[loop * 8 + 0] + 0x800) >> 12;
        output[dst + 1] = (((c0 + (a7 << 8) + c4 + c6 + 0x8000) >> 16) * qtable[loop * 8 + 1] + 0x800) >> 12;
        output[dst + 2] = (((c3 + ((a0 - a3) << 8) + 0x8000) >> 16) * qtable[loop * 8 + 2] + 0x800) >> 12;
        output[dst + 3] = ((((a7 << 8) - c0 - c5 + c7 + 0x8000) >> 16) * qtable[loop * 8 + 3] + 0x800) >> 12;
        output[dst + 4] = ((((c2 - c1) + 128) >> 8) * qtable[loop * 8 + 4] + 0x800) >> 12;
        output[dst + 5] = ((((a7 << 8) - c0 + c5 - c7 + 0x8000) >> 16) * qtable[loop * 8 + 5] + 0x800) >> 12;
        output[dst + 6] = (((((a0 - a3) << 8) - c3 + 0x8000) >> 16) * qtable[loop * 8 + 6] + 0x800) >> 12;
        output[dst + 7] = (((c0 + (a7 << 8) - c4 - c6 + 0x8000) >> 16) * qtable[loop * 8 + 7] + 0x800) >> 12;
    }
}
