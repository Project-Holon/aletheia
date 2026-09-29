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
 * blocker: codegen. Body hand-reconstructed from the disassembly and the
 *   algorithm is exact (both 1-D passes, the 181/98/237/139/334 AAN-style
 *   constants, the <<8/>>8/>>16 fixed-point scaling and the quantization
 *   `(c*q + 0x800) >> 12` are all reproduced), so compiled size is 848 vs
 *   the original 840. The two-word residue is register pressure in pass 2:
 *   the original keeps only one value live across the odd/even outputs and
 *   spills just `out4` to [sp,#8], while every source shape tried so far
 *   makes mwcc spill a second value. Tried: inline store expressions,
 *   named o0..o7, reusing c0..c7 as the pass-2 sums (DWARF only names
 *   a0..a7/c0..c7/loop/dst/tmp), t0..t3/d0..d3 temporaries, explicit even
 *   partials s=t0+t3/u=t1+t2, and pass-1 load/associations matched to the
 *   listing's `ldrb x4 / add / sub / sub` pair grouping. No relocations, so
 *   this cannot cap at MATCH; it is a pure codegen near miss.
 *
 * sdk:      Yos_JpegEncoderForwardDct (libssp.TWL.HYB.a jpegenc.o)
 */

static void Yos_JpegEncoderForwardDct(unsigned char *data, long *qtable, short *output)
{
    long a0, a1, a2, a3, a4, a5, a6, a7;
    long c0, c1, c2, c3, c4, c5, c6, c7;
    long loop, dst;
    long tmp[64];

    for (loop = 0; loop < 8; loop++) {
        c0 = data[loop + 0] + data[loop + 56] - 256;
        c7 = data[loop + 0] - data[loop + 56];
        c1 = data[loop + 8] + data[loop + 48] - 256;
        c6 = data[loop + 8] - data[loop + 48];
        c2 = data[loop + 16] + data[loop + 40] - 256;
        c5 = data[loop + 16] - data[loop + 40];
        c3 = data[loop + 24] + data[loop + 32] - 256;
        c4 = data[loop + 24] - data[loop + 32];

        tmp[loop + 0]  = ((c0 + c3) + (c1 + c2)) << 8;
        tmp[loop + 32] = ((c0 + c3) - (c1 + c2)) << 8;
        tmp[loop + 16] = ((c0 + (c1 - c2)) - c3) * 181 + ((c0 - c3) << 8);
        tmp[loop + 48] = ((c0 - c3) << 8) - ((c0 + (c1 - c2)) - c3) * 181;
        tmp[loop + 8]  = (c7 + c6) * 139 + ((c7 + c6) + (c4 + c5)) * 98
                       + (c6 + c5) * 181 + (c7 << 8);
        tmp[loop + 40] = ((c7 + c6) + (c4 + c5)) * 237 + (c7 << 8)
                       - (c6 + c5) * 181 - (c7 + c6) * 334;
        tmp[loop + 24] = (c7 + c6) * 334 + (c7 << 8)
                       - (c6 + c5) * 181 - ((c7 + c6) + (c4 + c5)) * 237;
        tmp[loop + 56] = (c6 + c5) * 181 + (c7 << 8)
                       - ((c7 + c6) + (c4 + c5)) * 98 - (c7 + c6) * 139;
    }

    for (loop = 0, dst = 0; loop < 8; loop++, dst += 8) {
        c0 = tmp[dst + 0] + tmp[dst + 7];
        c1 = tmp[dst + 1] + tmp[dst + 6];
        c2 = tmp[dst + 2] + tmp[dst + 5];
        c3 = tmp[dst + 3] + tmp[dst + 4];
        c4 = tmp[dst + 3] - tmp[dst + 4];
        c5 = tmp[dst + 2] - tmp[dst + 5];
        c6 = tmp[dst + 1] - tmp[dst + 6];
        c7 = tmp[dst + 0] - tmp[dst + 7];

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
