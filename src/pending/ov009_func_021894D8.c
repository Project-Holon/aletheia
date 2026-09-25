/*
 * function: func_021894D8
 * address:  0x021894D8
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF   (parked; not EXACT/MATCH)
 *
 * gpiSendData (static helper of gpiSendFromBuffer): one send() on the socket.
 * On -1/GOAGetLastError outside the three would-block/in-progress/timeout
 * codes, a "PR" peer id returns GP_NETWORK_ERROR immediately, else raise
 * GP_NETWORK on the connection and return GP_NETWORK_ERROR.  On rcode == 0
 * mark the connection closed; otherwise raw-dump the sent bytes through the
 * GSIDebug network logger and account them in the static sendCount.
 *
 * BLOCKER (codegen only, 21 bytes at +0x118..+0x138): the whole function is
 * the right size (364) and every other byte is identical, but the GSIDebug
 * raw-dump call schedules `sendCount++` differently.  The original loads the
 * format pointer into r3 *before* the counter (base r1, fmt r3, count r2,
 * stm sp,{r2,r6}, add r2,#1, str r2,[r1]); this front end instead does the
 * counter first (base r0, base r1, count r3, add, str, stm sp,{r3,sl}) and
 * rematerialises the format address after the increment.  Tried: scalar vs
 * array vs struct-member counter, a named count local, a `register` local,
 * both-fmt-and-count locals, a pointer-to-counter local, an unprototyped
 * callee, and void/int callee returns; all reproduce the same order.  Every
 * other call site in this file (the error path and the rcode==0 branch) is
 * byte-exact.  Not a witness problem: the three literals and both gsiSet
 * underlays all resolve; this is the mwcc argument-scheduling heuristic for
 * a post-increment in a varargs list.
 *
 * symbols:
 *   func_0217EC90  0x0217EC90  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_02193710  0x02193710  arm  ov009
 *   func_02189D78  0x02189D78  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02092344  0x02092344  arm
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   g_021A44DC     0x021A44DC  data ov009
 *   g_021A4504     0x021A4504  data ov009
 *   g_021A4528     0x021A4528  data ov009
 *   g_021ADFC8     0x021ADFC8  data ov009 a4
 */

extern int func_0217EC90(int sock, char *buffer, int bufferLen, int flags);
extern int func_0217ED54(int sock);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern char *func_0217EAB0(int size);
extern void func_02092344(void *dst, const void *src, int n);
extern void func_0217D254();
extern void func_0217EAE0(void *p);
extern char g_021A44DC[];
extern char g_021A4504[];
extern char g_021A4528[];
extern int g_021ADFC8;

int func_021894D8(int *connection, int sock, char *buffer, int bufferLen,
                  int *closed, int *sent, char *id)
{
    int rcode = func_0217EC90(sock, buffer, bufferLen, 0);

    if (rcode == -1) {
        rcode = func_0217ED54(sock);
        if (rcode != -6 && rcode != -26 && rcode != -76) {
            if (id[0] == 'P' && id[1] == 'R')
                return 3;
            func_02193710(connection, 5, (int)g_021A44DC);
            func_02189D78(connection, 3, 0);
            return 3;
        }
        *sent = 0;
        *closed = 0;
    } else if (rcode == 0) {
        func_0217D254(1, 0, 0x10, g_021A4504, id);
        *sent = 0;
        *closed = 1;
    } else {
        char *buf = func_0217EAB0(rcode + 1);

        func_02092344(buf, buffer, rcode);
        buf[rcode] = 0;
        func_0217D254(1, 0, 0x20, g_021A4528, g_021ADFC8++, id, buf);
        func_0217EAE0(buf);
        *sent = rcode;
        *closed = 0;
    }
    return 0;
}
