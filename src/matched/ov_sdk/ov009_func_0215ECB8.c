/*
 * function: SOCL_CloseAll
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
 *   SOCL_Close  0x0215E84C  arm  ov009
 *   SOCLiUDPSendSocket     0x021AA44C  data
 *   SOCLiSocketList     0x021AA4B4  data
 *   SOCLiTrashList     0x021AA4B8  data
 */

#include "../include/G_Sock.h"
#include "../include/G_021AA4B8.h"
#include "../include/G_Socket.h"

typedef struct Socket Socket;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int SOCL_Close(int s);
extern struct Sock *SOCLiUDPSendSocket;
extern struct Socket *SOCLiSocketList;
extern struct G_021AA4B8 *SOCLiTrashList;

int SOCL_CloseAll(void)
{
	unsigned long enable;
	Socket *socket;

	for (;;) {
		enable = OS_DisableInterrupts();
		for (socket = ((Socket *)SOCLiSocketList); socket != 0; socket = socket->next) {
			if (socket != ((Socket *)SOCLiUDPSendSocket) && (socket->state & 0x10) == 0) {
				break;
			}
		}
		OS_RestoreInterrupts(enable);
		if (socket == 0) {
			break;
		}
		SOCL_Close((int)socket);
	}
	if (((Socket *)SOCLiSocketList) == 0 || (((Socket *)SOCLiSocketList) == ((Socket *)SOCLiUDPSendSocket) && SOCLiSocketList->next == 0)) {
		if (((Socket *)SOCLiTrashList) == 0) {
			return 0;
		}
	}
	return -26;
}
