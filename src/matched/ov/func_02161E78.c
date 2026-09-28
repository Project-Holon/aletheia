/*
 * function: func_02161E78
 * address:  0x02161E78
 * packet:   pkt_02161E78
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_02082BCC, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02161E78.c \
 *       --func func_02161E78 --addr 0x02161E78 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02082BCC(void *, unsigned, unsigned);

void func_02161E78(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_02082BCC(a0, 0, 24);
}
