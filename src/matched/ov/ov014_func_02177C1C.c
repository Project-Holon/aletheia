/*
 * unit: yes
 * function: func_02177C1C, func_02177C30, func_02177C3C, func_02177C44
 * address: 0x02177C1C
 * packet: pkt_ov014_02177C1C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: C30 truncates r1 to u16 at the tail call; its extern reflects that caller width.
 * symbols:
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_02179368 0x02179368 thumb ov014
 *   func_02178E38 0x02178E38 thumb ov014
 *   func_021795A4 0x021795A4 thumb ov014
 */

extern int func_02178E4C(void);
int func_02177C1C(void) { if (func_02178E4C() == 2) return 1; return 0; }
extern int func_02179368(int a, unsigned short b, int c);
typedef unsigned short u16;
extern u16 func_02178E38(void);
extern unsigned short func_021795A4(void);
int func_02177C30(int a, unsigned int b, int c) { return func_02179368(a, b, c); }
unsigned int func_02177C3C(void) { return func_02178E38(); }
int func_02177C44(void) { return func_021795A4(); }
