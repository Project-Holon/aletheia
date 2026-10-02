/*
 * function: func_02164564
 * address: 0x02164564
 * packet: pkt_ov010_02164564
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E04 0x02013E04 thumb
 *   func_02013C50 0x02013C50 thumb
 */

typedef unsigned short u16;
extern u16 func_02012AC8(void *);
extern int func_02013E04(u16);
extern int func_02013C50(u16);
int func_02164564(void *a, void *b, void *c) { u16 v=func_02012AC8(c); if (!func_02013E04(v)) return 0; if (func_02013C50(v)) return 1; return 0; }
