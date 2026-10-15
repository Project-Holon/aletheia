/*
 * function: SBServerListDisconnect
 * address:  0x021A02E0
 * packet:   pkt_ov009_021A02E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerListDisconnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   FreeKeyList  0x021A027C  arm  ov009
 *   FreePopularValues  0x021A0238  arm  ov009
 */

struct SBL {
	int state;
	char pad0[0x7c - 4];
	char *errstr;
	int errlen;
	char pad1[0x484 - 0x84];
	int f484;
	char pad2[0x6b4 - 0x488];
	int sock;
};
extern void func_0217EAE0(void *p);
extern int closesocket(int sock);
extern void FreeKeyList(struct SBL *slist);
extern void FreePopularValues(char *slist);
void SBServerListDisconnect(struct SBL *slist)
{
	if (slist->errstr != 0)
		func_0217EAE0(slist->errstr);
	slist->errstr = 0;
	slist->errlen = 0;
	if (slist->sock != -1)
		closesocket(slist->sock);
	slist->sock = -1;
	slist->state = 1;
	FreeKeyList(slist);
	slist->f484 = -1;
	FreePopularValues((char *)slist);
}
