/*
 * unit: yes
 * function: func_021DC104, func_021DC130
 * address: 0x021DC104
 * packet: pkt_ov093_021DC104
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0690 0x021F0690 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern int d_021F0690;
extern int func_021D775C(int);
extern void *func_021C7CF4(void *,int);
extern int func_021D5B48(void *);
extern void func_021D7704(int,int);
void func_021DC104(int a,void *b,int c) { int k=4; if(c==func_021D775C(k) && func_021D5B48(func_021C7CF4(b,c))) func_021D7704(0x35,k<<9); }
int *func_021DC130(int *p) { *p=1; return &d_021F0690; }
