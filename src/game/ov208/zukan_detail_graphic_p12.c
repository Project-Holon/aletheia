/*
 * file:     zukan_detail_graphic_p12.c
 * unit:     yes
 * function: func_021C1E10, func_021C1F28, func_021C1F44, func_021C1F50, func_021C1FC4, func_021C1FE0, func_021C2090, func_021C20C0, func_021C21D0, func_021C2228, func_021C2234, func_021C2238, func_021C2304, func_021C231C, func_021C232C, func_021C239C
 * address:  0x021C1E10
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_021BDC48  0x021BDC48  thumb  ov208
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021C0CCC  0x021C0CCC  thumb  ov208
 *   func_021C1D30  0x021C1D30  thumb  ov208
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_020437DC  0x020437DC  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_021C0740  0x021C0740  thumb  ov208
 *   func_021C1920 0x021C1920  thumb  ov208
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02045334 0x02045334 arm
 *   func_021C0C8C 0x021C0C8C thumb ov208
 *   sub_0201D304  0x0201D304  thumb
 *   sub_0201C724  0x0201C724  thumb
 *   func_021C0CC0  0x021C0CC0  thumb  ov208
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   data_021C8E14  0x021C8E14  data
 *   data_021C8E1A  0x021C8E1A  data
 *   func_0207D63C 0x0207D63C  arm
 *   func_021BC518 0x021BC518  thumb  ov208
 *   func_021C2430 0x021C2430 thumb ov208
 */
#include "../../matched/include/Obj00081.h"
#include "../../matched/include/Obj18287.h"
#include "../../matched/include/Obj18288.h"

#define W(o) (*(u32 *)(p + (o)))
#define OBJ(i) (((u32 *)(p + 0xbc))[i])
#define REG32(a) (*(volatile u32 *)(a))
#define REG16(a) (*(volatile u16 *)(a))
struct Obj;
struct PrintSys;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Bmp;
struct StrObj;
struct U16Vec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 f0;
    u8 f1;
    u8 rest[0x3c];
} Entry_021C1E10;

typedef short          s16;

typedef signed short   s16_021C2090;

typedef signed int     s32_021C2090;

typedef signed short   s16_021C20C0;

typedef signed int     s32_021C20C0;

typedef short          s16_021C2228;

typedef int            s32_021C2228;

typedef int            s32;

typedef struct {
    u8 f0;
    u8 f1;
    u8 b[0x3c];
} Entry_021C2234;

typedef int BOOL;

extern int func_021BC3B4(int *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0204B878(u32 obj, u32 anim);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_021BDC48(void *s, u32 on);
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
extern void func_021C0CCC(u16 *heap, u8 *p, int key);
extern void func_021C1D30(u16 *heap, u8 *p, int key);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 func_020307B0(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);
extern void func_021C1920(u16 *heap, u8 *p, int key, int mode);
extern unsigned func_0204B3F4(struct Obj *);
extern void func_02045334(struct Descriptor *);
extern void func_021C0C8C(u16 *, u8 *, int, int);
extern u32 sub_0201D304(struct StrObj *s, u32 a, u32 b);
extern void sub_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern int func_021C0CC0(void *a0, u8 *st, void *a2);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_021BC518(int *p);
extern void func_021C2430(u8 *p);
void func_021C1E10(u16 *heap, u8 *p, int key, int dir, int touch);
void *func_021C1F28(int a, int b, int c);
void func_021C1F44(int a);
void func_021C1F50(u16 *heap, u8 *p, int key);
void func_021C1FC4(void *a, char *b, int c);
void func_021C1FE0(u16 *heap, u8 *p, int key);
void func_021C2090(void *unused, u8 *p);
void func_021C20C0(void *a0, u8 *st, void *a2);
void func_021C21D0(void *unused, char *p, int key);
void ov208_func_021C2228(u16 *heap, u8 *p, int key);
void ov208_func_021C2234(u16 *heap, u8 *p, int key);
void func_021C2238(u16 *heap, u8 *p, int key);
void func_021C2304(char *a0);
void func_021C231C(char *p);
void func_021C232C(char *p);
void func_021C239C(char *p);
extern const u8 data_021C8E14[3][2];
extern u8 data_021C8E1A[3][4];





void func_021C1E10(u16 *heap, u8 *p, int key, int dir, int touch)
{
    void *s;
    int other;
    u32 anim;

    s = (void *)func_021BC3B4((int *)key);
    if (W(0x8c) == 0)
        W(0x90) = ((Entry_021C1E10 *)W(0x94))[0].f1 == 0;
    else
        W(0x90) = ((Entry_021C1E10 *)W(0x94))[p[0x78]].f1 == 0;
    W(0x2c) = 0;
    func_0201C6EC((struct PrintSys *)W(0x3c));
    func_02043B5C(func_02045770((struct Descriptor *)W(0x1c)), 0);
    func_021C1F50(heap, p, key);
    if (dir) {
        p[0xd8] = 2;
        anim = 3;
        other = 1;
    } else {
        p[0xd8] = 1;
        anim = 5;
        other = 2;
    }
    func_0204B878(OBJ(p[0xd8]), anim);
    func_0204B92C((struct Obj *)OBJ(other), 0);
    func_0204B8C4((struct Obj *)OBJ(other), 0);
    func_021BDC48(s, 0);
    if (touch == 1) {
        func_0204B3DC((struct Obj *)W(0xcc), 0);
    } else if (W(0x6c) == 5 && W(0x90) == 1) {
        func_021C0CCC(heap, p, key);
        func_021C1D30(heap, p, key);
    }
    func_021C1FC4(heap, (char *)p, key);
    func_021C2238(heap, p, key);
}






/*
 * Forwards to func_0204A39C with the first argument less one and an out slot.
 */
void *func_021C1F28(int a, int b, int c)
{
    int out;

    return func_0204A39C((void *)c, a - 1, 0, b, (u32 *)(&out));
}






void func_021C1F44(int a)
{
    if (a != 0)
        func_020307B0((void *)a);
}





void func_021C1F50(u16 *heap, u8 *p, int key)
{
    void *str;
    u16 tw;
    u32 w;

    str = func_02045EC0((struct MsgBank *)W(0xc), p[0x78] + 0xbe);
    tw = func_0201D304(str, W(4), 0);
    w = func_020437DC(func_02045770((struct Descriptor *)W(0x1c)));
    func_0201C724((void *)W(0x3c), (u32)func_02045770((struct Descriptor *)W(0x1c)), (s16)((u16)((int)(w - tw) / 2)), (s16)1, (u32)str, W(4), 0x3c40);
    func_02045808(str);
    W(0x2c) = 1;
    func_021C0740(heap, p, key, 2);
}





/*
 * Dispatches on the word at +0x6C: state 0 hands a 3, state 5 hands an 8 to func_021C1920.
 */
void func_021C1FC4(void *a, char *b, int c)
{
    int s = ((struct Obj00081 *)b)->f6C;

    if (s == 0) {
        func_021C1920(a, (u8 *)b, c, 3);
        return;
    }
    if (s == 5) {
        func_021C1920(a, (u8 *)b, c, 8);
    }
}




void func_021C1FE0(u16 *heap, u8 *p, int key)
{
    u8 i;
    if (func_0204B3F4(*(struct Obj * *)&((struct Obj00081 *)p)->fC8)) {
        if (((struct Obj00081 *)p)->f90 == 1) {
            ((struct Obj00081 *)p)->f30 = 0;
            func_0201C6EC(*(struct PrintSys * *)&((struct Obj00081 *)p)->f40);
            func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20), 0);
            func_02045334(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fC8, 0);
        }
    } else {
        for (i = 0; i < 61; i++) func_0204B3DC(*(struct Obj **)(p + i * 4 + 0xdc), 0);
        if (((struct Obj00081 *)p)->f90 == 0) {
            func_021C0C8C(heap, p, key, 0);
            p[0x79] = 255;
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fCC, 0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fD0, 0);
            func_021C1D30(heap, p, key);
            func_021C2238(heap, p, key);
        }
    }
}




void func_021C2090(void *unused, u8 *p)
{
    if (func_0204B3F4((struct Obj *)(*(int *)&((struct Obj00081 *)p)->fC8)) == 0) {
        if (*(int *)&((struct Obj00081 *)p)->f90 == 0) {
            p[0x414] = 1;
        } else {
            p[0x414] = 2;
        }
    }
}




void func_021C20C0(void *a0, u8 *st, void *a2)
{
    int res = func_0204B3F4((struct Obj *)(*(int *)&((struct Obj00081 *)st)->fC8));

    if (((struct Obj00081 *)st)->f90 == 0) {
        if (res == 0) {
            void *msg;
            u32 w;
            int d;
            int h;
            u32 t;

            msg = func_02045EC0(((struct Obj00081 *)st)->fC, 0x80);
            w = (u16)sub_0201D304(msg, ((struct Obj00081 *)st)->f4, 0);
            h = func_020437DC((const struct Bmp *)((u32)func_02045770(((struct Obj00081 *)st)->f20)));
            t = (u32)func_02045770(((struct Obj00081 *)st)->f20);
            d = h - w;
            sub_0201C724(((struct Obj00081 *)st)->f40, t, (s16_021C20C0)(u16)(d / 2), 1, (u32)msg, ((struct Obj00081 *)st)->f4, 0x3c40);
            func_02045808(msg);
            ((struct Obj00081 *)st)->f30 = 1;
            func_021C0740((u16 *)a0, st, (int)a2, 3);
            func_0204B3DC((struct Obj *)*(int *)&((struct Obj00081 *)st)->fC8, 1);
        }
    } else {
        u8 i;
        u8 v;
        u8 *tbl;

        v = ((struct Obj00081 *)st)->f8C == 0 ? 0 : st[0x78];
        for (i = 0; i < 0x3d; i++) {
            tbl = *(u8 * *)&((struct Obj00081 *)st)->f94;
            if (tbl[v * 0x3e + st[0x3cc + i] + 2] != 0 && *(u32 *)(st + 0x1e0 + i * 8) != 1) {
                func_0204B3DC((struct Obj *)*(int *)(st + 0xdc + i * 4), 1);
            }
        }
        if (func_021C0CC0(a0, st, a2) == 0) {
            func_021C0C8C((u16 *)a0, st, (int)a2, 1);
        }
    }
}



void func_021C21D0(void *unused, char *p, int key)
{
    u8 i;
    if (func_0204B3F4(*(struct Obj * *)&((struct Obj00081 *)p)->fC8)) {
        ((struct Obj00081 *)p)->f30 = 0;
        func_0201C6EC(*(struct PrintSys * *)&((struct Obj00081 *)p)->f40);
        func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20), 0);
        func_02045334(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20);
        func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fC8, 0);
    } else {
        for (i = 0; i < 61; i++) func_0204B3DC(*(struct Obj **)(p + i * 4 + 0xdc), 0);
    }
}




void ov208_func_021C2228(u16 *heap, u8 *p, int key)
{
    p[0x414] = 3;
}



void ov208_func_021C2234(u16 *heap, u8 *p, int key)
{
}



/*
 * note: 2026-10-05 (D6-04): closed by declaring data_021C8E1A non-const; the
 *   image keeps the x0 table load below the stack argument stores (a plain
 *   extern cannot move past them).
 */
void func_021C2238(u16 *heap, u8 *p, int key)
{
    u8 on[3] = {0, 0, 0};
    u8 idx, k, i;

    if (W(0x90) == 1 && p[0x79] != 0xff) {
        idx = W(0x8c) != 0 ? p[0x78] : 0;
        k = (p + p[0x79])[0x3cc];
        if ((*(Entry_021C2234 **)(p + 0x94))[idx].b[k] & 7)
            on[0] = 1;
        if ((*(Entry_021C2234 **)(p + 0x94))[idx].b[k] & 0x18)
            on[1] = 1;
        if ((*(Entry_021C2234 **)(p + 0x94))[idx].b[k] & 0x60)
            on[2] = 1;
    }
    for (i = 0; i < 3; i++)
        func_020413B0(7, data_021C8E1A[i][0], data_021C8E1A[i][1], data_021C8E1A[i][2],
                      data_021C8E1A[i][3], data_021C8E14[i][on[i]]);
    func_02041B6C(7);
}



/*
 * Writes 4 on the stack and calls the SDK function at 0x0207D63C with
 * (0x04000050, 0, 0x3F, 0xC, 4).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207D63C is the ARM
 * SDK symbol G2x_SetBlendAlpha_, and the `sdk` class attests the call once
 * the symbols block declares `arm`.  The old `thumb` declaration fought the
 * image's ISA and suppressed the witness.  Verified EXACT, 24 bytes.
 */
void func_021C2304(char *a0)
{
    func_0207D63C((void *)0x04000050, 0, 0x3f, 0xc, 4);
}



/*
 * Loads the word at +0x418 and tail-calls func_021BC518 with it.
 */
void func_021C231C(char *p)
{
    func_021BC518((int *)(((struct Obj18287 *)p)->f418));
}


static inline void GX_SetVisibleWnd(int window)
{
    REG32(0x04000000) = (u32)((REG32(0x04000000) & ~0xe000) | (window << 13));
}


static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    REG16(0x04000040) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000044) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}


static inline void G2_SetWnd1Position(int x1, int y1, int x2, int y2)
{
    REG16(0x04000042) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000046) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}


static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x04000048) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(0x04000048) = (u16)tmp;
}


static inline void G2_SetWnd1InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x04000048) & ~0x3f00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    REG16(0x04000048) = (u16)tmp;
}


static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x0400004a) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(0x0400004a) = (u16)tmp;
}


void func_021C232C(char *p)
{
    GX_SetVisibleWnd(3);
    G2_SetWnd0Position(0, 0, 160, 168);
    G2_SetWnd1Position(160, 0, 0, 168);
    G2_SetWnd0InsidePlane(31, 1);
    G2_SetWnd1InsidePlane(31, 1);
    G2_SetWndOutsidePlane(31, 0);
    func_021C2430((u8 *)p);
}



/*
 * Masks 0x04000000 with 0xFFFF1FFF, then tail-calls func_021BC518 on the word at +0x418.
 */
void func_021C239C(char *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    func_021BC518((int *)(((struct Obj18288 *)p)->f418));
}
