/*
 * file:     unit_021ECE60_p13.c
 * unit:     yes
 * function: func_021EDE54, func_021EDF4C, func_021EDF78, func_021EDF7C, func_021EDFC4
 * address:  0x021EDE54
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020437EC 0x020437EC arm
 *   func_020437D4 0x020437D4 arm
 *   func_02082A90 0x02082A90 arm
 *   func_021EEE24 0x021EEE24 thumb ov093
 *   func_02040618  0x02040618  arm  arm9
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021F8AE8  0x021F8AE8  thumb  ov094
 *   func_02040B1C 0x02040B1C arm
 */
#include "../../matched/include/Obj01524.h"
#include "../../matched/include/Obj02797.h"
#include "../../matched/include/Obj21615.h"
#include "../../matched/include/Obj21616.h"
#include "../../matched/include/Obj05234.h"
#include "../../matched/include/Obj21617.h"
#include "../../matched/include/Obj00623.h"

struct Bmp;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

struct W {
    u8 pad[0xa];
    u8 fa;
    u8 fb;
    u8 pad2[0x16];
    u8 f22_0 : 1;
};

typedef signed char s8;

typedef signed int s32;

extern u32 func_020437EC(const struct Bmp *bmp);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A90(const void *, void *, u32);
extern void func_0201DD78(u32, u32, u32);
extern void func_021EEE24(u32, u16, u32, ...);
extern u32 func_0201D33C(struct StrObj *s, u32 a, u32 b, u32 *out, u32 max);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021D5440(u8 *p);
extern void func_021F8AE8(int i, u32 v);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_020061E4(u32 a);
extern int func_02006254(u32 a);
void func_021EDE54(u8 *p);
void func_021EDF4C(struct W *w);
/* 021EDF78 movs r0,#1 */ int func_021EDF78(u8 *a0);
void func_021EDF7C(u8 *p, u8 b);
int func_021EDFC4(u8 *p);

void func_021EDE54(u8 *p)
{
    u8 *q;
    u32 size;
    void *pixels;
    u32 widths[2];
    int right;
    int left;
    int gap;
    int extra;
    int half;
    u32 edge;
    u32 width;
    u32 center;
    q = *(u8 * *)&((struct Obj02797 *)p)->f0;
    size = func_020437EC(((struct Obj02797 *)p)->f4);
    pixels = func_020437D4(((struct Obj02797 *)p)->f4);
    func_02082A90(*(u8 * *)&((struct Obj21616 *)(*(u8 * *)&((struct Obj21615 *)(*(u8 * *)&((struct Obj02797 *)p)->f0))->fDC))->f14 + p[0xa] * 0x900, pixels, size);
    func_0201DD78(1, 2, 0);
    func_021EEE24(*(u32 *)&((struct Obj01524 *)q)->f38, 0x67, 2, p[0xc], ((struct Obj02797 *)p)->f8);
    if ((u8)func_0201D33C(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f28, 0, widths, 2) > 1) {
        width = widths[0];
        edge = width + 8;
        right = 0x84 - widths[1];
        gap = edge - right;
        if (gap < 12) {
            extra = 12 - gap;
            half = extra / 2;
            edge += half;
            extra -= half;
            right -= extra;
        }
        left = edge;
        left = left - width;
        if (left < 0) left = 0;
        if (right < 0) right = 0;
        func_0201D37C(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f3C, 0);
        func_0201C7A4(((struct Obj02797 *)p)->f4, left, 7, ((struct Obj01524 *)q)->f3C, (void *)(((struct Obj01524 *)q)->f28));
        func_0201D37C(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f3C, 1);
        func_0201C7A4(((struct Obj02797 *)p)->f4, right, 18, ((struct Obj01524 *)q)->f3C, (void *)(((struct Obj01524 *)q)->f28));
    } else {
        center = (0x88 - func_0201D304(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f28, 0)) / 2;
        if ((int)center < 0) center = 0;
        func_0201C7A4(((struct Obj02797 *)p)->f4, center, 18, ((struct Obj01524 *)q)->f38, (void *)(((struct Obj01524 *)q)->f28));
    }
}

void func_021EDF4C(struct W *w)
{
    if (w->fa == 0)
        func_02040618(w->fb, 0, 0x90);
    else
        func_02040618(w->fb, 0, -0x90);
    w->f22_0 = 0;
}


/* 021EDF78  movs r0,#1 */
/*
 * Returns the constant #1.
 */
int func_021EDF78(u8 *a0) { return 1; }


void func_021EDF7C(u8 *p, u8 b)
{
    u8 *r;
    u16 h;
    u8 t;

    r = (u8 *)func_021B98AC(*(char *const * *)&((struct Obj21617 *)(*(u8 * *)&((struct Obj05234 *)p)->f0))->f138, b);
    h = func_021D59B4(r, 0x10);
    t = func_021D5440(r);
    if (h != ((struct Obj05234 *)p)->f8 || t != p[0xc]) {
        p[0xc] = t;
        ((struct Obj05234 *)p)->f8 = h;
        func_021EDE54(p);
    }
    p[0xd] = 0;
    func_021F8AE8(b, h);
}

static inline void G2_BG2Mosaic(int enable)
{
    if (enable) *(volatile u16 *)0x0400000c |= 0x40;
    else *(volatile u16 *)0x0400000c &= ~0x40;
}

static inline void G2_BG3Mosaic(int enable)
{
    if (enable) *(volatile u16 *)0x0400000e |= 0x40;
    else *(volatile u16 *)0x0400000e &= ~0x40;
}

int func_021EDFC4(u8 *p)
{
    u8 a;
    switch (p[0xd]) {
    case 0:
        *(volatile u8 *)0x0400004c = 0;
        if (p[0xa] == 0) G2_BG2Mosaic(1);
        else G2_BG3Mosaic(1);
        p[0x20] = 0;
        p[0x21] = 0;
        func_020061E4(0x54e);
        p[0xd]++;
        break;
    case 1:
        p[0x20]++;
        if (*(volatile u8 *)&((struct Obj00623 *)p)->f20 > 1) {
            p[0x20] = 0;
            p[0x21]++;
            a = *(volatile u8 *)&((struct Obj00623 *)p)->f21;
            *(volatile u8 *)0x0400004c = a | (a << 4);
            if (*(volatile u8 *)&((struct Obj00623 *)p)->f21 >= 15) p[0xd]++;
        }
        break;
    case 2:
        func_02040B1C(p[0xb], func_020437D4(((struct Obj00623 *)p)->f4), 0x900, ((struct Obj00623 *)p)->f1C);
        p[0xd]++;
        break;
    case 3:
        p[0x20]++;
        if (*(volatile u8 *)&((struct Obj00623 *)p)->f20 > 1) {
            p[0x20] = 0;
            p[0x21]--;
            a = *(volatile u8 *)&((struct Obj00623 *)p)->f21;
            *(volatile u8 *)0x0400004c = a | (a << 4);
            if (*(volatile u8 *)&((struct Obj00623 *)p)->f21 == 0) p[0xd]++;
        }
        break;
    case 4:
        if (p[0xa] == 0) G2_BG2Mosaic(0);
        else G2_BG3Mosaic(0);
        p[0xd]++;
        break;
    case 5:
        if (func_02006254(0x54e) == 0) p[0xd]++;
        break;
    default:
        return 1;
    }
    return 0;
}
