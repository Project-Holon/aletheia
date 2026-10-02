/*
 * function: func_021B1F2C
 * address: 0x021B1F2C
 * packet: pkt_ov013_021B1F2C
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021B60D8 0x021B60D8 data a4
 *   func_021B24FC 0x021B24FC arm ov013
 */
extern unsigned int d_021B60D8[];
struct Node;
extern struct Node *func_021B24FC(unsigned int);
struct Node *func_021B1F2C(unsigned int i)
{
    if (d_021B60D8[4] == 0 || d_021B60D8[4] == 2) return 0;
    return func_021B24FC(i);
}
