/*
 * function: func_021F2BB8
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
typedef unsigned char u8;
struct Sub020090B0Obj;
extern int func_02009134(const struct Sub020090B0Obj *obj, int row, int col);
int func_021F2BB8(u8 *p, int row, int col)
{
    if (p[0x45a] != 0)
        return func_02009134(*(struct Sub020090B0Obj **)(p + 0x20), row, col);
    return 0;
}
