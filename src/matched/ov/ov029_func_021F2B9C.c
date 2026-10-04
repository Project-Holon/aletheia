/*
 * function: func_021F2B9C
 * address: 0x021F2B9C
 * packet: pkt_ov029_021F2B9C
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02009110 0x02009110 thumb
 */
#include "../include/Obj00042.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Sub020090B0Obj;
extern u32 func_02009110(const struct Sub020090B0Obj *obj, int row, int col);
u32 func_021F2B9C(u8 *p, int row, int col)
{
    if (p[0x45a] != 0)
        return func_02009110(*(struct Sub020090B0Obj * *)&((struct Obj00042 *)p)->f20, row, col);
    return 0;
}
