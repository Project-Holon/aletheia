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
 *   func_02085800  0x02085800  arm
 *   func_02087988  0x02087988  arm
 *   func_0215F31C  0x0215F31C  arm  ov009
 *   func_0215F3B8  0x0215F3B8  arm  ov009
 *   func_0208799C  0x0208799C  arm
 *   g_021A1CD8     0x021A1CD8  data
 */

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

typedef struct {
	unsigned char pad0[0x1c];
	void (*func1c)(void *);
} Config;

extern void func_0215EB14(unsigned char *pipe);
extern void func_02085800(void *queue);
extern unsigned long func_02087988(void);
extern void func_0215F31C(int a);
extern void func_0215F3B8(int a);
extern unsigned long func_0208799C(unsigned long state);
extern Config *g_021A1CD8;

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
			g_021A1CD8->func1c(udpdata);
			udpdata = udpdata_next;
		}
		socket->recv_pipe->udpdata.size = 0;
		socket->recv_pipe->udpdata.a = 0;
		socket->recv_pipe->udpdata.head = 0;
		func_02085800(socket->recv_pipe->udpdata.queue);
		func_0215EB14((unsigned char *)socket->recv_pipe);
	} else if (socket->flag_mode == 2) {
		func_0215EB14(socket->send_pipe);
	}
	enable = func_02087988();
	func_0215F31C((int)socket);
	func_0215F3B8((int)socket);
	g_021A1CD8->func1c(socket);
	func_0208799C(enable);
}
