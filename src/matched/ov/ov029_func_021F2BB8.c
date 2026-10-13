/*
 * function: C_GEAR_IsCellMarked
 * address: 0x021F2BB8
 * packet: pkt_ov029_021F2BB8
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02009134 0x02009134 thumb
 */
#include "../include/Obj00042.h"
typedef unsigned char u8;
struct Sub020090B0Obj;
extern int func_02009134(const struct Sub020090B0Obj *obj, int row, int col);
int C_GEAR_IsCellMarked(u8 *p, int row, int col)
{
    if (p[0x45a] != 0)
        return func_02009134(*(struct Sub020090B0Obj * *)&((struct Obj00042 *)p)->f20, row, col);
    return 0;
}
