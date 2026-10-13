/*
 * function: func_0215D650
 * address:  0x0215D650
 * packet:   pkt_ov009_0215D650
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_BindCallBack (libsoc.TWL.HYB.a(socl_bind.o))
 *
 * note:     the socket state word is spelled volatile: the only spelling found that
 *           keeps the per-arm ldrsh/strh (the vendor DWARF carries no volatile).
 *
 * symbols:
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   CPS_SocBind  0x0215AAB0  arm  ov009
 *   CPS_TcpConnect  0x0215AC60  arm  ov009
 */

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

extern void func_02086028(void *mutex);
extern void func_02086078(void *mutex);
extern void CPS_SocBind(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long CPS_TcpConnect(void);

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
