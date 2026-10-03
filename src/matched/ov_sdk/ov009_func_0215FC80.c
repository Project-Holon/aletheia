/*
 * function: func_0215FC80
 * address:  0x0215FC80
 * packet:   pkt_ov009_0215FC80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_EnableSsl (libsoc.TWL.HYB.a(socl_ssl.o))
 *
 * symbols:
 *   func_0215F3D0  0x0215F3D0  arm  ov009
 *   func_0215FD00  0x0215FD00  arm  ov009
 */

typedef struct {
	char pad0[0xac];
	short state;
	signed char flag_block;
	signed char flag_mode;
} Sock;

extern int func_0215F3D0(Sock *socket);
extern int func_0215FD00(void *socket, void *con);

static inline int isReady(Sock *s)
{
	return s->flag_mode == 0 || s->flag_mode == 4;
}

static inline int isOpen(Sock *s)
{
	int r = 0;
	if (s) r = (s->state & 1) ? 1 : 0;
	return r;
}

int func_0215FC80(int s, void *con)
{
	Sock *socket = (Sock *)s;

	if (func_0215F3D0(socket)) {
		return -28;
	}
	if (!isReady(socket)) {
		return -28;
	}
	if (!isOpen(socket)) {
		return -39;
	}
	if (socket->state & 2) {
		return -28;
	}
	return func_0215FD00(socket, con);
}
