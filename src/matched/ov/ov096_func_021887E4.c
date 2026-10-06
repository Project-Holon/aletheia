/*
 * function: func_021887E4
 * address: 0x021887E4
 * packet: pkt_ov096_021887E4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021887F4 0x021887F4 thumb ov096
 */
#include "../include/Obj21923.h"
struct Cursor;
extern int func_021887F4(struct Cursor *a, int b, int c);
int func_021887E4(struct Cursor *a, int b)
{
    func_021887F4(a, b, 3);
    return ((struct Obj21923 *)((unsigned int)b))->fC4;
}
