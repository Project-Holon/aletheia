/*
 * function: ErrorDisconnect
 * address:  0x0219FAAC
 * packet:   pkt_ov009_0219FAAC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ErrorDisconnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_020949F4  0x020949F4  arm
 *   SBServerListSetLastError  0x021A0A1C  arm  ov009
 *   SBServerListDisconnect  0x021A02E0  arm  ov009
 *   gSBMasterHostname  0x021A821C  data
 *   gSBNullServer  0x021AEB00  data
 */

struct SBL {
	char pad0[0x7c];
	char *errstr;
	int errlen;
	char pad1[0x488 - 0x84];
	void (*cb)(struct SBL *l, int type, void *s, void *ud);
	char pad2[0x494 - 0x48c];
	void *ud;
};
extern char *gSBMasterHostname;
extern void *gSBNullServer;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern void SBServerListSetLastError(int *p, int v);
extern void SBServerListDisconnect(struct SBL *slist);
void ErrorDisconnect(struct SBL *slist)
{
	int len = slist->errlen;
	char *q;
	if (len > 0 && len > (unsigned int)func_0209477C((const u8 *)(q = gSBMasterHostname))) {
		char *e = gSBMasterHostname;
		char *s = slist->errstr;
		if (func_020949F4((const u8 *)s, (const u8 *)e, (unsigned int)func_0209477C((const u8 *)e)) == 0) {
			SBServerListSetLastError((int *)slist, (int)(s + (unsigned int)func_0209477C((const u8 *)q)));
			slist->cb(slist, 5, gSBNullServer, slist->ud);
		}
	}
	slist->cb(slist, 4, gSBNullServer, slist->ud);
	SBServerListDisconnect(slist);
}
