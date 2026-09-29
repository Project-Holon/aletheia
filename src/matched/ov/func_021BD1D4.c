/*
 * function: func_021BD1D4
 * address:  0x021BD1D4
 * packet:   pkt_021BD1CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to func_021BD474 with no argument change.
 *
 * symbols:
 *   func_021BD474  0x021BD474  thumb
 *
 * Addresses are Black-image addresses.
 *
 * evidence: func_021BD474 is ov021's own code ("movs r1, #1; str r1, [r0,
 * #0x44]; bx lr" after the pop at 0x021BD470), inside ov021's window, so only
 * ov021 can be resident there when this pool word is used.  Its start is
 * seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov021's own listing.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BD474();

void func_021BD1D4(void)
{
    func_021BD474();
}
