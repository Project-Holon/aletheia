/*
 * function: SOCLi_ReadCPSBuffer
 * address:  0x0215DA34
 * packet:   pkt_ov009_0215DA34
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ReadCPSBuffer (libsoc.TWL.HYB.a(socl_read.o))
 *
 * symbols:
 *   (none)
 */

typedef struct {
    char pad0[8];
    unsigned char state;
    char pad9;
    unsigned short local_port;
    char padC[0xC];
    unsigned short remote_port;
    char pad1A[2];
    unsigned long remote_ip;
    char pad20[0x2C];
    unsigned char *buf;
    long total;
} CpSoc;

typedef struct {
    char pad0[0xC4];
    CpSoc *cpsoc;
    char padC8[0x30];
    long consumed;
} RecvPipe;

typedef struct {
    char pad0[0xA0];
    RecvPipe *recv_pipe;
} Socket;

unsigned char *SOCLi_ReadCPSBuffer(Socket *socket, long *buffer_len, unsigned short *local_port,
                             unsigned short *remote_port, unsigned long *remote_ip)
{
    RecvPipe *recv_pipe;
    CpSoc *cpsoc;
    long consumed;
    long len;

    recv_pipe = socket->recv_pipe;
    cpsoc = recv_pipe->cpsoc;
    consumed = recv_pipe->consumed;
    len = cpsoc->total - consumed;
    if (len >= 0) {
        *local_port = cpsoc->local_port;
        *remote_port = cpsoc->remote_port;
        *remote_ip = cpsoc->remote_ip;
        *buffer_len = len;
        if (len == 0 && cpsoc->state != 4)
            return 0;
    } else {
        *buffer_len = -1;
        return 0;
    }
    return cpsoc->buf + consumed;
}
