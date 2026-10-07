/*
 * function: func_021593A8
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
 *   func_0215938C  0x0215938C  arm  ov009
 *   func_02158714  0x02158714  arm  ov009
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 *   g_021A86A4  0x021A86A4  data
 */

#include "../include/G_021A86A4.h"

extern char g_02150FEC[];
extern struct G_021A86A4 g_021A86A4;
extern unsigned long func_0215938C(unsigned long ip);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct _CPSSoc;
extern u32 func_02158714(u8 *data, u32 len, struct _CPSSoc *soc, u8 flag);
extern unsigned long func_021578C8(unsigned long ip);
extern void func_02157E54(unsigned long ip);

void func_021593A8(char *soc, unsigned char flag)
{
    if (func_0215938C(*(unsigned long *)(soc + 0x1c)) != 0 || *(char **)(g_02150FEC + 4) != ((char *)&g_021A86A4)) {
        func_02158714(0, 0, (struct _CPSSoc *)soc, flag);
    } else {
        func_02157E54(func_021578C8(*(unsigned long *)(soc + 0x1c)));
    }
}
