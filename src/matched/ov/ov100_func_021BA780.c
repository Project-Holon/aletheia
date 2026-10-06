/*
 * function: func_021BA780
 * address: 0x021BA780
 * packet: pkt_ov100_021BA780
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: original entry R0 is preserved at 0201DD68; that callee's full
 *   matched body ignores it. 021BA028 likewise ignores the supplied context,
 *   but the original explicitly supplies it, so the caller retains it.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201EC74 0x0201EC74 thumb
 *   func_021BA624 0x021BA624 thumb ov100
 *   func_021BA028 0x021BA028 thumb ov100
 *   func_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_0204E720 0x0204E720 arm
 *   func_021BA668 0x021BA668 thumb ov100
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA1C8 0x021BA1C8 thumb ov100
 *   func_0201C440 0x0201C440 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_021B96EC 0x021B96EC thumb ov100
 *   func_021B974C 0x021B974C thumb ov100
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAA9C 0x021BAA9C thumb ov100
 *   d_020A1448 0x020A1448 data a4
 *   d_021BB6F0 0x021BB6F0 data a4
 */
#include "../include/Obj00178.h"
#include "../include/Obj22083.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_020A1448[],d_021BB6F0[];
struct Bank;
struct GfFont;
struct MsgBank;
struct R;
struct U16Vec;
struct Cfg;
extern void func_0201DD68(void);
extern void func_021BA624(unsigned a);
extern void func_021BA028(char *);
extern void func_021BA668(int a);
extern void func_021BA1C8(void);
extern void func_021BAA9C(int a);
extern void func_021B96EC(char *);
extern void func_021B974C(int,int,int,int,int);
extern void func_021B95B8(u8 *p, u32 v);
extern int func_0201EC74(u32,u32,u32);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern int func_020056A0(u32,u32,u32);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_0204E720(u32,int,int,int);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_02082D44(const void *,void *,u32);
extern u32 func_020307B0(void *p);
void func_021BA780(char *p) {
 void *owner;
 void *raw;
 void *resource;
 int i;
 func_0201DD68();
 ((struct Obj00178 *)p)->f28C=func_0201EC74(11,200,((struct Obj00178 *)p)->f278);
 func_021BA624((unsigned int)p);func_021BA028(p);
 ((struct Obj00178 *)p)->f298=(int)func_020457B0(200,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f294=(int)func_020457B0(200,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f290=(int)func_0201D7EC(23,0,0,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f288=(int)func_02045B38(0,2,46,((struct Obj00178 *)p)->f278);
 owner=func_020490F4(28,((struct Obj00178 *)p)->f278);
 func_02049B68(owner,1,0,0,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f2FC=(int)func_02049740(owner,6,0,0,0,((struct Obj00178 *)p)->f278);
 if(((struct Obj00178 *)p)->f24C!=5) func_02049990(owner,13,1,0,(u16)(((struct Obj00178 *)p)->f2FC),0,0,((struct Obj00178 *)p)->f278);
 else {func_02049990(owner,13,0,0,(u16)(((struct Obj00178 *)p)->f2FC),0,0,((struct Obj00178 *)p)->f278);func_02049990(owner,14,1,0,(u16)(((struct Obj00178 *)p)->f2FC),0,0,((struct Obj00178 *)p)->f278);}
 func_02049238(owner);
 owner=func_020490F4(29,((struct Obj00178 *)p)->f278);
 func_02049B68(owner,1,4,0,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f308=(int)func_02049740(owner,4,4,0,0,((struct Obj00178 *)p)->f278);
 func_02049990(owner,9,4,0,(u16)(((struct Obj00178 *)p)->f308),0,0,((struct Obj00178 *)p)->f278);func_02049238(owner);
 ((struct Obj00178 *)p)->f304=(int)func_0201F5DC((void *)5,14,0,((struct Obj00178 *)p)->f278);
 func_0204E720(3,16,0,2);func_021BA668((int)p);
 func_0204A48C((const struct Cfg *)d_020A1448,(u32)d_021BB6F0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f2B4=(int)func_0204B100(40,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f2B0=func_020056A0((u32)func_021BA1C8,(u32)p,0);
 ((struct Obj00178 *)p)->fCB8=func_0201C440((void *)(((struct Obj00178 *)p)->f278));
 ((struct Obj00178 *)p)->fCC4=(int)func_02027F60(6,9,((struct Obj00178 *)p)->f290,((struct Obj00178 *)p)->fCB8,((struct Obj00178 *)p)->f278);
 func_021B96EC(p);
 if(((struct Obj00178 *)p)->f24C!=5) {
  func_021B974C((int)p,57,154,2,10);func_021B974C((int)p,128,113,4,2);func_021B974C((int)p,200,38,0,11);func_021B974C((int)p,128,77,5,3);
 } else {
  func_021B974C((int)p,57,154,0,4);func_021B974C((int)p,198,154,1,5);func_021B974C((int)p,200,38,2,6);func_021B974C((int)p,55,38,3,7);func_021B974C((int)p,152,146,6,0);func_021B974C((int)p,103,146,7,1);func_021B974C((int)p,152,46,4,0);func_021B974C((int)p,103,46,5,1);
 }
 func_02043534((int)19);func_020435F4((int)23);
 ((struct Obj00178 *)p)->f242=((struct Obj00178 *)p)->f278;
 owner=func_020490F4(28,((struct Obj00178 *)p)->f242);
 raw=func_02049F78(owner,2,(u32)(&resource),((struct Obj00178 *)p)->f242);
 func_02082D44(((struct Obj22083 *)resource)->fC,p,0x120);
 for(i=0;i<9;i++) func_02082D44(p+(8-i)*32,p+(i+9)*32,32);
 func_020307B0(raw);func_02049238(owner);func_021B95B8((u8 *)p,(u32)func_021BAA9C);
}
