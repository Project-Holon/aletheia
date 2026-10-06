/*
 * function: func_021BA454
 * address: 0x021BA454
 * packet: pkt_ov100_021BA454
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes at 0x021BA52E.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009A34 0x02009A34 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj01246.h"
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
typedef signed short   s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Sub020097BCObj;
struct WordSet;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *);
void func_021BA454(int text,int a) {
 if(((struct Obj01246 *)a)->f280==0) {
  int v=(int)func_020450F0((int)5,(int)1,(int)8,(int)18,4,13,0);
  ((struct Obj01246 *)a)->f280=v;
  func_02045374((struct Cfg *)v);
  func_0201F73C((void *)(((struct Obj01246 *)a)->f280),0,(unsigned short)(((struct Obj01246 *)a)->f304),14);
 }
 func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj01246 *)a)->f280)),255);
 func_02045CAC((struct MsgBank *)(((struct Obj01246 *)a)->f288),text,(void *)(((struct Obj01246 *)a)->f294));
 func_0201EFA4((struct WordSet *)(((struct Obj01246 *)a)->f28C),0,func_02009A34((struct Sub020097BCObj *)func_0201283C((const struct BigObj *)(**(int * *)&((struct Obj01246 *)a)->f244))),2,1,1);
 func_0201EFA4((struct WordSet *)(((struct Obj01246 *)a)->f28C),1,32,2,1,1);
 func_0201F250((struct WordSet *)(((struct Obj01246 *)a)->f28C),(void *)(((struct Obj01246 *)a)->f298),(void *)(((struct Obj01246 *)a)->f294));
 func_0201C7A4((void *)((int)func_02045770((struct Descriptor *)((struct Obj01246 *)a)->f280)),0,2,(void *)(((struct Obj01246 *)a)->f298),(void *)(((struct Obj01246 *)a)->f290));
 func_02045334((struct Descriptor *)((struct Obj01246 *)a)->f280);
}
