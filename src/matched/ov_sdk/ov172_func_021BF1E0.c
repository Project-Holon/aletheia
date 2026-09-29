/*
 * function: func_021BF1E0
 * address:  0x021BF1E0
 * packet:   pkt_ov172_021BF1E0
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      decode_block_sub (jpegdec.o)
 *
 * AAN integer IDCT: pass 1 dequantises through qy[n..] into mtx[2], pass 2
 * range-limits through limits+0x180 (g_021C80AC) into d.  The odd-part sum
 * is spelled tmp5 + tmp10 in both passes (operand order of the add).
 *
 * symbols:
 *   g_021C8A1C     0x021C8A1C  data
 *   g_021C80AC     0x021C80AC  data
 *   g_021C8B1C     0x021C8B1C  data
 */

extern short g_021C8A1C[128];
extern unsigned char g_021C80AC[];
extern short g_021C8B1C[5][64];

void func_021BF1E0(short *s, short *d, int n)
{
    int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
    int tmp10, tmp11, tmp12, tmp13;
    int z5, z10, z11, z12, z13;
    unsigned char *limtbl = g_021C80AC;
    int i;

    for (i = 0; i < 8; i++) {
        if ((s[8 * 1 + i] | s[8 * 2 + i] | s[8 * 3 + i] | s[8 * 4 + i] |
             s[8 * 5 + i] | s[8 * 6 + i] | s[8 * 7 + i]) == 0) {
            g_021C8B1C[2][8 * 0 + i] = g_021C8B1C[2][8 * 1 + i] =
            g_021C8B1C[2][8 * 2 + i] = g_021C8B1C[2][8 * 3 + i] =
            g_021C8B1C[2][8 * 4 + i] = g_021C8B1C[2][8 * 5 + i] =
            g_021C8B1C[2][8 * 6 + i] = g_021C8B1C[2][8 * 7 + i] =
                s[8 * 0 + i] * g_021C8A1C[n + 8 * 0 + i];
            continue;
        }

        tmp0 = s[8 * 0 + i] * g_021C8A1C[n + 8 * 0 + i];
        tmp1 = s[8 * 2 + i] * g_021C8A1C[n + 8 * 2 + i];
        tmp2 = s[8 * 4 + i] * g_021C8A1C[n + 8 * 4 + i];
        tmp3 = s[8 * 6 + i] * g_021C8A1C[n + 8 * 6 + i];

        tmp10 = tmp0 + tmp2;
        tmp11 = tmp0 - tmp2;

        tmp13 = tmp1 + tmp3;
        tmp12 = (((tmp1 - tmp3) * 362) >> 8) - tmp13;

        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        tmp4 = s[8 * 1 + i] * g_021C8A1C[n + 8 * 1 + i];
        tmp5 = s[8 * 3 + i] * g_021C8A1C[n + 8 * 3 + i];
        tmp6 = s[8 * 5 + i] * g_021C8A1C[n + 8 * 5 + i];
        tmp7 = s[8 * 7 + i] * g_021C8A1C[n + 8 * 7 + i];

        z13 = tmp6 + tmp5;
        z10 = tmp6 - tmp5;
        z11 = tmp4 + tmp7;
        z12 = tmp4 - tmp7;

        tmp7 = z11 + z13;
        tmp11 = ((z11 - z13) * 362) >> 8;

        z5 = ((z10 + z12) * 473) >> 8;
        tmp10 = ((z12 * 277) >> 8) - z5;
        tmp12 = ((z10 * -669) >> 8) + z5;

        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp5 + tmp10;

        g_021C8B1C[2][8 * 0 + i] = tmp0 + tmp7;
        g_021C8B1C[2][8 * 7 + i] = tmp0 - tmp7;
        g_021C8B1C[2][8 * 1 + i] = tmp1 + tmp6;
        g_021C8B1C[2][8 * 6 + i] = tmp1 - tmp6;
        g_021C8B1C[2][8 * 2 + i] = tmp2 + tmp5;
        g_021C8B1C[2][8 * 5 + i] = tmp2 - tmp5;
        g_021C8B1C[2][8 * 4 + i] = tmp3 + tmp4;
        g_021C8B1C[2][8 * 3 + i] = tmp3 - tmp4;
    }

    for (i = 0; i < 8; i++) {
        if ((g_021C8B1C[2][i * 8 + 1] | g_021C8B1C[2][i * 8 + 2] | g_021C8B1C[2][i * 8 + 3] | g_021C8B1C[2][i * 8 + 4] | g_021C8B1C[2][i * 8 + 5] | g_021C8B1C[2][i * 8 + 6] | g_021C8B1C[2][i * 8 + 7]) == 0) {
            d[i * 8 + 0] = d[i * 8 + 1] = d[i * 8 + 2] = d[i * 8 + 3] =
            d[i * 8 + 4] = d[i * 8 + 5] = d[i * 8 + 6] = d[i * 8 + 7] =
                limtbl[(g_021C8B1C[2][i * 8 + 0] >> 5) & 0x3ff];
            continue;
        }

        tmp10 = g_021C8B1C[2][i * 8 + 0] + g_021C8B1C[2][i * 8 + 4];
        tmp11 = g_021C8B1C[2][i * 8 + 0] - g_021C8B1C[2][i * 8 + 4];

        tmp13 = g_021C8B1C[2][i * 8 + 2] + g_021C8B1C[2][i * 8 + 6];
        tmp12 = (((g_021C8B1C[2][i * 8 + 2] - g_021C8B1C[2][i * 8 + 6]) * 362) >> 8) - tmp13;

        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        z13 = g_021C8B1C[2][i * 8 + 5] + g_021C8B1C[2][i * 8 + 3];
        z10 = g_021C8B1C[2][i * 8 + 5] - g_021C8B1C[2][i * 8 + 3];
        z11 = g_021C8B1C[2][i * 8 + 1] + g_021C8B1C[2][i * 8 + 7];
        z12 = g_021C8B1C[2][i * 8 + 1] - g_021C8B1C[2][i * 8 + 7];

        tmp7 = z11 + z13;
        tmp11 = ((z11 - z13) * 362) >> 8;

        z5 = ((z10 + z12) * 473) >> 8;
        tmp10 = ((z12 * 277) >> 8) - z5;
        tmp12 = ((z10 * -669) >> 8) + z5;

        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp5 + tmp10;

        d[i * 8 + 0] = limtbl[((tmp0 + tmp7) >> 5) & 0x3ff];
        d[i * 8 + 7] = limtbl[((tmp0 - tmp7) >> 5) & 0x3ff];
        d[i * 8 + 1] = limtbl[((tmp1 + tmp6) >> 5) & 0x3ff];
        d[i * 8 + 6] = limtbl[((tmp1 - tmp6) >> 5) & 0x3ff];
        d[i * 8 + 2] = limtbl[((tmp2 + tmp5) >> 5) & 0x3ff];
        d[i * 8 + 5] = limtbl[((tmp2 - tmp5) >> 5) & 0x3ff];
        d[i * 8 + 4] = limtbl[((tmp3 + tmp4) >> 5) & 0x3ff];
        d[i * 8 + 3] = limtbl[((tmp3 - tmp4) >> 5) & 0x3ff];
    }
}
