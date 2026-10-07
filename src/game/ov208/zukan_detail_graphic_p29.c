/*
 * file:     zukan_detail_graphic_p29.c
 * unit:     yes
 * function: func_021C2090, func_021C20C0, func_021C21D0, func_021C2228
 * address:  0x021C2090
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
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_02045EC0  0x02045EC0  arm
 *   sub_0201D304  0x0201D304  thumb
 *   func_02045770  0x02045770  arm
 *   func_020437DC  0x020437DC  arm
 *   sub_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_021C0740  0x021C0740  thumb  ov208
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021C0CC0  0x021C0CC0  thumb  ov208
 *   func_021C0C8C  0x021C0C8C  thumb  ov208
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
#include "../../matched/include/Obj00081.h"

struct Obj;
struct Bmp;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct Descriptor;
struct PrintSys;
struct CharBuf;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_021C2090;

typedef signed int     s32_021C2090;

typedef signed short   s16_021C20C0;

typedef signed int     s32_021C20C0;

typedef short          s16_021C2228;

typedef int            s32_021C2228;

extern u32 func_0204B3F4(struct Obj *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 sub_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void sub_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_021C0740(void *a0, u8 *st, void *a2, u8 i);
extern void func_0204B3DC(struct Obj *a, unsigned int b);
extern int func_021C0CC0(void *a0, u8 *st, void *a2);
extern void func_021C0C8C(void *a0, u8 *st, void *a2, int on);
extern void func_0201C6EC(struct PrintSys *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_02045334(struct Descriptor *);
void func_021C2090(void *unused, u8 *p);
void func_021C20C0(void *a0, u8 *st, void *a2);
void func_021C21D0(void *unused, char *p, int key);
void ov208_func_021C2228(u16 *heap, u8 *p, int key);


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
            func_021C0740(a0, st, a2, 3);
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
            func_021C0C8C(a0, st, a2, 1);
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
