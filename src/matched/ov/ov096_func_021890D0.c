/*
 * function: func_021890D0
 * address: 0x021890D0
 * packet: pkt_ov096_021890D0
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02189100 0x02189100 thumb ov096
 */
#include "../include/Obj21952.h"
struct Cursor;
extern int func_02189100(struct Cursor *a, int b, int c);
int func_021890D0(struct Cursor *a, int b)
{
    func_02189100(a, b, 1);
    return ((struct Obj21952 *)b)->fC4;
}
