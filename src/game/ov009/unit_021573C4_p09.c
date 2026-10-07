/*
 * file:     unit_021573C4_p09.c
 * unit:     yes
 * function: func_021593A8, func_02159404
 * address:  0x021593A8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215938C  0x0215938C  arm  ov009
 *   func_02158714  0x02158714  arm  ov009
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 *   g_021A86A4  0x021A86A4  data
 *   OS_GetTick                       0x020870d0 arm
 *   dacktimer_reschedule             0x0215bac0 arm
 *   _tcp_send_handshake              0x021593a8 arm
 */
#include "../../matched/include/G_021A86A4.h"

struct _CPSSoc;
typedef unsigned int   u32;

typedef unsigned char  u8;

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

extern unsigned long func_0215938C(unsigned long ip);
extern u32 func_02158714(u8 *data, u32 len, struct _CPSSoc *soc, u8 flag);
extern unsigned long func_021578C8(unsigned long ip);
extern void func_02157E54(unsigned long ip);
extern unsigned long long OS_GetTick(void);
extern void dacktimer_reschedule(void);
extern void _tcp_send_handshake(struct _CPSSoc *soc, unsigned char flag);
void func_021593A8(char *soc, unsigned char flag);
extern char g_02150FEC[];
extern struct G_021A86A4 g_021A86A4;


/*
 * sdk:      _tcp_send_handshake (libcps.TWL.HYB.a(network.o))
 */
void func_021593A8(char *soc, unsigned char flag)
{
    if (func_0215938C(*(unsigned long *)(soc + 0x1c)) != 0 || *(char **)(g_02150FEC + 4) != ((char *)&g_021A86A4)) {
        func_02158714(0, 0, (struct _CPSSoc *)soc, flag);
    } else {
        func_02157E54(func_021578C8(*(unsigned long *)(soc + 0x1c)));
    }
}


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
