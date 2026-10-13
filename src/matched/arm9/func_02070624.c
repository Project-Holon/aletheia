/*
 * function: NNSi_G3dAnmGetTexSRTRotData
 * address:  0x02070624
 * packet:   pkt_02070360
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Vector-2 keyframe sampler: the exact sibling of NNSi_G3dAnmGetTexSRTScalarData (the same flag
 * cascade, word for word) but every key is a PAIR of s16 packed into one word,
 * and the result is the two interpolated components packed back into one u32.
 * NNSi_G3dAnmGetTexSRTData uses it for the animation node's rotation track, where
 * NNSi_G3dAnmGetTexSRTScalarData serves the scalar scale and translation tracks.  `flags` bit
 * 29 = inline value, bits 31:30 = key stride, bits 15:0 = key count; unlike
 * NNSi_G3dAnmGetTexSRTScalarData there is no bit-28 width selector, because the key type is
 * always the s16 pair.
 *
 * Per-file compiler pin, inherited from the cluster and from the caller
 * src/matched/NNSi_G3dAnmGetTexSRTData.c: ../2.0/sp2, not the project default.
 *
 * Three source levers, all measured (history in docs/notes/NNSi_G3dAnmGetTexSRTRotData.c.txt):
 *   1. in BOTH tail blocks the value read by byte-offset off `base` must be
 *      read and folded before the pointer local is created, or the four live
 *      s16 plus the pointer plus `base` want a sixth register and the leaf
 *      grows a `push {r3, lr}` the image does not have (the image is a pure
 *      leaf with four bare `bx lr`);
 *   2. the low half of the packed result is `((u32)(x >> k) & 0xffff)`, a
 *      shift and a mask.  Spelling it as the double shift
 *      `((u32)(x << (16-k)) >> 16)` emits the two halves' adds in the other
 *      order and exchanges r0 and r1 through all five packing instructions;
 *   3. in the `two:` block the high half's sum must go to a FRESH local
 *      (`s32 s = a + b;`) rather than accumulating into `a` (`a += b;`).
 *      The compound form keeps `a` live past its last read, so its sum lands
 *      in r1 and the low half's sum is then forced out of r0; letting `a` die
 *      at the sum puts both adds in r0 exactly as the image has them.
 *      Lever 3 was found by tools/permuter.py narrowing the residue to this
 *      one statement; the quad block already has this shape for free, because
 *      its `*3` weighting means each half is folded as it is read.
 *
 * No relocation sites: the function is self-contained.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dAnmGetTexSRTRotData.c \
 *       --func NNSi_G3dAnmGetTexSRTRotData --addr 0x02070624 --cc ../2.0/sp2 --arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

int NNSi_G3dAnmGetTexSRTRotData(u32 *base, u32 flags, u32 off, u32 idx)
{
    u32 n;
    u32 i0;

    if (flags & 0x20000000)
        return off;

    base = (u32 *)((int)base + off);

    if (flags & 0xc0000000) {
        n = flags & 0xffff;
        if (flags & 0x40000000) {
            if (idx & 1) {
                if (idx > n) { idx = (n >> 1) + 1; goto plain; }
                i0 = idx >> 1;
                goto two;
            }
            idx = idx >> 1;
            goto plain;
        } else {
            u32 r = idx & 3;
            if (r != 0) {
                if (idx > n) { idx = r + (n >> 2); goto plain; }
                if (idx & 1) {
                    s32 a, b, c, d;
                    if (idx & 2) { idx = idx >> 2; i0 = idx + 1; }
                    else         { i0 = idx >> 2; idx = i0 + 1; }
                    c = *(s16 *)((char *)base + (i0 << 2));
                    d = *(s16 *)((char *)base + (idx << 2));
                    c *= 3;
                    c += d;
                    a = ((s16 *)(base + i0))[1];
                    b = ((s16 *)(base + idx))[1];
                    a *= 3;
                    a += b;
                    return ((u32)(c >> 2) & 0xffff) | (u32)((a >> 2) << 16);
                }
                i0 = idx >> 2;
                goto two;
            }
            idx = idx >> 2;
        }
    }

plain:
    return base[idx];

two:
    {
        s32 c = *(s16 *)((char *)base + (i0 << 2));
        s16 *p = (s16 *)(base + i0);
        s32 a = p[1];
        s32 b = p[3];
        s32 d = p[2];
        s32 s = a + b;
        c += d;
        return ((u32)(c >> 1) & 0xffff) | (u32)((s >> 1) << 16);
    }
}
