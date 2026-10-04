/*
 * function: func_021E0130
 * address: 0x021E0130
 * packet: pkt_ov137_021E0130
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 021E01AE.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj03843.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C724(void *,void *,int,int,void *,void *,u16);
extern void func_02045334(struct Descriptor *),func_02045374(void *);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
void func_021E0130(u8 *p,int message)
{
    u8 *s;
    void *window,*owner,*data;
    s=p+3296;
    window=((struct Obj03843 *)s)->f10;
    func_02043B5C(func_02045770(window),15);
    func_0201F73C(window,2,1,14);
    func_02043B5C(func_02045770(window),15);
    func_02045CAC(((struct Obj03843 *)s)->f8,message,((struct Obj03843 *)s)->f5C);
    owner=((struct Obj03843 *)s)->f58;
    data=func_02045770(((struct Obj03843 *)s)->f28);
    func_0201C724(owner,data,0,0,((struct Obj03843 *)s)->f5C,((struct Obj03843 *)s)->f4,1088);
    ((struct Obj03843 *)s)->f2C=1;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}
