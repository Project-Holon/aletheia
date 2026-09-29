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
 *
 * w9_nm: 21 B, register assignment only (m in r4 vs lr; temps r3/r0). Tried DWARF and reverse declaration orders, a separate counter for the second loop, m assigned before or after the ctx stores, explicit u8 casts on j and k.
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
