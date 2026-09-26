/*
 * function: func_020964F4
 * address:  0x020964F4
 * packet:   pkt_020964F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Argument-defaulting thunk: call the s64 decimal parser func_020963F8 with
 * a null out-pointer and radix 10.  Reproducible from C as an ordinary tail
 * call; the previous note that claimed otherwise was wrong.
 *
 * symbols:
 *   func_020963F8  0x020963F8  arm
 */

typedef unsigned int u32;

extern long long func_020963F8(u32 a0, u32 *a1, u32 a2);

long long func_020964F4(u32 a0)
{
    return func_020963F8(a0, 0, 10);
}
