/*
 * function: func_0217EB9C
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

 */

extern int func_0215F638(int s, int how);
extern int func_0217EB00(int a, int b);

int func_0217EB9C(int sock, int how)
{
    return func_0217EB00(func_0215F638(sock, how), -1);
}

