/*
 * function: func_021DF37C
 * address: 0x021DF37C
 * packet: pkt_ov119_021DF37C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF338 0x021DF338 thumb ov119
 */
typedef unsigned char u8;
extern unsigned func_020399A8(void);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, void *d);
extern void func_02039C68(unsigned,unsigned,unsigned);
extern int func_021E12AC(char *);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
extern void func_021DF338(void *);
void func_021DF37C(u8 *p) {
 unsigned h=func_020399A8();
 u8 b;
 if(func_021E12AC((char *)p)) {
  if(func_021D8A24(p)) {
   b=10;
   if(func_0203D3A8((void *)h,0xc00,1,&b)) {
    func_02039C68(func_020399A8(),26,8);
    func_021D8E84(p,(int)func_021DF338);return;
   }
  } else {p[0x11e0]=10;p[0x11e1]=10;func_021D8E84(p,(int)func_021DF338);}
 }
}
