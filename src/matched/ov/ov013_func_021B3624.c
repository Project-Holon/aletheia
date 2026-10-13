/*
 * function: VCT_DSP_MixSaturated
 * address:  0x021B3624
 * packet:   pkt_ov013_021B3624
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef short s16;
typedef int s32;
typedef unsigned int u32;

#define CLAMP16(v) ((v) > 0x7fff ? 0x7fff : ((v) < -0x8000 ? -0x8000 : (v)))

void VCT_DSP_MixSaturated(s16 *a, s16 *b, s16 *d, u32 len)
{
    u32 i;
    u32 n;
    s32 v;

    n = len >> 1;
    for (i = 0; i < n; i += 4) {
        v = a[i] + b[i];
        if (v > 0x7fff) v = 0x7fff; else if (v < -0x8000) v = -0x8000;
        d[i] = v;
        v = a[i + 1] + b[i + 1];
        if (v > 0x7fff) v = 0x7fff; else if (v < -0x8000) v = -0x8000;
        d[i + 1] = v;
        v = a[i + 2] + b[i + 2];
        if (v > 0x7fff) v = 0x7fff; else if (v < -0x8000) v = -0x8000;
        d[i + 2] = v;
        v = a[i + 3] + b[i + 3];
        if (v > 0x7fff) v = 0x7fff; else if (v < -0x8000) v = -0x8000;
        d[i + 3] = v;
    }
}
