/*
 * file:     worldtrade_adapter_p21.c
 * unit:     yes
 * function: func_021FEB84, func_021FEBB8, func_021FEBE0, func_021FEC00, func_021FED24, func_021FED4C, func_021FED6C, func_021FEE1C, func_021FEE44, func_021FEE70, func_021FEEFC, func_021FEF24, func_021FEF50, func_021FF004, func_021FF024, func_021FF078, func_021FF0A0, func_021FF0BC
 * address:  0x021FEB84
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
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *   func_021FF318  0x021FF318  thumb  ov135
 *   func_021F4E98  0x021F4E98  thumb  ov135
 *   func_021F9968  0x021F9968  thumb  ov135
 *   func_021FF570  0x021FF570  thumb  ov135
 *   func_021F99F0  0x021F99F0  thumb
 *   func_021F89A8  0x021F89A8  thumb
 *   func_021F7F9C  0x021F7F9C  thumb
 *   func_021F7B9C  0x021F7B9C  thumb
 *   func_021F8098  0x021F8098  thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F882C 0x021F882C thumb ov135
 *   func_021F8154 0x021F8154 thumb ov135
 *   func_021F88B0 0x021F88B0 thumb ov135
 *   func_021F8010 0x021F8010 thumb ov135
 *   d_02202EAC 0x02202EAC data a4
 *   func_021F4BE0  0x021F4BE0  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FFBC8 0x021FFBC8 thumb ov135
 *   func_02202840  0x02202840  thumb  ov135
 */
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj12214.h"
#include "../../matched/include/Obj12215.h"
#include "../../matched/include/Obj02861.h"
#include "../../matched/include/Obj09239.h"
#include "../../matched/include/Obj05417.h"
#include "../../matched/include/Obj09240.h"
#include "../../matched/include/Obj02204.h"
#include "../../matched/include/Obj18599.h"
#include "../../matched/include/Obj00045.h"
#include "../../matched/include/Obj23427.h"
#include "../../matched/include/Obj12216.h"
#include "../../matched/include/Obj12217.h"

struct CharBuf;
struct Descriptor;
struct Personal;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed char s8;

typedef signed short s16;

typedef struct {
    u8 pad0[4];
    u16 x4;
    u16 x6;
    u16 x8;
    u16 xA;
    u8 padC[0x20 - 0xC];
    u32 x20;
} Target;

typedef struct {
    u8 pad0[0x28];
    u32 state;
    u8 pad2C[0xB56 - 0x2C];
    u16 sel;
    s8 mode;
    u8 padB59[0xB6C - 0xB59];
    void *bankA;
    void *bankB;
    u8 padB74[0xD94 - 0xB74];
    void *winA;
    u8 padD98[0xD9C - 0xD98];
    void *winB;
    u8 padDA0[0xDE4 - 0xDA0];
    void *obj;
    u8 padDE8[0xE00 - 0xDE8];
    Target *target;
    u8 padE04[0xEEC - 0xE04];
    u8 area[0xFA0 - 0xEEC];
    u8 g[4];
} Work;

extern void func_021C8658(u8 *p);
extern void func_021F4FC4(u8 *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021FF318(u8 *p, u32 k, int b, int c, int d);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_021F9968(u8 *p, int mode);
extern void func_021FF570(u32 k);
extern int func_021F99F0(void *obj);
extern void func_021F89A8(u8 *p, int i, u16 a, u16 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern int func_021F7B9C(u8 *p, int event);
extern void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);
extern void func_0201F7A8(void *, unsigned);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_021F882C(u8 *dst, int i, int kind);
extern void func_021F8154(void *, void *, int, unsigned, unsigned, u16, int, void *);
extern void func_021F88B0(u8 *p, u32 n);
extern void func_021F8010(void *, void *, void *, unsigned, unsigned, unsigned, u16, void *);
extern void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021FFBC8(u8 *p);
extern u32 func_02202840(u8 *p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
int func_021FEB84(u8 *p);
int func_021FEBB8(u8 *p);
int func_021FEBE0(u8 *p);
int func_021FEC00(Work *p);
int func_021FED24(u8 *p);
int func_021FED4C(u8 *p);
int func_021FED6C(char *p);
int func_021FEE1C(u8 *p);
int func_021FEE44(u8 *p);
int func_021FEE70(char *p);
int func_021FEEFC(u8 *p);
int func_021FEF24(u8 *p);
int func_021FEF50(char *p);
int func_021FF004(u8 *p);
int func_021FF024(char *p);
int func_021FF070(char *p);
int func_021FF078(u8 *p);
int func_021FF0A0(u8 *p);
int func_021FF0BC(u8 *p);
extern const int d_02202EAC;


/*
 * Every concrete byte is reproduced (52 bytes of code; the listing's extra two
 * are alignment padding).  The one wildcard is the BLX at +0006 to
 * func_021C8658, which has no independent witness outside 0x021FEB84..0x021FEBB6; the
 * resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Naming one of those eight
 * regions would be a guess, so the site stays parked.
 *
 * Shape: two hand-overs, then the fixed 6/1/0x48 opener, state 0, return 3.
 */
int func_021FEB84(u8 *p)
{
    func_021C8658(p);
    func_021F4FC4(p);
    func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    ((struct Obj00018 *)p)->f28 = 0;
    return 3;
}


/*
 * Build through func_021FF318 and publish the 0x10/0x5 pair.
 */
int func_021FEBB8(u8 *p)
{
    func_021FF318(p, 0x9, 1, 0, 0xf0f);
    func_021F4E98(p, 0x17, 0x5);
    return 2;
}


/*
 * Publish +0xde4, kick helper 9, latch state 6.
 */
int func_021FEBE0(u8 *p)
{
    func_021F9968((u8 *)(((struct Obj12214 *)p)->fDE4), 0);
    func_021FF570(9);
    ((struct Obj12214 *)p)->f28 = 6;
    return 2;
}


int func_021FEC00(Work *p)
{
    int r = func_021F99F0(p->obj);
    u32 h;
    u32 v;

    switch (r) {
    case -2:
        func_021FF570(0);
        p->state = 0;
        func_021F89A8(p->area, p->target->x6 + p->target->x4, p->target->xA, p->target->x8);
        break;
    case -1:
        break;
    default:
        func_021FF570(0);
        p->sel = r;
        p->state = 0;
        func_02043B5C(func_02045770(p->winA), 0);
        func_021F7F9C(p->winA, p->bankB, r, 0, 0, 0x3C40, p->g);
        h = (u32)func_0201ADE4((u16)r, 0, 0x48);
        v = func_0201AE1C((const struct Personal *)h, 0x14);
        func_0201AE14((void *)h);
        p->target->x20 = v;
        func_021F89A8(p->area, p->target->x6 + p->target->x4, p->target->xA, p->target->x8);
        if (func_021F7B9C((u8 *)(&p->sel), p->target->x20) != 0) {
            func_02043B5C(func_02045770(p->winB), 0);
            func_021F8098(p->winB, p->bankA, p->mode, 1, 0, 0, 0x3C40, p->g);
        }
        break;
    }
    return 2;
}


/*
 * Build through func_021FF318 and publish the 0x10/0x8 pair.
 */
int func_021FED24(u8 *p)
{
    func_021FF318(p, 0xa, 1, 0, 0xf0f);
    func_021F4E98(p, 0x17, 0x8);
    return 2;
}


/*
 * Publish the +0xde4 slot, kick helper 9 and latch state 9.
 */
int func_021FED4C(u8 *p)
{
    func_021F9968((u8 *)(((struct Obj12215 *)p)->fDE4), 1);
    func_021FF570(9);
    ((struct Obj12215 *)p)->f28 = 9;
    return 2;
}

int func_021FED6C(char *p)
{
    unsigned r;
    void *w;
    r = func_021F99F0(((struct Obj02861 *)p)->fDE4);
    switch (r) {
    case -2:
        func_021FF570(0);
        func_0201F7A8(((struct Obj02861 *)p)->fD40, 0);
        w = ((struct Obj02861 *)p)->fD40;
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
        ((struct Obj02861 *)p)->f28 = 0;
        break;
    case 0:
    case 1:
    case 2:
        func_021FF570(0);
        ((struct Obj02861 *)p)->fB58 = r + 1;
        ((struct Obj02861 *)p)->f28 = 0;
        func_02043B5C(func_02045770(((struct Obj02861 *)p)->fD9C), 0);
        func_021F8098(((struct Obj02861 *)p)->fD9C, ((struct Obj02861 *)p)->fB6C, ((struct Obj02861 *)p)->fB58, 1, 0, 0, 0x3c40, p + 0xfa0);
        break;
    }
    return 2;
}


/*
 * Build through func_021FF318 and publish the 0x10/0xb pair.
 */
int func_021FEE1C(u8 *p)
{
    func_021FF318(p, 0xb, 1, 0, 0xf0f);
    func_021F4E98(p, 0x17, 0xb);
    return 2;
}


/*
 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xc.
 */
int func_021FEE44(u8 *p)
{
    ((struct Obj09239 *)p)->fBC = 0xffff;
    func_021F9968((u8 *)(((struct Obj09239 *)p)->fDE4), 2);
    func_021FF570(9);
    ((struct Obj09239 *)p)->f28 = 0xc;
    return 2;
}

int func_021FEE70(char *p)
{
    unsigned r = func_021F99F0(((struct Obj05417 *)p)->fDE4);
    switch (r) {
    case 11:
    case -2:
        func_021FF570(0);
        ((struct Obj05417 *)p)->f28 = 0;
        break;
    case -1: break;
    default:
        func_021FF570(0);
        func_021F882C((u8 *)(p + 0xb56), r, 1);
        ((struct Obj05417 *)p)->f28 = 0;
        func_02043B5C(func_02045770(((struct Obj05417 *)p)->fDA4), 0);
        func_021F8154(((struct Obj05417 *)p)->fDA4, ((struct Obj05417 *)p)->fB6C, r, 0, 0, 0x3c40, 1, p + 0xfa0);
        break;
    }
    return 2;
}


/*
 * Build through func_021FF318 and publish the 0x10/0xe pair.
 */
int func_021FEEFC(u8 *p)
{
    func_021FF318(p, 0xbe, 1, 0, 0xf0f);
    func_021F4E98(p, 0x17, 0xe);
    return 2;
}


/*
 * Sentinel at +0xbc, publish +0xde4, kick helper 9, latch state 0xf.
 */
int func_021FEF24(u8 *p)
{
    ((struct Obj09240 *)p)->fBC = 0xffff;
    func_021F9968((u8 *)(((struct Obj09240 *)p)->fDE4), 3);
    func_021FF570(9);
    ((struct Obj09240 *)p)->f28 = 0xf;
    return 2;
}

int func_021FEF50(char *p)
{
    int r;
    void *w;
    r = func_021F99F0(((struct Obj02204 *)p)->fDE4);
    if (r == -1) {
    } else if (r == -2 || r == d_02202EAC + 1) {
        func_021FF570(0);
        func_0201F7A8(((struct Obj02204 *)p)->fD40, 0);
        w = ((struct Obj02204 *)p)->fD40;
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
        ((struct Obj02204 *)p)->f28 = 0;
    } else {
        func_021FF570(0);
        func_021F88B0((u8 *)p, r);
        ((struct Obj02204 *)p)->f28 = 0;
        func_02043B5C(func_02045770(((struct Obj02204 *)p)->fDDC), 0);
        func_021F8010(((struct Obj02204 *)p)->fDDC, ((struct Obj02204 *)p)->fB7C, ((struct Obj02204 *)p)->fB6C, ((struct Obj02204 *)p)->fF84, 0, 0, 0x3c40, p + 0xfa0);
    }
    return 2;
}


int func_021FF004(u8 *p)
{
    func_021F4BE0((u32)p, 0x14, 0x120, 0x3, 0x1);
    ((struct Obj18599 *)p)->f28 = 0x1b;
    return 2;
}

int func_021FF024(char *p)
{
    unsigned r = func_021F4D14(p);
    if (r == 1) {
        func_021F4CE4(p);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0((u8 *)p, 1, 0);
        if (((struct Obj00045 *)p)->fD0 > 0) func_021FFBC8((u8 *)p);
        ((struct Obj00045 *)p)->fD0 = 0;
    } else if (r == 2) {
        func_021F4CE4(p);
        *(int *)&((struct Obj00045 *)p)->f28 = 0;
    }
    return 2;
}

int func_021FF070(char *p)
{
    ((struct Obj23427 *)p)->f28 = 1;
    return 2;
}


/*
 * Build through func_021FF318 and publish the 0x10/0x1 pair.
 */
int func_021FF078(u8 *p)
{
    func_021FF318(p, 0x9e, 1, 0, 0xf0f);
    func_021F4E98(p, 0x17, 0x1);
    return 2;
}


int func_021FF0A0(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12216 *)p)->f28 = ((struct Obj12216 *)p)->f2C;
    }
    return 2;
}


/*
 * When the build query answers 0 and either probe is set, roll the state word over.
 */
int func_021FF0BC(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (func_020362DC() != 0 || func_02035C60() != 0) {
            ((struct Obj12217 *)p)->f28 = ((struct Obj12217 *)p)->f2C;
        }
    }
    return 2;
}
