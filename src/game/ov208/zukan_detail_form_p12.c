/*
 * file:     zukan_detail_form_p12.c
 * unit:     yes
 * function: func_021C66C8, func_021C6760, func_021C68D4, func_021C692C, func_021C6A10, func_021C6AFC, func_021C6BB4, func_021C6C00, func_021C6D10, func_021C6D6C, func_021C6DD8, func_021C6E30
 * address:  0x021C66C8
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
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   ov208_func_021BC3B4 0x021BC3B4 thumb ov208
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   ov208_func_021BDC48 0x021BDC48 thumb ov208
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021BC3B4  0x021BC3B4  thumb
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B404        0x0204B404  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_021BDC48  0x021BDC48  thumb
 *   ov208_func_021C6E60  0x021C6E60  thumb
 *   ov208_func_021C5C64  0x021C5C64  thumb
 */
#include "../../matched/include/Obj03368.h"
#include "../../matched/include/Obj05545.h"
#include "../../matched/include/Obj02258.h"
#include "../../matched/include/Obj01979.h"
#include "../../matched/include/Obj25526.h"

#define F32(b, o) (*(u32 *)((b) + (o)))
#define W(o) (*(u32 *)(p + (o)))
#define ST(i) (*(u32 *)(p + (i) * 0x28 + 0x614))
#define OBJ(i) (*(u32 *)(p + (i) * 0x28 + 0x618))
#define STB(i) (*(u32 *)(p + 0x614 + (i) * 0x28))
#define OBJB(i) (*(u32 *)(p + 0x618 + (i) * 0x28))
#define B8(i) (*(p + (i) * 0x28 + 0x608))
#define H(o) (*(u16 *)(p + (o)))
struct Obj;
struct Actor;
struct Vec2;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Ov208Pos;

struct Ov208Cursor {
    u8  slot;
    u8  pad;
    s16 x;
    s16 y;
};

extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void *ov208_func_021BC3B4(int key);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(int v);
extern void ov208_func_021BDC48(void *scene, u32 on);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern int func_021BC3B4(int *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u32  func_02035CB8(u32 *x, u32 *y);
extern void func_021BDC48(void *scene, u32 on);
extern u16  ov208_func_021C6E60(void *a0, u8 *p, int key, u16 skip, u16 want);
extern void ov208_func_021C5C64(void *a0, u8 *p, int key);
void func_021C66C8(void *unused,u8 *p);
int ov208_func_021C6760(void *unused, u8 *p, int key);
void ov208_func_021C68D4(void *unused, u8 *p);
void ov208_func_021C692C(u16 *heap, u8 *p, int key);
void ov208_func_021C6A10(void *unused, u8 *p);
void ov208_func_021C6AFC(void *a0, u8 *p, int a2);
void ov208_func_021C6BB4(void *a0, u8 *p, int key);
u32 ov208_func_021C6C00(void *a0, u8 *p, int key);
int ov208_func_021C6D10(void *a0, u8 *p, int a2);
void ov208_func_021C6D6C(int n, int i, u8 *lo, u8 *mid, u8 *hi);
u16 ov208_func_021C6DD8(u16 n, u8 x);
u16 ov208_func_021C6E30(void *unused, u8 *p, int unused2, u16 skip, u16 stop);

void func_021C66C8(void *unused,u8 *p)
{
    u8 i;
    for(i=0;i<4;i++)func_0204B3B4(*(struct Obj **)(p+i*0x28+0x618));
    for(i=0;i<4;i++)func_0204B3B4(*(struct Obj **)(p+i*4+0x5e4));
    func_0204ADA4(((struct Obj03368 *)p)->f5C4);
    func_0204A8D4(((struct Obj03368 *)p)->f5C0);
    func_0204AFD8(((struct Obj03368 *)p)->f5C8);
    func_0204ADA4(((struct Obj03368 *)p)->f5D0);
    func_0204A8D4(((struct Obj03368 *)p)->f5CC);
    func_0204AFD8(((struct Obj03368 *)p)->f5D4);
    func_0204ADA4(((struct Obj03368 *)p)->f5DC);
    func_0204A8D4(((struct Obj03368 *)p)->f5D8);
    func_0204AFD8(((struct Obj03368 *)p)->f5E0);
}


int ov208_func_021C6760(void *unused, u8 *p, int key)
{
    void *sys;
    enum { HIT_NONE = 5 } hit;
    u32 type;
    u32 x;
    u32 y;
    u8 i;
    u8 *b;
    u8 *c;
    u8 j;
    int partner;
    int o;
    u8 *q;
    int k;
    sys = ov208_func_021BC3B4(key);
    hit = HIT_NONE;
    if (hit == 5) {
        for (i = 0; i < 4; i++) {
            b = p + i * 0x28;
            if (func_0204B3F4((void *)F32(b, 0x618)) != 0) {
                if ((func_020362DC() & F32(b, 0x60c)) != 0) {
                    type = 0;
                    hit = i;
                    break;
                }
                if (i == 2 || i == 3) {
                    if ((func_0203633C() & F32(b, 0x60c)) != 0) {
                        type = 0;
                        hit = i;
                        break;
                    }
                }
            }
        }
    }
    if (hit == 5) {
        if (func_02035D20(&x, &y) != 0) {
            k = 0x604;
            for (j = 0; j < 4; j++) {
                c = p + j * 0x28;
                if (func_0204B3F4((void *)F32(c, 0x618)) != 0) {
                    if ((u32)c[k] <= x && x < (u32)c[k] + c[k + 2]
                        && (u32)c[k + 1] <= y && y < (u32)c[k + 1] + c[k + 3]) {
                        type = 1;
                        hit = j;
                        break;
                    }
                }
            }
        }
    }
    if (hit != 5) {
        if (F32(p, 0x694) != 5) {
            hit = 6;
        } else {
            func_020355D8(type);
            ov208_func_021BDC48(sys, 0);
            o = hit * 0x28;
            *(u32 *)(p + 0x614 + o) = 1;
            func_0204B878((void *)*(u32 *)(p + 0x618 + o), *(u8 *)(p + 0x609 + o));
            func_020061E4(*(u32 *)(p + 0x610 + o));
            partner = 5;
            if (hit == 2)
                partner = 3;
            else if (hit == 3)
                partner = 2;
            if (partner != 5) {
                q = p + 0x618;
                func_0204B92C((void *)F32(q, partner * 0x28), 0);
                func_0204B8C4((void *)F32(q, partner * 0x28), 0);
            }
            F32(p, 0x694) = hit;
        }
    }
    return hit;
}


void ov208_func_021C68D4(void *unused, u8 *p)
{
    int on = 0;

    switch (((struct Obj05545 *)p)->f6B8) {
    case 0:
        if (((struct Obj05545 *)p)->f548 >= 2)
            on = 1;
        break;
    case 4:
        break;
    }
    if (on) {
        func_0204B3DC((struct Obj *)((struct Obj05545 *)p)->f668, 1);
        func_0204B3DC((struct Obj *)*(u32 *)(p + 0x668 + 0x28), 1);
    } else {
        func_0204B3DC((struct Obj *)((struct Obj05545 *)p)->f668, 0);
        func_0204B3DC((struct Obj *)*(u32 *)(p + 0x668 + 0x28), 0);
    }
}


void ov208_func_021C692C(u16 *heap, u8 *p, int key)
{
    void *scene;
    u32 other;

    scene = (void *)func_021BC3B4((int *)key);
    if (W(0x694) == 5)
        return;
    switch (STB(W(0x694))) {
    case 0:
        break;
    case 1:
        STB(W(0x694)) = 2;
        return;
    case 2:
        if (func_0204B98C((struct Actor *)OBJ(W(0x694))) != 0)
            break;
        ST(W(0x694)) = 3;
        return;
    case 3:
        func_0204B878((struct Obj *)OBJ(W(0x694)), B8(W(0x694)));
        ST(W(0x694)) = 0;
        other = 5;
        if (W(0x694) == 2)
            other = 3;
        else if (W(0x694) == 3)
            other = 2;
        if (other != 5 && ST(other) == 0) {
            func_0204B92C((struct Obj *)OBJB(other), 1);
            func_0204B878((struct Obj *)OBJB(other), B8(other));
        }
        W(0x694) = 5;
        if (W(0x6b8) == 0 || W(0x6b8) == 4)
            ov208_func_021BDC48(scene, 1);
        break;
    }
}


void ov208_func_021C6A10(void *unused, u8 *p)
{
    int show = 1;
    int multi = 0;
    int v;
    int w;
    Ov208Pos pos;

    switch (((struct Obj02258 *)p)->f6B8) {
    case 0:
        show = 1;
        break;
    case 4:
        if (((struct Obj02258 *)p)->f548 >= 2)
            multi = 1;
        break;
    }
    if (show && multi) {
        pos.x = 0;
        pos.y = 0;
        func_0204B404((struct Obj *)(((struct Obj02258 *)p)->f5EC), (const struct Vec2 *)(&pos), 0);
        pos.x = 0x80;
        pos.y = 0;
        func_0204B404((struct Obj *)(((struct Obj02258 *)p)->f5F0), (const struct Vec2 *)(&pos), 0);
    } else if (show) {
        pos.x = 0x40;
        pos.y = 0;
        func_0204B404((struct Obj *)(((struct Obj02258 *)p)->f5EC), (const struct Vec2 *)(&pos), 0);
    }
    if (*(u32 *)(p + ((struct Obj02258 *)p)->f54E * 16 + 0x14c) == 2)
        v = 1;
    else
        v = 0;
    func_0204B3DC((struct Obj *)((struct Obj02258 *)p)->f5EC, 1);
    func_0204B878((struct Obj *)(((struct Obj02258 *)p)->f5EC), (u8)v);
    if (multi) {
        w = *(u32 *)(p + ((struct Obj02258 *)p)->f550 * 16 + 0x14c) == 2;
        func_0204B3DC((struct Obj *)((struct Obj02258 *)p)->f5F0, 1);
        func_0204B878((struct Obj *)(((struct Obj02258 *)p)->f5F0), (u8)w);
    } else {
        func_0204B3DC((struct Obj *)((struct Obj02258 *)p)->f5F0, 0);
    }
}


void ov208_func_021C6AFC(void *a0, u8 *p, int a2)
{
    int on = 0;
    u16 n;
    u8 mid;
    Ov208Pos pos;

    switch (((struct Obj01979 *)p)->f6B8) {
    case 0:
        break;
    case 4:
        if (((struct Obj01979 *)p)->f548 >= 3)
            on = 1;
        break;
    }
    if (on) {
        n = ov208_func_021C6E30(a0, p, a2, ((struct Obj01979 *)p)->f54E, ((struct Obj01979 *)p)->f550);
        ov208_func_021C6D6C((u16)(((struct Obj01979 *)p)->f548 - 1), n, 0, &mid, 0);
        pos.x = mid;
        pos.y = 0x30;
        func_0204B404((struct Obj *)(((struct Obj01979 *)p)->f5E8), (const struct Vec2 *)(&pos), 0);
        func_0204B3DC((struct Obj *)((struct Obj01979 *)p)->f5E4, 1);
        func_0204B3DC((struct Obj *)((struct Obj01979 *)p)->f5E8, 1);
        ((struct Obj01979 *)p)->f698 = 0;
        ((struct Obj01979 *)p)->f6D4 = 0;
        ((struct Obj01979 *)p)->f69C = 0;
    } else {
        func_0204B3DC((struct Obj *)((struct Obj01979 *)p)->f5E4, 0);
        func_0204B3DC((struct Obj *)((struct Obj01979 *)p)->f5E8, 0);
    }
}


void ov208_func_021C6BB4(void *a0, u8 *p, int key)
{
    if ((W(0x6b8) == 4 && W(0x6b4) != 0 && W(0x694) == 5) || W(0x6d4) != 0) {
        if (ov208_func_021C6D10(a0, p, key) == 0)
            ov208_func_021C6C00(a0, p, key);
    }
}


u32 ov208_func_021C6C00(void *a0, u8 *p, int key)
{
    u32 x;
    u32 y;
    s16 pos[2];
    void *scene;
    int moved;
    u16 old;

    scene = (void *)func_021BC3B4((int *)key);
    moved = 0;
    if (W(0x69c) != 0) {
        if (func_02035CB8(&x, &y) == 0) {
            W(0x69c) = 0;
            func_021BDC48(scene, 1);
        }
    } else if (H(0x548) >= 3) {
        if (func_02035D20(&x, &y) != 0 && x >= 0x90 && x <= 0xe7 && y >= 0x28 && y <= 0x3f) {
            W(0x69c) = 1;
            func_021BDC48(scene, 0);
            moved = 1;
        }
    }
    if (W(0x69c) != 0) {
        old = H(0x550);
        x = x > 0xdc ? 0xdc : (x < 0x9c ? 0x9c : x);
        pos[0] = x;
        pos[1] = 0x30;
        func_0204B404((struct Obj *)W(0x5e8), (const struct Vec2 *)pos, 0);
        H(0x550) = ov208_func_021C6E60(a0, p, key, H(0x54e),
                                       ov208_func_021C6DD8(H(0x548) - 1, x));
        if (old != H(0x550)) {
            ov208_func_021C5C64(a0, p, key);
            moved = 1;
        }
    }
    if (moved)
        func_020061E4(0x645);
    if (W(0x69c) != 0)
        func_020355D8(1);
    return W(0x69c);
}


int ov208_func_021C6D10(void *a0, u8 *p, int a2)
{
    struct Ov208Cursor c;
    int moved;
    u16 i;

    moved = 0;
    if (W(0x698) != 0) {
        i = ov208_func_021C6E30(a0, p, a2, H(0x54e), H(0x550));
        ov208_func_021C6D6C((u16)(H(0x548) - 1), i, 0, &c.slot, 0);
        c.x = c.slot;
        c.y = 0x30;
        func_0204B404((struct Obj *)W(0x5e8), (const struct Vec2 *)(&c.x), 0);
        moved = 1;
    }
    return moved;
}


void ov208_func_021C6D6C(int n, int i, u8 *lo, u8 *mid, u8 *hi)
{
    u8 a = i * 65 / n + 0x9c;
    u8 b = (i + 1) * 65 / n + 0x9c;
    u8 m;

    if (i == 0)
        m = a;
    else if (i == n - 1)
        m = b - 1;
    else if (a >= b)
        m = a;
    else
        m = (a + b - 1) / 2;
    if (lo != 0)
        *lo = a;
    if (hi != 0)
        *hi = b;
    if (mid != 0)
        *mid = m;
}


u16 ov208_func_021C6DD8(u16 n, u8 x)
{
    u8 b[3];
    u16 i;

    for (i = 0; i < n; i++) {
        ov208_func_021C6D6C(n, i, &b[2], &b[1], &b[0]);
        if (i == 0) {
            if (x < b[0])
                break;
        } else {
            if (i == n - 1)
                break;
            if (b[2] <= x && x < b[0])
                break;
        }
    }
    return i;
}


u16 ov208_func_021C6E30(void *unused, u8 *p, int unused2, u16 skip, u16 stop)
{
    u16 n = 0;
    u16 i;

    for (i = 0; i < ((struct Obj25526 *)p)->f548; i++) {
        if (i == skip)
            continue;
        if (i == stop)
            break;
        n++;
    }
    return n;
}
