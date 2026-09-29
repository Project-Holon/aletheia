/*
 * function: func_021A1254
 * address:  0x021A1254
 * packet:   pkt_ov009_021A1254
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * near miss (w3_s4): about 20 bytes differ, register naming only. Original keeps &port in ip and &ip in r7, loads buf[4],buf[5] first into r3/r2; the pointer temps in mine land in r7/r6 and the value temps in r5/lr. Block-scope pointer locals, static inline copy, struct copies and declaration swaps tried.
 *
 * sdk:      ProcessDeleteServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0219F6C8  0x0219F6C8  arm  ov009
 *   func_0219F768  0x0219F768  arm  ov009
 */

extern int func_0219F6C8(void *slist, unsigned int ip, unsigned short port);
extern void func_0219F768(void *slist, int index);
int func_021A1254(void *slist, unsigned char *buf, int len)
{
	int i;
	unsigned int ip;
	unsigned short port;
	if (len < 6)
		return 4;
	{
		unsigned char *pp = (unsigned char *)&port;
		unsigned char *pi = (unsigned char *)&ip;
		pp[0] = buf[4];
		pp[1] = buf[5];
		pi[0] = buf[0];
		pi[1] = buf[1];
		pi[2] = buf[2];
		pi[3] = buf[3];
	}
	i = func_0219F6C8(slist, ip, port);
	if (i == -1)
		return 0;
	func_0219F768(slist, i);
	return 0;
}
