/*
 * file:     mailtool_p02.c
 * unit:     yes
 * function: func_021C3FC8, func_021C409C, func_021C4134, func_021C414C, func_021C4184, func_021C41E0, func_021C427C, func_021C4290, func_021C42C8
 * address:  0x021C3FC8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202428C 0x0202428C thumb
 *   func_02024044 0x02024044 thumb
 *   func_02024104 0x02024104 thumb
 *   func_02024570 0x02024570 thumb
 *   func_02024450 0x02024450 thumb
 *   func_020242A4 0x020242A4 thumb
 *   func_02024108 0x02024108 thumb
 *   func_02030734 0x02030734 arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02008F80 0x02008F80 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02008F84 0x02008F84 thumb
 *   func_02045924 0x02045924 arm
 *   func_02008FA4 0x02008FA4 thumb
 *   func_02008FB0 0x02008FB0 thumb
 *   func_02008FB8 0x02008FB8 thumb
 *   func_02008FC0 0x02008FC0 thumb
 *   func_02008FC8 0x02008FC8 thumb
 *   d_021C7EEC 0x021C7EEC data a1
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02008FD8 0x02008FD8 thumb
 *   func_02008FC4 0x02008FC4 thumb
 *   func_02008FA8 0x02008FA8 thumb
 *   func_020242C0 0x020242C0 thumb
 *   d_021C77A0 0x021C77A0 data a1
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02031140 0x02031140 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   func_020306F0 0x020306F0 arm
 *   func_021C4AF8 0x021C4AF8 thumb ov136
 *   func_021C4BFC 0x021C4BFC thumb ov136
 *   func_021C4B5C 0x021C4B5C thumb ov136
 *   func_021C4D14 0x021C4D14 thumb ov136
 *   data_021C7774 0x021C7774 data
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_020434DC 0x020434DC arm
 *   func_02022230 0x02022230 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_020056BC 0x020056BC thumb
 *   func_0202173C 0x0202173C thumb
 *   func_02021ED8 0x02021ED8 thumb
 *   func_0202DBC4 0x0202DBC4 thumb
 *   func_02028178 0x02028178 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_0204A600 0x0204A600 arm
 *   func_02030D28 0x02030D28 arm
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 */
#include "../../matched/include/Obj01412.h"
#include "../../matched/include/Obj10598.h"
#include "../../matched/include/Obj23490.h"
#include "../../matched/include/Obj23491.h"
#include "../../matched/include/Obj03834.h"
#include "../../matched/include/Obj14182.h"
#include "../../matched/include/Obj14183.h"
#include "../../matched/include/Obj01064.h"
#include "../../matched/include/Obj08198.h"
#include "../../matched/include/Obj00539.h"

struct Obj;
struct Rec8;
struct Sub02008F80Obj;
struct Strbuf;
struct Sub02008F80Entry;
struct U16Vec;
struct Obj0203159C;
struct GfFont;
struct Tcbl;
struct S02031140;
struct S020315D4;
struct Ctx;
struct Node;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef int (*Step021C42C8)(u8 *p);

extern void func_0202428C(void *p);
extern struct Obj *func_02024044(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
extern void func_02024104(u16 *p, u16 v);
extern void func_02024570(struct Rec8 *dst, const struct Rec8 *src);
extern int func_02024450(const u16 *p);
extern void func_020242A4(void *obj, u32 id);
extern void func_02024108(u16 *dst, const u16 *src);
extern void *func_02030734(unsigned heapId, unsigned size, int clear, const char *site, u16 tag);
extern void func_02082AC0(unsigned, void *, unsigned);
extern u32 func_02008F80(const struct Sub02008F80Obj *obj);
extern void *func_020457B0(unsigned, u16);
extern u8 *func_02008F84(struct Sub02008F80Obj *obj);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern u8 func_02008FA4(const struct Sub02008F80Obj *obj);
extern u8 func_02008FB0(const struct Sub02008F80Obj *obj);
extern u8 func_02008FB8(const struct Sub02008F80Obj *obj);
extern u16 func_02008FC0(const struct Sub02008F80Obj *obj);
extern struct Sub02008F80Entry *func_02008FC8(struct Sub02008F80Obj *obj, u32 i);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern void func_02008FD8(struct Sub02008F80Obj *obj, void *arg, u32 i);
extern void func_02008FC4(struct Sub02008F80Obj *obj, u16 value);
extern void func_02008FA8(struct Sub02008F80Obj *obj, u32 value);
extern void func_020242C0(void *a, void *b, void *c);
extern void func_0203064C(unsigned, unsigned, unsigned);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern signed char func_02012FFC(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0203F8F4(u16);
extern void func_0203F9B4(void);
extern void func_02031140(struct S02031140 *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_0203084C(u16 v);
extern void func_020306F0(u32 v);
extern void func_021C4AF8(void);
extern int func_021C4BFC(u8 *p);
extern void func_021C4B5C(void *a, u32 *p);
extern int func_021C4D14(u8 *p);
extern void func_0202223C(u32 a, u32 b);
extern u32 func_02022224(void *win);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02022230(u32 a);
extern void func_0207D63C(void *reg, int a, int b, int c, int d);
extern u32 func_020056BC(void);
extern void func_0202173C(void *p, int a, int b, int c, int d, int e, int f, u32 g);
extern u32 func_02021ED8(const char *ptr);
extern void func_0202DBC4(u8 *p);
extern void func_02028178(u8 *p);
extern void func_02030EAC(struct Node *n);
extern void func_0204A600(void *p);
extern void func_02030D28(struct Ctx *c);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
void func_021C3FC8(u8 *ctx, u8 *arg);
void *func_021C409C(void *a, unsigned heap);
void func_021C4134(u8 *p);
void func_021C414C(void *a, u8 *p);
void func_021C4184(void *a, u8 *p);
int func_021C41E0(void *a, void *b, u8 *p);
int func_021C427C(void *a, void *b, void *c, void *p);
int func_021C4290(void *a, void *b, void *c, u32 *p);
int func_021C42C8(u8 *p);
extern const char d_021C7EEC[];
extern const u8 d_021C77A0[][3];
extern Step021C42C8 data_021C7774[];

/*
 * note:     2026-10-02 only unresolved arm9 Thumb leaf witnesses (02024104, 02024108, 02024450 unmanifested); C is complete
 */
void func_021C3FC8(u8 *ctx, u8 *arg)
{
    u8 *p = *(u8 * *)&((struct Obj01412 *)ctx)->f10;
    u32 k = p[2];
    if (k == 3) {
        func_0202428C(ctx + 0x14);
        ((struct Obj01412 *)ctx)->f14 = 6;
        ((struct Obj01412 *)ctx)->f16 = 0;
        ((struct Obj01412 *)ctx)->f18 = ((struct Obj23490 *)(*(u8 * *)&((struct Obj01412 *)ctx)->f10))->f32;
        ((struct Obj01412 *)ctx)->f8 = func_02024044(0, 0, 0, 1, ((struct Obj10598 *)arg)->f10, ((struct Obj01412 *)ctx)->f0);
        func_02024104(((struct Obj01412 *)ctx)->f8, ((struct Obj23491 *)(*(u8 * *)&((struct Obj01412 *)ctx)->f10))->f32);
    } else if (*(p + k + 0x2e) == 1) {
        func_02024570((struct Rec8 *)(ctx + 0x14), (const struct Rec8 *)(p + 0x16 + k * 8));
        ((struct Obj01412 *)ctx)->f8 = func_02024044(2, 0, ctx + 0x14, 1, ((struct Obj10598 *)arg)->f10, ((struct Obj01412 *)ctx)->f0);
    } else {
        ((struct Obj01412 *)ctx)->f8 = func_02024044(2, 0, 0, 1, ((struct Obj10598 *)arg)->f10, ((struct Obj01412 *)ctx)->f0);
        if (func_02024450((u16 *)(*(u8 * *)&((struct Obj01412 *)ctx)->f10 + 0x16 + (*(u8 **)(ctx + 0x10))[2] * 8)))
            func_02024570((struct Rec8 *)(ctx + 0x14), (const struct Rec8 *)(*(u8 * *)&((struct Obj01412 *)ctx)->f10 + 0x16 + (*(u8 **)(ctx + 0x10))[2] * 8));
        else
            func_020242A4(ctx + 0x14, 0);
        func_02024108(((struct Obj01412 *)ctx)->f8, (const u16 *)(ctx + 0x14));
    }
}

void *func_021C409C(void *a, unsigned heap)
{
    u8 *p;
    u16 i;
    i = 0;
    p = func_02030734((u16)heap, 0x34, 0, d_021C7EEC, 0x147);
    func_02082AC0(0, p, 0x34);
    ((struct Obj03834 *)p)->f0 = i;
    ((struct Obj03834 *)p)->f4 = func_02008F80(a);
    ((struct Obj03834 *)p)->fC = func_020457B0(0x10, heap);
    func_02045924(((struct Obj03834 *)p)->fC, (const u16 *)func_02008F84(a));
    p[0xB] = func_02008FA4(a);
    p[9] = func_02008FB0(a);
    p[0xA] = func_02008FB8(a);
    ((struct Obj03834 *)p)->f32 = func_02008FC0(a);
    for (; i < 3; i++) func_02024570((struct Rec8 *)(p + 0x16 + i * 8), (const struct Rec8 *)func_02008FC8(a, (u8)i));
    return p;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C4134(u8 *p)
{
    if (((struct Obj14182 *)p)->fC)
        func_02045808(((struct Obj14182 *)p)->fC);
    func_020307B0(p);
}

void func_021C414C(void *a, u8 *p)
{
    u16 i;
    for (i = 0; i < 3; i++) func_02008FD8(a, p + 0x16 + i * 8, (u8)i);
    func_02008FC4(a, ((struct Obj14183 *)p)->f32);
    func_02008FA8(a, p[0xB]);
}

/*
 *   int func_02024450(unsigned short *p) { return *p != 0xFFFF; }
 */
void func_021C4184(void *a, u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (func_02024450((const u16 *)(p + 0x16 + i * 8)) == 0) {
            if (d_021C77A0[p[0xB]][i] != 0xFF) func_020242C0(p + 0x16 + i * 8, (void *)5, (void *)d_021C77A0[p[0xB]][i]);
        }
        if (d_021C77A0[p[0xB]][i] == 0xFF) p[0x2E + i] = 0;
        else p[0x2E + i] = 1;
    }
}

int func_021C41E0(void *a, void *b, u8 *p)
{
    u8 *q;
    u8 v;
    func_0203064C(1, 0x64, 0x20000);
    q = func_0203159C(a, 0x15C, 0x64);
    func_02082AC0(0, q, 0x15C);
    ((struct Obj01064 *)q)->f0 = 0x64;
    ((struct Obj01064 *)q)->f1C = p;
    q[0xB] = ((struct Obj08198 *)p)->f0;
    q[0xC] = q[0xB];
    q[0x16] = p[2];
    q[0x17] = p[3];
    v = q[0x16];
    q[0x1A] = v;
    q[0x1B] = v;
    ((struct Obj08198 *)p)->f0 = 0xFFFF;
    q[0x15] = func_02012FFC();
    func_021C4184(q, *(u8 * *)&((struct Obj01064 *)q)->f1C);
    ((struct Obj01064 *)q)->f24 = func_0201D7EC((unsigned)0x17, (unsigned)0, (unsigned)0, (unsigned)0, (u16)(((struct Obj01064 *)q)->f0));
    ((struct Obj01064 *)q)->f100 = func_0203101C((u16)(((struct Obj01064 *)q)->f0), ((struct Obj01064 *)q)->f0, 0x20, 0x20);
    q[0xA] = 1;
    func_0203F8F4(((struct Obj01064 *)q)->f0);
    return 1;
}

int func_021C427C(void *a, void *b, void *c, void *p)
{
    if (func_021C42C8(p)) return 1;
    return 0;
}

int func_021C4290(void *a, void *b, void *c, u32 *p)
{
    u32 h;
    func_0203F9B4();
    func_02031140((struct S02031140 *)p[0x40]);
    func_0201D83C((void *)p[9]);
    h = p[0];
    func_020315D4(a);
    func_0203084C(h);
    func_020306F0((u16)h);
    return 1;
}


int func_021C42C8(u8 *p)
{
    int r = 0;
    u32 t;

    switch (((struct Obj00539 *)p)->f4) {
    case 0:
        func_021C4AF8();
        func_0202223C(0, 0);
        func_0202223C(1, 0);
        func_02022224(0);
        func_02022224((void *)1);
        (((struct Obj00539 *)p)->f4)++;
        break;
    case 1:
        if (func_021C4BFC(p)) {
            ((struct Obj00539 *)p)->f104 = func_020056A0((void *)func_021C4B5C, p, 0x10);
            func_020434DC(0x10, 1);
            func_02022230(0);
            func_0207D63C((void *)0x04000050, 4, 8, 0x1C, 4);
            t = func_020056BC();
            func_0202173C(((struct Obj00539 *)p)->f38, 5, 0xFFFF, -1, 0x10, 0, 0, t);
            (((struct Obj00539 *)p)->f4)++;
        }
        break;
    case 2:
        if (!func_02021ED8(((struct Obj00539 *)p)->f38))
            (((struct Obj00539 *)p)->f4)++;
        func_0202DBC4(((struct Obj00539 *)p)->f148);
        break;
    case 3:
        if (data_021C7774[p[0xB]](p) == 1) {
            (((struct Obj00539 *)p)->f4)++;
            t = func_020056BC();
            func_0202173C(((struct Obj00539 *)p)->f38, 5, 0xFFFF, -1, 0, 0x10, 0, t);
        }
        func_0202DBC4(((struct Obj00539 *)p)->f148);
        if (((struct Obj00539 *)p)->f128) {
            func_02028178(((struct Obj00539 *)p)->f128);
            func_02028178(((struct Obj00539 *)p)->f12C);
        }
        break;
    case 4:
        if (!func_02021ED8(((struct Obj00539 *)p)->f38)) {
            func_0202223C(0, 0);
            func_0202223C(1, 0);
            func_02030EAC(((struct Obj00539 *)p)->f104);
            func_021C4AF8();
            (((struct Obj00539 *)p)->f4)++;
        }
        func_0202DBC4(((struct Obj00539 *)p)->f148);
        break;
    case 5:
        if (func_021C4D14(p))
            r = 1;
        break;
    }
    if (((struct Obj00539 *)p)->fA0)
        func_0204A600(((struct Obj00539 *)p)->fA0);
    if (((struct Obj00539 *)p)->fF8)
        func_02030D28(((struct Obj00539 *)p)->fF8);
    if (((struct Obj00539 *)p)->f100)
        func_020310C4(((struct Obj00539 *)p)->f100);
    if (((struct Obj00539 *)p)->f98)
        func_0201C4E4(((struct Obj00539 *)p)->f98);
    if (((struct Obj00539 *)p)->f158)
        func_0201C4E4(((struct Obj00539 *)p)->f158);
    return r;
}
