/*
 * function: DELIVERY_IRC_StepExitParent
 * address: 0x02157A30
 * packet: pkt_ov010_02157A30
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02179D3C 0x02179D3C thumb ov015
 *   GFL_NET_Exit 0x0203CEAC arm
 *   DELIVERY_IRC_SetStepAtLine 0x02157960 thumb ov010
 *   DELIVERY_IRC_StepFinish 0x021579B0 thumb ov010
 */
extern int func_02179D3C(void);
extern int GFL_NET_Exit(int);
extern void DELIVERY_IRC_SetStepAtLine(int, int, int);
typedef unsigned char  u8;
extern void DELIVERY_IRC_StepFinish(u8 *p);
void DELIVERY_IRC_StepExitParent(int p) { if (func_02179D3C()) GFL_NET_Exit(0); DELIVERY_IRC_SetStepAtLine(p, (int)DELIVERY_IRC_StepFinish, 0x102); }
