/*
 * file:     unit_0215F2DC_p02.c
 * unit:     yes
 * function: func_0215F334, func_0215F36C
 * address:  0x0215F334
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
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_0215F36C  0x0215F36C  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 */
struct SOCLSocket;
typedef struct Sock {
	char pad[0xb8];
	struct Sock *next;
} Sock;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern Sock **func_0215F36C(Sock **next, Sock *socket);
void func_0215F334(Sock **next, Sock *socket);
struct SOCLSocket **SOCLi_SocketGetNextPtr(struct SOCLSocket **next, struct SOCLSocket *socket);


/*
 * sdk:      SOCLi_SocketUnregisterList (libsoc.TWL.HYB.a(socl_list.o))
 */
void func_0215F334(Sock **next, Sock *socket)
{
	unsigned long enable;

	enable = OS_DisableInterrupts();
	next = func_0215F36C(next, socket);
	if (next)
		*next = socket->next;
	OS_RestoreInterrupts(enable);
}


struct SOCLSocket **SOCLi_SocketGetNextPtr(struct SOCLSocket **next,
                                           struct SOCLSocket *socket)
{
    struct SOCLSocket *t;
    unsigned long enable = OS_DisableInterrupts();

    t = *next;
    while (t != 0) {
        if (t == socket) {
            OS_RestoreInterrupts(enable);
            return next;
        }
        next = (struct SOCLSocket **)((char *)t + 0xb8);
        t = *next;
    }
    OS_RestoreInterrupts(enable);
    return 0;
}
