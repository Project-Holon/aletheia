/*
 * function: func_0219FAAC
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
 *   func_021A0A1C  0x021A0A1C  arm  ov009
 *   func_021A02E0  0x021A02E0  arm  ov009
 *   g_021A821C  0x021A821C  data
 *   g_021AEB00  0x021AEB00  data
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
extern char *g_021A821C;
extern void *g_021AEB00;
extern unsigned int func_0209477C(char *s);
extern int func_020949F4(char *a, char *b, unsigned int n);
extern void func_021A0A1C(struct SBL *slist, char *err);
extern void func_021A02E0(struct SBL *slist);
void func_0219FAAC(struct SBL *slist)
{
	int len = slist->errlen;
	char *q;
	if (len > 0 && len > func_0209477C(q = g_021A821C)) {
		char *e = g_021A821C;
		char *s = slist->errstr;
		if (func_020949F4(s, e, func_0209477C(e)) == 0) {
			func_021A0A1C(slist, s + func_0209477C(q));
			slist->cb(slist, 5, g_021AEB00, slist->ud);
		}
	}
	slist->cb(slist, 4, g_021AEB00, slist->ud);
	func_021A02E0(slist);
}
