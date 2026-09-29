/*
 * function: func_021A153C
 * address:  0x021A153C
 * packet:   pkt_ov009_021A153C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * near miss (w3_s4): 104 bytes differ. Original keeps a real beq on state==2 around the decrypt and reloads inlen after the store; mine if-converts (ldrne/cmpne) and keeps the sum in r2. oldlen local and err=0 carried live are right (mov r4,#0 reused for the flags arg). Nested and && forms both if-convert.
 *
 * sdk:      ProcessIncomingData (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   func_0217EC4C  0x0217EC4C  arm  ov009
 *   func_0219FAAC  0x0219FAAC  arm  ov009
 *   func_0219D478  0x0219D478  arm  ov009
 *   func_021A0A24  0x021A0A24  arm  ov009
 *   func_021A13D0  0x021A13D0  arm  ov009
 */

struct SBL {
	int state;
	char pad0[0x7c - 4];
	char *inbuf;
	int inlen;
	char pad1[0x6b4 - 0x84];
	int sock;
	char pad2[0x6c0 - 0x6b8];
	char cs[0x7cc - 0x6c0];
	int crypt;
};
extern int func_0217EF50(int sock);
extern int func_0217EC4C(int sock, char *buf, int len, int flags);
extern void func_0219FAAC(struct SBL *slist);
extern void func_0219D478(void *state, char *bp, int len);
extern int func_021A0A24(struct SBL *slist);
extern int func_021A13D0(struct SBL *slist);
int func_021A153C(struct SBL *slist)
{
	int err;
	int len;
	int oldlen;
	if (!func_0217EF50(slist->sock))
		return 0;
	oldlen = slist->inlen;
	err = 0;
	len = func_0217EC4C(slist->sock, slist->inbuf + oldlen, 0x1000 - oldlen, 0);
	if (len == -1 || len == 0) {
		func_0219FAAC(slist);
		return 3;
	}
	slist->inlen += len;
	if (slist->state != 2) {
		if (slist->crypt > 0)
			func_0219D478(slist->cs, slist->inbuf + oldlen, slist->inlen - oldlen);
	}
	if (slist->state == 3)
		err = func_021A0A24(slist);
	if (err != 0)
		return err;
	if (slist->state == 2 && slist->inlen > 0)
		return func_021A13D0(slist);
	return 0;
}
