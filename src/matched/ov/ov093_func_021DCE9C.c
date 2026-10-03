/*
 * function: func_021DCE9C
 * address: 0x021DCE9C
 * packet: pkt_ov093_021DCE9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: u8 result local reproduces 021DCEA6/021DCEA8 truncation in r0,
 * then shift-copy to r1; inline narrowing produced an extra register copy.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 */
extern int func_021D775C(int);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern void func_021D7704(int,int);
void func_021DCE9C(int a,int b,unsigned int c) { unsigned char k; k=func_021D775C(3); if(func_021B9A24(c,k)) func_021D7704(53,4506); }
