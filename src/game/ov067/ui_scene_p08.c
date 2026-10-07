/*
 * file:     ui_scene_p08.c
 * unit:     yes
 * function: func_021B709C, func_021B70F4, func_021B72DC
 * address:  0x021B709C
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_021B6284  0x021B6284  thumb  ov067
 *   func_020452E8  0x020452E8  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021B76C8  0x021B76C8  thumb  ov067
 *   func_0204B404  0x0204B404  arm
 *   func_021B7718  0x021B7718  thumb  ov067
 *   func_02040588  0x02040588  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 */
#include "../../matched/include/Obj07677.h"

struct Descriptor;
struct Obj;
struct Cfg;
struct CharBuf;
struct PrintSys;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

struct S_021B70F4 {
    u8 _0[0x8];
    u32 f8;
    u32 fC;
    u32 f10;
    u8 f14;
    u8 _15;
    u8 f16;
    u8 f17;
    u8 f18;
    u8 _19[0x1c - 0x19];
    u32 f1C;
    u8 _20[0x22 - 0x20];
    u8 f22[0x88 - 0x22];
    int f88;
    int f8c;
    u32 f90;
    u32 f94;
    u32 f98;
    u32 f9c;
    int arrA0[4];
    u8 _b0[0xc0 - 0xb0];
    u32 fC0;
};

typedef struct {
    u16 x;
    u16 y;
} Pt;

struct S_021B72DC {
    u8 _0[0x14];
    u8 f14;
    u8 _15[0x18 - 0x15];
    u8 f18;
    u8 _19[0x88 - 0x19];
    void *f88;
    void *f8c;
    u8 _90[0x98 - 0x90];
    u32 f98;
    u8 _9c[0xa0 - 0x9c];
    void *arrA0[4];
};

extern void func_0204B3B4(struct Obj *p);
extern void func_021B6284(unsigned int *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020307B0(void *p);
extern u8 func_021B76C8(u32 a, u32 b, u32 c);
extern void func_0204B404(int h, Pt *pt, u16 v);
extern void func_021B7718(int which, int idx, void *data);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021B709C(u8 *p);
void func_021B70F4(struct S_021B70F4 *s, u32 a1, u32 a2);
void func_021B72DC(struct S_021B72DC *s);


void func_021B709C(u8 *p)
{
    u8 i;
    u32 v;

    for (i = 0; i < 4; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + i * 4 + 0xa0)));
    }
    func_021B6284((unsigned int *)(p + 0xb0));
    func_020452E8((struct Descriptor *)(((struct Obj07677 *)p)->f88));
    func_020452E8((struct Descriptor *)(((struct Obj07677 *)p)->f8C));
    v = ((struct Obj07677 *)p)->f84;
    func_0203FB44(p[0x14], (u16)v, (u16)(v >> 16));
    func_020307B0(p);
}


void func_021B70F4(struct S_021B70F4 *s, u32 a1, u32 a2)
{
    Pt pt;
    u8 i;
    u32 t;
    int p;

    s->f98 = 1;
    s->f9c = 2;
    s->fC0 = 0;
    for (i = 0; i < 4; i++) {
        pt.x = func_021B76C8(s->fC0, i, 0);
        pt.y = func_021B76C8(s->fC0, i, 1);
        func_0204B404(s->arrA0[i], &pt, s->f1C);
    }
    func_021B7718(s->f10, s->f16, s->f22);
    func_021B7718(s->f10, s->f17, s->f22);
    func_02040588(s->f14, 1);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->f88)), 0);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->f8c)), 0);
    t = func_0201D304((struct StrObj *)a1, s->f8, 0);
    func_0201C724((void *)s->fC, (int)func_02045770((struct Descriptor *)s->f88), (s16)((u16)((0x100 - t) / 2)), (s16)0x10, a1, s->f8, 0x3c40);
    t = func_0201D304((struct StrObj *)a2, s->f8, 0);
    func_0201C724((void *)s->fC, (int)func_02045770((struct Descriptor *)s->f8c), (s16)((u16)((0x100 - t) / 2)), (s16)0x10, a2, s->f8, 0x3c40);
    s->f90 = 0;
    s->f94 = 0;
    func_02040588(s->f18, 1);
    if (s->f90 == 0 && func_0201C6C4((struct PrintSys *)s->fC, (void *)((int)func_02045770((struct Descriptor *)s->f88))) == 0) {
        p = s->f88;
        func_02045334((struct Descriptor *)p);
        func_02045374((struct Cfg *)p);
        func_02041B6C(func_02045730((struct Descriptor *)p));
        s->f90 = 1;
    }
    if (s->f94 == 0 && func_0201C6C4((struct PrintSys *)s->fC, (void *)((int)func_02045770((struct Descriptor *)s->f8c))) == 0) {
        p = s->f8c;
        func_02045334((struct Descriptor *)p);
        func_02045374((struct Cfg *)p);
        func_02041B6C(func_02045730((struct Descriptor *)p));
        s->f94 = 1;
    }
    if (func_020355C4() == 0) {
        for (i = 0; i < 4; i++) {
            func_0204B3DC((struct Obj *)s->arrA0[i], 1);
            func_0204B92C((struct Obj *)s->arrA0[i], 1);
        }
    }
}


void func_021B72DC(struct S_021B72DC *s)
{
    int p;
    u8 i;

    func_02040588(s->f14, 0);
    func_02040588(s->f18, 0);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->f88)), 0);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->f8c)), 0);
    p = (int)s->f88;
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    p = (int)s->f8c;
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    for (i = 0; i < 4; i++) {
        func_0204B3DC((struct Obj *)s->arrA0[i], 0);
        func_0204B92C(s->arrA0[i], 0);
    }
    s->f98 = 0;
}
