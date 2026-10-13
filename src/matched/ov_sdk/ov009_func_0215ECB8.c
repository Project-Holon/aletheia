/*
 * function: func_0215ECB8
 * address:  0x0215ECB8
 * packet:   pkt_ov009_0215ECB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_CloseAll (libsoc.TWL.HYB.a(socl_cleanup.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_0215E84C  0x0215E84C  arm  ov009
 *   g_021AA44C     0x021AA44C  data
 *   g_021AA4B4     0x021AA4B4  data
 *   g_021AA4B8     0x021AA4B8  data
 */

#include "../include/G_Sock.h"
#include "../include/G_021AA4B8.h"
#include "../include/G_Socket.h"

typedef struct Socket Socket;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int func_0215E84C(int s);
extern struct Sock *g_021AA44C;
extern struct Socket *g_021AA4B4;
extern struct G_021AA4B8 *g_021AA4B8;

int func_0215ECB8(void)
{
	unsigned long enable;
	Socket *socket;

	for (;;) {
		enable = OS_DisableInterrupts();
		for (socket = ((Socket *)g_021AA4B4); socket != 0; socket = socket->next) {
			if (socket != ((Socket *)g_021AA44C) && (socket->state & 0x10) == 0) {
				break;
			}
		}
		OS_RestoreInterrupts(enable);
		if (socket == 0) {
			break;
		}
		func_0215E84C((int)socket);
	}
	if (((Socket *)g_021AA4B4) == 0 || (((Socket *)g_021AA4B4) == ((Socket *)g_021AA44C) && g_021AA4B4->next == 0)) {
		if (((Socket *)g_021AA4B8) == 0) {
			return 0;
		}
	}
	return -26;
}
