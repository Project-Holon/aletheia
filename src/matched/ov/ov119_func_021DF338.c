/*
 * function: func_021DF338
 * address: 0x021DF338
 * packet: pkt_ov119_021DF338
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF210 0x021DF210 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;

extern unsigned func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
extern void func_021DF210(char *p);
void func_021DF338(void *p) {
 unsigned h=func_020399A8();
 u8 b;
 if(func_021D8A24(p)) {
  b=1;
  if(func_0203D3A8((void *)h,0xc0f,1,&b)) {func_021D8E84(p,(int)func_021DF210);return;}
 } else {func_021D8E84(p,(int)func_021DF210);}
}
