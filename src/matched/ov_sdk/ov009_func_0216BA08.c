/*
 * function: func_0216BA08
 * address:  0x0216BA08
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Whether this host is the match server.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   func_0216B9B0  0x0216B9B0  arm  ov009
 */

extern char g_021AA878[];
extern unsigned char func_0216B9B0(void);

int func_0216BA08(void)
{
    if (*(char **)(g_021AA878 + 4) == 0) {
        return 0;
    }
    if (func_0216B9B0() == 0xff) {
        return 0;
    }
    return *(unsigned char *)(*(char **)(g_021AA878 + 4) + 0x366) == 2;
}
