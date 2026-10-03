/*
 * function: func_0216DB04
 * address:  0x0216DB04
 * packet:   pkt_0216DA70
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_0216D570  0x0216D570  thumb  ov010

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D570, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DB04.c \
 *       --func func_0216DB04 --addr 0x0216DB04 --region ov010 --cc dsi/1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0216D570(char *p, u32 v);

void func_0216DB04(void *a0)
{

    func_0216D570(a0, 8);
}
