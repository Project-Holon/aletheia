/*
 * function: func_0215F0F0
 * address:  0x0215F0F0
 * packet:   pkt_ov009_0215F0F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * u21: the defining object socl_misc.o is .comment 4.0.0.1024 -> dsi/1.1p1, so the front end is
 *      right and this is a codegen-shape wall, not a spelling one. The image is branch codegen: the
 *      `(netmask & (dns ^ addr)) || (dns & ~netmask)` test recomputes the xor at L12C instead of
 *      CSE-ing it, and the flag stores stay `cmp r3,#0 / movne r4,#1`. 1.1p1 CSEs the masked xor
 *      into one live register and cascades conditional execution over the whole middle, which is 12
 *      bytes SHORTER from the same source (136 vs 148). First divergence +0000 image `push {r4, lr}`
 *      | ours `push {r3, r4, r5, lr}`; body at +0024 image `tst r0, r3` | ours `ands r3, r0, r2`.
 *      -O2/-O3/-O4,s identical (136 B), -O1,p 176 B, so no flag reaches 148.
 *
 * lane05 (2026-09-30), no relocations exist in this function (it is a leaf
 *   with 0 relocation sites), so the header's old `status: MATCH` was never a
 *   real verdict; it is DIFF.  The current body is 152 B / 99 diffs; the
 *   closest raw form is a single `return` &&-chain of the five terms, at
 *   144 B / 69 diffs, and the *only* remaining divergence is the isB block:
 *   image keeps `mov r3,#1; bne 0x215f14c` and only then computes
 *   `~netmask == (dns & ~netmask)`, while 1.1p1 if-converts that arm.
 *
 * lane08 (2026-09-30): the closest shape found is 148 B / 33 concrete bytes.
 *   Writing isA/isB as macros (rather than `static inline` helpers) keeps the
 *   148-byte length and the whole guard's branch structure; the ONLY remaining
 *   divergence is the CSE of `(addr ^ dns) & netmask`, which 1.1p1 computes
 *   once into r3 across the isA->isB boundary:
 *     image   eor r3,r2,r1 / tst r0,r3 / bne ISB ... then in isB
 *             eor r2,r2,r1 / tst r0,r2 / mov r3,#1 / bne KEEP ...
 *     ours    eor r2,r2,r1 / ands r3,r0,r2 / bne ISB ... then in isB
 *             cmp r3,#0 / movne r0,#1 / bne KEEP ...
 *   isA/isB also land their result in r0 where the image uses r3.
 *   Ruled out (all still 148/33 or worse): commuted operands `m & (a^d)` and
 *   `(d^a) & m`, `(unsigned)` casts, helper-with-local, swapping d/a argument
 *   order, the negated-or spelling, separate bool statements, unsigned helper
 *   parameters.  The CSE is the whole wall; nothing that keeps the source
 *   spelled as two independent predicates stops 1.1p1 from value-numbering the
 *   masked xor across the inlined isA/isB boundary (same front end that built
 *   the object, so this is a source-shape wall, not a stamp mismatch).
 *
 * sdk:      SOCLi_IsIPv4ValidDNSAddr (libsoc.TWL.HYB.a(socl_misc.o))
 */

#define IS_A(m, d, a) ((((a) ^ (d)) & (m)) != 0 || ((d) & ~(m)) != 0)
#define IS_B(m, d, a) (((((a) ^ (d)) & (m)) != 0) ? 1 : (((~(m)) == ((d) & ~(m))) ? 0 : 1))

int func_0215F0F0(unsigned long netmask, unsigned long dns, unsigned long addr)
{
	int ret = 0;
	int notloop = 0;
	int valid = 0;

	if (dns != 0xffffffff && dns != 0 && addr != dns && IS_A(netmask, dns, addr) && IS_B(netmask, dns, addr))
		valid = 1;
	if (valid && ((dns & 0xff000000) ^ 0x7f000000) != 0)
		notloop = 1;
	if (notloop && ((dns & 0xf0000000) ^ 0xe0000000) != 0)
		ret = 1;
	return ret;
}
