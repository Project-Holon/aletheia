/*
 * function: FIELD_GIMMICK_CART_LANES_FindDockAt
 * address: 0x021F36C0
 * packet: pkt_ov039_021F36C0
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sDockCells 0x021F4C58 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 sDockCells[][2];
u8 FIELD_GIMMICK_CART_LANES_FindDockAt(int a, int b) { u8 i; for (i = 0; i < 9; i++) { if (sDockCells[i][0] == a && sDockCells[i][1] == b) return i; } return 0xff; }
