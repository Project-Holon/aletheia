/*
 * function: Yos_JpegEncoderForwardDct
 * address:  0x021C0D04
 * packet:   pkt_ov172_021C0D04
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * lane 06 (2026-10-01, wave 3): closed from the vendor .debug_line table of
 *   jpegenc.o, which maps every instruction to its source line. It gives the
 *   statement order (even sums, the 181 sum, tmp13, the odd sums, then all six
 *   products on their own lines) and shows the butterfly temporaries are
 *   in-place reassignments of a0..a6 (eight c locals for the two sums and six
 *   products). The in-place writes are what fix 1.1p1's schedule; a4 stays a
 *   single-use local (absent from DWARF). `loop = dst = 0` gives the image's
 *   literal-into-dst, copy-into-loop init. Which dead a-local holds each
 *   temporary is not observable (all eight choices are EXACT).
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

        c0 = a0 + a3;
        c1 = a1 + a2;
        a1 = a1 - a2 + a0 - a3;
        a0 = a0 - a3;
        a2 = a5 + a6;
        a6 = a6 + a7;

        a5 = a4 + a5 + a6;

        c2 = a1 * 181;
        c3 = a2 * 181;
        c4 = a5 * 98;
        c5 = a5 * 237;
        c6 = a6 * 139;
        c7 = a6 * 334;

        tmp[loop + 0] = (c0 + c1) << 8;
        tmp[loop + 32] = (c0 - c1) << 8;
        tmp[loop + 16] = c2 + (a0 << 8);
        tmp[loop + 48] = (a0 << 8) - c2;
        tmp[loop + 8] = c3 + (a7 << 8) + c4 + c6;
        tmp[loop + 40] = (a7 << 8) - c3 + c5 - c7;
        tmp[loop + 24] = (a7 << 8) - c3 - c5 + c7;
        tmp[loop + 56] = c3 + (a7 << 8) - c4 - c6;
    }

    for (loop = dst = 0; loop < 8; loop++, dst += 8) {
        a0 = tmp[dst + 0] + tmp[dst + 7];
        a1 = tmp[dst + 1] + tmp[dst + 6];
        a2 = tmp[dst + 2] + tmp[dst + 5];
        a3 = tmp[dst + 3] + tmp[dst + 4];
        a4 = tmp[dst + 3] - tmp[dst + 4];
        a5 = tmp[dst + 2] - tmp[dst + 5];
        a6 = tmp[dst + 1] - tmp[dst + 6];
        a7 = tmp[dst + 0] - tmp[dst + 7];

        c0 = a0 + a3;
        c1 = a1 + a2;
        a1 = a1 - a2 + a0 - a3;
        a0 = a0 - a3;
        a2 = a5 + a6;
        a6 = a6 + a7;

        a5 = a4 + a5 + a6;

        c2 = a1 * 181;
        c3 = a2 * 181;
        c4 = a5 * 98;
        c5 = a5 * 237;
        c6 = a6 * 139;
        c7 = a6 * 334;

        output[dst + 0] = ((((c0 + c1) + 128) >> 8) * qtable[loop * 8 + 0] + 0x800) >> 12;
        output[dst + 1] = (((c3 + (a7 << 8) + c4 + c6 + 0x8000) >> 16) * qtable[loop * 8 + 1] + 0x800) >> 12;
        output[dst + 2] = (((c2 + (a0 << 8) + 0x8000) >> 16) * qtable[loop * 8 + 2] + 0x800) >> 12;
        output[dst + 3] = ((((a7 << 8) - c3 - c5 + c7 + 0x8000) >> 16) * qtable[loop * 8 + 3] + 0x800) >> 12;
        output[dst + 4] = ((((c0 - c1) + 128) >> 8) * qtable[loop * 8 + 4] + 0x800) >> 12;
        output[dst + 5] = ((((a7 << 8) - c3 + c5 - c7 + 0x8000) >> 16) * qtable[loop * 8 + 5] + 0x800) >> 12;
        output[dst + 6] = ((((a0 << 8) - c2 + 0x8000) >> 16) * qtable[loop * 8 + 6] + 0x800) >> 12;
        output[dst + 7] = (((c3 + (a7 << 8) - c4 - c6 + 0x8000) >> 16) * qtable[loop * 8 + 7] + 0x800) >> 12;
    }
}
