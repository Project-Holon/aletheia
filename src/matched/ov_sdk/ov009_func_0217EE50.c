/*
 * function: SetSockBlocking
 * address:  0x0217EE50
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SetSockBlocking: read the socket's fcntl flags (SOC_Fcntl cmd 3), set or
 * clear the non-blocking bit (4), write them back (cmd 4), and log the
 * outcome through gsDebugFormat.  Returns 1 on success, 0 on failure.
 *
 * EXACT*: the inferred extent ran four bytes long into the unlabelled
 * follower at 0x0217EF00 (a leaf whose prologue saves r0-r3, not lr, so
 * disasm.py does not trace it); seed that start to make the extent exact.
 *
 * symbols:
 *   SOC_Fcntl  0x0215F854  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021A3740     0x021A3740  data
 *   g_021A374C     0x021A374C  data
 *   g_021A375C     0x021A375C  data
 *   g_021A3784     0x021A3784  data
 */

extern int SOC_Fcntl(int sock, int cmd, int arg);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern char g_021A3740[];
extern char g_021A374C[];
extern char g_021A375C[];
extern char g_021A3784[];

int SetSockBlocking(int sock, int isblocking)
{
    int val;
    int rcode;

    val = SOC_Fcntl(sock, 3, 0);
    if (isblocking)
        val &= ~4;
    else
        val |= 4;
    rcode = SOC_Fcntl(sock, 4, val);
    if (rcode == 0) {
        func_0217D254(12, 0, 0x10, g_021A375C, sock, isblocking ? g_021A3740 : g_021A374C);
        return 1;
    }
    func_0217D254(12, 0, 0x10, g_021A3784, sock, isblocking ? g_021A3740 : g_021A374C);
    return 0;
}
