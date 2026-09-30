/*
 * function: func_02163E40
 * address:  0x02163E40
 * packet:   pkt_ov009_02163E40
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * u1: four more declaration permutations (m last / m first / m_i first / m folded into the char declarator) all stay at 21 B (two rise to 32 B). The four-register mirror is not declaration-driven.
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
	int i;
	unsigned char *m;
	unsigned char m_i, j, k;

	m = ctx->m;
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
