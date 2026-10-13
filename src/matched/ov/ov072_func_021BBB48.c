/*
 * function: TOWNMAP_GRH_FindRecordIndex
 * address:  0x021BBB48
 * packet:   pkt_021BBB48
 * region:   ov072
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Linear search of the first u16 field of 0x36-byte records for `a1`;
 * returns the zero-extended matching index or 0xffff.  The third argument
 * is a named zero kept live in a callee-saved register, which is what pins
 * the caller-side truncation of the index into r1 (see
 * docs/idioms/a-named-zero-argument-pins-the-callers-truncation.md).
 *
 * symbols:
 *   TOWNMAP_GRH_GetTownInfoValue  0x021BBB3C  thumb
 */

typedef unsigned short u16;

int TOWNMAP_GRH_GetTownInfoValue(int a0, u16 a1, int a2);

int TOWNMAP_GRH_FindRecordIndex(int a0, int a1)
{
    int i;
    int j = 0;

    for (i = 0; i < 0x3d; i++) {
        if (TOWNMAP_GRH_GetTownInfoValue(a0, i, j) == a1)
            return (u16)i;
    }
    return 0xffff;
}
