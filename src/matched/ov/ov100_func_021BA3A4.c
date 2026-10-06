/*
 * function: func_021BA3A4
 * address: 0x021BA3A4
 * packet: pkt_ov100_021BA3A4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 0x021BA452.
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj00060.h"
struct Word { int x; };
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
typedef signed short   s16;
struct Cfg;
struct CharBuf;
struct MsgBank;
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *);
void func_021BA3A4(struct Word *p,int a) {
 func_02049B40(23,5,4,0x1a0,32,((struct Obj00060 *)a)->f278);
 if(*(int *)&((struct Obj00060 *)a)->f27C==0) {
  int v=func_020450F0(5,1,1,30,5,13,0);
  *(int *)&((struct Obj00060 *)a)->f27C=v;
  func_02045374((struct Cfg *)v);
  func_0201F73C((void *)(*(int *)&((struct Obj00060 *)a)->f27C),0,(unsigned short)(((struct Obj00060 *)a)->f304),14);
 }
 func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj00060 *)a)->f27C)),255);
 ((struct Obj00060 *)a)->fCB0=p->x;
 func_02045CAC((struct MsgBank *)(((struct Obj00060 *)a)->f288),p->x,(void *)(((struct Obj00060 *)a)->f298));
 func_0201C7A4((void *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj00060 *)a)->f27C)),4,4,(void *)(((struct Obj00060 *)a)->f298),(void *)(((struct Obj00060 *)a)->f290));
 func_02045334((struct Descriptor *)*(int *)&((struct Obj00060 *)a)->f27C);
}
