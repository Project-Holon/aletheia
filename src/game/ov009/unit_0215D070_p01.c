/*
 * file:     unit_0215D070_p01.c
 * unit:     yes
 * function: func_0215D070, func_0215D124, func_0215D198, func_0215D200
 * address:  0x0215D070
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
 *   SOCLi_StartupSocket                0x0215d198 arm
 *   SOCLi_CreateCommandPacket          0x0215ce3c arm
 *   SOCLi_ExecCommandPacketInCtrlPipe  0x0215cfa8 arm
 *   SOCLiConfigPtr                     0x021a1cd8 data
 *   SOCLi_CreateSocketCallBack         0x0215d124 arm
 *   SOCLi_Resource                     0x021aa4ac data
 *   func_0215AA5C  0x0215AA5C  arm  ov009
 *   func_0215AB7C  0x0215AB7C  arm  ov009
 *   func_0215AB10  0x0215AB10  arm  ov009
 *   func_0215AA88  0x0215AA88  arm  ov009
 *   func_0215AB94  0x0215AB94  arm  ov009
 *   func_0215DF08  0x0215DF08  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0215D2A8  0x0215D2A8  arm  ov009
 *   func_0215F2DC  0x0215F2DC  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021A1CD8  0x021A1CD8  data
 *   func_0215F0C8  0x0215F0C8  arm  ov009
 *   func_0215D280  0x0215D280  arm  ov009
 */
#include "../../matched/include/G_021A1CD8.h"

struct SOCLSocketParam;
struct SOCLiCommandPacket;
struct CPSSoc;
struct SOCLSocket {
    unsigned char pad[0xac];
    short field_ac;
    signed char field_ae;
    signed char field_af;
};

struct SOCLiResource {
    unsigned long count0;
    unsigned long count4;
};

typedef struct {
	unsigned char pad0[0xa4];
	unsigned char *send_pipe;
	unsigned char pad1[4];
	short state;
	signed char flag_block;
	signed char flag_mode;
} Socket;

typedef struct {
	unsigned long pad0;
	Socket *socket;
} Cmd;

typedef struct {
	unsigned char a;
	unsigned char b;
	unsigned short send;
	unsigned short f4;
	unsigned short recv;
	unsigned short sendbuf;
	unsigned short rbuf1;
	unsigned short rbuf2;
	unsigned short cfg;
	unsigned char pipe1[4];
	unsigned char pipe2[4];
} Param;

extern struct SOCLSocket *SOCLi_StartupSocket(struct SOCLSocketParam *param);
extern struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                            struct SOCLSocket *socket,
                                                            long flag);
extern int SOCLi_ExecCommandPacketInCtrlPipe(struct SOCLSocket *socket,
                                             struct SOCLiCommandPacket *command);
extern int SOCLi_CreateSocketCallBack(void *arg);
extern void func_0215AA5C(int v);
extern void func_0215AB7C(void *thread);
extern void func_0215AB10(void);
extern void func_0215AA88(void);
extern void func_0215AB94(int (*callback)(unsigned char *, unsigned long, void *));
extern int func_0215DF08(unsigned char *data, unsigned long len, struct CPSSoc *soc);
extern unsigned long OS_DisableInterrupts(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern unsigned char *func_0215D2A8(void *socket, void *param);
extern void func_0215F2DC(int a);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned long func_0215F0C8(unsigned long size);
extern unsigned long func_0215D280(void *param);
int SOCL_CreateSocket(struct SOCLSocketParam *param);
int func_0215D124(void *arg);
void *func_0215D198(void *param);
unsigned long func_0215D200(Param *param);
extern void *SOCLiConfigPtr;
extern struct SOCLiResource SOCLi_Resource;
extern struct G_021A1CD8 *g_021A1CD8;


int SOCL_CreateSocket(struct SOCLSocketParam *param)
{
    struct SOCLSocket *socket;
    struct SOCLiCommandPacket *command;

    if (SOCLiConfigPtr == 0)
        return -0x27;
    socket = SOCLi_StartupSocket(param);
    if (socket == 0)
        return -0x31;
    command = SOCLi_CreateCommandPacket(SOCLi_CreateSocketCallBack, socket, 1);
    SOCLi_ExecCommandPacketInCtrlPipe(socket, command);
    {
        int flag = 0;

        if (socket != 0) {
            if (socket->field_ac & 1)
                flag = 1;
            else
                flag = 0;
        }
        if (flag != 0) {
            int b = (socket->field_af == 0 || socket->field_af == 4);

            if (b)
                SOCLi_Resource.count0++;
            else
                SOCLi_Resource.count4++;
        }
    }
    return (int)socket;
}


/*
 * sdk:      SOCLi_CreateSocketCallBack (libsoc.TWL.HYB.a(socl_create.o))
 */
int func_0215D124(void *arg)
{
	Socket *socket;
	unsigned char *send_pipe;

	socket = ((Cmd *)arg)->socket;
	func_0215AA5C((int)socket);
	send_pipe = socket->send_pipe;
	switch (socket->flag_mode) {
	case 0:
	case 4:
		func_0215AB7C(send_pipe + 0x20);
		func_0215AB10();
		break;
	case 1:
		func_0215AB10();
		func_0215AA88();
		func_0215AB94((int (*)(unsigned char *, long unsigned int,  void *))func_0215DF08);
		break;
	case 2:
		func_0215AA88();
		break;
	}
	socket->state = 1;
	return 0;
}


void *func_0215D198(void *param)
{
	void *socket;
	unsigned long enable;
	unsigned long size;

	size = func_0215D200(param);
	enable = OS_DisableInterrupts();
	socket = g_021A1CD8->alloc(size);
	if (socket) {
		MI_CpuFill8(socket, 0, size);
		func_0215D2A8(socket, param);
		func_0215F2DC((int)socket);
	}
	OS_RestoreInterrupts(enable);
	return socket;
}


/*
 * sdk:      SOCLi_GetSizeSocket (libsoc.TWL.HYB.a(socl_create.o))
 */
unsigned long func_0215D200(Param *param)
{
	unsigned long size;

	size = 0xbc;
	if (param->send) {
		size += 0x114;
		size += func_0215F0C8(param->send);
		size += func_0215F0C8(param->sendbuf);
		size += func_0215D280(param->pipe1);
	}
	if (param->recv) {
		size += 0x110;
		size += func_0215F0C8(param->recv);
		size += func_0215F0C8(param->rbuf1);
		size += func_0215F0C8(param->rbuf2);
		size += func_0215D280(param->pipe2);
	}
	return size;
}
