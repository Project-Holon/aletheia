/*
 * function: func_021B7E48
 * address: 0x021B7E48
 * packet: pkt_ov105_021B7E48
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7CA0 0x021B7CA0 thumb ov105
 *   func_021B7CA4 0x021B7CA4 thumb ov105
 *   func_021B7CA8 0x021B7CA8 thumb ov105
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201C724 0x0201C724 thumb
 */
#include "../include/Obj02813.h"
typedef unsigned char u8; typedef unsigned short u16; typedef short s16;
extern int func_021B7CA0(void *); extern int func_021B7CA4(void *); extern int func_021B7CA8(void *);
typedef unsigned int   u32;
struct Descriptor;
struct StrObj;
extern void *func_02045770(struct Descriptor *p); extern void func_02043B5C(void *,u8);
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u8 func_02045738(struct Descriptor *p); extern u8 func_02045740(void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b); extern unsigned func_0201D42C(void *,int);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021B7E48(u8 *p,void *a,int b)
{
 int bank; int font; int tag; u16 x,y;
 bank=func_021B7CA8(a); font=func_021B7CA4(a); tag=func_021B7CA0(a);
 func_02043B5C(func_02045770(((struct Obj02813 *)p)->f0),((struct Obj02813 *)p)->f10);
 func_02045CAC((struct MsgBank *)bank,b,((struct Obj02813 *)p)->fC);
 x=func_02045738(((struct Obj02813 *)p)->f0)*4; y=func_02045740(((struct Obj02813 *)p)->f0)*4;
 x-= (u16)(func_0201D304(((struct Obj02813 *)p)->fC,tag,0)/2);
 y-= (u16)(func_0201D42C(((struct Obj02813 *)p)->fC,tag)/2);
 func_0201C724((void *)font,(u32)func_02045770(((struct Obj02813 *)p)->f4),(s16)x,(s16)y,(u32)(((struct Obj02813 *)p)->fC),tag,15812);
 p[8]=1;
}
