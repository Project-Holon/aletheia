/*
 * function: func_021DAA4C
 * address: 0x021DAA4C
 * packet: pkt_ov119_021DAA4C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021E31FC 0x021E31FC thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAA18 0x021DAA18 thumb ov119
 */
extern int func_021D8A24(void *);
extern unsigned func_020399A8(void);
extern unsigned func_02039CB4(unsigned,unsigned,unsigned);
extern void func_021E31FC(void *),func_021D8E84(void *,int),func_021DAA18(void *);
void func_021DAA4C(void *p) {
 if(!func_021D8A24(p) || func_02039CB4(func_020399A8(),18,8)!=0) {
  func_021E31FC(p);
  func_021D8E84(p,(int)func_021DAA18);
 }
}
