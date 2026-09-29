/*
 * function: func_021C57DC
 * address:  0x021C57DC
 * packet:   pkt_ov127_021C57DC
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call forwarder: (p) -> func_021C5944(p, 1, p->u16 at +0xA).
 * Blocker of ov099 func_021B99F4 / func_021B9A70.
 *
 * symbols:
 *   func_021C5944  0x021C5944  thumb  ov127
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void func_021C5944(u8 *p, int one, int v);

void func_021C57DC(u8 *p)
{
    func_021C5944(p, 1, *(u16 *)(p + 0xa));
}
