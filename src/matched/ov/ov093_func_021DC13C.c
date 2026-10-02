/*
 * unit: yes
 * function: func_021DC13C, func_021DC164
 * address: 0x021DC13C
 * packet: pkt_ov093_021DC13C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0780 0x021F0780 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern int d_021F0780;
extern int func_021D775C(int);
extern int func_021B9A24(unsigned int,unsigned int);
extern void func_021D7704(int,int);
void func_021DC13C(int a,int b,unsigned int c) { unsigned char k; k=func_021D775C(4); if(k!=c && func_021B9A24(c,k)) func_021D7704(0x35,3<<10); }
int *func_021DC164(int *p) { *p=1; return &d_021F0780; }
