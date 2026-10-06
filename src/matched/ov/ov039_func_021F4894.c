/*
 * function: func_021F4894
 * address: 0x021F4894
 * packet: pkt_ov039_021F4894
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F3DE4 0x021F3DE4 thumb ov039
 *   d_021F4BE4 0x021F4BE4 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F3DE4(void *p, u16 delta, u16 i);
extern const u16 d_021F4BE4[];
int func_021F4894(void *p, int i, u8 j) { if (func_021F3DE4(p, (u8)i, j + 1) <= (int)(d_021F4BE4[i] << 12)) return 1; return 0; }
