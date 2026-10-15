/*
 * function: tcp_write_do
 * address:  0x0215B09C
 * packet:   pkt_ov009_0215B09C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      tcp_write_do (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   _send_tcp  0x02158714  arm  ov009
 *   OS_YieldThread  0x020858D8  arm
 *   gCpsNetVars  0x021A826C  data
 */

struct Soc {
	unsigned char pad0[8];
	unsigned char state;
	unsigned char pad1[0x2f];
	unsigned short remote_win;
	unsigned short remote_mss;
	unsigned char pad2[4];
	unsigned long ackrcvd;
};

struct NetVars {
	unsigned char pad0[4];
	unsigned short send_win;
};

typedef unsigned int   u32;
typedef unsigned char  u8;
struct _CPSSoc;
extern u32 _send_tcp(u8 *data, u32 len, struct _CPSSoc *soc, u8 flag);
extern void OS_YieldThread(void);
extern struct NetVars gCpsNetVars;

unsigned long tcp_write_do(unsigned char *buf, unsigned long len, struct Soc *soc, int need_probe)
{
	unsigned long thislen;
	unsigned long remote_win;
	unsigned long ackrcvd_save;
	unsigned long limit;
	unsigned long r;
	unsigned long ackno;

	ackrcvd_save = soc->ackrcvd;
	if (need_probe)
		remote_win = 1;
	else
		remote_win = soc->remote_win;
	limit = ackrcvd_save * 2 + 4;
	while (len != 0 && soc->state == 4) {
		thislen = soc->remote_mss;
		if (thislen >= remote_win)
			thislen = remote_win;
		if (gCpsNetVars.send_win < thislen)
			thislen = gCpsNetVars.send_win;
		if (!need_probe)
			thislen &= ~1;
		if (len < thislen)
			thislen = len;
		ackno = soc->ackrcvd;
		limit += ackno - ackrcvd_save;
		r = limit;
		limit = r - 1;
		ackrcvd_save = ackno;
		if (r == 0)
			thislen = 0;
		if (thislen == 0)
			break;
		thislen = _send_tcp(buf, thislen, (struct _CPSSoc *)soc, 0x18);
		OS_YieldThread();
		remote_win -= thislen;
		buf += thislen;
		len -= thislen;
	}
	return thislen;
}
