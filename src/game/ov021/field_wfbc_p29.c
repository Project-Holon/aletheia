/*
 * file:     field_wfbc_p29.c
 * unit:     yes
 * function: func_0219630C, func_02196454, func_0219649C, func_021964B0, func_02196538
 * address:  0x0219630C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020414EC  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020456F8  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02051C6C  0x02051C6C  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02040588  0x02040588  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_02049F78  0x02049F78  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 *   d_021DDAD4     0x021DDAD4  data  ov021  a2
 */
#include "../../matched/include/Obj03578.h"
#include "../../matched/include/Obj00150.h"
#include "../../matched/include/Obj12630.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct GfFont;
struct U16Vec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 x0; u32 x4; u32 x8; u32 xc; } Desc;

typedef struct Obj {
    u8 pad0[0x10];
    u16 x10;
    u16 pad12;
    u32 w[4];
    u32 x24;
    u32 x28;
    u32 x2c;
    u8 pad30[8];
    u32 x38;
    u8 pad3c[0x2B8];
    int x2f4;
} Obj;

typedef struct Cb { u32 x0; int (*fn)(void *, struct Cb *); } Cb;

extern void func_020414EC(u32);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201DD78(u32, u32, u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02051C6C(void *p);
extern void func_02041B6C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *h);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(void *src, void *dst, u32 n);
extern u32 func_020307B0(void *p);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
void func_0219630C(int n, u32 *msg, Obj *a, Desc *d, int *xs, int *ys);
void func_02196454(u8 *p);
void func_0219649C(void *a, int b, Cb *c);
void func_021964B0(u16 (*dst)[16], u16 *add, int n);
void func_02196538(u8 *p);
extern const u16 d_021DDAD4[];


/*
 * Addresses are Black-image addresses.
 */
void func_0219630C(int n, u32 *msg, Obj *a, Desc *d, int *xs, int *ys)
{
    int i;
    int x;
    int y;

    func_020414EC(7);
    a->x2f4 = n;
    func_02049B40(0x17, 5, 4, 0x100, 0x20, a->x10);
    for (i = 0; i < 4; i++) {
        if (a->w[i] != 0) {
            func_020456F8((struct Descriptor *)a->w[i]);
            func_0201F7A8((void *)a->w[i], 2);
            func_020452E8((struct Descriptor *)a->w[i]);
        }
        a->w[i] = 0;
    }
    for (i = 0; i < n; i++) {
        func_0201DD78(15, 2, 0);
        a->w[i] = func_020450F0(7, (u8)d[i].x0, (u8)d[i].x4, (u8)d[i].x8, (u8)d[i].xc, 8, 0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)a->w[i])), 0);
        func_02045CAC((struct MsgBank *)a->x28, msg[i], (void *)a->x38);
        if (xs != 0) {
            x = xs[i] - (func_0201D304((struct StrObj *)a->x38, a->x2c, 0) >> 1);
        } else {
            x = 0;
        }
        if (ys != 0) {
            y = ys[i] - (func_0201D42C((struct StrObj *)a->x38, (void *)a->x2c) >> 1);
        } else {
            y = 0;
        }
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)a->w[i])), x, y, (void *)a->x38, (void *)a->x2c);
        func_02045334((struct Descriptor *)a->w[i]);
        func_02045374((struct Cfg *)a->w[i]);
    }
    if (a->x24 != 0) {
        func_02051C6C((void *)a->x24);
    }
    a->x24 = 0;
    func_02041B6C(7);
    func_02040588(7, 1);
}


void func_02196454(u8 *p)
{
    int i;

    if (((struct Obj03578 *)p)->f24 != 0)
        func_02051C6C((void *)(((struct Obj03578 *)p)->f24));
    ((struct Obj03578 *)p)->f24 = 0;
    for (i = 0; i < 4; i++) {
        u32 *q = (u32 *)p + i;
        if (q[5] != 0) {
            func_020456F8((struct Descriptor *)q[5]);
            func_02041B6C(5);
            func_0201F7A8((void *)q[5], 2);
            func_020452E8((struct Descriptor *)q[5]);
        }
        q[5] = 0;
    }
    ((struct Obj03578 *)p)->f2F4 = 0;
}


void func_0219649C(void *a, int b, Cb *c)
{
    if (b == 0 && c->fn != 0 && c->fn(a, c) != 0) {
        return;
    }
}


void func_021964B0(u16 (*dst)[16], u16 *add, int n)
{
    int i;
    int j;
    u16 c;
    u16 r;
    u16 g;
    u16 b;

    for (i = 0; i < n; i++) {
        for (j = 0; j < 16; j++) {
            c = dst[i][j];
            r = c & 0x1F;
            g = (c & 0x3E0) >> 5;
            b = (c & 0x7C00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) {
                r = 31;
            }
            if (g > 31) {
                g = 31;
            }
            if (b > 31) {
                b = 31;
            }
            dst[i][j] = (b << 10) + (r + (g << 5));
        }
    }
}


void func_02196538(u8 *p)
{
    void *h;
    void *res;
    u8 *pal;

    ((struct Obj00150 *)p)->f2F8 = 0;
    ((struct Obj00150 *)p)->f38 = func_020457B0(0x12C, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f2C = func_0201D7EC(0x17, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f28 = func_02045B38(0, 2, 0x2E, ((struct Obj00150 *)p)->f10);

    h = func_020490F4(0x1C, ((struct Obj00150 *)p)->f10);
    func_02049B68(h, 1, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f44 = func_02049740(h, 6, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    func_02049990(h, 0xD, 0, 0, (u16)((struct Obj00150 *)p)->f44, 0, 0, ((struct Obj00150 *)p)->f10);
    func_02049238(h);

    h = func_020490F4(0x1D, ((struct Obj00150 *)p)->f10);
    func_02049B68(h, 2, 4, 0, 0, ((struct Obj00150 *)p)->f10);
    res = func_02049F78(h, 2, (u32)(&pal), ((struct Obj00150 *)p)->f10);
    func_02082D44(((struct Obj12630 *)pal)->fC, p + 0x48, 0x100);
    func_02082D44(((struct Obj12630 *)pal)->fC, p + 0x148, 0x100);
    func_021964B0((u16 (*)[16])(p + 0x148), (u16 *)d_021DDAD4, 8);
    func_020307B0(res);
    func_02049B68(h, 0, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f40 = func_02049740(h, 4, 4, 0, 0, ((struct Obj00150 *)p)->f10);
    func_02049990(h, 9, 4, 0, (u16)((struct Obj00150 *)p)->f40, 0, 0, ((struct Obj00150 *)p)->f10);
    func_02049990(h, 0xB, 6, 0, (u16)((struct Obj00150 *)p)->f40, 0, 0, ((struct Obj00150 *)p)->f10);
    func_02049238(h);

    ((struct Obj00150 *)p)->f3C = func_0201F5DC((void *)5, 0xC, 0, ((struct Obj00150 *)p)->f10);
    func_02049B40(0x17, 5, 4, 0x160, 0x20, ((struct Obj00150 *)p)->f10);
}
