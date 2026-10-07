/*
 * file:     unit_021B95A0_p05.c
 * unit:     yes
 * function: func_021BA194, func_021BA1C4, func_021BA254, func_021BA278, func_021BA28C
 * address:  0x021BA194
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02028470  0x02028470  thumb
 *   func_02045778  0x02045778  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 */
#include "../../matched/include/Obj05150.h"
#include "../../matched/include/Obj01227.h"
#include "../../matched/include/Obj07683.h"
#include "../../matched/include/Obj00884.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct Rec3;
struct MsgBank;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_02082BCC(void *p, u32 a, u32 b);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02028470(u8 *p, u32 v);
extern u8 func_02045778(struct Descriptor *p);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u32  func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                          u32 a7, u16 a8, u16 a9);
void func_021BA194(const u8 *p, int which, int *out);
void func_021BA1C4(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u16 s2);
void func_021BA254(u8 *p);
void func_021BA278(u8 *p, u32 a, u32 b, u32 c);
void func_021BA28C(u8 *p, u32 a1, u32 a2, u32 a3, u32 a4);


void func_021BA194(const u8 *p, int which, int *out)
{
    if (out == 0)
        return;
    switch (which) {
    case 0:
        out[0] = *(const int *)&((struct Obj05150 *)p)->f4;
        out[1] = *(const int *)&((struct Obj05150 *)p)->f8;
        break;
    case 1:
        out[0] = *(const int *)&((struct Obj05150 *)p)->fC;
        out[1] = *(const int *)&((struct Obj05150 *)p)->f10;
        break;
    case 2:
        out[0] = *(const int *)&((struct Obj05150 *)p)->f14;
        out[1] = *(const int *)&((struct Obj05150 *)p)->f18;
        break;
    }
}


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
    func_0201F73C((void *)(((struct Obj01227 *)p)->f10), 2, 1, func_02045778((struct Descriptor *)a1));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01227 *)p)->f10)), (u8)((struct Obj01227 *)p)->f18);
    w = ((struct Obj01227 *)p)->f10;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    ((struct Obj01227 *)p)->f1C = ((struct Obj01227 *)p)->f10;
    p[0x20] = 0;
}


void func_021BA254(u8 *p)
{
    if (((struct Obj07683 *)p)->f8 != 0) {
        func_0201CE48((struct Rec3 *)(((struct Obj07683 *)p)->f8));
        ((struct Obj07683 *)p)->f8 = 0;
    }
    func_02045808((struct U16Vec *)(((struct Obj07683 *)p)->f14));
    func_02082BCC(p, 0, 0x38);
}

void func_021BA278(u8 *p, u32 a, u32 b, u32 c)
{
    func_021BA28C(p, ((struct Obj00884 *)p)->f0, a, b, c);
}


void func_021BA28C(u8 *p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 t;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00884 *)p)->f10)), (u8)((struct Obj00884 *)p)->f18);
    func_02045CAC((struct MsgBank *)a1, a2, (void *)(((struct Obj00884 *)p)->f14));
    if (((struct Obj00884 *)p)->f8 != 0) {
        func_0201CE48((struct Rec3 *)(((struct Obj00884 *)p)->f8));
        ((struct Obj00884 *)p)->f8 = 0;
    }
    if (a4 == 0) {
        t = ((struct Obj00884 *)p)->f24;
        func_0201C6FC((struct PrintSys *)t, (u32)func_02045770((struct Descriptor *)((struct Obj00884 *)p)->f1C), 0, 0,
                      (void *)(((struct Obj00884 *)p)->f14), ((struct Obj00884 *)p)->f4);
        p[0x20] = 1;
        ((struct Obj00884 *)p)->f28 = 2;
        return;
    }
    ((struct Obj00884 *)p)->f8 = func_0201CCE4(((struct Obj00884 *)p)->f10, 0, 0, ((struct Obj00884 *)p)->f14,
                                    ((struct Obj00884 *)p)->f4, a3, ((struct Obj00884 *)p)->fC, 0,
                                    ((struct Obj00884 *)p)->f1A, ((struct Obj00884 *)p)->f18);
    ((struct Obj00884 *)p)->f28 = 1;
}
