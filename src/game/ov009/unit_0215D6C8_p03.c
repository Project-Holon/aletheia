/*
 * file:     unit_0215D6C8_p03.c
 * unit:     yes
 * function: func_0215DD78, func_0215DD88, func_0215DDC4, func_0215DF08
 * address:  0x0215DD78
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
 *   SOCLi_ConsumeCPSBuffer  0x0215DD88  arm
 *   func_02087988  0x02087988  arm
 *   CPS_SocConsume  0x0215B064  arm  ov009
 *   func_0208799C  0x0208799C  arm
 *   func_020857B0  0x020857B0  arm
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   g_021A1CD8  0x021A1CD8  data
 *   func_02085800  0x02085800  arm
 *   g_021AA4A4     0x021AA4A4  data
 */
#include "../../matched/include/G_021A1CD8.h"

typedef struct {
    char pad0[0xF8];
    long consumed;
} RecvPipe;

typedef struct {
    char pad0[0xA0];
    RecvPipe *recv_pipe;
} Socket;

struct SOCLiSocketUdpData {
    struct SOCLiSocketUdpData *next;
    unsigned short size;
    unsigned short remote_port;
    unsigned long remote_ip;
};

struct SOCLiSocketRecvCommandPipe {
    unsigned char pad0[0xf8];
    long consumed;
    unsigned short consumed_min;
    signed char flag_noconsume;
    unsigned char padding[1];
    struct SOCLiSocketUdpData *tail;
    struct SOCLiSocketUdpData *head;
    unsigned short recv_size;
    unsigned char pad10a[2];
    struct { void *head; void *tail; } waiting;
};

struct SOCLSocket {
    unsigned char pad0[0xa0];
    struct SOCLiSocketRecvCommandPipe *recv_pipe;
    unsigned char pada4[0xac - 0xa4];
    short state;
    signed char flag_block;
    signed char flag_mode;
};

struct SOCLiUdpData {
	struct SOCLiUdpData *next;
	unsigned short len;
	unsigned short remote_port;
	unsigned long remote_ip;
	unsigned char data[1];
};

struct SOCLRecvPipe {
	unsigned char pad[0x100];
	struct SOCLiUdpData *volatile last;
	struct SOCLiUdpData *first;
	unsigned short used;
	unsigned short limit;
	unsigned char queue[1];
};

struct CPSSoc {
	unsigned char pad0[0xa];
	unsigned short local_port;
	unsigned char padc[0x18 - 0xc];
	unsigned short remote_port;
	unsigned short remote_port2;
	unsigned long remote_ip;
	unsigned long remote_ip2;
	unsigned char pad24[0xa0 - 0x24];
	struct SOCLRecvPipe *recv_pipe;
	unsigned char pada4[0xb0 - 0xa4];
	unsigned short socket_port;
};

extern void SOCLi_ConsumeCPSBuffer(void *next);
extern unsigned long func_02087988(void);
extern void CPS_SocConsume(unsigned long len);
extern unsigned long func_0208799C(unsigned long state);
extern void func_020857B0(void *queue);
extern int func_0215F3D0(struct SOCLSocket *socket);
extern void func_02082EA4(void *srcp, void *destp, unsigned long size);
extern void func_02085800(void *queue);
void DWCi_LSTlPopFront(void *list);
long func_0215DD88(Socket *socket);
int func_0215DF08(unsigned char *data, unsigned long len, struct CPSSoc *soc);
extern struct G_021A1CD8 *g_021A1CD8;
extern unsigned long g_021AA4A4[2];


void DWCi_LSTlPopFront(void *list)
{
    SOCLi_ConsumeCPSBuffer(*(void **)((char *)list + 4));
}


/*
 * sdk:      SOCLi_ConsumeCPSBuffer (libsoc.TWL.HYB.a(socl_read.o))
 */
long func_0215DD88(Socket *socket)
{
    RecvPipe *recv_pipe;
    unsigned long enable;
    long consumed;

    recv_pipe = socket->recv_pipe;
    enable = func_02087988();
    consumed = recv_pipe->consumed;
    if (consumed != 0) {
        recv_pipe->consumed = 0;
        CPS_SocConsume(consumed);
    }
    func_0208799C(enable);
    return consumed;
}


static inline int isNotReady(struct SOCLSocket *socket)
{
    int r = 0;
    if (socket != 0)
        r = (socket->state & 1) ? 1 : 0;
    return r;
}


/*
 * sdk:      SOCLi_ReadUdpBuffer (socl_read.o)
 */
static int func_0215DDC4(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
                         unsigned long *remote_ip, long flag_block)
{
    unsigned long enable;
    struct SOCLiSocketRecvCommandPipe *pipe;
    struct SOCLiSocketUdpData *udpdata;
    int result;

    pipe = socket->recv_pipe;
    enable = func_02087988();
    udpdata = pipe->head;
    if (udpdata == 0) {
        for (;;) {
            if (!(flag_block & 1)) {
                result = -6;
                break;
            }
            func_020857B0(&pipe->waiting);
            if (func_0215F3D0(socket) || !isNotReady(socket)) {
                result = -0x38;
                break;
            }
            udpdata = pipe->head;
            if (udpdata != 0)
                break;
        }
    }
    if (udpdata != 0) {
        if (buffer_len > udpdata->size)
            buffer_len = udpdata->size;
        func_02082EA4(udpdata + 1, buffer, buffer_len);
        if (remote_port)
            *remote_port = udpdata->remote_port;
        if (remote_ip)
            *remote_ip = udpdata->remote_ip;
        result = udpdata->size;
        if (!pipe->flag_noconsume) {
            pipe->head = udpdata->next;
            if (udpdata->next == 0)
                pipe->tail = 0;
            g_021A1CD8->free(udpdata);
            pipe->recv_size -= (unsigned short)result;
        }
    }
    func_0208799C(enable);
    return result;
}


/*
 * sdk:      SOCLi_UdpRecvCallback (libsoc.TWL.HYB.a(socl_read.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
int func_0215DF08(unsigned char *data, unsigned long len, struct CPSSoc *soc)
{
	struct SOCLRecvPipe *pipe = soc->recv_pipe;
	struct SOCLiUdpData *udpheader;
	unsigned long enable;

	enable = func_02087988();
	if (pipe->limit >= pipe->used + len) {
		udpheader = g_021A1CD8->alloc(len + 12);
		if (udpheader != 0) {
			pipe->used += len;
			udpheader->next = 0;
			udpheader->len = len;
			udpheader->remote_port = soc->remote_port;
			udpheader->remote_ip = soc->remote_ip;
			func_02082EA4(data, udpheader->data, len);
			if (pipe->last != 0)
				pipe->last->next = udpheader;
			pipe->last = udpheader;
			if (pipe->first == 0)
				pipe->first = udpheader;
		} else {
			g_021AA4A4[0]++;
		}
	} else {
		g_021AA4A4[1]++;
	}
	soc->remote_port = soc->remote_port2;
	soc->remote_ip = soc->remote_ip2;
	if (soc->socket_port == 0)
		soc->socket_port = soc->local_port;
	func_02085800(pipe->queue);
	func_0208799C(enable);
	return 1;
}
