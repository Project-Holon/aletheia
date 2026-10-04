/*
 * function: func_021892E8
 * address: 0x021892E8
 * packet: pkt_ov096_021892E8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021892F8 0x021892F8 thumb ov096
 */
#include "../include/Obj21960.h"
typedef struct Obj Obj;
extern int func_021892F8(int, Obj *, int);
int func_021892E8(int a, Obj * b)
{
    func_021892F8(a, b, 3);
    return ((struct Obj21960 *)((unsigned int)b))->fC4;
}
