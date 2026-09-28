/*
 * function: func_021CA9F8
 * address:  0x021CA9F8
 * packet:   pkt_ov114_021CA9F8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTO_VerifySignatureWithHash (libcrypto.TWL.HYB.a(sign.o))
 *
 * symbols:
 *   func_021CA8EC  0x021CA8EC  arm  ov114
 */

extern int func_021CA8EC(void *decoded_hash_ptr, unsigned long decoded_hash_len, void *sign_ptr, unsigned long sign_len, void *mod_ptr, unsigned long mod_len, unsigned long exp_num);

int func_021CA9F8(void *hash_ptr, void *sign_ptr, void *mod_ptr)
{
	unsigned char decoded_hash[20];
	int decoded_hash_len;
	int i;

	decoded_hash_len = func_021CA8EC(decoded_hash, 20, sign_ptr, 128, mod_ptr, 128, 0x10001);
	if (decoded_hash_len != 20)
		return 0;
	for (i = 0; i < 20; i++) {
		if (decoded_hash[i] != ((unsigned char *)hash_ptr)[i])
			return 0;
	}
	return 1;
}
