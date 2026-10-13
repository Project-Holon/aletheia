/*
 * function: GIMMICK39_GetDockCart
 * address: 0x021F3D98
 * packet: pkt_ov039_021F3D98
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GIMMICK39_GetDockLane 0x021F3DAC thumb ov039
 *   GIMMICK39_GetActiveCart 0x021F36F0 thumb ov039
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 GIMMICK39_GetDockLane(int i);
extern u8 GIMMICK39_GetActiveCart(u8 *p, int i);
u8 GIMMICK39_GetDockCart(u8 *p, int i) { return GIMMICK39_GetActiveCart(p, GIMMICK39_GetDockLane(i)); }
