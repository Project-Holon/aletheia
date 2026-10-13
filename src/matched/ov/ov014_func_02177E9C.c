/*
 * function: NET_WHPIPE_TaskFinishEnd
 * address: 0x02177E9C
 * packet: pkt_ov014_02177E9C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02178E4C 0x02178E4C thumb ov014
 *   WIH_FreeWork 0x02179158 thumb ov014
 *   func_02177704 0x02177704 thumb ov014
 */

extern int func_02178E4C(void);
extern void WIH_FreeWork(void);
extern void func_02177704(void);
void NET_WHPIPE_TaskFinishEnd(void) { if (func_02178E4C() == 0) { WIH_FreeWork(); func_02177704(); } }
