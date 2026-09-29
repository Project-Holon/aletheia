/*
 * function: func_021BB3C4
 * address:  0x021BB3C4
 * packet:   pkt_021BB394
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tail-call thunk: the object's word at +0x8.
 *
 * symbols:
 *   func_021BB13C  0x021BB13C  thumb
 *
 * Addresses are Black-image addresses.
 *
 * evidence: func_021BB13C is ov021's own code (a "push {r4, r5}" leaf right
 * after the "pop {r4, pc}" at 0x021BB13A), inside ov021's window, so only
 * ov021 can be resident there when this pool word is used.  Its start is
 * seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov021's own listing.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BB13C();

void func_021BB3C4(u8 *p)
{
    func_021BB13C(*(u32 *)(p + 0x8));
}
