/*
 * function: func_021F3DB8
 * address: 0x021F3DB8
 * packet: pkt_ov039_021F3DB8
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Keep base-plus-index before the far 0x21F0 offset. The subscript
 *       p[index + 0x21F0] adds the constant to the index first (five-byte DIFF).
 * symbols:
 *   func_021F3DAC 0x021F3DAC thumb ov039
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021F3DAC(int i);
int func_021F3DB8(signed char *p, int i) { int v; v = *(p + func_021F3DAC(i) + 0x21f0); if (v == -1) return 0; return v == i; }
