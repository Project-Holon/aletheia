/*
 * function: func_021DEEA8
 * address: 0x021DEEA8
 * packet: pkt_ov119_021DEEA8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_0215642C 0x0215642C thumb ov009
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DEE00 0x021DEE00 thumb ov119
 */
typedef unsigned short u16;

extern unsigned func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void func_02039C68(unsigned,unsigned,unsigned);
extern void func_0215642C(int);
extern void func_021D8E84(void *,int);
extern void func_021DEE00(unsigned char *p);
void func_021DEEA8(void *p) {
 unsigned h=func_020399A8();
 *(unsigned short *)((char *)p+0x109a)=0;
 if(func_0203D3A8((void *)h,0xc11,1,(char *)p+0x11e6)) {
  func_02039C68(func_020399A8(),21,8);
  if(*(int *)((char *)p+0x118c)==2) func_0215642C(0);
  func_021D8E84(p,(int)func_021DEE00);
 }
}
