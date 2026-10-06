/*
 * function: func_02188980
 * address: 0x02188980
 * packet: pkt_ov096_02188980
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021889A0 0x021889A0 thumb ov096
 */
#include "../include/Obj21930.h"
struct Cursor;
extern int func_021889A0(struct Cursor *a, int b, int c);
int func_02188980(struct Cursor *a, int b)
{
    func_021889A0(a, b, 2);
    return ((struct Obj21930 *)b)->fC4;
}
