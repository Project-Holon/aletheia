/*
 * function: func_021889F8
 * address: 0x021889F8
 * packet: pkt_ov096_021889F8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188A08 0x02188A08 thumb ov096
 */
#include "../include/Obj21933.h"
struct Cursor;
extern int func_02188A08(struct Cursor *a, int b, int c);
int func_021889F8(struct Cursor *a, int b)
{
    func_02188A08(a, b, 3);
    return ((struct Obj21933 *)b)->fC4;
}
