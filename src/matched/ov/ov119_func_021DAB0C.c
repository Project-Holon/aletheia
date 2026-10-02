/*
 * function: func_021DAB0C
 * address: 0x021DAB0C
 * packet: pkt_ov119_021DAB0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E3E00 0x021E3E00 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAAE4 0x021DAAE4 thumb ov119
 */
extern int func_021E3E00(char *,int);
extern void func_021D8E84(char *,int),func_021DAAE4(char *);
void func_021DAB0C(char *p) {
 if(func_021E3E00(p,*(int *)(p+0xf2c)-1)) {
  *(int *)(p+0xf2c)=0;
  func_021D8E84(p,(int)func_021DAAE4);
 }
}
