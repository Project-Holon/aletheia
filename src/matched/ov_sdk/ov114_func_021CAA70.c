/*
 * function: func_021CAA70
 * address:  0x021CAA70
 * packet:   pkt_ov114_021CAA70
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTO_VerifySignature (libcrypto.TWL.HYB.a(sign.o))
 *
 * symbols:
 *   func_020816B8  0x020816B8  arm
 *   func_021CA9F8  0x021CA9F8  arm  ov114
 */

extern void func_020816B8(void *digest, void *data, unsigned long dataLength);
extern int func_021CA9F8(void *hash_ptr, void *sign_ptr, void *mod_ptr);

int func_021CAA70(void *data_ptr, int data_len, void *sign_ptr, void *mod_ptr)
{
	unsigned char hash[20];

	func_020816B8(hash, data_ptr, data_len);
	return func_021CA9F8(hash, sign_ptr, mod_ptr);
}
