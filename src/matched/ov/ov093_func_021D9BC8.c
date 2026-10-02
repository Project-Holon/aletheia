/*
 * unit: yes
 * function: func_021D9BC8, func_021D9BEC
 * address: 0x021D9BC8
 * packet: pkt_ov093_021D9BC8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0860 0x021F0860 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);
void func_021D9BC8(int a,int b,int c) { unsigned char v; if(c==func_021D775C(3)) { v=func_021D775C(0x2c)+1; func_021D76BC(0x2c,v); } }
extern unsigned int d_021F0860;
void *func_021D9BEC(int *p) { *p=1; return &d_021F0860; }
