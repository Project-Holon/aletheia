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

 */

extern int func_0215F644(int s);
extern int func_0217EB00(int a, int b);

int func_0217EB2C(int sock)
{
    return func_0217EB00(func_0215F644(sock), -1);
}

