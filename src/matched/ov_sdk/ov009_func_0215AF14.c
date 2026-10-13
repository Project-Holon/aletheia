/*
 * function: CPSi_SocConsumeRaw
 * address:  0x0215AF14
 * packet:   pkt_ov009_0215AF14
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_SocConsumeRaw (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   OS_DisableInterrupts     0x02087988  arm
 *   MI_CpuMove               0x02083194  arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   OS_Terminate             0x02088234  arm
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   _tcp_send_ack            0x02159404  arm  ov009
 */

struct _CPSRwin {
	unsigned long start;
	unsigned long len;
	unsigned long pad;
};

struct _CPSSoc {
	unsigned char pad0[8];
	unsigned char state;            /* 0x08 */
	unsigned char pad9[0x3f];
	unsigned long rcvbufsize;       /* 0x48 */
	unsigned char *rcvbuf;          /* 0x4c */
	unsigned long rcvlen;           /* 0x50 */
	unsigned char pad54[0x1c];
	struct _CPSRwin rwin[4];        /* 0x70 */
};

extern unsigned long OS_DisableInterrupts(void);
extern void MI_CpuMove(void *srcp, void *destp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void OS_Terminate(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void _tcp_send_ack(struct _CPSSoc *soc, int flush);

void CPSi_SocConsumeRaw(unsigned long len, struct _CPSSoc *soc)
{
	unsigned char *d;
	unsigned char *s;
	unsigned long enabled;
	long ci;
	int was_full;
	unsigned long old;

	enabled = OS_DisableInterrupts();
	old = soc->rcvlen;
	was_full = 0;
	if (old == soc->rcvbufsize && len != 0)
		was_full = 1;
	if (len >= old) {
		soc->rcvlen = 0;
	} else {
		soc->rcvlen = old - len;
		MI_CpuMove(soc->rcvbuf + len, soc->rcvbuf, old - len);
	}
	if (soc->rwin[0].start != 0 && (old -= soc->rcvlen) != 0) {
		for (ci = 0; ci < 4 && soc->rwin[ci].start != 0; ci++)
			;
		if (soc->rwin[0].start > old) {
			s = soc->rcvbuf + soc->rwin[0].start;
			d = s - old;
			ci--;
			MI_CpuMove(s, d, soc->rwin[ci].start + soc->rwin[ci].len - soc->rwin[0].start);
			for (ci = 0; ci < 4 && soc->rwin[ci].start != 0; ci++)
				soc->rwin[ci].start -= old;
		} else {
			MI_CpuFill8(soc->rwin, 0, sizeof(soc->rwin));
			OS_Terminate();
		}
	}
	OS_RestoreInterrupts(enabled);
	if (soc->state != 0xa && soc->state != 0xb) {
		if (soc->rcvlen == 0 || was_full)
			_tcp_send_ack(soc, 0);
	}
}
