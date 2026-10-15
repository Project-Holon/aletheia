/*
 * function: func_0217EC4C
 * address:  0x0217EC4C
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

extern int func_0215F4DC(void);
extern int CheckRcode(int a, int b);

int func_0217EC4C(int sock, char *buffer, int len, int flags)
{
    return CheckRcode(func_0215F4DC(), -1);
}

