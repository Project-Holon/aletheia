/*
 * function: func_02020F14
 * address:  0x02020F14
 * packet:   pkt_02020E60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_02020F0C.c is now a manifest entry (matched class)
 *
 * Tail-call thunk: opens handle 0x18 with the caller's argument.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02020F14.c \
 *       --func func_02020F14 --addr 0x02020F14 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020490F4(u32 a, u32 b);

void func_02020F14(u32 a)
{
    func_020490F4(0x18, a);
}
