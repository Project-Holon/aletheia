/*
 * function: _tcp_send_handshake
 * address:  0x021593A8
 * packet:   pkt_ov009_021593A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _tcp_send_handshake (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   no_need_inq  0x0215938C  arm  ov009
 *   _send_tcp  0x02158714  arm  ov009
 *   get_targetip  0x021578C8  arm  ov009
 *   send_arprequest  0x02157E54  arm  ov009
 *   gMslRefToken  0x02150FEC  data
 *   g_021A86A4  0x021A86A4  data
 */

#include "../include/G_021A86A4.h"

extern char gMslRefToken[];
extern struct G_021A86A4 g_021A86A4;
extern unsigned long no_need_inq(unsigned long ip);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct _CPSSoc;
extern u32 _send_tcp(u8 *data, u32 len, struct _CPSSoc *soc, u8 flag);
extern unsigned long get_targetip(unsigned long ip);
extern void send_arprequest(unsigned long ip);

void _tcp_send_handshake(char *soc, unsigned char flag)
{
    if (no_need_inq(*(unsigned long *)(soc + 0x1c)) != 0 || *(char **)(gMslRefToken + 4) != ((char *)&g_021A86A4)) {
        _send_tcp(0, 0, (struct _CPSSoc *)soc, flag);
    } else {
        send_arprequest(get_targetip(*(unsigned long *)(soc + 0x1c)));
    }
}
