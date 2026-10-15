/*
 * function: SendWithRetry
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
 *   SBServerListDisconnect  0x021A02E0  arm  ov009
 *   SBServerListConnectAndQuery  0x0219FFD4  arm  ov009
 *   ErrorDisconnect  0x0219FAAC  arm  ov009
 */

struct SBL { char pad0[0x80]; int errlen; char pad1[0x6b4 - 0x84]; int sock; };
extern int func_0217EC90(int sock, char *buf, int len, int flags);
extern void SBServerListDisconnect(struct SBL *slist);
struct SBServerList;
extern int SBServerListConnectAndQuery(struct SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers);
extern void ErrorDisconnect(struct SBL *slist);
int SendWithRetry(struct SBL *slist, char *data, int len)
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
		SBServerListDisconnect(slist);
		err = SBServerListConnectAndQuery((struct SBServerList *)slist, 0, 0, 2, 0);
		if (err != 0) {
			ErrorDisconnect(slist);
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
