/*
 * function: func_02194704
 * address:  0x02194704
 * packet:   pkt_02194704
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_02195530 with no argument change.
 *
 * symbols:
 *   func_02195530  0x02195530  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02195530(char *p);

void func_02194704(char *a0)
{
    func_02195530(a0);
}
