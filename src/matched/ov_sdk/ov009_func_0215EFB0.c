/*
 * function: func_0215EFB0
 * address:  0x0215EFB0
 * packet:   pkt_ov009_0215EFB0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_GetStatus (libsoc.TWL.HYB.a(socl_poll.o))
 *
 * note:     state is spelled volatile: the only spelling found that reproduces the
 *           per-test ldrsh reloads (the vendor DWARF carries no volatile).
 *
 * symbols:
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_0215F080  0x0215F080  arm  ov009
 *   func_0215E2C0  0x0215E2C0  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef struct {
	unsigned char pad0[8];
	unsigned char type;
	unsigned char pad1[0xa3];
	volatile short state;
	signed char flag_block;
	signed char flag_mode;
} Socket;

extern int func_0215F3D0(Socket *socket);
extern unsigned long OS_DisableInterrupts(void);
extern int func_0215F080(char *p);
extern long func_0215E2C0(Socket *socket);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

static inline int IsStream(Socket *socket)
{
	int r = 1;
	if (socket->flag_mode != 0 && socket->flag_mode != 4) {
		r = 0;
	}
	return r;
}

int func_0215EFB0(int s)
{
	unsigned long enable;
	int result;
	Socket *socket;

	result = 0;
	socket = (Socket *)s;
	if (func_0215F3D0(socket)) {
		result |= 0x80;
	} else {
		if (socket->state & 0x40) {
			result |= 0x20;
		}
		if (socket->flag_mode == 1 || (socket->state & 4)) {
			enable = OS_DisableInterrupts();
			if (func_0215F080((char *)socket) > 0) {
				result |= 1;
			}
			if (func_0215E2C0(socket) > 0) {
				result |= 8;
			}
			OS_RestoreInterrupts(enable);
		}
		if (IsStream(socket)) {
			if ((socket->state & 4) && socket->type != 4) {
				if (!(result & 1)) {
					socket->state &= ~6;
				}
			}
			if (!(socket->state & 2)) {
				if (!(socket->state & 4)) {
					result |= 0x40;
				}
			}
		}
	}
	return result;
}
