/*
 * function: func_021DAB34
 * address: 0x021DAB34
 * packet: pkt_ov119_021DAB34
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D89A8 0x021D89A8 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAB0C 0x021DAB0C thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021D8A24(void *),func_021D89A8(void *);
extern void *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void func_021D8E84(void *,int),func_021DAB0C(void *);
void func_021DAB34(char *p) {
 u8 b[2];
 if(func_021D8A24(p)) {
  b[0]=*(int *)(p+0x630);b[1]=func_021D89A8(p);
  if(func_0203D3A8(func_020399A8(),0xc10,2,(void *)b)) {*(int *)(p+0xf2c)=0;func_021D8E84(p,(int)func_021DAB0C);}
 } else {
  p[0x11f2]=*(int *)(p+0x630);*(u16 *)(p+0x107e)=*(u8 *)(p+0x11f2)*160+16;
  *(int *)(p+0xf2c)=0;func_021D8E84(p,(int)func_021DAB0C);
 }
}
