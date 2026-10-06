/*
 * function: func_02188990
 * address: 0x02188990
 * packet: pkt_ov096_02188990
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021889A0 0x021889A0 thumb ov096
 */
#include "../include/Obj21931.h"
struct Cursor;
extern int func_021889A0(struct Cursor *a, int b, int c);
int func_02188990(struct Cursor *a, int b)
{
    func_021889A0(a, b, 3);
    return ((struct Obj21931 *)b)->fC4;
}
