/*
 * function: func_021C867C
 * address: 0x021C867C
 * packet: pkt_ov128_021C867C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045808 0x02045808 arm
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 */
#include "../include/Obj00329.h"
#include "../include/Obj03811.h"
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
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,int,int,void *,void *,void *,void *,int,u16,int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_02045808(struct U16Vec *vec);
extern void func_021CA3E8(int);
void func_021C867C(u8 *p,u8 *a,int n,u16 heap)
{
    void *text;
    void *q;
    if (((struct Obj00329 *)a)->f2C) {
        func_0201CE48(((struct Obj00329 *)a)->f2C);
        ((struct Obj00329 *)a)->f2C = 0;
    }
    func_02043B5C(func_02045770(((struct Obj03811 *)p)->f108),15);
    text=func_020457B0(128,heap);
    func_02045CAC(((struct Obj00329 *)a)->f4,n,text);
    func_0201F250(((struct Obj00329 *)a)->f0,((struct Obj03811 *)p)->f110,text);
    ((struct Obj00329 *)a)->f2C=func_0201CCE4(((struct Obj03811 *)p)->f108,0,0,((struct Obj03811 *)p)->f110,((struct Obj00329 *)a)->f17C,(void *)func_02012FFC(),((struct Obj00329 *)a)->f28,10,((struct Obj00329 *)a)->f180,0);
    func_0201F73C(((struct Obj03811 *)p)->f108,2,70,11);
    q=((struct Obj03811 *)p)->f108;
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(func_02045730(q));
    func_02045808(text);
    func_021CA3E8(0);
}
