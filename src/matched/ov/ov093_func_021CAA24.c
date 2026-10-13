/*
 * function: BTL_SERVER_FLOW_ResolveCurseTargetPosition
 * address: 0x021CAA24
 * packet: pkt_ov093_021CAA24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 021CAA56..021CAA58 is zero alignment padding.
 * symbols:
 *   BTL_CALC_DecideMoveTarget 0x021D80BC thumb ov093
 */
#include "../include/Obj09977.h"
#include "../include/Obj13344.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int BTL_CALC_DecideMoveTarget(void *, int, int, u16);
int BTL_SERVER_FLOW_ResolveCurseTargetPosition(u8 *p, u8 *q, int m, int n, int value)
{
    if (((struct Obj09977 *)q)->f0 == 174) {
        if (((struct Obj09977 *)q)->fC == 0) {
            if (n == value || value == 6)
                return BTL_CALC_DecideMoveTarget(((struct Obj13344 *)p)->f4, ((struct Obj13344 *)p)->f8, m, 174);
        } else if (((struct Obj09977 *)q)->fC == 7 && n != value) {
            value = n;
        }
    }
    return value;
}
