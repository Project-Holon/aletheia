/*
 * function: func_021F3D98
 * address: 0x021F3D98
 * packet: pkt_ov039_021F3D98
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F3DAC 0x021F3DAC thumb ov039
 *   func_021F36F0 0x021F36F0 thumb ov039
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021F3DAC(int i);
extern u8 func_021F36F0(u8 *p, int i);
u8 func_021F3D98(u8 *p, int i) { return func_021F36F0(p, func_021F3DAC(i)); }
