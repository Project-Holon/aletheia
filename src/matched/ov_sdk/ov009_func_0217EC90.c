/*
 * function: func_0217EC90
 * address:  0x0217EC90
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
 *   CheckRcode  0x0217EB00  arm

 */

extern int func_0215F590(void);
extern int CheckRcode(int a, int b);

int func_0217EC90(int sock, char *buffer, int bufferLen, int flags)
{
    return CheckRcode(func_0215F590(), -1);
}

