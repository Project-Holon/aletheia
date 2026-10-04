/*
 * function: func_021F2BD4
 * address: 0x021F2BD4
 * packet: pkt_ov029_021F2BD4
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02009160 0x02009160 thumb
 */
#include "../include/Obj00042.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Sub020090B0Obj;
extern u32 func_02009160(const struct Sub020090B0Obj *obj, int row, int col, int kind);
u32 func_021F2BD4(u8 *p, int row, int col, int kind)
{
    if (p[0x45a] != 0)
        return func_02009160(*(struct Sub020090B0Obj * *)&((struct Obj00042 *)p)->f20, row, col, kind);
    return 0;
}
