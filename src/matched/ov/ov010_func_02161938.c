/*
 * function: func_02161938
 * address: 0x02161938
 * packet: pkt_ov010_02161938
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216DE54 0x0216DE54 thumb ov010
 *   func_0216DE94 0x0216DE94 thumb ov010
 */

extern void *func_0216DE54(void *, unsigned int);
extern void *func_0216DE94(void *, unsigned int);
void func_02161938(void *p, unsigned int id) { if (id == 0xf2) func_0216DE54(p, 0x30); else if (id != 0xf1) func_0216DE94(p, id); }
