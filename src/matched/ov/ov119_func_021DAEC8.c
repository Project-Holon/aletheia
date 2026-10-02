/*
 * function: func_021DAEC8
 * address: 0x021DAEC8
 * packet: pkt_ov119_021DAEC8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAE2C 0x021DAE2C thumb ov119
 */
extern int func_021E12AC(void *);
extern unsigned func_020399A8(void);
extern void func_02039C68(unsigned,unsigned,unsigned);
extern void func_021D8E84(void *,int),func_021DAE2C(void *);
void func_021DAEC8(void *p) {
 if(func_021E12AC(p)) {
  func_02039C68(func_020399A8(),25,8);
  func_021D8E84(p,(int)func_021DAE2C);
 }
}
