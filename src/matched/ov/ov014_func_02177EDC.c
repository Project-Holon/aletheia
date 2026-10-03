/*
 * function: func_02177EDC
 * address: 0x02177EDC
 * packet: pkt_ov014_02177EDC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: 79328 stores its r0 payload unchanged; caller passes a function pointer.
 * symbols:
 *   func_02179328 0x02179328 thumb ov014
 *   func_02177ED4 0x02177ED4 thumb ov014
 *   func_02177ED8 0x02177ED8 thumb ov014
 */

extern void func_02179328(void *v);
extern int func_02177ED4(void);
extern int func_02177ED8(void);
void func_02177EDC(int a) { if (a != 0) func_02179328(func_02177ED4); else func_02179328(func_02177ED8); }
