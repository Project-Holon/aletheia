/*
 * function: func_0217EB2C
 * address:  0x0217EB2C
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
 *   SOC_Close  0x0215F644  arm

 */

extern int SOC_Close(int s);
extern int func_0217EB00(int a, int b);

int func_0217EB2C(int sock)
{
    return func_0217EB00(SOC_Close(sock), -1);
}

