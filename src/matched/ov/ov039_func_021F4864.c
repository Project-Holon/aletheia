/*
 * function: func_021F4864
 * address: 0x021F4864
 * packet: pkt_ov039_021F4864
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F4D78 0x021F4D78 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_021F4D78[][2];
int func_021F4864(u32 a, u32 b, u8 *out) { u8 i; for (i = 0; i < 2; i++) { if (d_021F4D78[a][i] == b) { *out = i; return 1; } } return 0; }
