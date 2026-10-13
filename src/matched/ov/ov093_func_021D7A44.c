/*
 * function: BTL_CALC_CalcBaseDamage
 * address: 0x021D7A44
 * packet: pkt_ov093_021D7A44
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
u32 BTL_CALC_CalcBaseDamage(u32 a,u32 b,u32 c,u32 d) { return (a*b*(2*c/5+2)/d)/50+2; }
