/*
 * function: func_0215D124
 * address:  0x0215D124
 * packet:   pkt_ov009_0215D124
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_CreateSocketCallBack (libsoc.TWL.HYB.a(socl_create.o))
 *
 * symbols:
 *   CPS_SocRegister  0x0215AA5C  arm  ov009
 *   CPS_SocDup  0x0215AB7C  arm  ov009
 *   CPS_SocUse  0x0215AB10  arm  ov009
 *   CPS_SocDatagramMode  0x0215AA88  arm  ov009
 *   CPS_SetUdpCallback  0x0215AB94  arm  ov009
 *   func_0215DF08  0x0215DF08  arm  ov009
 */

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

extern void CPS_SocRegister(int v);
extern void CPS_SocDup(void *thread);
extern void CPS_SocUse(void);
extern void CPS_SocDatagramMode(void);
extern void CPS_SetUdpCallback(int (*callback)(unsigned char *, unsigned long, void *));
struct CPSSoc;
extern int func_0215DF08(unsigned char *data, unsigned long len, struct CPSSoc *soc);

int func_0215D124(void *arg)
{
	Socket *socket;
	unsigned char *send_pipe;

	socket = ((Cmd *)arg)->socket;
	CPS_SocRegister((int)socket);
	send_pipe = socket->send_pipe;
	switch (socket->flag_mode) {
	case 0:
	case 4:
		CPS_SocDup(send_pipe + 0x20);
		CPS_SocUse();
		break;
	case 1:
		CPS_SocUse();
		CPS_SocDatagramMode();
		CPS_SetUdpCallback((int (*)(unsigned char *, long unsigned int,  void *))func_0215DF08);
		break;
	case 2:
		CPS_SocDatagramMode();
		break;
	}
	socket->state = 1;
	return 0;
}
