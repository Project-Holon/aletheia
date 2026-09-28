/*
 * function: SOCL_IsReleased
 * address:  0x0215E7C8
 * packet:   pkt_ov009_0215E7C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_IsReleased (socl_close.o)
 *
 * symbols:
 *   OS_DisableInterrupts   0x02087988 arm
 *   SOCL_SocketIsInTrash   0x0215f404 arm
 *   OS_RestoreInterrupts   0x0208799c arm
 *   SOCL_SocketIsInvalid   0x0215f3d0 arm
 */

struct SOCLSocket {
    char pad[0xac];
    signed short flags;
};

extern unsigned long OS_DisableInterrupts(void);
extern int SOCL_SocketIsInTrash(struct SOCLSocket * socket);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int SOCL_SocketIsInvalid(struct SOCLSocket * socket);

int SOCL_IsReleased(int s)
{
    unsigned long enable;
    struct SOCLSocket * socket;

    if (s <= 0)
        return 0;
    enable = OS_DisableInterrupts();
    socket = (struct SOCLSocket *)s;
    if (SOCL_SocketIsInTrash(socket)) {
        OS_RestoreInterrupts(enable);
        return 0;
    }
    if (SOCL_SocketIsInvalid(socket)) {
        OS_RestoreInterrupts(enable);
        return 1;
    }
    if (socket->flags & 0x10) {
        OS_RestoreInterrupts(enable);
        return 0;
    }
    OS_RestoreInterrupts(enable);
    return 1;
}
