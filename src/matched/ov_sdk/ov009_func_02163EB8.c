/*
 * function: CPSi_rc4_crypt
 * address:  0x02163EB8
 * packet:   pkt_ov009_02163EB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_rc4_crypt (libssl.TWL.HYB.a(arc4.o))
 *
 * symbols:
 *   (none)
 */

typedef struct {
	unsigned char x;
	unsigned char y;
	unsigned char m[256];
} CPSRc4Ctx;

void CPSi_rc4_crypt(CPSRc4Ctx *ctx, unsigned char *data, int len)
{
	int i;
	unsigned char x;
	unsigned char y;
	unsigned char *m;
	unsigned char m_x;
	unsigned char m_y;

	m = ctx->m;
	x = ctx->x;
	y = ctx->y;
	for (i = 0; i < len; i++) {
		x = x + 1;
		m_x = m[x];
		y = y + m_x;
		m_y = m[y];
		m[x] = m_y;
		m[y] = m_x;
		data[i] ^= m[(unsigned char)(m_x + m_y)];
	}
	ctx->x = x;
	ctx->y = y;
}
