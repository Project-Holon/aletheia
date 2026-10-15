/*
 * function: SOCL_Connect
 * address:  0x0215D4AC
 * packet:   pkt_ov009_0215D4AC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_Connect (libsoc.TWL.HYB.a(socl_bind.o))
 *
 * symbols:
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_0215D5F8  0x0215D5F8  arm  ov009
 *   gCpsMyIp     0x021A82BC  data
 *   gCpsNetMask     0x021A827C  data
 *   gSoclBindConst     0x021A1CE0  data
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

struct SOCLSocket {
	unsigned char pad[0xa8];
	int result;
	volatile short state;
	signed char flag_block;
	signed char flag_mode;
	unsigned short local_port;
	unsigned short remote_port;
	unsigned long remote_ip;
};

extern unsigned long gCpsMyIp;
extern unsigned long gCpsNetMask;
extern int gSoclBindConst;

extern int func_0215F3D0(struct SOCLSocket *socket);
extern int func_0215D5F8(struct SOCLSocket *socket);

int SOCL_Connect(int s, unsigned short remote_port, unsigned long remote_ip)
{
	struct SOCLSocket *socket = (struct SOCLSocket *)s;

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
		if ((gCpsNetMask & (gCpsMyIp ^ remote_ip)) != 0)
			bcast = remote_ip == 0xffffffff;
		else
			bcast = (~gCpsNetMask & remote_ip) == ~gCpsNetMask;
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
			return gSoclBindConst;
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
