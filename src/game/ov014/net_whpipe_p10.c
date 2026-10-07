/*
 * file:     net_whpipe_p10.c
 * unit:     yes
 * function: func_02177B2C, func_02177B58
 * address:  0x02177B2C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A4 0x021797A4 data ov014 a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

u8 *func_02177B2C(int i);
u8 *func_02177B58(int i);
extern u8 *g_021797A4;

/*
 * lever: integer address sum preserves base+0x58 and the final pointer+8;
 * plain pointer additions fold these into base+0x60 (r1 DIFF, r2 EXACT).
 */
u8 *func_02177B2C(int i) { u8 *base = g_021797A4; if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0) return (u8 *)((unsigned int)(base + 0x58) + i * 0xC0) + 8; return 0; }

u8 *func_02177B58(int i) { u8 *base = g_021797A4; if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0) return base + 0xC + i * 0xC0; return 0; }
