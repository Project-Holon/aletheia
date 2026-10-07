/*
 * file:     unit_0219FBB8_p03.c
 * unit:     yes
 * function: func_021A0340, func_021A0378, func_021A0414
 * address:  0x021A0340
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A02E0  0x021A02E0  arm  ov009
 *   func_0219F830  0x0219F830  arm  ov009
 *   func_0219DFC0  0x0219DFC0  arm  ov009
 *   func_021841B0  0x021841B0  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   func_0219D2F0  0x0219D2F0  arm  ov009
 */
struct SBL;
struct GOACryptState;
struct SBServerList {
    char pad[4];
    void *servers;
};

struct SBL { char pad0[0x54]; char seckey[0x20]; char cryptkey[8]; char pad1[0x6c0 - 0x74 - 8]; char cs[1]; };

typedef unsigned char  u8;

extern void func_021A02E0(struct SBL *slist);
extern void func_0219F830(struct SBL *slist);
extern void func_0219DFC0(struct SBServerList *slist);
extern void func_021841B0(void *array);
extern int func_0209477C(const u8 *s);
extern void func_0219D2F0(struct GOACryptState *state, unsigned char *key, unsigned char keysize);
void func_021A0340(struct SBServerList *slist);
void func_021A0378(struct SBL *slist, char *key, int keylen);
int func_021A0414(int f);


/*
 * sdk:      SBServerListCleanup (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
void func_021A0340(struct SBServerList *slist)
{
    func_021A02E0((struct SBL *)slist);
    func_0219F830((struct SBL *)slist);
    func_0219DFC0(slist);
    if (slist->servers != 0)
        func_021841B0(slist->servers);
    slist->servers = 0;
}

/*
 * sdk:      InitCryptKey (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 */
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

/*
 * Maps the flag bits 2, 8, 0x10 and 0x20 to a size code starting at 5.
 */
int func_021A0414(int f)
{
    int n = 5;

    if (f & 2) n += 4;
    if (f & 8) n += 4;
    if (f & 0x10) n += 2;
    if (f & 0x20) n += 2;
    return n;
}
