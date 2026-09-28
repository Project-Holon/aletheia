/*
 * function: _tcp_send_ack
 * address:  0x02159404
 * packet:   pkt_ov009_02159404
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _tcp_send_ack (libcps.TWL.HYB.a network.o)
 * symbols:
 *   OS_GetTick                       0x020870d0 arm
 *   dacktimer_reschedule             0x0215bac0 arm
 *   _tcp_send_handshake              0x021593a8 arm
 */

struct _CPSSoc {
	unsigned char pad0[0x24];
	unsigned long ackno;
	unsigned long ackno_sent;
	unsigned long tick_acked;
	unsigned short win_sent;
	unsigned char ack_pending;
	unsigned char pad1[0x15];
	unsigned long rcvbuf;
	unsigned char pad2[4];
	unsigned long rcvbufp;
};

extern unsigned long long OS_GetTick(void);
extern void dacktimer_reschedule(void);
extern void _tcp_send_handshake(struct _CPSSoc *soc, unsigned char flag);

static void _tcp_send_ack(struct _CPSSoc *soc, int flush)
{
	if (flush == 2)
		goto send;
	if (soc->ackno_sent == soc->ackno &&
	    soc->win_sent == (unsigned short)(soc->rcvbuf - soc->rcvbufp))
		return;
	if (flush == 1)
		goto send;
	soc->ack_pending++;
	if ((unsigned char)soc->ack_pending >= 2)
		goto send;
	if ((unsigned long)OS_GetTick() - soc->tick_acked >= 0x1991b)
		goto send;
	dacktimer_reschedule();
	return;

send:
	_tcp_send_handshake(soc, 0x10);
}

