/*
 * file:     mailview_p01.c
 * unit:     yes
 * function: func_021C446C, func_021C44FC, func_021C4528, func_021C4534, func_021C4538, func_021C4590, func_021C45C0, func_021C4700, func_021C479C, func_021C47C4, func_021C483C, func_021C48FC, func_021C4998, func_021C49D0, func_021C4AF8, func_021C4B5C, func_021C4B88, func_021C4BFC, func_021C4C9C
 * address:  0x021C446C
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
 *   func_02024464 0x02024464 thumb
 *   func_02024450 0x02024450 thumb
 *   d_021C77A0 0x021C77A0 data a1
 *   func_02021FD8 0x02021FD8 thumb
 *   func_02035C38 0x02035C38 arm
 *   func_0203630C 0x0203630C arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_02028218 0x02028218 thumb
 *   _s32_div_f 0x0209C0A4 arm
 *   func_02035C08 0x02035C08 arm
 *   d_021C7784 0x021C7784 data a4
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02045808 0x02045808 arm
 *   func_02028230 0x02028230 thumb
 *   func_020282A4 0x020282A4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02027974 0x02027974 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02028454 0x02028454 thumb
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 *   func_02021D50 0x02021D50 thumb
 *   func_0204A648 0x0204A648 arm
 *   func_020419E4 0x020419E4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 *   func_021C4DE4 0x021C4DE4 thumb ov136
 *   func_021C4EEC 0x021C4EEC thumb ov136
 *   func_021C515C 0x021C515C thumb ov136
 *   func_021C5420 0x021C5420 thumb ov136
 *   func_021C4D54 0x021C4D54 thumb ov136
 *   func_021C5360 0x021C5360 thumb ov136
 *   func_021C5268 0x021C5268 thumb ov136
 *   func_02021EE4 0x02021EE4 thumb
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02030DA8 0x02030DA8 arm
 *   d_021C7EF8 0x021C7EF8 data a1
 */
#include "../../matched/include/Obj14184.h"
#include "../../matched/include/Obj01065.h"
#include "../../matched/include/Obj00274.h"
#include "../../matched/include/Obj02206.h"
#include "../../matched/include/Obj01413.h"
#include "../../matched/include/Obj00275.h"
#include "../../matched/include/Obj06524.h"
#include "../../matched/include/Obj00160.h"
#include "../../matched/include/Obj02865.h"

struct T;
struct Chan02021FD8;
struct Obj;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct TaskMenu;
struct TaskMenuTmpl;
struct U16Vec;
struct S02021D50;
struct R;
struct Ctx;
struct Obj02021EE4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char s8;

typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 x,y,w,h; } Template;

extern int func_02024464(struct T *p, u32 a1);
extern int func_02024450(const u16 *p);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02035C38(void);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020061E4(u32 a);
extern void func_0202822C(char *p, int v);
extern void func_02028218(struct Obj *obj, u32 a);
extern int func_02035C08(const void *p);
extern void func_0201F73C(void *, int, int, int);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 func_02028230(u8 *p);
extern void func_020282A4(struct Obj *obj);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_0202843C(u8 *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern void func_02045808(struct U16Vec *vec);
extern void func_02027974(void *p);
extern void func_02028454(u8 *p);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02021D50(struct S02021D50 *p);
extern void func_0204A648(void);
extern void func_020419E4(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_021C4DE4(u32 *p);
extern void func_021C4EEC(u8 *);
extern void func_021C515C(u8 *);
extern void func_021C5420(u8 *);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_021C4D54(u8 *);
extern void func_021C5360(u8 *);
extern void func_021C5268(u8 *);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_02030DA8(void *, void (*)(void *, u8 *), u8 *, int);
int func_021C446C(void *a);
void func_021C44FC(u8 *p);
int func_021C4528(void *a);
int func_021C4534(void);
int func_021C4538(u8 *p);
int func_021C4590(u8 *p);
int func_021C45C0(u8 *p);
int func_021C4700(u8 *p);
int func_021C479C(u8 *p);
void func_021C47C4(u8 *p, int n);
int func_021C483C(u8 *p);
void func_021C48FC(u8 *p);
int func_021C4998(u8 *p);
int func_021C49D0(u8 *p);
void func_021C4AF8(void);
void func_021C4B5C(void *a, u32 *p);
void func_021C4B88(void *unused, u8 *p);
int func_021C4BFC(u8 *p);
void func_021C4C9C(u8 *p);
extern const u8 d_021C77A0[][3];
extern u8 d_021C7784[];
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];
extern char d_021C7EF8[];

int func_021C446C(void *a)
{
    int t = 1;
    int n = 0;
    int c0 = 0;
    int c1 = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (d_021C77A0[((u8 *)((struct Obj14184 *)a)->f1C)[0xb]][i] != 0xFF) n++;
    }
    if (n == 3) t = 0;
    for (i = 0; i < 3; i++) {
        u8 *x = *(u8 * *)&((struct Obj14184 *)a)->f1C;
        if (d_021C77A0[x[0xb]][i] != 0xFF) {
            if (func_02024464((struct T *)(x + 0x16 + i * 8), 0x64)) c1++;
        } else {
            if (func_02024450((u16 *)(x + 0x16 + i * 8))) c0++;
        }
    }
    if (c0 < t || c1 < n) return 1;
    return 0;
}

void func_021C44FC(u8 *p)
{
    func_02021FD8((struct Chan02021FD8 *)(*(u32 *)&((struct Obj01065 *)p)->f38), 0, (u16)(p[0x1b] + 0x21), 1, 0, 0x7FFF);
    p[0x19] = 0;
    p[0x18] = 0;
}

int func_021C4528(void *a)
{
    func_021C44FC(a);
    return 0;
}

int func_021C4534(void)
{
    return 0;
}

/*
 * tail: 021C458E..021C4590 zero alignment padding.
 */
int func_021C4538(u8 *p)
{
    if (p[0xA] == 0) {
        if (func_02035C38()) return 0;
        if (func_0203630C()) {
            if (*(void (**)(void *))(p + 0x3C)) (*(void (**)(void *))(p + 0x3C))(p);
            p[0xA] = 1;
            return 1;
        }
    } else {
        if (func_0203630C()) return 0;
        if (func_02035C38()) {
            if (*(void (**)(void *))(p + 0x40)) (*(void (**)(void *))(p + 0x40))(p);
            p[0xA] = 0;
            return 0;
        }
    }
    return 0;
}

int func_021C4590(u8 *p)
{
    if (func_020362DC()) {
        p[0xA] = 1;
    } else if (func_02035C60()) {
        p[0xA] = 0;
    } else {
        return 0;
    }
    func_020061E4(0x54E);
    return 1;
}


int func_021C45C0(u8 *p)
{
    int moved;

    if (func_020362DC() & 1) {
        if (p[0x16] == 4) {
            if (func_021C446C(p)) {
                func_020061E4(0x551);
                p[0xB] = 2;
                return 0;
            }
            **(u16 * *)&((struct Obj00274 *)p)->f1C = 4;
            func_020061E4(0x54E);
            (*(u8 **)(p + 0x1C))[2] = 0;
            (*(u8 **)(p + 0x1C))[3] = 0;
            func_0202822C(((struct Obj00274 *)p)->f128, 1);
            return 1;
        }
        if (p[0x16] == 5) {
            func_020061E4(0x551);
            p[0xB] = 3;
            return 0;
        }
        (*(u8 **)(p + 0x1C))[2] = p[0x16];
        **(u16 * *)&((struct Obj00274 *)p)->f1C = (*(u8 **)(p + 0x1C))[2];
        (*(u8 **)(p + 0x1C))[3] = p[0x17];
        func_020061E4(0x54D);
        return 1;
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        p[0xB] = 3;
        return 0;
    }
    if (func_020362DC() & 8) {
        p[0x16] = 4;
        p[0x17] = 0;
        moved = 1;
    } else if (func_020362DC() & 0x80) {
        p[0x16] = (p[0x16] + 1) % 6;
        moved = 1;
    } else if (func_020362DC() & 0x40) {
        p[0x16] = (p[0x16] + 5) % 6;
        moved = 1;
    } else {
        return 0;
    }
    if (moved == 0) {
        return 0;
    }
    func_020061E4(0x54C);
    if (p[0x16] < 4) {
        func_02028218(((struct Obj00274 *)p)->f128, 0);
        func_02028218(((struct Obj00274 *)p)->f12C, 0);
    } else if (p[0x16] == 4) {
        func_02028218(((struct Obj00274 *)p)->f128, 1);
        func_02028218(((struct Obj00274 *)p)->f12C, 0);
    } else if (p[0x16] == 5) {
        func_02028218(((struct Obj00274 *)p)->f128, 0);
        func_02028218(((struct Obj00274 *)p)->f12C, 1);
    }
    p[0x1A] = p[0x16];
    return 0;
}

int func_021C4700(u8 *p)
{
    int n;
    n = func_02035C08(d_021C7784);
    if (n == -1) return 0;
    if (n == 4) {
        func_020061E4(0x551);
        p[0xB] = 3;
        return 0;
    }
    if (n < 4) {
        (*(u8 **)(p + 0x1C))[2] = n;
        *(u16 *)*(u8 * *)&((struct Obj00274 *)p)->f1C = (*(u8 **)(p + 0x1C))[2];
        (*(u8 **)(p + 0x1C))[3] = p[0x17];
        func_020061E4(0x54D);
        return 1;
    }
    if (func_021C446C(p)) {
        func_020061E4(0x551);
        p[0xB] = 2;
        return 0;
    }
    *(u16 *)*(u8 * *)&((struct Obj00274 *)p)->f1C = 4;
    func_020061E4(0x54E);
    (*(u8 **)(p + 0x1C))[2] = 0;
    (*(u8 **)(p + 0x1C))[3] = 0;
    func_0202822C(((struct Obj00274 *)p)->f128, 1);
    func_02028218(((struct Obj00274 *)p)->f12C, 0);
    return 1;
}

int func_021C479C(u8 *p)
{
    if (func_021C4538(p)) return 0;
    if (p[0xA] == 1) return func_021C45C0(p);
    return func_021C4700(p);
}

void func_021C47C4(u8 *p, int n)
{
    void *q;
    func_0201F73C(((struct Obj02206 *)p)->f5C, 2, 13, 4);
    func_02043B5C(func_02045770(((struct Obj02206 *)p)->f5C), 255);
    func_02045CAC(((struct Obj02206 *)p)->f20, n, ((struct Obj02206 *)p)->f34);
    ((struct Obj02206 *)p)->f9C = func_0201CCE4(*(u32 *)&((struct Obj02206 *)p)->f5C, 0, 0, *(u32 *)&((struct Obj02206 *)p)->f34, ((struct Obj02206 *)p)->f24, ((struct Obj02206 *)p)->f15, ((struct Obj02206 *)p)->f100, 4, (u16)((struct Obj02206 *)p)->f0, 15);
    q = ((struct Obj02206 *)p)->f5C;
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
}

int func_021C483C(u8 *p)
{
    void *q;
    switch (((struct Obj01413 *)p)->f8) {
    case 0:
        func_0202822C(((struct Obj01413 *)p)->f128, 1);
        func_02028218(((struct Obj01413 *)p)->f12C, 0);
        ((struct Obj01413 *)p)->f8 = 1;
        break;
    case 1:
        if (func_02028230(((struct Obj01413 *)p)->f128) != 0) {
            func_020282A4(((struct Obj01413 *)p)->f128);
            func_02028218(((struct Obj01413 *)p)->f128, 1);
            func_021C47C4(p, 2);
            ((struct Obj01413 *)p)->f8 = 2;
        }
        break;
    case 2:
        if (func_0201CE30(((struct Obj01413 *)p)->f9C) == 2) {
            if ((func_020362DC() & 1) || func_02035C60()) {
                func_0201CE48(((struct Obj01413 *)p)->f9C);
                ((struct Obj01413 *)p)->f8 = 3;
            }
        }
        break;
    case 3:
        func_0201F7A8(((struct Obj01413 *)p)->f5C, 2);
        q = ((struct Obj01413 *)p)->f5C;
        func_020456F8(q);
        func_020409B4(func_02045730(q));
        func_021C44FC(p);
        ((struct Obj01413 *)p)->f8 = 0;
        p[0xB] = p[0xC];
        break;
    }
    return 0;
}

void func_021C48FC(u8 *p)
{
    Template t;
    ((struct Obj00275 *)p)->f110 = (u32)func_02045EC0(((struct Obj00275 *)p)->f20, 4);
    ((struct Obj00275 *)p)->f114 = 0x39E3;
    ((struct Obj00275 *)p)->f118 = 0;
    ((struct Obj00275 *)p)->f11C = (u32)func_02045EC0(((struct Obj00275 *)p)->f20, 5);
    ((struct Obj00275 *)p)->f120 = 0x39E3;
    ((struct Obj00275 *)p)->f124 = 0;
    t.heap = ((struct Obj00275 *)p)->f0;
    t.count = 2;
    t.items = p + 0x110;
    t.zero = 0;
    t.x = 23;
    t.y = 6;
    t.w = 8;
    t.h = 3;
    ((struct Obj00275 *)p)->f10C = func_02027778((struct TaskMenuTmpl *)(&t), ((struct Obj00275 *)p)->f108);
    func_02021FD8(((struct Obj00275 *)p)->f38, 0, 0, 48, 10, 0);
    func_0202843C(((struct Obj00275 *)p)->f128);
    func_0202843C(((struct Obj00275 *)p)->f12C);
}

int func_021C4998(u8 *p)
{
    int r = -1;
    if (func_020279E8(((struct Obj06524 *)p)->f10C)) {
        r = func_02027A04(((struct Obj06524 *)p)->f10C);
        func_02027858(((struct Obj06524 *)p)->f10C);
        func_02045808(((struct Obj06524 *)p)->f110);
        func_02045808(((struct Obj06524 *)p)->f11C);
    }
    return r;
}


int func_021C49D0(u8 *p)
{
    int r;
    void *w;

    switch (((struct Obj00275 *)p)->f8) {
    case 0:
        func_02028218(((struct Obj00275 *)p)->f128, 0);
        func_0202822C(((struct Obj00275 *)p)->f12C, 1);
        break;
    case 1:
        if (func_02028230(((struct Obj00275 *)p)->f12C)) {
            func_020282A4(((struct Obj00275 *)p)->f12C);
            func_02028218(((struct Obj00275 *)p)->f12C, 1);
            ((struct Obj00275 *)p)->f10 = 1;
            func_021C47C4(p, 3);
            func_021C44FC(p);
            p[0x1B] = p[0x1A];
            break;
        }
        return 0;
    case 2:
        if (func_0201CE30(((struct Obj00275 *)p)->f9C) == 2) {
            func_0201CE48(((struct Obj00275 *)p)->f9C);
            func_021C48FC(p);
            ((struct Obj00275 *)p)->f8 = 3;
        }
        return 0;
    case 3:
        func_02027974(((struct Obj00275 *)p)->f10C);
        r = func_021C4998(p);
        if (r < 0)
            return 0;
        func_0201F7A8(((struct Obj00275 *)p)->f5C, 2);
        w = ((struct Obj00275 *)p)->f5C;
        func_020456F8(w);
        func_020409B4(func_02045730(w));
        ((struct Obj00275 *)p)->f8 = 0;
        if (r == 0) {
            **(u16 * *)&((struct Obj00275 *)p)->f1C = 0xFFFF;
            p[0xB] = p[0xC];
            return 1;
        }
        ((struct Obj00275 *)p)->f10 = 0;
        p[0xB] = p[0xC];
        func_02021FD8(((struct Obj00275 *)p)->f38, 0, 0, 0x30, 0, 0);
        func_02028454(((struct Obj00275 *)p)->f128);
        func_02028454(((struct Obj00275 *)p)->f12C);
        return 0;
    }
    (((struct Obj00275 *)p)->f8)++;
    return 0;
}

void func_021C4AF8(void)
{
    func_020434CC();
    func_02043588();
    func_020434DC(1, 0);
    func_020434DC(2, 0);
    func_020434DC(4, 0);
    func_020434DC(8, 0);
    func_020434DC(16, 0);
    func_020434DC(1, 0);
    func_02043598(1, 0);
    func_02043598(2, 0);
    func_02043598(4, 0);
    func_02043598(8, 0);
    func_02043598(16, 0);
}

void func_021C4B5C(void *a, u32 *p)
{
    if (p[14]) func_02021D50((struct S02021D50 *)p[14]);
    func_0204A648();
    func_020419E4();
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
}

/*
 * lever: p[0x18] >> 1 promotes to signed int before the u8 argument;
 * an unsigned cast drops the narrowing shift pair, a bitfield shifts 24/25.
 */
void func_021C4B88(void *unused, u8 *p)
{
    u8 old;
    u8 direction;
    if (((struct Obj01065 *)p)->f10 != 0 || p[0xA] == 0) return;
    if (p[0x1B] != p[0x1A]) {
        func_021C44FC(p);
        p[0x1B] = p[0x1A];
    }
    func_02021FD8(((struct Obj01065 *)p)->f38, 0, (u16)(p[0x1A] + 33), 1, p[0x18] >> 1, 0x7FFF);
    direction = p[0x19];
    old = p[0x18];
    if (direction != 0) {
        p[0x18] = old - 1;
        if (old == 1) p[0x19] = direction ^ 1;
    } else {
        p[0x18] = old + 1;
        if (old == 24) p[0x19] = direction ^ 1;
    }
}

/*
 * tail: 0x021C4C9A..0x021C4C9C is a zero alignment halfword.
 */
int func_021C4BFC(u8 *p)
{
    switch (((struct Obj00160 *)p)->f8) {
    case 0:
        ((struct Obj00160 *)p)->f20 = func_02045B38(0, 2, 60, (u16)((struct Obj00160 *)p)->f0);
        ((struct Obj00160 *)p)->f34 = func_020457B0(128, (u16)((struct Obj00160 *)p)->f0);
        func_021C4DE4((u32 *)p);
        break;
    case 1:
        func_021C4EEC(p);
        break;
    case 2:
        func_021C515C(p);
        break;
    case 3:
        func_021C5420(p);
        ((struct Obj00160 *)p)->f108 = func_02027F60(0, 8, (u32)(((struct Obj00160 *)p)->f24), (u32)(((struct Obj00160 *)p)->f98), (u16)((struct Obj00160 *)p)->f0);
        ((struct Obj00160 *)p)->f8 = 0;
        func_021C4D54(p);
        func_021C5360(p);
        func_021C5268(p);
        func_021C4C9C(p);
        return 1;
    }
    (((struct Obj00160 *)p)->f8)++;
    return 0;
}

void func_021C4C9C(u8 *p)
{
    void *q;
    func_02021FD8(((struct Obj02865 *)p)->f38, 0, 0, 112, 16, 0);
    func_02021EE4(((struct Obj02865 *)p)->f38, 1);
    func_02021D50(((struct Obj02865 *)p)->f38);
    p[0x18] = 0;
    p[0x19] = 0;
    q = func_02030734((u16)((struct Obj02865 *)p)->f0, func_02030CB0(3), 0, d_021C7EF8, 0x4F3);
    ((struct Obj02865 *)p)->fF4 = q;
    ((struct Obj02865 *)p)->fF8 = func_02030CBC(3, q);
    ((struct Obj02865 *)p)->fFC = func_02030DA8(((struct Obj02865 *)p)->fF8, func_021C4B88, p, 0);
}
