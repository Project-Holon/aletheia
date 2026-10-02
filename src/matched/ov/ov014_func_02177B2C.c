/*
 * function: func_02177B2C
 * address: 0x02177B2C
 * packet: pkt_ov014_02177B2C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: integer address sum preserves base+0x58 and the final pointer+8;
 * plain pointer additions fold these into base+0x60 (r1 DIFF, r2 EXACT).
 * symbols:
 *   g_021797A4 0x021797A4 data ov014 a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *g_021797A4;
u8 *func_02177B2C(int i) { u8 *base = g_021797A4; if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0) return (u8 *)((unsigned int)(base + 0x58) + i * 0xC0) + 8; return 0; }
