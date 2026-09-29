/*
 * function: func_0219FF30
 * address:  0x0219FF30
 * packet:   pkt_ov009_0219FF30
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SendWithRetry (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0217EC90  0x0217EC90  arm  ov009
 *   func_021A02E0  0x021A02E0  arm  ov009
 *   func_0219FFD4  0x0219FFD4  arm  ov009
 *   func_0219FAAC  0x0219FAAC  arm  ov009
 */

struct SBL { char pad0[0x80]; int errlen; char pad1[0x6b4 - 0x84]; int sock; };
extern int func_0217EC90(int sock, char *buf, int len, int flags);
extern void func_021A02E0(struct SBL *slist);
extern int func_0219FFD4(struct SBL *slist, char *fieldList, char *serverFilter, int options, int maxServers);
extern void func_0219FAAC(struct SBL *slist);
int func_0219FF30(struct SBL *slist, char *data, int len)
{
	int err;
	int ret;
	int retryCount;
	retryCount = 1;
	do {
		retryCount--;
		ret = func_0217EC90(slist->sock, data, len, 0);
		if (ret > 0 || retryCount < 0 || slist->errlen > 0)
			break;
		func_021A02E0(slist);
		err = func_0219FFD4(slist, 0, 0, 2, 0);
		if (err != 0) {
			func_0219FAAC(slist);
			return err;
		}
	} while (retryCount >= 0);
	{
		int r = 3;
		if (ret > 0)
			r = 0;
		return r;
	}
}
