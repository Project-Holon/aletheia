/*
 * function: func_021BA1C4
 * address:  0x021BA1C4
 * packet:   pkt_ov068_021BA1C4
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_020457B0 takes two arguments: the u16 stack parameter s2 is loaded
 * into r1 before `movs r0, #0xff` and stays there as the second argument
 * (heap id), which is why it is loaded ahead of the strh that stores it.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02028470  0x02028470  thumb
 *   BMP_WIN_GetPalette  0x02045778  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../include/Obj01227.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082BCC(void *p, u32 a, u32 b);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02028470(u8 *p, u32 v);
extern u8 BMP_WIN_GetPalette(struct Descriptor *p);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);

void func_021BA1C4(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u16 s2)
{
    u32 w;

    func_02082BCC(p, 0, 0x38);
    ((struct Obj01227 *)p)->f18 = 4;
    ((struct Obj01227 *)p)->f10 = a1;
    ((struct Obj01227 *)p)->f1A = s2;
    ((struct Obj01227 *)p)->f4 = a2;
    ((struct Obj01227 *)p)->f0 = a3;
    ((struct Obj01227 *)p)->f14 = (u32)func_020457B0(0xff, s2);
    ((struct Obj01227 *)p)->fC = s0;
    ((struct Obj01227 *)p)->f8 = 0;
    ((struct Obj01227 *)p)->f24 = s1;
    ((struct Obj01227 *)p)->f28 = 0;
    func_02028470(p + 0x2c, 0x406);
    func_0201F73C((void *)(((struct Obj01227 *)p)->f10), 2, 1, BMP_WIN_GetPalette((struct Descriptor *)a1));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01227 *)p)->f10)), (u8)((struct Obj01227 *)p)->f18);
    w = ((struct Obj01227 *)p)->f10;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    ((struct Obj01227 *)p)->f1C = ((struct Obj01227 *)p)->f10;
    p[0x20] = 0;
}
