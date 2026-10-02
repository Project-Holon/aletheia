/*
 * function: func_021DAA18
 * address: 0x021DAA18
 * packet: pkt_ov119_021DAA18
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA9F0 0x021DA9F0 thumb ov119
 */
extern void func_0202208C(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_021D8E84(void *,int);
extern void func_021DA9F0(void *);
void func_021DAA18(char *p) {
 func_0202208C(4,0,0,0,6,1,*(unsigned short *)(p+0x5f4));
 func_021D8E84(p,(int)func_021DA9F0);
}
