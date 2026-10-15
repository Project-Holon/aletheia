/*
 * function: atoll
 * address:  0x020964F4
 * packet:   pkt_020964F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Argument-defaulting thunk: call the s64 decimal parser strtoll with
 * a null out-pointer and radix 10.  Reproducible from C as an ordinary tail
 * call; the previous note that claimed otherwise was wrong.
 *
 * symbols:
 *   strtoll  0x020963F8  arm
 */

typedef unsigned int u32;

extern long long strtoll(u32 a0, u32 *a1, u32 a2);

long long atoll(u32 a0)
{
    return strtoll(a0, 0, 10);
}
