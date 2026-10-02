/*
 * unit: yes
 * function: func_021DEBB4, func_021DEBE0
 * address: 0x021DEBB4
 * packet: pkt_ov093_021DEBB4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes store-return follower 0x021DEBE0.
 * symbols:
 *   d_021F16DC 0x021F16DC data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021DD008 0x021DD008 thumb ov093
 */
extern int func_021D775C(int);
extern int d_021F16DC;
extern void func_021D7704(int,int);
extern int func_021DD008(int);
void func_021DEBB4(int a,int b,int c) { if(c==func_021D775C(3)) { if(func_021D775C(56)>3) func_021D7704(53,func_021DD008(a)); } }
int *func_021DEBE0(int *p) { *p=2; return &d_021F16DC; }
