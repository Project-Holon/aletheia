/*
 * PARKED WIP (DIFF, not byte-correct).  Frontier work on the smallest open
 * function of pkt_0206F4C8: 344 code bytes + 20 bytes of literal pool at
 * 0x0206FFA0..0x0207010C, no calls at all, only four pool relocations, and
 * those four already resolve: the pool holds 0x020A1998, 0x020A1999,
 * 0x020A199A, 0x020A199B, i.e. one data object at 0x020A1998 with addends
 * 0..3 (see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md),
 * and 0x020A1998 itself attests `literal` with five pool references
 * image-wide.  So the attestation side is already clean; the whole residue is
 * code shape.
 *
 * Worked out and stable across four attempts:
 *   - flags & 0x8000 selects an extended entry read as three s16 through
 *     argument 1 at 6*idx; cleared selects a normal entry read as five s16
 *     through argument 2 at 10*idx.
 *   - the byte table at 0x020A1998 is the output-slot permutation, four u8
 *     columns indexed by (row[0] & 0xf); the entry's bit 4 picks +0x1000 vs
 *     -0x1000 for the first slot, bit 5 negates the third value, bit 6 the
 *     second.
 *   - the normal entry's five 3-bit fields pack as v0, v4, v1, v2, v3 into a
 *     13-bit signed word stored to out[5]; out[k] = v[k] >> 3 for k 0..4.
 *
 * Residue: this C compiles to 428 bytes against the original's 364.  Four
 * spellings were compiled, best first: 400 (fields as expression locals,
 * extra callee-saved registers pushed), 428 (this one: row pointer + field
 * locals), 448 (b[5*i+k] expression spellings), 468 (row locals only).  The
 * deviation is scheduling and shape, not length of the algorithm: the
 * original hoists nothing, keeps the nine zero stores pure, and reaches the
 * row with `and r2, r3, #0x7fff / add r3, r2, r2, lsl #1 / add r2, r1, r3,
 * lsl #1`, while this C computes the row pointer earlier and the field loads
 * then interleave differently, which shifts every later branch target.  Next
 * step for a dedicated run: match the store order exactly (all nine zeros
 * first, then the row computation), keep row[0] as a fresh load for each of
 * the three flag/index uses (the aliasing between `out` and the row is what
 * makes the original reload it), and check the first branch's
 * `out[i] = flip` / table-index pair against
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md before
 * touching the second branch.
 *
 * function: func_0206FFA0
 * address:  0x0206FFA0
 * packet:   pkt_0206F4C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   unk_020A1998  0x020A1998  data
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0206FFA0.c \
 *       --func func_0206FFA0 --addr 0x0206FFA0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef signed int     s32;
typedef unsigned int   u32;

extern const u8 unk_020A1998[][4];

s32 func_0206FFA0(s32 *out, s16 *a, s16 *b, u32 flags)
{
    s16 v0, v1, v2, v3, v4;
    s16 h2, h3;
    s16 p;
    s16 *row;
    u32 i;

    if ((flags & 0x8000) != 0) {
        out[8] = 0;
        out[7] = 0;
        out[6] = 0;
        out[5] = 0;
        out[4] = 0;
        out[3] = 0;
        out[2] = 0;
        out[1] = 0;
        out[0] = 0;

        row = a + 3 * (flags & 0x7FFF);
        h2 = row[1];
        h3 = row[2];
        out[row[0] & 0xf] = ((row[0] & 0x10) != 0) ? -0x1000 : 0x1000;
        out[unk_020A1998[row[0] & 0xf][0]] = h2;
        out[unk_020A1998[row[0] & 0xf][1]] = h3;
        if ((row[0] & 0x20) != 0) {
            h3 = -h3;
        }
        out[unk_020A1998[row[0] & 0xf][2]] = h3;
        if ((row[0] & 0x40) != 0) {
            h2 = -h2;
        }
        out[unk_020A1998[row[0] & 0xf][3]] = h2;
        return 0;
    }

    i = flags & 0x7FFF;
    v4 = b[5 * i + 4];
    out[4] = v4 >> 3;
    v0 = b[5 * i];
    out[0] = v0 >> 3;
    v1 = b[5 * i + 1];
    out[1] = v1 >> 3;
    v2 = b[5 * i + 2];
    out[2] = v2 >> 3;
    v3 = b[5 * i + 3];
    out[3] = v3 >> 3;

    p = (v0 & 7) | ((v4 & 7) << 3);
    p = (v1 & 7) | (p << 3);
    p = (v2 & 7) | (p << 3);
    p = (v3 & 7) | (p << 3);
    out[5] = (p << 19) >> 19;
    return 1;
}
