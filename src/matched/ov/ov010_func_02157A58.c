/*
 * function: DELIVERY_IRC_StepExitChild
 * address: 0x02157A58
 * packet: pkt_ov010_02157A58
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_Exit 0x0203CEAC arm
 *   DELIVERY_IRC_SetStepAtLine 0x02157960 thumb ov010
 *   DELIVERY_IRC_StepFinish 0x021579B0 thumb ov010
 */
extern int GFL_NET_Exit(int);
extern void DELIVERY_IRC_SetStepAtLine(int, int, int);
typedef unsigned char  u8;
extern void DELIVERY_IRC_StepFinish(u8 *p);
void DELIVERY_IRC_StepExitChild(int p) { GFL_NET_Exit(0); DELIVERY_IRC_SetStepAtLine(p, (int)DELIVERY_IRC_StepFinish, 0x10a); }
