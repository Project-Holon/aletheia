/*
 * function: NNSi_G3dAnmGetMatAlphaData
 * address:  0x02070274
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * u8 keyframe sampler, the byte-key sibling of src/matched/NNSi_G3dAnmGetTexSRTScalarData.c
 * (same track descriptor word: bit 29 = inline value, returned as its low
 * half; bits 31:30 = full / half / quarter key stride; bits 28:16 = key
 * count n; bits 15:0 = the key block's offset from base).  Its one caller,
 * NNSi_G3dAnmCalcNsBma at 0x0207050C, shifts the result into bits 16..20 of a
 * packed word, hence the u16 return.
 *
 * Front end: filed under the packet's ../2.0/sp2 unit pin
 * (docs/notes/pkt_0206EB00.c.txt, docs/FRONTEND-PINS.md).  This function is
 * neutral between front ends: the same C is EXACT under dsi/1.1p1 as well (measured
 * 2026-09-22), so it carries no tell of its own.
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dAnmGetMatAlphaData.c \
 *       --func NNSi_G3dAnmGetMatAlphaData --addr 0x02070274 --cc ../2.0/sp2 --arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 NNSi_G3dAnmGetMatAlphaData(u8 *base, u32 flags, u32 idx)
{
    u8 *p;
    u32 n;
    u32 i0;
    u32 v0, v1;

    if (flags & 0x20000000)
        return (u16)flags;

    p = base + (u16)flags;

    if ((flags & 0xc0000000) == 0)
        return p[idx];

    n = (flags & 0x1fff0000) >> 16;
    if (flags & 0x40000000) {
        if (idx & 1) {
            if (idx > n)
                return (p + (n >> 1))[1];
            idx = idx >> 1;
            v0 = p[idx];
            v1 = (p + idx)[1];
            return (u16)((v0 + v1) >> 1);
        }
        return p[idx >> 1];
    } else {
        u32 r = idx & 3;
        if (r != 0) {
            if (idx > n)
                return (p + (n >> 2))[r];
            if (idx & 1) {
                if (idx & 2) { idx = idx >> 2; i0 = idx + 1; }
                else { i0 = idx >> 2; idx = i0 + 1; }
                v0 = p[i0];
                v1 = p[idx];
                v0 *= 3;
                v0 += v1;
                return (u16)(v0 >> 2);
            }
            idx = idx >> 2;
            v0 = p[idx];
            v1 = (p + idx)[1];
            return (u16)((v0 + v1) >> 1);
        }
        return p[idx >> 2];
    }
}
