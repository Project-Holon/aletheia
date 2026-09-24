/*
 * function: func_0218F9F8
 * address:  0x0218F9F8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The high word of the 64-bit word the call on the pointed-to word returns.
 *
 * symbols:

 */

extern unsigned long long func_0209C0A4(int v);

int func_0218F9F8(int *p)
{
    return (int)(func_0209C0A4(*p) >> 32);
}

