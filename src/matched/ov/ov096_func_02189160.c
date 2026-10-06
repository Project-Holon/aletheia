/*
 * function: func_02189160
 * address: 0x02189160
 * packet: pkt_ov096_02189160
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02189170 0x02189170 thumb ov096
 */
#include "../include/Obj21956.h"
struct Cursor;
extern int func_02189170(struct Cursor *a, int b, int c);
int func_02189160(struct Cursor *a, int b)
{
    func_02189170(a, b, 1);
    return ((struct Obj21956 *)b)->fC4;
}
