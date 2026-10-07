/*
 * function: func_021A02E0
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
 *   func_0217EB2C  0x0217EB2C  arm  ov009
 *   func_021A027C  0x021A027C  arm  ov009
 *   func_021A0238  0x021A0238  arm  ov009
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
extern int func_0217EB2C(int sock);
extern void func_021A027C(struct SBL *slist);
extern void func_021A0238(char *slist);
void func_021A02E0(struct SBL *slist)
{
	if (slist->errstr != 0)
		func_0217EAE0(slist->errstr);
	slist->errstr = 0;
	slist->errlen = 0;
	if (slist->sock != -1)
		func_0217EB2C(slist->sock);
	slist->sock = -1;
	slist->state = 1;
	func_021A027C(slist);
	slist->f484 = -1;
	func_021A0238((char *)slist);
}
