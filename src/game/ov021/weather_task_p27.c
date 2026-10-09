/*
 * file:     weather_task_p27.c
 * unit:     yes
 * function: func_021A666C, func_021A66E4, func_021A66EC, func_021A66F8, func_021A6708, func_021A6714, func_021A6720, func_021A672C, func_021A6738, func_021A6744, func_021A6750, func_021A675C, func_021A6768, func_021A6774, func_021A6780, func_021A678C, func_021A6798, func_021A67A4, func_021A682C, func_021A6870, func_021A6908, func_021A6974, func_021A69D8
 * address:  0x021A666C
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
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A652C  0x021A652C  thumb  ov021
 *   func_021A658C  0x021A658C  thumb  ov021
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB348  0x021AB348  thumb  ov021
 *   func_021BB1AC  0x021BB1AC  thumb  ov021
 *   func_021BB1B8  0x021BB1B8  thumb  ov021
 *   func_021BB1C4  0x021BB1C4  thumb  ov021
 *   func_021BB1D0  0x021BB1D0  thumb  ov021
 *   func_021BB1DC  0x021BB1DC  thumb  ov021
 *   func_021BB1E8  0x021BB1E8  thumb  ov021
 *   data_021D8AB8  0x021D8AB8  data  a4
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_021A6BAC  0x021A6BAC  thumb  ov021
 *   func_021A5B6C  0x021A5B6C  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 */
#include "../../matched/include/Obj19808.h"
#include "../../matched/include/Obj01658.h"
#include "../../matched/include/Obj01658.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
} S;

typedef u32 (*Fn)(u8 *p, u32 a, u32 b);

extern u16 func_0216D5F8(void *o);
extern void *func_0216D4B4(char *p);
extern int func_0216D3CC(int a0);
extern u32 func_021A652C(void *a, void *b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_021A658C(void *a, void *b, u32 c, u32 d, u32 e, u32 f);
extern u32 func_0216D7DC(void *p);
extern u16 func_021AB0F0(u32 a);
extern int func_021AB348(u32 a);
extern int func_021BB1AC(int x);
extern int func_021BB1B8(int x);
extern int func_021BB1C4(int x);
extern int func_021BB1D0(int x);
extern int func_021BB1DC(int x);
extern int func_021BB1E8(int x);
extern u32 *func_0216D550(u32 *p, u32 v);
extern void func_021A3964(u8 *p, u32 v);
extern u16 func_0216D608(void *p);
extern u16 func_021642A4(int i);
extern int func_0216D60C(int a0, int a1);
extern int func_021A6BAC(void *a);
extern int func_021A5B6C(u32 a, u32 b, u32 c, u32 d);
extern void func_0216D5E0(int a0, int a1);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *o, u32 v);
extern u32 *func_0216D548(u32 *p, u32 v);
u32 func_021A666C(void *a, void *b, u32 c, u32 d, u32 e, u32 f);
void func_021A66E4(u32 *p, u32 v);
void func_021A66EC(u32 *p, u32 v);
int func_021A66F8(S *a, int m);
void func_021A6708(void *a);
void func_021A6714(void *a);
void func_021A6720(void *a);
void func_021A672C(void *a);
void func_021A6738(void *a);
void func_021A6744(void *a);
void func_021A6750(void *a);
void func_021A675C(void *a);
void func_021A6768(void *a);
void func_021A6774(void *a);
void func_021A6780(void *a);
void func_021A678C(void *a);
void func_021A6798(void *a);
u32 func_021A67A4(u8 *p);
u32 func_021A682C(u8 *p, u32 a1, u32 a2);
void func_021A6870(u8 *p);
u32 func_021A6908(u8 *p, u32 a1);
u32 func_021A6974(u8 *p, u32 a1);
u32 func_021A69D8(u8 *p, u32 a1);
extern const Fn data_021D8AB8[];




/*
 * Addresses are Black-image addresses.
 */
u32 func_021A666C(void *a, void *b, u32 c, u32 d, u32 e, u32 f)
{
    u32 r0 = func_0216D5F8(b);

    if (e != 9 && e != r0) {
        func_0216D4B4(b);
        return func_021A658C(a, b, c, d, e, f);
    }
    if (!func_0216D3CC((int)b))
        return 0;
    if (e == 9)
        return func_021A652C(a, b, c, d, e, f);
    return func_021A658C(a, b, c, d, e, f);
}





/*
 * Unlabelled leaf: sets bits in the word at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A66E4(u32 *p, u32 v)
{
    p[1] |= v;
}





/*
 * Unlabelled leaf: clears bits in the word at +4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A66EC(u32 *p, u32 v)
{
    p[1] &= ~v;
}





int func_021A66F8(S *a, int m)
{
    if (a->f4 & m) {
        return 1;
    }
    return 0;
}





/*
 * Tail-call thunk: pins the second argument to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6708(void *a)
{
    func_021A66E4(a, 1);
}





void func_021A6714(void *a)
{
    func_021A66EC(a, 1);
}





/*
 * Tail-call thunk: pins the second argument to 2.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6720(void *a)
{
    func_021A66E4(a, 2);
}





void func_021A672C(void *a)
{
    func_021A66EC(a, 2);
}





/*
 * Tail-call thunk: pins the second argument to 4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6738(void *a)
{
    func_021A66EC(a, 4);
}





/*
 * Tail-call thunk: pins the second argument to 8.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6744(void *a)
{
    func_021A66E4(a, 8);
}





void func_021A6750(void *a)
{
    func_021A66EC(a, 8);
}





/*
 * Tail-call thunk: pins the second argument to 16.
 *
 * Addresses are Black-image addresses.
 */
void func_021A675C(void *a)
{
    func_021A66E4(a, 16);
}





void func_021A6768(void *a)
{
    func_021A66EC(a, 16);
}





/*
 * Tail-call thunk: pins the second argument to 32.
 *
 * Addresses are Black-image addresses.
 */
void func_021A6774(void *a)
{
    func_021A66E4(a, 32);
}





void func_021A6780(void *a)
{
    func_021A66EC(a, 32);
}




/*
 * Tail-call thunk: pins the second argument to 64.
 *
 * Addresses are Black-image addresses.
 */
void func_021A678C(void *a)
{
    func_021A66E4(a, 64);
}




void func_021A6798(void *a)
{
    func_021A66EC(a, 64);
}




u32 func_021A67A4(u8 *p)
{
    u32 r4 = func_0216D7DC((void *)(((struct Obj19808 *)p)->f1C));

    if (!func_021A66F8((S *)p, 2)) {
        r4 = func_021AB0F0(r4);
        if (func_021AB348(r4) == 1)
            return 1;
        if (func_021BB1AC(r4) == 1)
            return 2;
        if (func_021BB1B8(r4) == 1)
            return 3;
        if (func_021BB1C4(r4) == 1)
            return 4;
        if (func_021BB1D0(r4) == 1)
            return 5;
        if (func_021BB1DC(r4) == 1)
            return 6;
        if (func_021BB1E8(r4) == 1)
            return 7;
    }
    return 0;
}




u32 func_021A682C(u8 *p, u32 a1, u32 a2)
{
    u32 k;

    if (!func_0216D3CC(*(u32 *)&((struct Obj01658 *)p)->f1C))
        return a1;
    if (a2 == 0) {
        k = func_021A67A4(p);
        if (k != 0)
            return data_021D8AB8[k](p, a1, a2);
    }
    func_021A6870(p);
    return a1;
}




void func_021A6870(u8 *p)
{
    u32 o = *(u32 *)&((struct Obj01658 *)p)->f1C;

    if (func_021A66F8((S *)p, 0x59))
        func_0216D550((u32 *)o, 0x18);
    if (func_021A66F8((S *)p, 1)) {
        func_021A6714(p);
        func_021A6720(p);
        func_021A3964((u8 *)(*(u32 *)&((struct Obj01658 *)p)->f14), 0);
    }
    if (func_021A66F8((S *)p, 0x18)) {
        func_021A6750(p);
        func_021A6768(p);
        func_0216D60C(o, func_021642A4(func_0216D608((void *)o)));
    }
    if (func_021A66F8((S *)p, 0x20)) {
        func_021A6780(p);
        func_0216D60C(o, 3);
    }
    if (func_021A66F8((S *)p, 0x40)) {
        func_021A6798(p);
        func_021A6BAC(p + 0xC);
    }
}




u32 func_021A6908(u8 *p, u32 a1)
{
    void *o = ((struct Obj01658 *)p)->f1C;
    u32 r6 = func_0216D608(o);

    if (func_021A5B6C((u32)p, (u32)o, r6, 0)) {
        func_021A6870(p);
        return a1;
    }
    func_021A6708(p);
    func_021A6750(p);
    func_021A6768(p);
    func_0216D5E0((int)o, r6);
    func_0216D410(o, func_02197E7C(r6, 0x10));
    func_0216D548(o, 0x18);
    ((struct Obj01658 *)p)->f0 = 1;
    func_021A3964(*(u8 * *)&((struct Obj01658 *)p)->f14, 1);
    return r6;
}




u32 func_021A6974(u8 *p, u32 a1)
{
    void *o = ((struct Obj01658 *)p)->f1C;
    u32 r7 = func_0216D608(o);

    if (func_021A5B6C((u32)p, (u32)o, r7, 0)) {
        func_021A6870(p);
        return a1;
    }
    func_021A6708(p);
    func_021A6744(p);
    func_021A6768(p);
    func_0216D410(o, func_02197E7C(r7, 0x10));
    func_0216D548(o, 0x18);
    ((struct Obj01658 *)p)->f0 = 1;
    func_021A3964(*(u8 * *)&((struct Obj01658 *)p)->f14, 1);
    return r7;
}


u32 func_021A69D8(u8 *p, u32 a1)
{
    void *o = ((struct Obj01658 *)p)->f1C;
    u32 r7 = func_0216D608(o);

    if (func_021A5B6C((u32)p, (u32)o, r7, 0)) {
        func_021A6870(p);
        return a1;
    }
    func_021A6708(p);
    func_021A675C(p);
    func_021A6750(p);
    func_0216D410(o, func_02197E7C(r7, 0x10));
    func_0216D548(o, 0x18);
    ((struct Obj01658 *)p)->f0 = 1;
    func_021A3964(*(u8 * *)&((struct Obj01658 *)p)->f14, 1);
    return r7;
}
