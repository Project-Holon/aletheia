/*
 * file:     socl_write.c
 * unit:     yes
 * function: SOCL_WriteTo, SOCLi_WriteBuffer, SOCLi_AllocWriteBuffer, SOCLi_GetWriteBufferFreeSize, SOCLi_ExecWriteCommand, SOCLi_WriteCallBack, SOCLi_GetOptimumSendBufLen, SOCLi_MemCpy
 * address:  0x0215E024
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SOCL_SocketIsInvalid  0x0215F3D0  arm  ov009
 *   OS_TryLockMutex  0x020860D0  arm
 *   OS_LockMutex  0x02086028  arm
 *   SOCLi_WriteBuffer  0x0215E138  arm  ov009
 *   OS_UnlockMutex  0x02086078  arm
 *   SOCLi_ExecWriteCommand  0x0215E2E4  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_SleepThread  0x020857B0  arm
 *   SOCLi_CreateCommandPacket  0x0215CE3C  arm  ov009
 *   MI_CpuCopy  0x02082EA4  arm
 *   CPS_SocGetEport  0x0215A970  arm  ov009
 *   SOCLi_ExecCommandPacketInSendPipe  0x0215CF98  arm  ov009
 *   SOCLi_WriteCallBack  0x0215E450  arm  ov009
 *   CPS_SocBind  0x0215AAB0  arm  ov009
 *   SOCLi_MemCpy  0x0215E620  arm  ov009
 *   CPS_SocWrite  0x0215B470  arm  ov009
 *   CPS_TcpClose  0x0215AD3C  arm  ov009
 *   OS_WakeupThread  0x02085800  arm
 *   OSi_ThreadInfo     0x02150FEC  data
 *   SOCLiCPSConfig     0x021AA450  data
 */
#include "../arm9/os_thread.h"
#include "ov009_globals.h"

#include "socl_types.h"
#include "socl_command.h"

struct SOCLiCommandWrite {
    int (*handler)(void *);
    struct SOCLSocket *socket;
    long response_queue;
    signed char pipeIndex;
    signed char blockFlag;
    unsigned char padE[2];
    unsigned char *buffer1;
    long buffer1_len;
    unsigned char *buffer2;
    long buffer2_len;
    unsigned short wrtbuf_after;
    unsigned char padding[2];
    unsigned short local_port;
    unsigned short remote_port;
    unsigned long remote_ip;
};

#include "../types.h"

typedef struct {
	char pad0[0x38];
	unsigned short mss;
	unsigned short winSize;
} Soc;

#include "socl_list.h"
#include "../sdk_os.h"

#include "../arm9/os_mutex.h"
#include "../arm9/os_system.h"
struct SOCLiCommandPacket;
extern struct SOCLiCommandPacket *SOCLi_CreateCommandPacket(int (*handler)(void *), struct SOCLSocket *socket, long flag);
#include "../arm9/mi_memory.h"
#include "cps_network.h"
int SOCL_WriteTo(int s, void *buffer, int buffer_len, unsigned short remote_port, unsigned long remote_ip,
                  int flags);
static int SOCLi_WriteBuffer(struct SOCLSocket *socket, unsigned char *buffer, long buffer_len,
                         unsigned short remote_port, unsigned long remote_ip, long flag_block);
int SOCLi_AllocWriteBuffer(struct SOCLSocket *socket, int n, int m, int *out, int f5);
long SOCLi_GetWriteBufferFreeSize(struct SOCLSocket *socket);
static int SOCLi_ExecWriteCommand(struct SOCLSocket *socket, unsigned char *buffer, long buffer_len, long wrtbuf_in,
                         unsigned short remote_port, unsigned long remote_ip, long flag_block);
static int SOCLi_WriteCallBack(void *arg);
int SOCLi_GetOptimumSendBufLen(int len);
int SOCLi_MemCpy(u8 *dst, int len, struct SOCLiCommandWrite *r);

static inline int isNotReady(struct SOCLSocket *socket)
{
    int r = 0;
    if (socket != 0)
        r = (socket->state & 1) ? 1 : 0;
    return r;
}
#define isNotReady(x) (isNotReady(x))

static inline int isStream(signed char m)
{
    int r = 1;
    if (m != 0 && m != 4)
        r = 0;
    return r;
}

/*
 * sdk:      SOCL_WriteTo (socl_write.o)
 *
 * The second state test is a volatile load: the image reloads socket->state between the two bit tests.
 */
int SOCL_WriteTo(int s, void *buffer, int buffer_len, unsigned short remote_port, unsigned long remote_ip,
                  int flags)
{
    int result;
    int flag_block;
    struct SOCLiSocketSendCommandPipe *send_pipe;
    struct SOCLSocket *socket = (struct SOCLSocket *)s;

    if (SOCL_SocketIsInvalid(socket))
        return -0x1c;
    if (!isNotReady(socket))
        return -0x27;
    if (isStream(socket->flag_mode)) {
        if (!(socket->state & 4) || (*(volatile short *)&socket->state & 8))
            return -0x38;
    }
    send_pipe = socket->send_pipe;
    if ((flags & 4) || socket->flag_block == 0) {
        if (!OS_TryLockMutex((struct OSMutex *)send_pipe->mutex))
            return -6;
        flag_block = 0;
    } else {
        OS_LockMutex((struct OSMutex *)send_pipe->mutex);
        flag_block = 1;
    }
    result = SOCLi_WriteBuffer(socket, buffer, buffer_len, remote_port, remote_ip, flag_block);
    OS_UnlockMutex((struct OSMutex *)send_pipe->mutex);
    return result;
}

/*
 * sdk:      SOCLi_WriteBuffer (socl_write.o)
 */
static int SOCLi_WriteBuffer(struct SOCLSocket *socket, unsigned char *buffer, long buffer_len,
                         unsigned short remote_port, unsigned long remote_ip, long flag_block)
{
    int result;
    long buffer_min;
    long write_len;
    long copied_len;
    long wrtbuf_in;
    long sndbuf_len;

    sndbuf_len = socket->send_pipe->exe_socket->cps_socket.sndbuf.size;
    copied_len = 0;
    if (socket->flag_mode == 1) {
        sndbuf_len -= 0x2a;
        if (buffer_len > sndbuf_len)
            return -0x23;
        buffer_min = buffer_len;
    } else {
        sndbuf_len -= 0x36;
        buffer_min = sndbuf_len;
        if (buffer_len <= buffer_min)
            buffer_min = buffer_len;
    }
    while (buffer_len > 0) {
        write_len = SOCLi_AllocWriteBuffer(socket, buffer_len, buffer_min, (int *)(&wrtbuf_in), flag_block);
        if (write_len > 0) {
            result = SOCLi_ExecWriteCommand(socket, buffer, write_len, wrtbuf_in, remote_port, remote_ip, flag_block);
            if (result <= 0)
                return -6;
            buffer += write_len;
            buffer_len -= write_len;
            copied_len += write_len;
        }
        if (!(flag_block & 1)) {
            if (write_len <= 0)
                return -6;
            break;
        }
    }
    return copied_len;
}

/*
 * Pull a count out of the socket's send pipe, clamped to `n` (and, when it came
 * back short, to `m`) -- below `m` the loop instead either gives up with 0 or
 * pumps OS_SleepThread on the pipe's waiting queue, depending on the low bit of
 * the fifth argument.  The success path copies the pipe's `in` cursor out.  The
 * whole scan runs inside a OS_DisableInterrupts/OS_RestoreInterrupts interrupt bracket.
 */
/*
 * Pull a count out of the object at +0xa4, clamped to `n` (and, when it came
 * back short, to `m`) -- below `m` the loop instead either gives up with 0 or
 * pumps OS_SleepThread on the +0x104 channel, depending on the low bit of the
 * fifth argument.  The success path copies the u16 at +0x100 out.  The whole
 * scan runs inside a OS_DisableInterrupts/OS_RestoreInterrupts interrupt bracket.
 */
int SOCLi_AllocWriteBuffer(struct SOCLSocket *socket, int n, int m, int *out, int f5)
{
    struct SOCLiSocketSendCommandPipe *base;
    int st;
    int v;
    int flag;

    base = socket->send_pipe;
    if (m > n)
        m = n;
    st = OS_DisableInterrupts();
    flag = f5 & 1;
    for (;;) {
        v = SOCLi_GetWriteBufferFreeSize(socket);
        if (v >= m) {
            if (v >= n)
                v = n;
            *out = base->buffer.in;
            break;
        }
        if (flag == 0) {
            v = 0;
            break;
        }
        OS_SleepThread(&base->buffer.waiting);
    }
    OS_RestoreInterrupts(st);
    return v;
}

/*
 * Free space in a socket's send ring buffer: (out - in - 1), plus the buffer
 * size when that goes negative.
 *
 * The pipe's two cursors are `vu16` in the vendor header
 * (sdk/TwlDWC/include/nitroWiFi/socl.h, SOCLiSocketRingBuffer), not plain
 * u16: with volatile loads the two ldrh keep source order (in at +0x100, out
 * at +0x102) and the size word at +0xf8 (a non-volatile CPSSocBuf.size) is
 * free to float below them.  Without the qualifier the front end folds the
 * pair into the subtraction the other way round and only nine bytes of the
 * 36 come out.
 *
 * sdk:      SOCLi_GetWriteBufferFreeSize (libsoc.TWL.HYB.a(socl_write.o))
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/SOCLi_GetWriteBufferFreeSize.c \
 *       --func SOCLi_GetWriteBufferFreeSize --addr 0x0215E2C0 --region ov009 --arm --cc 1.1p1 \
 *       --lang c99 --diff
 */
long SOCLi_GetWriteBufferFreeSize(struct SOCLSocket *socket)
{
	struct SOCLiSocketSendCommandPipe *send_pipe = socket->send_pipe;
	long wrtbuf_size = send_pipe->buffer.size;
	long wrtbuf_in = send_pipe->buffer.in;
	long wrtbuf_out = send_pipe->buffer.out;
	long available_len = wrtbuf_out - wrtbuf_in - 1;

	if (available_len < 0) {
		available_len += wrtbuf_size;
	}
	return available_len;
}

/*
 * sdk:      SOCLi_ExecWriteCommand (socl_write.o)
 */
static int SOCLi_ExecWriteCommand(struct SOCLSocket *socket, unsigned char *buffer, long buffer_len, long wrtbuf_in,
                         unsigned short remote_port, unsigned long remote_ip, long flag_block)
{
    struct SOCLiSocketSendCommandPipe *send_pipe = socket->send_pipe;
    struct SOCLiCommandWrite *command;
    unsigned short saved_send_buffer_in;
    long wrtbuf_size;
    unsigned char *wrtbuf;
    int result;

    command = (struct SOCLiCommandWrite *)SOCLi_CreateCommandPacket(SOCLi_WriteCallBack, send_pipe->exe_socket, flag_block);
    if (command == 0)
        return -0x21;
    if ((flag_block & 1) && socket->flag_mode != 1)
        command->blockFlag = 3;
    else
        command->blockFlag = 0;
    wrtbuf_size = send_pipe->buffer.size;
    wrtbuf = send_pipe->buffer.area;
    if (wrtbuf_in + buffer_len < wrtbuf_size) {
        command->buffer1 = wrtbuf + wrtbuf_in;
        command->buffer1_len = buffer_len;
        command->buffer2 = 0;
        command->buffer2_len = 0;
        wrtbuf_in += buffer_len;
    } else {
        command->buffer1 = wrtbuf + wrtbuf_in;
        command->buffer1_len = wrtbuf_size - wrtbuf_in;
        wrtbuf_in = buffer_len - command->buffer1_len;
        command->buffer2 = wrtbuf;
        command->buffer2_len = wrtbuf_in;
        MI_CpuCopy(buffer + command->buffer1_len, command->buffer2, command->buffer2_len);
    }
    MI_CpuCopy(buffer, command->buffer1, command->buffer1_len);
    saved_send_buffer_in = send_pipe->buffer.in;
    command->wrtbuf_after = wrtbuf_in;
    send_pipe->buffer.in = command->wrtbuf_after;
    if (socket->flag_mode == 1) {
        if (socket->local_port == 0) {
            socket->local_port = CPS_SocGetEport();
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
    result = SOCLi_ExecCommandPacketInSendPipe(send_pipe->exe_socket, (struct SOCLiCommandPacket *)command);
    if (result) {
        send_pipe->buffer.in = saved_send_buffer_in;
        buffer_len = 0;
    }
    return buffer_len;
}

/*
 * sdk:      SOCLi_WriteCallBack (socl_write.o)
 */
static int SOCLi_WriteCallBack(void *arg)
{
    unsigned char *sndbuf;
    struct SOCLSocket *socket;
    int hdr;
    int sndbuf_len;
    int result;
    struct SOCLiSocketSendCommandPipe *send_pipe;
    int copied;
    struct SOCLiCommandWrite *cpacket = arg;

    socket = cpacket->socket;
    send_pipe = socket->send_pipe;
    copied = 0;

    if (socket->flag_mode == 2 && (socket->state & 8))
        return -0x1c;
    if ((socket->flag_mode == 0 || socket->flag_mode == 4) && !(socket->state & 4))
        goto fail;
    if (cpacket->remote_ip)
        CPS_SocBind(cpacket->local_port, cpacket->remote_port, cpacket->remote_ip);
    hdr = 0x36;
    if (!isStream(socket->flag_mode))
        hdr = 0x2a;
    sndbuf = socket->cps_socket.sndbuf.data;
    if (socket->flag_mode == 0 || socket->flag_mode == 4)
        sndbuf_len = SOCLi_GetOptimumSendBufLen((long)socket->cps_socket.sndbuf.size - hdr);
    else
        sndbuf_len = (long)socket->cps_socket.sndbuf.size - hdr;
    for (;;) {
        int n = SOCLi_MemCpy(sndbuf + hdr, sndbuf_len, cpacket);
        if (n <= 0)
            goto done;
        result = CPS_SocWrite(sndbuf + hdr, n);
        if (result <= 0) {
            if (isStream(socket->flag_mode)) {
                socket->state &= ~0xe;
                socket->state |= 0x80;
                CPS_TcpClose();
            }
            copied = -0x4c;
            goto done;
        } else {
            copied += result;
        }
    }
fail:
    copied = -0x4c;
done:
    send_pipe->buffer.out = cpacket->wrtbuf_after;
    OS_WakeupThread(&send_pipe->buffer.waiting);
    return copied;
}

/*
 * Send-buffer length that fits the current link: min(winSize, mss, the CPS
 * config buffer size), doubled, then as many whole copies of `len` as the
 * divisor helper allows.  Interrupts are off across the window-size read.
 *
 * The lever was the `int max = SOCLiCPSConfig.mymss;` local: reading the config
 * word into a local *before* the two min compares is what makes the scheduler
 * hoist the config base load above `cmp winSize, mss`, which in turn keeps
 * `mss` alive in r2 (r3 = winSize, r2 = mss, r1 = bufSize).  Reading
 * SOCLiCPSConfig.mymss inline in the second compare sinks both loads below the
 * first min and reuses r1 for mss (21 bytes out); using `temp` itself as the
 * running minimum forces it into r6 and costs the frame (`push {r4,r5,r6,lr}`).
 *
 * sdk:      SOCLi_GetOptimumSendBufLen (libsoc.TWL.HYB.a(socl_write.o))
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/SOCLi_GetOptimumSendBufLen.c \
 *       --func SOCLi_GetOptimumSendBufLen --addr 0x0215E588 --region ov009 --arm --cc 1.1p1 \
 *       --lang c99 --diff
 */
int SOCLi_GetOptimumSendBufLen(int len)
{
	Soc *soc;
	int temp;
	unsigned long enabled;
	int count;

	soc = (Soc *)OSi_ThreadInfo.current->specific[0];
	enabled = OS_DisableInterrupts();
	if (soc != 0) {
		if (soc->winSize != 0 && soc->mss != 0) {
			int w = soc->winSize;
			int max = SOCLiCPSConfig.mymss;
			if (w > soc->mss) {
				w = soc->mss;
			}
			if (w > max) {
				w = max;
			}
			temp = w << 1;
		} else {
			temp = SOCLiCPSConfig.mymss << 1;
		}
	} else {
		temp = SOCLiCPSConfig.mymss << 1;
	}
	OS_RestoreInterrupts(enabled);
	if (temp > 0) {
		count = len / temp;
		if (count > 0) {
			return temp * count;
		}
	}
	return len;
}

/*
 * Consume up to `len` bytes from a two-segment ring object into `dst`: the
 * head segment is `[+0x10]/len[+0x14]`, the wrapped tail `[+0x18]/len[+0x1c]`.
 * A request longer than the head drops the tail entirely (n = len, m = 0),
 * otherwise the tail is clamped to what is left.  Both segments copied with
 * the byte copier at 0x02082EA4, and the two cursors advanced in place.
 * Returns the number of bytes produced.
 */
int SOCLi_MemCpy(u8 *dst, int len, struct SOCLiCommandWrite *r)
{
    int n;
    int m;

    n = r->buffer1_len;
    m = r->buffer2_len;
    if (n > len) {
        n = len;
        m = 0;
    } else if (m > len - n) {
        m = len - n;
    }
    if (n > 0) {
        MI_CpuCopy(r->buffer1, dst, n);
        r->buffer1 += n;
        r->buffer1_len -= n;
    }
    if (m > 0) {
        MI_CpuCopy(r->buffer2, dst + n, m);
        r->buffer2 += m;
        r->buffer2_len -= m;
    }
    return n + m;
}
