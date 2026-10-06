/*
 * function: func_021FC754
 * address: 0x021FC754
 * packet: pkt_ov186_021FC754
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021FC870 0x021FC870 thumb ov186
 *   func_0201C724 0x0201C724 thumb
 */
#include "../include/Obj02902.h"
typedef struct Pair {int x,y;} Pair;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021FC870(int,Pair *,const void *,void *,void *,Pair *);
typedef unsigned short u16;
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021FC754(char *p,void *a,void *b,void *font,unsigned short value)
{
    Pair xy;
    void *owner;
    func_02043B5C(func_02045770(((struct Obj02902 *)p)->fC),((struct Obj02902 *)p)->f14);
    func_02045CAC(a,(u32)b,((struct Obj02902 *)p)->f10);
    func_021FC870(((struct Obj02902 *)p)->f18,(Pair *)(p+28),func_02045770(((struct Obj02902 *)p)->fC),((struct Obj02902 *)p)->f10,font,&xy);
    owner=((struct Obj02902 *)p)->f8;
    func_0201C724(owner,(u32)func_02045770(((struct Obj02902 *)p)->f0),(short)xy.x,(short)xy.y,(u32)(((struct Obj02902 *)p)->f10),(u32)font,value);
    p[4]=1;
}
