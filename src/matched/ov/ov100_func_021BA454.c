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
extern int func_020450F0(int,int,int,int,unsigned char,unsigned char,unsigned char);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(int,int,unsigned short,int);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *);
void func_021BA454(int text,int a) {
 if(*(int *)(a+0x280)==0) {
  int v=func_020450F0(5,1,8,18,4,13,0);
  *(int *)(a+0x280)=v;
  func_02045374((struct Cfg *)v);
  func_0201F73C(*(int *)(a+0x280),0,*(int *)(a+0x304),14);
 }
 func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)(a+0x280))),255);
 func_02045CAC((struct MsgBank *)(*(int *)(a+0x288)),text,(void *)(*(int *)(a+0x294)));
 func_0201EFA4((struct WordSet *)(*(int *)(a+0x28c)),0,func_02009A34((struct Sub020097BCObj *)func_0201283C((const struct BigObj *)(**(int **)(a+0x244)))),2,1,1);
 func_0201EFA4((struct WordSet *)(*(int *)(a+0x28c)),1,32,2,1,1);
 func_0201F250((struct WordSet *)(*(int *)(a+0x28c)),(void *)(*(int *)(a+0x298)),(void *)(*(int *)(a+0x294)));
 func_0201C7A4((void *)((int)func_02045770((struct Descriptor *)*(int *)(a+0x280))),0,2,(void *)(*(int *)(a+0x298)),(void *)(*(int *)(a+0x290)));
 func_02045334((struct Descriptor *)*(int *)(a+0x280));
}
