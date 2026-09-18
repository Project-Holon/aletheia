/*
 * function: func_0202B7D4
 * address:  0x0202B7D4
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker: func_0202BECC - one call site, inside this range only; every concrete byte reproduces.
 *
 * Tail-call thunk: the node's 0x1c word goes straight to func_0202BECC.
 *
 * symbols:
 *   func_0202BECC  0x0202BECC  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B7D4.c \
 *       --func func_0202B7D4 --addr 0x0202B7D4 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202BECC(u32 v);

void func_0202B7D4(u8 *p)
{
    func_0202BECC(*(u32 *)(p + 0x1c));
}
