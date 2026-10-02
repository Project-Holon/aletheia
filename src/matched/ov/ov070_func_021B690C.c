/*
 * function: func_021B690C
 * address: 0x021B690C
 * packet: pkt_ov070_021B690C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B68E8 0x021B68E8 thumb ov070
 */
typedef unsigned short u16;
extern int func_021B68E8(u16);
int func_021B690C(u16 id)
{
    if (func_021B68E8(id)) return 1;
    if (id == 0x268 || id == 0x269) return 2;
    return 0;
}
