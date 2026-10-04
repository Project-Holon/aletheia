/*
 * function: func_021D1708
 * address: 0x021D1708
 * packet: pkt_ov093_021D1708
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 * symbols:
 *   func_021D171C 0x021D171C thumb ov093
 */
#include "../include/Obj00066.h"
typedef unsigned char u8;
extern int func_021D171C(u8 *, int *, void *);
int func_021D1708(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D171C(p, state, q);
    return 1;
}
