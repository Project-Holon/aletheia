/*
 * function: func_0215E2E4
 * address:  0x0215E2E4
 * packet:   pkt_ov009_0215E2E4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_ExecWriteCommand (socl_write.o)
 *
 * symbols:
 *   func_0215CE3C  0x0215CE3C  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   func_0215A970  0x0215A970  arm  ov009
 *   func_0215CF98  0x0215CF98  arm  ov009
 *   func_0215E450  0x0215E450  arm  ov009
 */

struct SOCLiCommandPacket;

struct SOCLSocket {
    struct { unsigned char pad0[0xa]; unsigned short local_port; unsigned char padc[0xa0 - 0xc]; } cps_socket;
    void *recv_pipe;
    struct SOCLiSocketSendCommandPipe *send_pipe;
    unsigned char pada8[0xaf - 0xa8];
    signed char flag_mode;
    unsigned short local_port;
    unsigned short remote_port;
    unsigned long remote_ip;
};

struct SOCLiCommandPacket {
    int (*handler)(void *);
    struct SOCLSocket *socket;
    long field8;
    signed char fieldC;
    signed char fieldD;
    unsigned char padE[2];
    unsigned char *buf1;
    long len1;
    unsigned char *buf2;
    long len2;
    unsigned short buffer_in;
    unsigned short pad22;
    unsigned short local_port;
    unsigned short remote_port;
    unsigned long remote_ip;
};

struct SOCLiSocketRingBuffer {
    long size;
    unsigned char *area;
    unsigned short in;
    unsigned short out;
    unsigned char pad8[8];
};

struct SOCLiSocketSendCommandPipe {
    unsigned char pad0[0xf8];
    struct SOCLiSocketRingBuffer buffer;
    struct SOCLSocket *exe_socket;
};

extern struct SOCLiCommandPacket *func_0215CE3C(int (*handler)(void *), struct SOCLSocket *socket, long flag);
extern void func_02082EA4(void *srcp, void *destp, unsigned long size);
extern unsigned short func_0215A970(void);
extern int func_0215CF98(struct SOCLSocket *socket, struct SOCLiCommandPacket *command);
extern int func_0215E450(void *arg);

static int func_0215E2E4(struct SOCLSocket *socket, unsigned char *buffer, long buffer_len, long wrtbuf_in,
                         unsigned short remote_port, unsigned long remote_ip, long flag_block)
{
    struct SOCLiSocketSendCommandPipe *send_pipe = socket->send_pipe;
    struct SOCLiCommandPacket *command;
    unsigned short saved_send_buffer_in;
    long wrtbuf_size;
    unsigned char *wrtbuf;
    int result;

    command = func_0215CE3C(func_0215E450, send_pipe->exe_socket, flag_block);
    if (command == 0)
        return -0x21;
    if ((flag_block & 1) && socket->flag_mode != 1)
        command->fieldD = 3;
    else
        command->fieldD = 0;
    wrtbuf_size = send_pipe->buffer.size;
    wrtbuf = send_pipe->buffer.area;
    if (wrtbuf_in + buffer_len < wrtbuf_size) {
        command->buf1 = wrtbuf + wrtbuf_in;
        command->len1 = buffer_len;
        command->buf2 = 0;
        command->len2 = 0;
        wrtbuf_in += buffer_len;
    } else {
        command->buf1 = wrtbuf + wrtbuf_in;
        command->len1 = wrtbuf_size - wrtbuf_in;
        wrtbuf_in = buffer_len - command->len1;
        command->buf2 = wrtbuf;
        command->len2 = wrtbuf_in;
        func_02082EA4(buffer + command->len1, command->buf2, command->len2);
    }
    func_02082EA4(buffer, command->buf1, command->len1);
    saved_send_buffer_in = send_pipe->buffer.in;
    command->buffer_in = wrtbuf_in;
    send_pipe->buffer.in = command->buffer_in;
    if (socket->flag_mode == 1) {
        if (socket->local_port == 0) {
            socket->local_port = func_0215A970();
            socket->cps_socket.local_port = socket->local_port;
        }
        command->local_port = socket->local_port;
        if (socket->remote_ip == 0 || remote_ip != 0) {
            command->remote_ip = remote_ip;
            command->remote_port = remote_port;
        } else {
            command->remote_ip = socket->remote_ip;
            command->remote_port = socket->remote_port;
        }
    } else {
        command->remote_ip = 0;
    }
    result = func_0215CF98(send_pipe->exe_socket, command);
    if (result) {
        send_pipe->buffer.in = saved_send_buffer_in;
        buffer_len = 0;
    }
    return buffer_len;
}
