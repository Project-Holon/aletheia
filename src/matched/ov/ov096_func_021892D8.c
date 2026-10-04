/*
 * function: func_021892D8
 * address: 0x021892D8
 * packet: pkt_ov096_021892D8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021892F8 0x021892F8 thumb ov096
 */
#include "../include/Obj21959.h"
typedef struct Obj Obj;
extern int func_021892F8(int, Obj *, int);
int func_021892D8(int a, Obj * b)
{
    func_021892F8(a, b, 2);
    return ((struct Obj21959 *)((unsigned int)b))->fC4;
}
