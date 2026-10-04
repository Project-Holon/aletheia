/*
 * function: func_0216242C
 * address:  0x0216242C
 * packet:   pkt_0216242C
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_021624B0  0x021624B0  thumb  ov010

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_021624B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216242C.c \
 *       --func func_0216242C --addr 0x0216242C --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj17713.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021624B0(void *, unsigned);

void func_0216242C(void *a0, unsigned a1, unsigned a2, unsigned a3)
{
    ((struct Obj17713 *)a0)->f10 = a1;
    func_021624B0(a0, a1);
}
