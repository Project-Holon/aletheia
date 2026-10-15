/*
 * function: SOCLi_ConsumeCPSBuffer
 * address:  0x0215DD88
 * packet:   pkt_ov009_0215DD88
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ConsumeCPSBuffer (libsoc.TWL.HYB.a(socl_read.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   CPS_SocConsume  0x0215B064  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 */

typedef struct {
    char pad0[0xF8];
    long consumed;
} RecvPipe;

typedef struct {
    char pad0[0xA0];
    RecvPipe *recv_pipe;
} Socket;

extern unsigned long OS_DisableInterrupts(void);
extern void CPS_SocConsume(unsigned long len);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

long SOCLi_ConsumeCPSBuffer(Socket *socket)
{
    RecvPipe *recv_pipe;
    unsigned long enable;
    long consumed;

    recv_pipe = socket->recv_pipe;
    enable = OS_DisableInterrupts();
    consumed = recv_pipe->consumed;
    if (consumed != 0) {
        recv_pipe->consumed = 0;
        CPS_SocConsume(consumed);
    }
    OS_RestoreInterrupts(enable);
    return consumed;
}
