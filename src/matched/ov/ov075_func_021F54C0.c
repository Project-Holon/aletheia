/*
 * function: func_021F54C0
 * address: 0x021F54C0
 * packet: pkt_ov075_021F54C0
 * region: ov075
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 */
extern void func_02030EAC(void *);
void func_021F54C0(void *p,int *flag) { *(unsigned int *)0x04000064=0x81330010; func_02030EAC(p); if(flag) *flag=1; }
