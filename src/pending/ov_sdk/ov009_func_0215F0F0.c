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
 * u1: `(m & (a^d))`, `((d^a) & m)` and an empty-then/else spelling are all canonicalised - still 99 B. The cross-condition CSE of (addr^dns)&netmask into the live r5 (which also costs the extra push) is not steerable.
 *
 * w9_nm: not closed: the object branches on isA (bne to the isB block), no result temp and no cmp r5; isA as if/return chains (three forms) is 99 to 101 B, worse than the draft.
 *
 * lane05 (2026-09-30), no relocations exist in this function (it is a leaf
 *   with 0 relocation sites), so the header's old `status: MATCH` was never a
 *   real verdict; it is DIFF.  Re-measured: the current body is 152 B / 99
 *   diffs; the closest raw form is a single `return` &&-chain of the five
 *   terms, at 144 B / 69 diffs, and the *only* remaining divergence is the
 *   isB block: image keeps `mov r3,#1; bne 0x215f14c` and only then computes
 *   `~netmask == (dns & ~netmask)`, while 1.1p1 if-converts that arm
 *   (`mvneq r2,r0; andeq r0,r2,r1; cmpeq r2,r0; moveq r3,#0`) using the flags
 *   from the immediately preceding `tst r0,r2`.  Breaking the CSE of the shared
 *   `(addr^dns)&netmask` (commuted operands, `(unsigned long)` cast, `!((..)==0)`,
 *   `> 0`, nested ifs, `goto`, separate isA/isB inline helpers) all still
 *   if-convert; every multi-statement isB body the front end refuses to inline
 *   (272-280 B with real calls).  The vendor object stamp is 4.0.0.1024, i.e.
 *   dsi/1.1p1, so the object is reproducible in principle, but no source shape
 *   found reaches the branchy arm.  Ruled out: any local for the three flags
 *   (present draft), the two helper forms, five &&-chain spellings.
 *
 * sdk:      SOCLi_IsIPv4ValidDNSAddr (libsoc.TWL.HYB.a(socl_misc.o))
 */

static inline int isA(unsigned long m, unsigned long d, unsigned long a)
{
	return ((a ^ d) & m) != 0 || (d & ~m) != 0;
}

static inline int isB(unsigned long m, unsigned long d, unsigned long a)
{
	int r = 1;
	if (((a ^ d) & m) == 0) {
		unsigned long t = ~m;
		if (t == (d & t))
			r = 0;
	}
	return r;
}

int func_0215F0F0(unsigned long netmask, unsigned long dns, unsigned long addr)
{
	int ret = 0;
	int notloop = 0;
	int valid = 0;

	if (dns != 0xffffffff && dns != 0 && addr != dns && isA(netmask, dns, addr) && isB(netmask, dns, addr))
		valid = 1;
	if (valid && ((dns & 0xff000000) ^ 0x7f000000) != 0)
		notloop = 1;
	if (notloop && ((dns & 0xf0000000) ^ 0xe0000000) != 0)
		ret = 1;
	return ret;
}
