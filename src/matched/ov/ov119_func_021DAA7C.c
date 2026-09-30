/*
 * function: func_021DAA7C
 * address: 0x021DAA7C
 * packet: pkt_ov119_021DAA7C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E31FC 0x021E31FC thumb ov119
 *   func_021DAA4C 0x021DAA4C thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_02039C68 0x02039C68 arm
 */
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int),func_021E31FC(void *),func_021DAA4C(void *);
extern unsigned func_020399A8(void);
extern int func_0203D3F8(unsigned,unsigned,unsigned,unsigned,void *,int,int,int);
extern void func_02039C68(unsigned,unsigned,unsigned);
void func_021DAA7C(char *p) {
 if(func_021D8A24(p)) {
  if(func_0203D3F8(func_020399A8(),255,0xc0e,0x2d6,p+16,0,0,1)) {
   func_02039C68(func_020399A8(),18,8);func_021D8E84(p,(int)func_021DAA4C);
  }
 } else {func_021E31FC(p);func_021D8E84(p,(int)func_021DAA4C);}
}
