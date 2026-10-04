/*
 * function: func_021D13FC
 * address: 0x021D13FC
 * packet: pkt_ov093_021D13FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 * symbols:
 *   func_021D1410 0x021D1410 thumb ov093
 */
#include "../include/Obj00066.h"
typedef unsigned char u8;
extern int func_021D1410(u8 *, int *, void *);
int func_021D13FC(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D1410(p, state, q);
    return 1;
}
