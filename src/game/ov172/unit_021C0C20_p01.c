/*
 * file:     unit_021C0C20_p01.c
 * unit:     yes
 * function: func_021C0D04, func_021C104C
 * address:  0x021C0D04
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
 *   MIi_CpuClearFast                0x02082AC0  arm
 *   MIi_CpuCopyFast                 0x02082B0C  arm
 *   MI_CpuCopy                      0x02082EA4  arm
 *   dc0_tbl                         0x021C8500  data  ov172
 *   dc1_tbl                         0x021C8520  data  ov172
 *   ac0_tbl                         0x021C86C0  data  ov172
 *   ac1_tbl                         0x021C8600  data  ov172
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct huffman_structure {
    u32 mFrequencies[257];
    u8  mHuffBits[32];
    u8  mHuffValues[256];
    u16 mEhufco[258];
    u8  mEhufsi[260];
} huffman_structure;

typedef struct Yos_JpegEncoderHuffmanEncoderBuildTableWork {
    u32 mHuffSize[256];
    u32 mHuffCode[256];
} Yos_JpegEncoderHuffmanEncoderBuildTableWork;

extern void MIi_CpuClearFast(u32 data, void *destp, u32 size);
extern void MIi_CpuCopyFast(void *srcp, void *destp, u32 size);
extern void MI_CpuCopy(void *srcp, void *destp, u32 size);

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

extern u8 dc0_tbl[28] __attribute__((aligned(32)));

extern u8 dc1_tbl[28] __attribute__((aligned(32)));

extern u8 ac0_tbl[178] __attribute__((aligned(32)));

extern u8 ac1_tbl[178] __attribute__((aligned(32)));


static void Yos_JpegEncoderHuffmanEncoderBuildTable(Yos_JpegEncoderHuffmanEncoderBuildTableWork *pWork,
                          huffman_structure *hf, u32 idx)
{
    u32 ii;
    u32 jj;
    u32 kk;
    u32 si;
    u16 code = 0;


    MIi_CpuClearFast(0, &hf->mHuffBits[0], 0x428);

    switch (idx) {
    case 0: MIi_CpuCopyFast(dc0_tbl, &hf->mHuffBits[0], 0x10); break;
    case 1: MIi_CpuCopyFast(dc1_tbl, &hf->mHuffBits[0], 0x10); break;
    case 2: MIi_CpuCopyFast(ac0_tbl, &hf->mHuffBits[0], 0x10); break;
    case 3: MIi_CpuCopyFast(ac1_tbl, &hf->mHuffBits[0], 0x10); break;
    }

    switch (idx) {
    case 0: MIi_CpuCopyFast(dc0_tbl + 0x10, &hf->mHuffValues[0], 0xc); break;
    case 1: MIi_CpuCopyFast(dc1_tbl + 0x10, &hf->mHuffValues[0], 0xc); break;
    case 2: MI_CpuCopy(ac0_tbl + 0x10, &hf->mHuffValues[0], 0xa2); break;
    case 3: MI_CpuCopy(ac1_tbl + 0x10, &hf->mHuffValues[0], 0xa2); break;
    }

    MIi_CpuClearFast(0, pWork, 0x400);
    ii = 0;
    kk = 0;
    while (ii < 0x10) {
        for (jj = 0; jj < hf->mHuffBits[ii]; jj++)
            pWork->mHuffSize[kk++] = ii + 1;
        pWork->mHuffSize[kk] = 0;
        ii++;
    }

    MIi_CpuClearFast(0, pWork->mHuffCode, 0x400);
    kk = 0;
    si = pWork->mHuffSize[0];
    while (pWork->mHuffSize[kk] != 0) {
        while (pWork->mHuffSize[kk] == si) {
            pWork->mHuffCode[kk++] = code++;
        }
        si++;
        code = code << 1;
    }

    for (kk = 0; kk < 0x100; kk++) {
        if (pWork->mHuffSize[kk] != 0) {
            si = hf->mHuffValues[kk];
            hf->mEhufco[si] = pWork->mHuffCode[kk];
            hf->mEhufsi[si] = pWork->mHuffSize[kk];
        }
    }
}
