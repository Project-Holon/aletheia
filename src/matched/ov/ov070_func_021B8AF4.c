/*
 * function: func_021B8AF4
 * address: 0x021B8AF4
 * packet: pkt_ov070_021B8AF4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6100 0x021B6100 thumb ov070
 *   func_021B7250 0x021B7250 thumb ov070
 *   func_02036270 0x02036270 arm
 */
typedef unsigned int u32;
extern void func_021B6100(void *p, void (*callback)(void *));
extern void func_021B7250(void *p);
extern void func_02036270(u32 a, u32 b);
void func_021B8AF4(void *p)
{
    func_021B6100(p, func_021B7250);
    func_02036270(3, 6);
}
