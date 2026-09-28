/*
 * function: SOCLi_SocketGetNextPtr
 * address:  0x0215f36c
 * packet:   pkt_ov009_0215F36C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_SocketGetNextPtr (socl_list.o)
 *
 * symbols:
 *   OS_DisableInterrupts    0x02087988 arm
 *   OS_RestoreInterrupts    0x0208799c arm
 */

struct SOCLSocket;

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

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
