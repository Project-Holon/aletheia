/*
 * function: func_021DAAE4
 * address: 0x021DAAE4
 * packet: pkt_ov119_021DAAE4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC62C 0x021DC62C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAA7C 0x021DAA7C thumb ov119
 */
extern void func_021DC62C(char *,int),func_021D8E84(char *,int),func_021DAA7C(char *);
void func_021DAAE4(char *p) {
 func_021DC62C(p,*(int *)(p+0xf2c)-1);
 if(*(int *)(p+0xf2c)>=24) func_021D8E84(p,(int)func_021DAA7C);
}
