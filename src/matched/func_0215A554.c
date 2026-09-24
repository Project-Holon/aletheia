/*
 * function: func_0215A554
 * address:  0x0215A554
 * packet:   pkt_0215A554
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0215A554.c \
 *       --func func_0215A554 --addr 0x0215A554 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020307B0(void *);

void func_0215A554(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_020307B0(a0);
}
