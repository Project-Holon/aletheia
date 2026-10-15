/*
 * function: CPSi_sha1_result_prng
 * address:  0x02163E10
 * packet:   pkt_ov009_02163E10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_sha1_result_prng (libssl.TWL.HYB.a(sha1.o))
 *
 * symbols:
 *   func_02163CF0  0x02163CF0  arm  ov009
 *   func_0216359C  0x0216359C  arm  ov009
 *   g_021A1F28  0x021A1F28  data
 *
 * note: the pool word is padding+1 (0x021A1F29); the extern is the padding
 *   array itself and the call passes its second byte.
 */

extern void func_02163CF0(void *ctx, void *data0, int datalen);
extern void func_0216359C(unsigned char *d, unsigned long *s, unsigned int len);
extern unsigned char g_021A1F28[64];

void CPSi_sha1_result_prng(void *ctx, unsigned char *digest)
{
	func_02163CF0(ctx, g_021A1F28 + 1, 44);
	func_0216359C(digest, ctx, 20);
}
