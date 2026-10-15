/*
 * function: SOCLi_SocketUnregisterList
 * address:  0x0215F334
 * packet:   pkt_ov009_0215F334
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_SocketUnregisterList (libsoc.TWL.HYB.a(socl_list.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_0215F36C  0x0215F36C  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef struct Sock {
	char pad[0xb8];
	struct Sock *next;
} Sock;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern Sock **func_0215F36C(Sock **next, Sock *socket);

void SOCLi_SocketUnregisterList(Sock **next, Sock *socket)
{
	unsigned long enable;

	enable = OS_DisableInterrupts();
	next = func_0215F36C(next, socket);
	if (next)
		*next = socket->next;
	OS_RestoreInterrupts(enable);
}
