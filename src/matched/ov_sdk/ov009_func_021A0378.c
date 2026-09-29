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
extern int func_0209477C(char *s);
extern void func_0219D2F0(void *state, char *key, int keysize);
void func_021A0378(struct SBL *slist, char *key, int keylen)
{
	int i;
	int seckeylen;
	char *seckey;
	seckeylen = func_0209477C(slist->seckey);
	seckey = slist->seckey;
	for (i = 0; i < keylen; i++)
		slist->cryptkey[(i * seckey[i % seckeylen]) % 8] ^= slist->cryptkey[i % 8] ^ key[i];
	func_0219D2F0(slist->cs, slist->cryptkey, 8);
}
