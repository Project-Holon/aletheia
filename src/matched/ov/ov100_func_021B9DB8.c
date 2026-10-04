/*
 * function: func_021B9DB8
 * address: 0x021B9DB8
 * packet: pkt_ov100_021B9DB8
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9D6C 0x021B9D6C thumb ov100
 */
#include "../include/Obj13709.h"
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u16 func_02039338(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B9D6C(int a);
void func_021B9DB8(int a) {
 if(func_02039CB4((struct Link *)func_020399A8(),0x7c,12)!=0) {
  int i=func_02039338();
  int n=((struct Obj13709 *)a)->f24C;
  switch(n) {
  case 1: case 2: case 3: case 4: {
   int v=*(int *)(a+(1-i)*4+0x250);
   if(n>v) *(int *)(((struct Obj13709 *)a)->f244+0x1c)=v;
   break;
  }
  }
  func_021B95B8((u8 *)a,(u32)func_021B9D6C);
 }
}
