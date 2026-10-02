/*
 * unit: yes
 * function: func_021DB9DC, func_021DBA00
 * address: 0x021DB9DC
 * packet: pkt_ov093_021DB9DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F06E8 0x021F06E8 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int d_021F06E8;
extern int func_021D775C(int);
extern int func_021D76BC(int,unsigned int);
void func_021DB9DC(int a,int b,int c) { if(c==func_021D775C(3) && (unsigned char)func_021D775C(0x25)==0) func_021D76BC(0x26,10); }
int *func_021DBA00(int *p) { *p=1; return &d_021F06E8; }
