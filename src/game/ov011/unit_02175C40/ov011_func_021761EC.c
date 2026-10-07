/*
 * function: func_021761EC
 * address: 0x021761EC
 * packet: pkt_ov011_021761EC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02176200 0x02176200 thumb ov011
 */
typedef unsigned char u8;
extern void func_02176200(char *p);
u8 func_021761EC(char *p)
{
    u8 value;
    value = ((u8 *)p)[0x1a3];
    func_02176200(p);
    return value;
}
