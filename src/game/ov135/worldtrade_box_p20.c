/*
 * file:     worldtrade_box_p20.c
 * unit:     yes
 * function: func_021F7A4C, func_021F7A70, func_021F7A8C, func_021F7B50, func_021F7B9C, func_021F7BC8, func_021F7CB4, func_021F7CDC, func_021F7D00, func_021F7D80, func_021F7DA8, func_021F7DD0, func_021F7E74, func_021F7E9C, func_021F7EC0, func_021F7F14, func_021F7F64, func_021F7F80, func_021F7F9C
 * address:  0x021F7A4C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4EC0  0x021F4EC0  thumb  ov135
 *   func_021F9968  0x021F9968  thumb  ov135
 *   func_021F8950 0x021F8950 thumb ov135
 *   func_02202644 0x02202644 thumb ov135
 *   func_020452E8 0x020452E8 arm
 *   func_021F875C 0x021F875C thumb ov135
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021F81C8 0x021F81C8 thumb ov135
 *   func_021F89A8 0x021F89A8 thumb ov135
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_021F7538  0x021F7538  thumb  ov135
 *   func_021F4E98  0x021F4E98  thumb  ov135
 *   func_021F882C 0x021F882C thumb ov135
 *   func_021F886C 0x021F886C thumb ov135
 *   func_021F4BE0  0x021F4BE0  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F8668 0x021F8668 thumb ov135
 *   func_02202840  0x02202840  thumb  ov135
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 */
#include "../../matched/include/Obj12199.h"
#include "../../matched/include/Obj12200.h"
#include "../../matched/include/Obj01552.h"
#include "../../matched/include/Obj02855.h"
#include "../../matched/include/Obj23386.h"
#include "../../matched/include/Obj09230.h"
#include "../../matched/include/Obj01553.h"
#include "../../matched/include/Obj03830.h"
#include "../../matched/include/Obj23387.h"
#include "../../matched/include/Obj23388.h"
#include "../../matched/include/Obj09231.h"
#include "../../matched/include/Obj02856.h"
#include "../../matched/include/Obj09232.h"
#include "../../matched/include/Obj01942.h"
#include "../../matched/include/Obj23389.h"
#include "../../matched/include/Obj18563.h"
#include "../../matched/include/Obj10576.h"
#include "../../matched/include/Obj10577.h"
#include "../../matched/include/Obj12201.h"

struct Descriptor;
struct Obj;
struct Personal;
struct MsgBank;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef void (*Fn)(void);

typedef signed short s16;

typedef signed char s8;

extern u32 func_020362DC(void);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021F9968(u8 *p, int mode);
extern int func_021F8950(void *p, u16 *old);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern void func_02202644(u32 a, int kind);
extern void func_0201F7A8(void *p, unsigned kind);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020061E4(unsigned se);
extern void *func_021F875C(void *p, void *dst, void *win, void *bank, void *names, void *obj, void *ctx);
extern int func_021F99F0(void *);
extern void *func_0201ADE4(u32,int,u32);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern void func_021F81C8(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
extern void func_021F89A8(u8 *p, int i, u16 a, u16 b);
extern void func_021F7538(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_021F882C(u8 *dst, int i, int kind);
extern int func_021F886C(int x, int y, int which);
extern void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_021F8668(u8 *dst, u8 *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_02202840(u8 *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
int func_021F7A4C(u8 *p);
int func_021F7A70(u8 *p);
int func_021F7A8C(u8 *p);
int func_021F7B50(u8 *p);
int func_021F7B9C(u8 *p, int event);
int func_021F7BC8(u8 *p);
int func_021F7CB4(u8 *p);
int func_021F7CDC(u8 *p);
int func_021F7D00(u8 *p);
int func_021F7D80(u8 *p);
int func_021F7DA8(u8 *p);
int func_021F7DD0(u8 *p);
int func_021F7E74(u8 *p);
int func_021F7E9C(u8 *p);
int func_021F7EC0(u8 *p);
int func_021F7F14(u8 *p);
int func_021F7F64(u8 *p);
u16 func_021F7F80(int mode);
void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);


/*
 * Test bit 1 of the callee result; the odd branch re-latches state 2 before state 3.
 */
int func_021F7A4C(u8 *p)
{
    u32 v = func_020362DC();

    if (v & 2) {
        func_021F4EC0(p, 5, 5);
        ((struct Obj12199 *)p)->f28 = 2;
    }
    ((struct Obj12199 *)p)->f28 = 3;
    return 2;
}


/*
 * Hand the buffer at +0xde4 to the writer and stamp state 6.
 */
int func_021F7A70(u8 *p)
{
    func_021F9968((u8 *)(((struct Obj12200 *)p)->fDE4), 0);
    ((struct Obj12200 *)p)->f28 = 6;
    return 2;
}

int func_021F7A8C(u8 *p)
{
    switch ((unsigned)func_021F8950(((struct Obj01552 *)p)->fDF4, (u16 *)(p + 0xBC))) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        func_0202020C(((struct Obj01552 *)p)->fDF4, (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 6), (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 4));
        func_0201F868(((struct Obj01552 *)p)->fDE8);
        ((struct Obj01552 *)p)->f28 = 5;
        func_020061E4(0x54C);
        break;
    case (unsigned)-2:
        func_0202020C(((struct Obj01552 *)p)->fDF4, (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 6), (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 4));
        func_0201F868(((struct Obj01552 *)p)->fDE8);
        func_02202644((u32)(((struct Obj01552 *)p)->fD50), 0);
        func_0201F7A8(((struct Obj01552 *)p)->fD40, 0);
        func_020452E8(((struct Obj01552 *)p)->fD50);
        func_020452E8(((struct Obj01552 *)p)->fD54);
        func_021F4EC0(p, 5, 5);
        ((struct Obj01552 *)p)->f28 = 2;
        func_020061E4(0x54C);
        break;
    case 0:
        break;
    }
    return 2;
}

int func_021F7B50(u8 *p)
{
    ((struct Obj02855 *)p)->fDF4 = func_021F875C(p, p + 0xDE8, ((struct Obj02855 *)p)->fD54, ((struct Obj02855 *)p)->fB6C, ((struct Obj02855 *)p)->fB70, ((struct Obj02855 *)p)->fE00, ((struct Obj23386 *)(*(u8 * *)&((struct Obj02855 *)p)->f0))->f10);
    ((struct Obj02855 *)p)->fBC = 0xFFFF;
    ((struct Obj02855 *)p)->f28 = 6;
    return 2;
}

/*
 * Map the event code to its state byte: 0, 0xfe and 0xff are accepted.
 */
int func_021F7B9C(u8 *p, int event)
{
    switch (event) {
    case 0:
        ((struct Obj09230 *)p)->f2 = 1;
        return 1;
    case 0xfe:
        ((struct Obj09230 *)p)->f2 = 2;
        return 1;
    case 0xff:
        ((struct Obj09230 *)p)->f2 = 3;
        return 1;
    }
    return 0;
}

/*
 * lever: signed halfword selection store keeps the unsigned argument truncation after it.
 */
int func_021F7BC8(u8 *p)
{
    int result=func_021F99F0(((struct Obj01553 *)p)->fDE4);
    u32 h,v;
    int mode;
    u8 *target;
    switch(result) {
    case (u32)-2:
        func_0201F7A8(((struct Obj01553 *)p)->fD40,0);
        func_021F4EC0(p,5,5);
        ((struct Obj01553 *)p)->f28=2;
        target=*(u8 * *)&((struct Obj01553 *)p)->fE00;
        func_021F89A8(p+0xEEC,((struct Obj03830 *)target)->f6+((struct Obj03830 *)target)->f4,((struct Obj03830 *)target)->fA,((struct Obj03830 *)target)->f8);
        break;
    case (u32)-1:
        break;
    default:
        ((struct Obj01553 *)p)->fB50=result;
        h=(u32)func_0201ADE4((u16)result,0,0x48);
        v=func_0201AE1C((const struct Personal *)h,20);
        func_0201AE14((void *)h);
        ((struct Obj23387 *)(*(u8 * *)&((struct Obj01553 *)p)->fE00))->f20=v;
        if(func_021F7B9C(p+0xB50,((struct Obj23388 *)(*(u8 * *)&((struct Obj01553 *)p)->fE00))->f20)) {
            ((struct Obj01553 *)p)->f28=10;
            mode=((struct Obj01553 *)p)->fB52;
        } else {
            ((struct Obj01553 *)p)->f28=7;
            mode=3;
        }
        func_021F81C8(((struct Obj01553 *)p)->fB6C,((struct Obj01553 *)p)->fB70,(int)(((struct Obj01553 *)p)->fB68),p+0xD90,((struct Obj01553 *)p)->fB50,mode,-1,p+0xFA0);
        target=*(u8 * *)&((struct Obj01553 *)p)->fE00;
        func_021F89A8(p+0xEEC,((struct Obj03830 *)target)->f6+((struct Obj03830 *)target)->f4,((struct Obj03830 *)target)->fA,((struct Obj03830 *)target)->f8);
        break;
    }
    return 2;
}


/*
 * Build through func_021F7538 and publish the 0x10/0x8 pair.
 */
int func_021F7CB4(u8 *p)
{
    func_021F7538(p, 0xa, 1, 0, 0xf0f);
    func_021F4E98(p, 0x10, 0x8);
    return 2;
}


/*
 * Publish the 0xffff sentinel at +0xbc and the u32 at +0xde4, then latch state 9.
 */
int func_021F7CDC(u8 *p)
{
    ((struct Obj09231 *)p)->fBC = 0xffff;
    func_021F9968((u8 *)(((struct Obj09231 *)p)->fDE4), 1);
    ((struct Obj09231 *)p)->f28 = 9;
    return 2;
}

int func_021F7D00(u8 *p)
{
    unsigned result = func_021F99F0(((struct Obj02856 *)p)->fDE4);
    switch (result) {
    case (unsigned)-2:
        func_0201F7A8(((struct Obj02856 *)p)->fD40, 0);
        ((struct Obj02856 *)p)->f28 = 0;
        break;
    case 0: case 1: case 2:
        ((struct Obj02856 *)p)->fB52 = result + 1;
        ((struct Obj02856 *)p)->f28 = 10;
        func_021F81C8(((struct Obj02856 *)p)->fB6C, ((struct Obj02856 *)p)->fB70, (int)(((struct Obj02856 *)p)->fB68), p + 0xD90, ((struct Obj02856 *)p)->fB50, ((struct Obj02856 *)p)->fB52, -1, p + 0xFA0);
        break;
    }
    return 2;
}


int func_021F7D80(u8 *p)
{
    func_021F7538(p, 0xb, 1, 0, 0xf0f);
    func_021F4E98(p, 0x10, 0xb);
    return 2;
}


/*
 * Publish the u32 at +0xde4, the 0xffff sentinel at +0xbc and latch state 0xc.
 */
int func_021F7DA8(u8 *p)
{
    func_021F9968((u8 *)(((struct Obj09232 *)p)->fDE4), 2);
    ((struct Obj09232 *)p)->fBC = 0xffff;
    ((struct Obj09232 *)p)->f28 = 0xc;
    return 2;
}

int func_021F7DD0(u8 *p)
{
    unsigned result = func_021F99F0(((struct Obj01942 *)p)->fDE4);
    switch (result) {
    case 12: case (unsigned)-2:
        func_0201F7A8(((struct Obj01942 *)p)->fD40, 0);
        if (func_021F7B9C(p + 0xB50, ((struct Obj23389 *)(*(u8 * *)&((struct Obj01942 *)p)->fE00))->f20)) {
            ((struct Obj01942 *)p)->f28 = 0;
        } else {
            ((struct Obj01942 *)p)->f28 = 7;
        }
        break;
    case (unsigned)-1:
        break;
    default:
        func_021F882C(p + 0xB50, result, 0);
        ((struct Obj01942 *)p)->f28 = 13;
        result = func_021F886C(((struct Obj01942 *)p)->fB53, ((struct Obj01942 *)p)->fB54, 0);
        func_021F81C8(((struct Obj01942 *)p)->fB6C, ((struct Obj01942 *)p)->fB70, (int)(((struct Obj01942 *)p)->fB68), p + 0xD90, ((struct Obj01942 *)p)->fB50, ((struct Obj01942 *)p)->fB52, result, p + 0xFA0);
        break;
    }
    return 2;
}


int func_021F7E74(u8 *p)
{
    func_021F7538(p, 0x17, 1, 0, 0xf0f);
    func_021F4E98(p, 0x10, 0xe);
    return 2;
}


/*
 * State setter: build with the fixed 0x14/0x126/0x3/0x0 argument pair and latch state 0xf.
 */
int func_021F7E9C(u8 *p)
{
    func_021F4BE0((u32)p, 0x14, 0x126, 0x3, 0x0);
    ((struct Obj18563 *)p)->f28 = 0xf;
    return 2;
}

int func_021F7EC0(u8 *p)
{
    int result;
    result = func_021F4D14((char *)p);
    if (result == 1) {
        func_021F4CE4((char *)p);
        func_021F4EC0(p, 7, 7);
        ((struct Obj10576 *)p)->f28 = 2;
        ((struct Obj10576 *)p)->fEB4 = 1;
        func_021F8668(p + 0xE4, p);
    } else if (result == 2) {
        func_021F4CE4((char *)p);
        func_021F4EC0(p, 5, 5);
        ((struct Obj10576 *)p)->f28 = 2;
    }
    return 2;
}

int func_021F7F14(u8 *p)
{
    if (((struct Obj10577 *)p)->f14 == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        ((struct Obj10577 *)p)->fEB4 = 1;
    } else {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj10577 *)p)->f28 = 0;
    return 3;
}


/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int func_021F7F64(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12201 *)p)->f28 = ((struct Obj12201 *)p)->f2C;
    }
    return 2;
}


/*
 * Mode table: 0 -> 0x14c0, 1 -> 0xc80, anything else 0.
 */
u16 func_021F7F80(int mode)
{
    switch (mode) {
    case 0:
        return 0x53 << 6;
    case 1:
        return 0x32 << 6;
    default:
        return 0;
    }
}


void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        func_021F91A0(win, (u32)str, 0, x, y, color, (u32)g);
        func_02045808(str);
    }
}
