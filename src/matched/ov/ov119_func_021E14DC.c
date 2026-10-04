/*
 * function: func_021E14DC
 * address: 0x021E14DC
 * packet: pkt_ov119_021E14DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_0201AF80 0x0201AF80 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern void func_020307B0(void *);
typedef signed short   s16;
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
void func_021E14DC(void *a,void *b,int x,int y,int flag,char *p) {int v;u16 *t;if(!flag) {v=func_02017E1C(a,171,0);if(!((struct Obj00001 *)p)->f11F6) {t=func_0201AF80(((struct Obj00001 *)p)->f5F4,0);v=t[v];func_020307B0(t);}if(v==999) {func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),162,(void *)(*(int *)&((struct Obj00001 *)p)->f730));}else {func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),1,v,3,1,1);func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),27,(void *)(*(int *)&((struct Obj00001 *)p)->f734));func_0201F250((struct WordSet *)(*(int *)&((struct Obj00001 *)p)->f724),(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f734));}func_0201C7A4(b,x,y,(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f728));}}
