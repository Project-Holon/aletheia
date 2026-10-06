/*
 * function: func_021A0378
 * address:  0x021A0378
 * packet:   pkt_ov009_021A0378
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      InitCryptKey (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_0219D2F0  0x0219D2F0  arm  ov009
 */

struct SBL { char pad0[0x54]; char seckey[0x20]; char cryptkey[8]; char pad1[0x6c0 - 0x74 - 8]; char cs[1]; };
typedef unsigned char  u8;
struct GOACryptState;
extern int func_0209477C(const u8 *s);
extern void func_0219D2F0(struct GOACryptState *state, unsigned char *key, unsigned char keysize);
void func_021A0378(struct SBL *slist, char *key, int keylen)
{
	int i;
	int seckeylen;
	char *seckey;
	seckeylen = func_0209477C((const u8 *)slist->seckey);
	seckey = slist->seckey;
	for (i = 0; i < keylen; i++)
		slist->cryptkey[(i * seckey[i % seckeylen]) % 8] ^= slist->cryptkey[i % 8] ^ key[i];
	func_0219D2F0((struct GOACryptState *)slist->cs, (unsigned char *)slist->cryptkey, 8);
}
