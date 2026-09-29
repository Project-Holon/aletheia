/*
 * function: func_0215D92C
 * address:  0x0215D92C
 * packet:   pkt_ov009_0215D92C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * pending:  near miss, 2 branch-shape diffs (flag_fe update if-converted, -0x1c mvn/moveq order)
 *
 * sdk:      SOCLi_CopyCPSBuffer (libsoc.TWL.HYB.a(socl_read.o))
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0215DA34  0x0215DA34  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   func_0208799C  0x0208799C  arm
 */

struct SOCLRecvPipe {
	unsigned char pad[0xf8];
	long received;
	unsigned char padfc[2];
	signed char flag_fe;
};

struct SOCLSocket {
	unsigned char pad[0xa0];
	struct SOCLRecvPipe *recv_pipe;
	unsigned char pada4[8];
	short state;
	signed char flag_block;
	signed char flag_mode;
	unsigned short local_port;
};

extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern unsigned char *func_0215DA34(struct SOCLSocket *socket, long *buffer_len, unsigned short *local_port,
				    unsigned short *remote_port, unsigned long *remote_ip);
extern void func_02082EA4(void *srcp, void *destp, unsigned long size);

static int func_0215D92C(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port,
			 unsigned long *remote_ip)
{
	unsigned long enable;
	unsigned char *cpsbuffer;
	long cpsbuffer_len;
	unsigned short my_port;
	unsigned short his_port;
	unsigned long his_ip;
	int result;

	enable = func_02087988();
	cpsbuffer = func_0215DA34(socket, &cpsbuffer_len, &my_port, &his_port, &his_ip);
	if (cpsbuffer != 0) {
		result = cpsbuffer_len;
		if (result == 0) {
			result = -6;
		} else {
			int dgram = 1;

			if (buffer_len > result)
				buffer_len = result;
			if (socket->flag_mode != 0 && socket->flag_mode != 4)
				dgram = 0;
			if (dgram != 0)
				result = buffer_len;
			func_02082EA4(cpsbuffer, buffer, buffer_len);
			{
				struct SOCLRecvPipe *recv_pipe = socket->recv_pipe;

				if (recv_pipe->flag_fe == 0)
					recv_pipe->received += result;
			}
		}
	} else {
		result = cpsbuffer_len != 0 ? -0x1c : 0;
		socket->state &= ~6;
	}
	if (result >= 0) {
		if (remote_port != 0 && remote_ip != 0) {
			*remote_port = his_port;
			*remote_ip = his_ip;
		}
		if (socket->local_port == 0)
			socket->local_port = my_port;
	}
	func_0208799C(enable);
	return result;
}
