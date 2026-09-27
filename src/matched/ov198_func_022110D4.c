/*
 * function: func_022110D4
 * address:  0x022110D4
 * packet:   pkt_ov198_022110D4
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Recursive MATCH unblocker: named callee of the parked ov198 func_0220C8F0
 * (the first statement, `func_022110D4(a0)`, and every later use of the
 * resulting entry pointer).  `(p + i)[0x1cc]` is what keeps the added index in
 * r1 and the 0x1cc constant in r0 (`ldrb r0,[r1,r0]`); the subscript form folds
 * the constant into the pointer add.  The two-byte follower is the listing's
 * alignment word, so the extent runs one word long.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

int func_022110D4(u8 *p, int i)
{
    return (p + i)[0x1cc];
}
