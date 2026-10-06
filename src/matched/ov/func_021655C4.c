/*
 * function: func_021655C4
 * address:  0x021655C4
 * packet:   pkt_0216555C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_0202744C  0x0202744C  thumb

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0202744C, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021655C4.c \
 *       --func func_021655C4 --addr 0x021655C4 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj00121.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0202744C(void *);

void func_021655C4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 38;
    ((struct Obj00121 *)a0)->f32 = a1;
    func_0202744C(a0);
}
