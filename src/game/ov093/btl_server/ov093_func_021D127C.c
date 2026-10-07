/*
 * function: func_021D127C
 * address: 0x021D127C
 * packet: pkt_ov093_021D127C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 * symbols:
 *   func_021D1290 0x021D1290 thumb ov093
 */
#include "../../../matched/include/Obj00066.h"
typedef unsigned char u8;
extern int func_021D1290(u8 *, int *, void *);
int func_021D127C(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D1290(p, state, q);
    return 1;
}
