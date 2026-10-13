/*
 * function: func_0217771C
 * address: 0x0217771C
 * packet: pkt_ov014_0217771C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 *   func_0217731C 0x0217731C thumb ov014
 */

typedef unsigned char u8;
extern u8 *g_pWhPipeWork;
extern int func_0217731C(u8 *obj);
int func_0217771C(u8 *obj) { u8 *base = g_pWhPipeWork; void (*fn)(void); if (func_0217731C(obj) == 0) return 0; fn = *(void (**)(void))(base + 0xC60); if (fn != 0) fn(); return 1; }
