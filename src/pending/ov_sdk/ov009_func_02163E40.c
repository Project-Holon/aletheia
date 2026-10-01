/*
 * function: func_02163E40
 * address:  0x02163E40
 * packet:   pkt_ov009_02163E40
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: 12 concrete bytes, one scratch/zero register pair mirrored (image
 *          r0 = k-reset zero, r3 = loop-2 scratch; this build the reverse). See
 *          the residue note below.  Every declaration order tried is inert; the
 *          swap is not source-steerable under dsi/1.1p1.
 *
 * u1: four more declaration permutations (m last / m first / m_i first / m folded into the char declarator) all stay at 21 B (two rise to 32 B). The four-register mirror is not declaration-driven.
 *
 * w8: the surviving 12 B is a pure zero-temp/loop-2-scratch colour swap (image
 *     zero r0 / scratch r3). Inert at 12: compound `j +=`, a named sum temp
 *     (coalesced), `while`/`do-while`, `i += 1`, enum-typed zero local,
 *     `unsigned char z = 0` named zero used for the reset, `(unsigned char)0`,
 *     separate loop-1/loop-2 counters, `void *key` cast spellings, and
 *     `k=k; j=j; i=i; m=m; m_i=m_i;` self-assignments at the loop head / pre-loop.
 *     Same-width-4-reg colour tie, not source-steerable by these shapes.
 *     (The arm9 sibling CRYPTO_RC4Init, same vendor algorithm, is EXACT but has
 *     a key_len clamp and a `==` wrap, so its colouring does not transfer.)
 *
 * w8b: still 12 B. New inert levers: `k=0;j=0;` vs `j=k=0;`, `for(i=0,k=0;...)`,
 *      `for(i=0,j=0,k=0;...)`, `for(i=k;...)`, named `zero` local spelled as a
 *      copy of k (`zero=k;`) in three declaration slots, a `kk=key[k]` reorder
 *      (19 B), reset moved after the swap (26 B), enum-typed KZERO (12 B),
 *      `const unsigned char *key` (12 B), `if((k=..)>=len)`, `k &= 0`. The pair
 *      is the hoisted k-reset zero (image r0) vs the loop-2 scratch (image r3):
 *      the freshly-dead loop-1 index register goes to whichever web the
 *      allocator colours first, and no source shape reached here moves it.
 *
 * w9_nm: 21 B, register assignment only. Residue (lane S7, re-measured): the whole
 * output is one mirrored pair swap -- image keeps the table pointer `m` in r4 and
 * the loaded byte m_i in lr (with the k-zero temp in r0 and the accumulator
 * chain in r3); this compile has m in lr, m_i in r4, the k-zero temp in r3 and
 * the chain in r0. All 21 bytes are those four register numbers. Tried here:
 * declaration order (forward and reverse), `m` declared last, declaration
 * initialiser (`unsigned char *m = ctx->m;`), `m = &ctx->m[0]`, no `m` local at
 * all (93 out), `ctx->x = ctx->y = 0;` chained (23 out), `j += ...`, `k++`,
 * `j`/`k` assigned separately, `int i` vs `unsigned int i` (34 out),
 * `m = m;`/`m_i = m_i;` self-assignments at the loop head and after the load
 * (no move). Declaration order is inert; the pointer/m_i tie is not steerable
 * from the source shapes tried so far.
 *
 * u31: 21 -> 12 concrete bytes, one declaration change. The defining object's
 * DWARF names locals m_i, k, j, m, i; declaring `unsigned char m_i;` FIRST and
 * then `unsigned char *m = ctx->m;` (then j, k, int i) is what flips the pair:
 * m lands in r4 and m_i in lr -- the image's own map (m=r4, m_i=lr, j=r5, k=r6,
 * i=r7, k-reset zero=r0). Before this every statement was a mirrored r4/lr swap.
 * 23 declaration orders were compiled; only m_i,m,j,k,i reproduces the map.
 * `m` as a plain statement (`unsigned char *m; ... m = ctx->m;`) is equivalent.
 *
 * REMAINING RESIDUE (12 B), one scratch/constant pair mirrored, image | ours:
 *   +0030 mov r0, r6   (k-reset zero)   | mov r3, r6
 *   +003C add r3, r6, #1                | add r0, r6, #1
 *   +0040 and r6, r3, #0xff             | and r6, r0, #0xff
 *   +0044 add r3, lr, ip                | add r0, lr, ip
 *   +005C movge r6, r0                  | movge r6, r3
 *   +0060 strb r3, [r4, r7]             | strb r0, [r4, r7]
 * The image hands r3 (the register freed by loop 1's index i) to the loop-2
 * scratch and keeps the reset zero in r0; 1.1p1 does the reverse. Inert against
 * six spellings of the reset (if, if/else, ternary, named zero local, int cast,
 * k = k else), a named sum temp, a separate loop-1 index, and the m initialiser
 * vs statement form. ../2.0/sp1p2 also reaches exactly 12.
 *
 * sdk:      CPSi_rc4_init (libssl.TWL.HYB.a(arc4.o))
 *
 * symbols:
 *   (none)
 */

typedef struct {
	unsigned char x;
	unsigned char y;
	unsigned char m[256];
} CPSRc4Ctx;

void func_02163E40(CPSRc4Ctx *ctx, unsigned char *key, int len)
{
	unsigned char m_i;
	unsigned char *m = ctx->m;
	unsigned char j;
	unsigned char k;
	int i;

	ctx->x = 0;
	ctx->y = 0;
	for (i = 0; i < 256; i++) {
		m[i] = i;
	}
	j = k = 0;
	for (i = 0; i < 256; i++) {
		m_i = m[i];
		j = j + (unsigned char)(m_i + key[k]);
		k = (k + 1) & 0xff;
		if (k >= len) {
			k = 0;
		}
		m[i] = m[j];
		m[j] = m_i;
	}
}
