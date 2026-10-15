/*
 * function: atoi
 * address:  0x020964E0
 * packet:   pkt_020964E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Argument-defaulting thunk: call the s32 decimal parser strtol with
 * a null out-pointer and radix 10.  It is the `atoi` entry point the overlay
 * error parser uses.  Reproducible from C as an ordinary tail call; the
 * previous note that claimed otherwise was wrong.
 *
 * symbols:
 *   strtol  0x02095F40  arm
 */

typedef unsigned int u32;

extern int strtol(u32 a0, u32 *a1, u32 a2);

int atoi(u32 a0)
{
    return strtol(a0, 0, 10);
}
