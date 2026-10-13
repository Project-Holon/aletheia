/*
 * file:     socl_bind.c
 * unit:     yes
 * function: func_0215D43C, func_0215D4AC, func_0215D5F8, func_0215D650
 * address:  0x0215D43C
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
 *   SOCL_SocketIsInvalid     0x0215f3d0 arm
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_0215D5F8  0x0215D5F8  arm  ov009
 *   g_021A82BC     0x021A82BC  data
 *   g_021A827C     0x021A827C  data
 *   g_021A1CE0     0x021A1CE0  data
 *   SOCLi_CreateCommandPacket           0x0215ce3c arm
 *   SOCLi_ExecCommandPacketInRecvPipe   0x0215cf88 arm
 *   SOCLi_BindCallBack                  0x0215d650 arm
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   CPS_SocBind  0x0215AAB0  arm  ov009
 *   CPS_TcpConnect  0x0215AC60  arm  ov009
 */
struct SOCLSocket_0215D43C {
    unsigned char pad[0xac];
    short field_ac;
    signed char field_ae;
    signed char field_af;
    unsigned short field_b0;
};

struct SOCLSocket_0215D4AC {
	unsigned char pad[0xa8];
	int result;
	volatile short state;
	signed char flag_block;
	signed char flag_mode;
	unsigned short local_port;
	unsigned short remote_port;
	unsigned long remote_ip;
};

struct SOCLSocket_0215D5F8 {
    unsigned char pad[0xac];
    short field_ac;
    signed char field_ae;
    signed char field_af;
    unsigned short field_b0;
    unsigned short field_b2;
    unsigned long field_b4;
};

struct SOCLiCommandPacket {
    int (*handler)(void *);
    struct SOCLSocket_0215D5F8 *socket;
    long field8;
    signed char fieldC;
    signed char fieldD;
    unsigned char padE[2];
    unsigned short field10;
    unsigned short field12;
    unsigned long field14;
};

typedef struct {
	unsigned char pad0[0xe0];
	unsigned char mutex[0x18];
	unsigned long result;
} RecvPipe;

typedef struct {
	unsigned char pad0[0xa0];
	RecvPipe *recv_pipe;
	unsigned char pad1[8];
	volatile short flags;
} Socket;

typedef struct {
	unsigned long pad0;
	Socket *socket;
	unsigned long pad1;
	signed char type;
	unsigned char pad2[3];
	unsigned short local_port;
	unsigned short remote_port;
	unsigned long remote_ip;
} CmdBind;

extern int SOCL_SocketIsInvalid(struct SOCLSocket_0215D43C *socket);
extern int func_0215F3D0(struct SOCLSocket_0215D4AC *socket);
extern int func_0215D5F8(struct SOCLSocket_0215D4AC *socket);
extern struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *),
                                                            struct SOCLSocket_0215D5F8 *socket,
                                                            long flag);
extern int SOCLi_ExecCommandPacketInRecvPipe(struct SOCLSocket_0215D5F8 *socket,
                                             struct SOCLiCommandPacket *command);
extern int SOCLi_BindCallBack(void *arg);
extern void func_02086028(void *mutex);
extern void func_02086078(void *mutex);
extern void CPS_SocBind(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long CPS_TcpConnect(void);
int SOCL_Bind(int s, unsigned short local_port);
int func_0215D4AC(int s, unsigned short remote_port, unsigned long remote_ip);
int func_0215D650(void *arg);
extern unsigned long g_021A82BC;
extern unsigned long g_021A827C;
extern int g_021A1CE0;


int SOCL_Bind(int s, unsigned short local_port)
{
    struct SOCLSocket_0215D43C *socket = (struct SOCLSocket_0215D43C *)s;

    if (SOCL_SocketIsInvalid(socket))
        return -0x1c;
    {
        int flag = 0;

        if (socket != 0)
            flag = (socket->field_ac & 1) != 0;
        if (flag == 0)
            return -0x27;
    }
    if (socket->field_ac & 2)
        return -7;
    socket->field_b0 = local_port;
    if (socket->field_af != 1)
        return 0;
    return SOCLi_ExecBindCommand(socket);
}


/*
 * sdk:      SOCL_Connect (libsoc.TWL.HYB.a(socl_bind.o))
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
int func_0215D4AC(int s, unsigned short remote_port, unsigned long remote_ip)
{
	struct SOCLSocket_0215D4AC *socket = (struct SOCLSocket_0215D4AC *)s;

	if (func_0215F3D0(socket) != 0 || (socket->state & 8))
		return -0x1c;
	{
		int flag = 0;

		if (socket != 0)
			flag = (socket->state & 1) != 0;
		if (flag == 0)
			return -0x27;
	}
	{
		int mode = 1;

		if (socket->flag_mode != 0 && socket->flag_mode != 4)
			mode = 0;
		if (mode != 0) {
		int bcast;

		if ((remote_ip & 0xf0000000) == 0xe0000000)
			goto invalid;
		if ((g_021A827C & (g_021A82BC ^ remote_ip)) != 0)
			bcast = remote_ip == 0xffffffff;
		else
			bcast = (~g_021A827C & remote_ip) == ~g_021A827C;
		if (bcast) {
invalid:
			return -0x1c;
		}
		if (socket->state & 4) {
			if (socket->flag_block == 1)
				return -0x1e;
			return 0;
		}
		if (socket->state & 2) {
			if (socket->state & 0x40)
				return socket->result;
			return g_021A1CE0;
		}
		socket->remote_port = remote_port;
		socket->remote_ip = remote_ip;
		{
			int r = func_0215D5F8(socket);

			if (socket->flag_block == 1)
				return r;
			if (r >= 0)
				return -0x1a;
			return r;
		}
		}
	}
	socket->remote_port = remote_port;
	socket->remote_ip = remote_ip;
	return 0;
}


static int SOCLi_ExecBindCommand(struct SOCLSocket_0215D5F8 *socket)
{
    struct SOCLiCommandPacket *command
        = SOCLi_CreateCommandPacket(SOCLi_BindCallBack, socket, socket->field_ae);

    if (command == 0)
        return -0x21;
    command->field10 = socket->field_b0;
    command->field12 = socket->field_b2;
    command->field14 = socket->field_b4;
    socket->field_ac |= 2;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, command);
}


/*
 * sdk:      SOCLi_BindCallBack (libsoc.TWL.HYB.a(socl_bind.o))
 *
 * note:     the socket state word is spelled volatile: the only spelling found that
 *           keeps the per-arm ldrsh/strh (the vendor DWARF carries no volatile).
 */
int func_0215D650(void *arg)
{
	CmdBind *cpacket;
	Socket *socket;
	RecvPipe *recv_pipe;
	unsigned long retcode;

	cpacket = (CmdBind *)arg;
	socket = cpacket->socket;
	retcode = 0;
	recv_pipe = socket->recv_pipe;
	func_02086028(recv_pipe->mutex);
	CPS_SocBind(cpacket->local_port, cpacket->remote_port, cpacket->remote_ip);
	recv_pipe->result = retcode;
	if (cpacket->type == 0 || cpacket->type == 4) {
		retcode = CPS_TcpConnect();
	}
	func_02086078(recv_pipe->mutex);
	if (retcode != 0) {
		socket->flags |= 0x40;
		return -76;
	}
	socket->flags |= 4;
	return 0;
}
