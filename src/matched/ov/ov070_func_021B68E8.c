/*
 * function: func_021B68E8
 * address: 0x021B68E8
 * packet: pkt_ov070_021B68E8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Bounded bit mask is literal code; switch lowers to a compare chain.
 */
typedef unsigned short u16;
int func_021B68E8(u16 id)
{
    int result = 0;
    id = (u16)(id + 0xFFB4);
    if (id <= 3 && ((1 << id) & 0xB)) result = 1;
    return result;
}
