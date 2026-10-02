/*
 * function: func_02157A30
 * address: 0x02157A30
 * packet: pkt_ov010_02157A30
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02179D3C 0x02179D3C thumb ov015
 *   func_0203CEAC 0x0203CEAC arm
 *   func_02157960 0x02157960 thumb ov010
 *   func_021579B0 0x021579B0 thumb ov010
 */
extern int func_02179D3C(void);
extern int func_0203CEAC(int);
extern void func_02157960(int, int, int);
extern void func_021579B0(void);
void func_02157A30(int p) { if (func_02179D3C()) func_0203CEAC(0); func_02157960(p, (int)func_021579B0, 0x102); }
