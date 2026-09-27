/*
 * function: func_021D7B74
 * address:  0x021D7B74
 * packet:   pkt_ov093_021D7B74
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: named callee of the parked ov093 func_021DFABC
 * (the `func_021D7B74(func_021C7CF4(b, k), (u8)func_021DCFF8(a,2))` halfword).
 * Runs func_021D59B4(a, 0xe) through the unsigned divide entry 0x0209C2B0
 * (`_u32_div_f`, see docs/notes/unsigned-divide-entry-is-0209c2b0.c.txt) and
 * floors a zero quotient at 1.
 *
 * symbols:
 *   func_021D59B4   0x021D59B4  thumb  ov093
 *   _u32_div_f      0x0209C2B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int func_021D59B4(int, int);
extern u32 _u32_div_f(u32, u32);

int func_021D7B74(int a0, u32 a1)
{
    u32 r = func_021D59B4(a0, 0xe);

    r = r / a1;
    if (r == 0)
        r = 1;
    return r;
}
