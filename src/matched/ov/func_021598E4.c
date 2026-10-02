/*
 * function: func_021598E4
 * address:  0x021598E4
 * packet:   pkt_021598E4
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_021B1BB8  0x021B1BB8  thumb

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_021B1BB8, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021598E4.c \
 *       --func func_021598E4 --addr 0x021598E4 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B1BB8(int a, void *b);

int func_021598E4(int a0, void *a1)
{
    return func_021B1BB8(a0, a1);
}
