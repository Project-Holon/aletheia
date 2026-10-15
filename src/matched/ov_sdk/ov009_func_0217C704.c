/*
 * function: func_0217C704
 * address:  0x0217C704
 * packet:   pkt_ov009_0217C704
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SendPacket (gsavailable.o)
 *
 * symbols:
 *   sendto  0x0217ECA4  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   g_021ACF7C     0x021ACF7C  data
 *   g_021ACF80     0x021ACF80  data
 *   g_021ACF88     0x021ACF88  data
 */

#include "../include/G_SOCSockAddrIn.h"

typedef struct {
    int sock;
    char pad[0x48];
    int len;
    int time;
} AC;
extern AC g_021ACF7C;
extern struct SOCSockAddrIn g_021ACF80;
extern char g_021ACF88[];
struct SOCSockAddr;
extern int sendto(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
extern unsigned int current_time(void);

void func_0217C704(void)
{
    sendto(g_021ACF7C.sock, g_021ACF88, g_021ACF7C.len, 0, (struct SOCSockAddr *)((char *)&g_021ACF80), 8);
    g_021ACF7C.time = current_time();
}
