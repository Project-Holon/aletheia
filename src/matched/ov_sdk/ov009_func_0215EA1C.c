/*
 * function: func_0215EA1C
 * address:  0x0215EA1C
 * packet:   pkt_ov009_0215EA1C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_CleanupSocket (libsoc.TWL.HYB.a(socl_close.o))
 *
 * symbols:
 *   func_0215EB14  0x0215EB14  arm  ov009
 *   OS_WakeupThread  0x02085800  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_0215F31C  0x0215F31C  arm  ov009
 *   func_0215F3B8  0x0215F3B8  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gSoclConfig     0x021A1CD8  data
 */

#include "../include/G_021A1CD8.h"

typedef struct UdpData UdpData;
struct UdpData {
	UdpData *next;
};

typedef struct {
	unsigned long a;
	UdpData *head;
	unsigned short size;
	unsigned short pad;
	unsigned long queue[2];
} UdpControl;

typedef struct {
	unsigned char pad0[0x100];
	UdpControl udpdata;
} RecvPipe;

typedef struct {
	unsigned char pad0[0xa0];
	RecvPipe *recv_pipe;
	unsigned char *send_pipe;
	unsigned char pad1[4];
	short state;
	signed char flag_block;
	signed char flag_mode;
} Socket;

extern void func_0215EB14(unsigned char *pipe);
extern void OS_WakeupThread(void *queue);
extern unsigned long OS_DisableInterrupts(void);
extern void func_0215F31C(int a);
extern void func_0215F3B8(int a);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern struct G_021A1CD8 *gSoclConfig;

static inline int IsStream(Socket *socket)
{
	int r = 1;
	if (socket->flag_mode != 0 && socket->flag_mode != 4) {
		r = 0;
	}
	return r;
}

void func_0215EA1C(Socket *socket)
{
	UdpData *udpdata_next;
	UdpData *udpdata;
	unsigned long enable;

	if (socket == 0) {
		return;
	}
	socket->state = 0;
	if (IsStream(socket)) {
		func_0215EB14(socket->send_pipe);
		func_0215EB14((unsigned char *)socket->recv_pipe);
	} else if (socket->flag_mode == 1) {
		udpdata = socket->recv_pipe->udpdata.head;
		while (udpdata) {
			udpdata_next = udpdata->next;
			gSoclConfig->free(udpdata);
			udpdata = udpdata_next;
		}
		socket->recv_pipe->udpdata.size = 0;
		socket->recv_pipe->udpdata.a = 0;
		socket->recv_pipe->udpdata.head = 0;
		OS_WakeupThread(socket->recv_pipe->udpdata.queue);
		func_0215EB14((unsigned char *)socket->recv_pipe);
	} else if (socket->flag_mode == 2) {
		func_0215EB14(socket->send_pipe);
	}
	enable = OS_DisableInterrupts();
	func_0215F31C((int)socket);
	func_0215F3B8((int)socket);
	gSoclConfig->free(socket);
	OS_RestoreInterrupts(enable);
}
