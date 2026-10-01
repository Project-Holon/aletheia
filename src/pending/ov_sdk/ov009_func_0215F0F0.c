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
 * blocker:  1.1p1 value-numbers `(addr ^ dns) & netmask` (CSE) across the
 *           inlined isA/isB boundary and materialises its boolean once in a
 *           callee-saved reg (`ands r3, r0, r2` then `cmp r3,#0` in isB),
 *           whereas the image tests isA with `tst r0, r3` (no value) and then
 *           RECOMPUTES `eor r2, r2, r1` in isB because r3 was clobbered by the
 *           intervening `mvn`.  The recompute falls out for free once the
 *           boolean is not shared; the whole wall is stopping the front end
 *           from sharing it.
 *
 * lane05 (2026-09-30), no relocations exist in this function (leaf, 0 sites).
 * lane08 (2026-09-30): closest shape 148 B / 33 bytes.  isA/isB as macros keeps
 *   the 148-byte length and the whole guard's branch structure; the only
 *   divergence is the CSE above.  Ruled out (all 148/33 or worse): commuted
 *   operands, casts, helper-with-local, swapped d/a order, negated-or,
 *   separate bool statements, unsigned helper params.
 * wave8 (2026-10-01): re-confirmed 148/33.  Also tried, all no better:
 *   - nested `if (A||B){ if(C) ok=1; else ok=...; if(ok) valid=1; }` and an
 *     `int ok` local (identical 33);
 *   - bare-integer vs `!= 0` on either/both tests (identical 33);
 *   - GNU statement-expression macro computing the xor into its own `__xa`
 *     local (34 — commutes the `ands` operands, CSE unchanged);
 *   - inner `unsigned long x = addr ^ dns;` then `x & netmask` (33);
 *   - `volatile` on dns/addr (212 B — forces stack homes, wrong).
 *   Every pure-expression spelling is canonicalised; only a memory/sequence
 *   barrier kills the CSE, and there is no frame word to spend on one.  Parked.
 * wave8 lane (2026-10-01, 08:21 deadline): additional attempts, all 148/33
 *   unchanged: `> 0` vs `!= 0`; distributed `(a&m)^(d&m)`; swapped AND operand
 *   order `m&(a^d)`; `(a&m)!=(d&m)` for isA (156, not reduced); `nm=netmask`
 *   alias local; `const` on all three params; an
 *   `__asm volatile("" ::: "memory")` barrier between the tests (accepted,
 *   emitted nothing, 33 unchanged -- a memory clobber cannot break arithmetic
 *   value-numbering).  Confirms the wall is arithmetic CSE, not memory order.
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
