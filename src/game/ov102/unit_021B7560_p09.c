/*
 * file:     unit_021B7560_p09.c
 * unit:     yes
 * function: func_021B8868, func_021B8874, func_021B88F8, func_021B8934, func_021B89B8, func_021B89F0, func_021B8A40
 * address:  0x021B8868
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02005728 0x02005728 thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0200A8AC  0x0200A8AC  thumb
 *   func_021B78EC  0x021B78EC  thumb  ov102
 *   func_0200A8F8  0x0200A8F8  thumb
 *   func_021B8810  0x021B8810  thumb  ov102
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../../matched/include/Obj22169.h"
#include "../../matched/include/Obj05270.h"

struct Obj;
struct Vec2;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32_021B8868;

typedef signed int     s32_021B8934;

extern void func_02082BCC(void *, int, int);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32 func_02005728(u32 range);
extern s32_021B8934 func_0200A8AC(struct Rec *r);
extern u32 func_021B78EC(void *, int);
extern u32 func_0200A8F8(struct Rec *r, u32 index);
extern void func_021B8810(int a0, int b, int c, int a3);
void func_021B8868(void *p);
void func_021B8874(u32 *p);
void func_021B88F8(int *p);
void func_021B8934(u8 *a, void *b, void *c, int d);
void func_021B89B8(u8 *p);
void func_021B89F0(u8 *p);
void func_021B8A40(int *p, int a, int b, int n);

void func_021B8868(void *p) { func_02082BCC(p, 0, 0x1c); }

/*
 * extent: two trailing zero padding bytes at 021B88F6.
 * lever: sign declared before start fixes r6/r7; diff * counter avoids a move.
 */
void func_021B8874(u32 *p)
{
    u16 xy[2];
    int sign;
    int start, diff, magnitude, start2, diff2, magnitude2;
    s8 sign2;
    start = p[2];
    diff = (int)p[0] - start;
    magnitude = diff < 0 ? -diff : diff;
    sign = (s8)(diff / magnitude);
    if (diff < 0) diff = -diff;
    xy[0] = start + sign * (((u32)diff * (u32)p[4]) / (u32)p[5]);
    start2 = p[3];
    diff2 = (int)p[1] - start2;
    magnitude2 = diff2 < 0 ? -diff2 : diff2;
    sign2 = diff2 / magnitude2;
    if (diff2 < 0) diff2 = -diff2;
    xy[1] = start2 + sign2 * (((u32)diff2 * (u32)p[4]) / (u32)p[5]);
    func_0204B404((struct Obj *)p[6], (const struct Vec2 *)xy, 1);
    if ((p[4])++ > (u32)p[5]) func_021B88F8((int *)p);
}

void func_021B88F8(int *p) { p[2]=func_02005728(256); p[3]=208; p[0]=p[2]+func_02005728(184)-92; p[1]=184-200; p[4]=0; p[5]=func_02005728(360)+240; }


/*
 * Clears 0x350 bytes, stores the record count (0x1e or from 0x0200A8AC) at +0x34e,
 * then initialises count records of 0x1c bytes through func_021B8810.
 * Note 2026-10-05: func_021B8810 is matched with three parameters, but this caller
 * loads d into r3 before the call, so the original call site passes four. The older
 * draft that declared three arguments dropped that load (DIFF 109/128).
 */
void func_021B8934(u8 *a, void *b, void *c, int d)
{
    int i;
    func_02082BCC(a, 0, 0x350);
    if (c == 0)
        *(u16 *)(a + 0x34e) = 0x1e;
    else
        *(u16 *)(a + 0x34e) = func_0200A8AC(c);
    for (i = 0; i < *(u16 *)(a + 0x34e); i++) {
        u32 t = func_021B78EC(b, i);
        u32 u;
        if (c == 0)
            u = func_02005728(2);
        else
            u = (func_0200A8F8(c, i) == 1);
        func_021B8810((int)(a + i * 0x1c), t, u, d);
    }
}

void func_021B89B8(u8 *p) { int i; for(i=0;i<((struct Obj22169 *)p)->f34E;i++)func_021B8868(p+i*28); func_02082BCC(p,0,848); }

/*
 * extent: two trailing zero padding bytes at 021B8A3E.
 */
void func_021B89F0(u8 *p)
{
    int i;
    for (i = 0; i < ((struct Obj05270 *)p)->f34C; i++)
        func_021B8874((u32 *)(p + i * 0x1c));
    if ((((struct Obj05270 *)p)->f348)++ > 30) {
        ((struct Obj05270 *)p)->f348 = 0;
        if (((struct Obj05270 *)p)->f34C < ((struct Obj05270 *)p)->f34E)
            (((struct Obj05270 *)p)->f34C)++;
    }
}

/*
 * extent: two trailing zero padding bytes at 021B8A8E.
 */
void func_021B8A40(int *p, int a, int b, int n)
{
    int d;
    float f;
    p[0] = a;
    p[1] = a;
    p[2] = b;
    p[5] = n;
    if (n) {
        d = b - a;
        if (d > 0)
            f = 0.5f + (float)(d << 12);
        else
            f = (float)(d << 12) - 0.5f;
        p[3] = (int)f / n;
        p[4] = 0;
    } else {
        p[4] = n - 2;
    }
}
