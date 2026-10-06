/*
 * function: func_021BAB24
 * address:  0x021BAB24
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Successor of a character on the '0'..'z' wheel, wrapping at the gaps.
 * Returning 'signed char' is what puts the single shared sign-extending
 * epilogue at 0x021BAB4C after the value is assigned, not returned early.
 */

typedef unsigned char u8;
typedef unsigned int u32;

char func_021BAB24(u8 c)
{
    c = (c + 1) & 0xff;
    if (c == 0x7b)
        c = 0x30;
    else if (c == 0x5b)
        c = 0x61;
    else if (c == 0x3a)
        c = 0x41;
    return (signed char)c;
}
