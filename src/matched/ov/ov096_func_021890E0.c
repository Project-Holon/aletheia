/*
 * function: func_021890E0
 * address: 0x021890E0
 * packet: pkt_ov096_021890E0
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02189100 0x02189100 thumb ov096
 */
#include "../include/Obj21953.h"
struct Cursor;
extern int func_02189100(struct Cursor *a, int b, int c);
int func_021890E0(struct Cursor *a, int b)
{
    func_02189100(a, b, 2);
    return ((struct Obj21953 *)b)->fC4;
}
