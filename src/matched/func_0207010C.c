/*
 * function: func_0207010C
 * address:  0x0207010C
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * RGB555 colour keyframe sampler, the u16-key sibling of
 * src/matched/func_02070274.c (same descriptor word: bit 29 = inline value,
 * bits 31:30 = key stride, bits 28:16 = key count, bits 15:0 = key offset).
 * The two-key mean and the 3:1 blend are done per channel group with the
 * 0x7C1F (red+blue) and 0x03E0 (green) masks, so one add serves two
 * channels.  func_02070434 calls it four times (0x0207048C..0x020704E0).
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md): the
 * image keeps `cmp r2, r3` / `bls 0x02070168` at 0x02070150 / 0x02070154
 * over the four-instruction clamp return (`bic r1, r3, #1` / `add r0, r0,
 * r1` / `ldrh r0, [r0, #2]` / `bx lr`); dsi/1.1p1 -O4,p predicates it to
 * bichi/addhi/ldrhhi/bxhi and the same C is 352 bytes against 360, 246
 * concrete bytes out.  Under ../2.0/sp2 the same C is 360 bytes, 0 mismatches.
 *
 * Source levers: the shared `two:` block takes its own index i0 (not idx),
 * as in src/matched/func_02070624.c; the 3:1 arm's index pair is a fresh
 * pair (i0, j), not idx rewritten in place; and the 3:1 arm reads its second
 * key p[j] directly in both channel sums rather than through a local (found
 * by tools/permuter.py, expand(v1)).
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0207010C.c \
 *       --func func_0207010C --addr 0x0207010C --cc ../2.0/sp2 --arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_0207010C(u8 *base, u32 flags, u32 idx)
{
    u16 *p;
    u32 n;
    u32 i0;
    u32 v0, v1, g, rb;

    if (flags & 0x20000000)
        return (u16)flags;

    p = (u16 *)(base + (u16)flags);

    if ((flags & 0xc0000000) == 0)
        return p[idx];

    n = (flags & 0x1fff0000) >> 16;
    if (flags & 0x40000000) {
        if (idx & 1) {
            if (idx > n)
                return (p + (n >> 1))[1];
            i0 = idx >> 1;
            goto two;
        }
        return p[idx >> 1];
    } else {
        u32 r = idx & 3;
        if (r != 0) {
            if (idx > n)
                return (p + (n >> 2))[r];
            if (idx & 1) {
                u32 j;
                if (idx & 2) { j = idx >> 2; i0 = j + 1; }
                else { i0 = idx >> 2; j = i0 + 1; }
                v0 = p[i0];
                g = ((v0 & 0x3e0) * 3 + (p[j] & 0x3e0)) >> 2;
                rb = ((v0 & 0x7c1f) * 3 + (p[j] & 0x7c1f)) >> 2;
                return (u16)((rb & 0x7c1f) | (g & 0x3e0));
            }
            i0 = idx >> 2;
            goto two;
        }
        return p[idx >> 2];
    }

two:
    v0 = p[i0];
    v1 = (p + i0)[1];
    g = ((v0 & 0x3e0) + (v1 & 0x3e0)) >> 1;
    rb = ((v0 & 0x7c1f) + (v1 & 0x7c1f)) >> 1;
    return (u16)((rb & 0x7c1f) | (g & 0x3e0));
}
