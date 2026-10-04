/*
 * function: func_021C7558
 * address: 0x021C7558
 * packet: pkt_ov128_021C7558
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045808 0x02045808 arm
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 */
#include "../include/Obj03280.h"
#include "../include/Obj05379.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
extern void func_0201CE48(struct Rec3 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,int,int,void *,void *,int,void *,int,u16,u16);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
extern void func_02045808(struct U16Vec *vec);
extern void func_021CA3E8(int);
void func_021C7558(u8 *p,u8 *ctx,unsigned v,unsigned heap)
{
    void *buf;
    void *obj;
    int font;
    if(((struct Obj03280 *)ctx)->f2C) {
        func_0201CE48(((struct Obj03280 *)ctx)->f2C);
        ((struct Obj03280 *)ctx)->f2C=0;
    }
    buf=func_020457B0(128,heap);
    func_02043B5C(func_02045770(((struct Obj05379 *)p)->f1C),15);
    func_02045CAC(((struct Obj03280 *)ctx)->f4,v,buf);
    func_0201F250(((struct Obj03280 *)ctx)->f0,((struct Obj05379 *)p)->f2C,buf);
    font=func_02012FFC();
    ((struct Obj03280 *)ctx)->f2C=func_0201CCE4(((struct Obj05379 *)p)->f1C,0,0,((struct Obj05379 *)p)->f2C,((struct Obj03280 *)ctx)->f17C,font,((struct Obj03280 *)ctx)->f28,10,((struct Obj03280 *)ctx)->f180,0);
    func_0201F73C(((struct Obj05379 *)p)->f1C,2,70,11);
    obj=((struct Obj05379 *)p)->f1C;
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
    func_02045808(buf);
    func_021CA3E8(0);
}
