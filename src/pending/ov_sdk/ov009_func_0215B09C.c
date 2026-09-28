/*
 * function: tcp_write_do
 * address:  0x0215B09C
 * packet:   pkt_ov009_0215B09C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  184/192 bytes exact; only a 2-instruction schedule swap:
 *           original emits `sub r7,r0,#1` (limit = r - 1) before
 *           `cmp r4,#0` (the thislen==0 break test), the compiler here
 *           hoists the cmp above the sub. Same instruction multiset,
 *           same branch target. Tried: no temp (adds into r7, wrong),
 *           reordered ackrcvd_save/limit updates, !thislen. Source
 *           reuses one `thislen` local for the send result.
 *
 * sdk:      tcp_write_do (libcps.TWL.HYB.a network.o)
 * symbols:
 *   _send_tcp                        0x02158714 arm
 *   OS_YieldThread                   0x020858d8 arm
 *   wfailed                          0x021a826c data
 */

struct _CPSSoc {
	unsigned char pad0[8];
	unsigned char state;
	unsigned char pad1[0x2f];
	unsigned short remote_win;
	unsigned short remote_mss;
	unsigned char pad2[4];
	unsigned long ackrcvd;
};

extern unsigned long _send_tcp(unsigned char *data, unsigned long len, struct _CPSSoc *soc, unsigned char flag);
extern void OS_YieldThread(void);
extern unsigned char wfailed;

static unsigned long tcp_write_do(unsigned char *buf, unsigned long len, struct _CPSSoc *soc, int need_probe)
{
	unsigned long thislen;
	unsigned long remote_win;
	unsigned long ackrcvd_save = soc->ackrcvd;
	unsigned long limit;

	if (need_probe)
		remote_win = 1;
	else
		remote_win = soc->remote_win;
	limit = ackrcvd_save * 2 + 4;

	while (len != 0 && soc->state == 4) {
		unsigned long send_win = *(unsigned short *)((char *)&wfailed + 4);
		unsigned long ackno;
		unsigned long r;

		thislen = soc->remote_mss;
		if (thislen >= remote_win)
			thislen = remote_win;
		if (send_win < thislen)
			thislen = send_win;
		if (!need_probe)
			thislen &= ~1;
		if (len < thislen)
			thislen = len;
		ackno = soc->ackrcvd;
		r = limit + (ackno - ackrcvd_save);
		if (r == 0)
			thislen = 0;
		ackrcvd_save = ackno;
		limit = r - 1;
		if (!thislen)
			break;
		thislen = _send_tcp(buf, thislen, soc, 0x18);
		OS_YieldThread();
		remote_win -= thislen;
		buf += thislen;
		len -= thislen;
	}
	return thislen;
}
