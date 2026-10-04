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
#include "../include/Obj13900.h"
typedef unsigned short u16;

struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *,unsigned,unsigned);
extern void func_0215642C(int);
extern void func_021D8E84(void *,int);
extern void func_021DEE00(unsigned char *p);
void func_021DEEA8(void *p) {
 void *h=func_020399A8();
 ((struct Obj13900 *)p)->f109A=0;
 if(func_0203D3A8((void *)h,0xc11,1,(u32)((char *)p+0x11e6))) {
  func_02039C68((struct Link *)func_020399A8(),21,8);
  if(((struct Obj13900 *)p)->f118C==2) func_0215642C(0);
  func_021D8E84(p,(int)func_021DEE00);
 }
}
