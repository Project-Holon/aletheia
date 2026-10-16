/*
 * function: shutdown
 * address:  0x0217EB9C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the module setter on the value with the sentinel -1.
 *
 * symbols:
 *   SOC_Shutdown  0x0215F638  arm
 *   CheckRcode  0x0217EB00  arm

 */

extern int SOC_Shutdown(int s, int how);
extern int CheckRcode(int a, int b);

int shutdown(int sock, int how)
{
    return CheckRcode(SOC_Shutdown(sock, how), -1);
}

