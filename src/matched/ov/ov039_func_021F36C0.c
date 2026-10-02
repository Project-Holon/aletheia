/*
 * function: func_021F36C0
 * address: 0x021F36C0
 * packet: pkt_ov039_021F36C0
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F4C58 0x021F4C58 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 d_021F4C58[][2];
u8 func_021F36C0(int a, int b) { u8 i; for (i = 0; i < 9; i++) { if (d_021F4C58[i][0] == a && d_021F4C58[i][1] == b) return i; } return 0xff; }
