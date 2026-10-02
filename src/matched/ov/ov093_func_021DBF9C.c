/*
 * unit: yes
 * function: func_021DBF9C, func_021DBFC8
 * address: 0x021DBF9C
 * packet: pkt_ov093_021DBF9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0D14 0x021F0D14 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DBFD4 0x021DBFD4 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int d_021F0D14;
extern int func_021D775C(int);
extern int func_021DBFD4(unsigned short);
extern int func_021D76BC(int,unsigned int);
void func_021DBF9C(int a,int b,int c) { if(c==func_021D775C(3) && func_021DBFD4(func_021D775C(0x12))) func_021D76BC(0x48,1); }
int *func_021DBFC8(int *p) { *p=5; return &d_021F0D14; }
