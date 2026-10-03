/*
 * function: func_02170200
 * address:  0x02170200
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sends a match command to a buddy as a GP buddy message.
 *
 * symbols:
 *   OS_SNPrintf  0x02084F80  arm
 *   d_021A2190  0x021A2190  data
 *   d_021A2198  0x021A2198  data
 *   d_021A21A0  0x021A21A0  data
 *   func_0209477C  0x0209477C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_021864CC  0x021864CC  arm  ov009
 */

extern int OS_SNPrintf(char *dst, int len, const char *fmt, ...);
extern char d_021A2190[];
extern char d_021A2198[];
extern char d_021A21A0[];
extern int func_0209477C(const char *s);
extern void MI_CpuCopy8(const void *src, void *dst, int size);
extern int func_021864CC(void **connection, int profile, char *message);

int func_02170200(void *conn, unsigned char command, int pid, const char *data)
{
    char msg[0x200];
    char *p;
    int len;

    len = OS_SNPrintf(msg, 0x200, d_021A2190, d_021A2198, 0x5a, d_021A21A0);
    msg[len] = command;
    p = msg + 1;
    p[len] = 0;
    p += len;
    if (data != 0) {
        len = func_0209477C(data);
        MI_CpuCopy8(data, p, len);
        p[len] = 0;
    }
    return func_021864CC(conn, pid, msg);
}
