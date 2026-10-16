/*
 * function: ProcessIncomingData
 * address:  0x021A153C
 * packet:   pkt_ov009_021A153C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessIncomingData (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   recv  0x0217EC4C  arm  ov009
 *   ErrorDisconnect  0x0219FAAC  arm  ov009
 *   GOADecrypt  0x0219D478  arm  ov009
 *   ProcessMainListData  0x021A0A24  arm  ov009
 *   ProcessAdHocData  0x021A13D0  arm  ov009
 *
 * Receives one chunk into the server browser's line buffer, advances inlen,
 * decrypts what arrived, and hands off to the state-3 / state-2 processors.
 *
 * The decrypt guard is an OR, not an AND.  The image branches
 * `cmp r1,#2 / beq <decrypt>` - state == 2 jumps STRAIGHT INTO the decrypt
 * block - and only the not-2 path falls through to the `crypt <= 0` skip.  So
 * the condition is `state == 2 || crypt > 0`; the earlier parked spelling
 * (nested `if (state != 2) if (crypt > 0)`) is if-converted to ldrne/cmpne and
 * compiles 8 bytes short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_021A153C.c \
 *       --func ProcessIncomingData --addr 0x021A153C --region ov009 --arm --lang c99 --cc 1.1p1 --diff
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
extern int recv(int sock, char *buf, int len, int flags);
extern void ErrorDisconnect(struct SBL *slist);
struct GOACryptState;
struct _SBServerList;
extern void GOADecrypt(struct GOACryptState *state, unsigned char *bp, int len);
extern int ProcessMainListData(struct _SBServerList *slist);
extern int ProcessAdHocData(struct SBL *slist);
int ProcessIncomingData(struct SBL *slist)
{
	int err;
	int len;
	int oldlen;
	if (!func_0217EF50(slist->sock))
		return 0;
	oldlen = slist->inlen;
	err = 0;
	len = recv(slist->sock, slist->inbuf + oldlen, 0x1000 - oldlen, 0);
	if (len == -1 || len == 0) {
		ErrorDisconnect(slist);
		return 3;
	}
	slist->inlen += len;
	if (slist->state == 2 || slist->crypt > 0)
		GOADecrypt((struct GOACryptState *)slist->cs, (unsigned char *)(slist->inbuf + oldlen), slist->inlen - oldlen);
	if (slist->state == 3)
		err = ProcessMainListData((struct _SBServerList *)slist);
	if (err != 0)
		return err;
	if (slist->state == 2 && slist->inlen > 0)
		return ProcessAdHocData(slist);
	return 0;
}
