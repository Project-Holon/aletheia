/*
 * function: func_021DB6D0
 * address: 0x021DB6D0
 * packet: pkt_ov131_021DB6D0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02019B44 0x02019B44 thumb
 */
typedef signed char s8;
typedef unsigned int u32;
extern s8 func_02019B44(u32 a, u32 n);
int func_021DB6D0(u32 a, u32 b, unsigned char c, u32 d) {
 switch (func_02019B44(c, d)) {
 case 1: return 0x3d20;
 case -1: return 0x3d40;
 case 0:
 default: return 0x3c40;
 }
}
