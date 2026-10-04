/*
 * function: func_021C8DA0, func_021C8E24
 * unit: yes
 * address: 0x021C8DA0
 * packet: pkt_ov128_021C8DA0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216BFD4 0x0216BFD4 thumb ov010
 *   func_02045924 0x02045924 arm
 *   func_021C8F88 0x021C8F88 thumb ov128
 * extent: includes the eight-byte forwarding follower at 0x021C8E24.
 */
#include "../include/Obj00227.h"
#include "../include/Obj03544.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Big;
struct Sub020097BCObj;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *);
struct BigObj;
struct Strbuf;
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern char *func_0216BFD4(int,int,u32,u32,int,int,void *);
extern void func_02045924(struct Strbuf *o, const u16 *src);
char *func_021C8DA0(void *unused,char *q,int mode,int heap) {
 void *v;void *base;int idx;char *ret;unsigned kind;
 v=func_0200C0F0(func_02012EBC(((struct Obj00227 *)q)->f4));
 base=(void *)func_0201283C(((struct Obj00227 *)q)->f4);idx=*(u8 *)(q+24+*(signed char *)&((struct Obj00227 *)q)->fB);
 kind=func_02009864(base,idx,9);
 if(mode==1 || kind==2) ret=func_0216BFD4(heap,4,65535,0,7,0,v);
 else ret=func_0216BFD4(heap,4,func_02009864(base,idx,8),0,7,0,v);
 if(((struct Obj00227 *)q)->f64==1) {func_02045924(((struct Obj03544 *)ret)->f20,(const u16 *)(((struct Obj00227 *)q)->f60));((struct Obj00227 *)q)->f64=0;}
 return ret;
}
extern void func_021C8F88(void *,void *,void *,int);
void func_021C8E24(void *p,void *q,void *r,int s) {
 func_021C8F88(p,q,r,s);
}
