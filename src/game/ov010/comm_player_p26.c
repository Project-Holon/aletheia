/*
 * file:     comm_player_p26.c
 * unit:     yes
 * function: func_0216A07C, func_0216A0BC, func_0216A128, func_0216A148, func_0216A184, func_0216A1C0, func_0216A1F8, func_0216A21C, func_0216A244, func_0216A264, func_0216A280, func_0216A298
 * address:  0x0216A07C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_021904A8  0x021904A8  thumb  ov021
 *   func_02027F60  0x02027F60  thumb
 *   func_02027FD8   0x02027FD8  thumb
 *   func_02045808   0x02045808  arm
 *   func_0202784C  0x0202784C  thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02027858  0x02027858  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3208  0x021A3208  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_021A2F54  0x021A2F54  thumb
 *   func_021A3244   0x021A3244  thumb  ov021
 *   func_021D1164  0x021D1164  thumb
 *   func_021D11B0  0x021D11B0  thumb
 *   func_021D11D8  0x021D11D8  thumb
 *   func_021D1194  0x021D1194  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988  0x02017988  thumb
 */
#include "../../matched/include/Obj09164.h"
#include "../../matched/include/Obj17748.h"
#include "../../matched/include/Obj17749.h"
#include "../../matched/include/Obj17750.h"
#include "../../matched/include/Obj00029.h"
#include "../../matched/include/Obj17751.h"
#include "../../matched/include/Obj17752.h"
#include "../../matched/include/Obj17753.h"
#include "../../matched/include/Obj17754.h"
#include "../../matched/include/Obj17755.h"

struct Descriptor;
struct PrintSys;
struct MsgBank;
struct R;
struct Rec;
struct TaskMenuState;
struct U16Vec;
struct TaskMenu;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Res {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    void *f10;          /* 0x10 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    void *f24;          /* 0x24 */
    u16 f28;            /* 0x28 */
    u32 f2C;            /* 0x2C */
    void *f30;          /* 0x30 */
    u16 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
    void *f3C;          /* 0x3C */
    void *f40;          /* 0x40 */
} Res;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    void *f0C;          /* 0x0C */
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res *f18;           /* 0x18 */
} Work;

typedef struct Slot {
    void *f00;
    u8 f04;
} Slot;

typedef struct Desc {
    u32 heap;           /* 0x00 */
    u8 f04;             /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0C;            /* 0x0C */
    u8 f10;             /* 0x10 */
    u8 f11;             /* 0x11 */
    u8 f12;             /* 0x12 */
    u8 f13;             /* 0x13 */
} Desc;

extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_021904AC(u8 *p);
extern u32 func_021904A8(u32 *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02045808(struct U16Vec *vec);
extern int func_0202784C(int a0, int a1);
extern int func_02027974();
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern int func_02027858();
extern void *func_02188CB4(unsigned char *p);
extern int func_021A3208();
extern void *func_021A3074(unsigned char *p);
extern int func_021A2F48();
extern char *func_0216DB04(void *a0);
extern u32 *func_0216D550(u32 *p, u32 v);
extern int func_021A2F54();
extern int func_021A3244(void *);
extern void *func_021D1164(u32 heap, u32 v);
extern int func_021D11B0();
extern int func_021D11D8();
extern int func_021D1194();
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017988(void *p, u32 a);
int func_0216A07C(Work *w);
void func_0216A0BC(Work *w);
void func_0216A128(void *p);
void func_0216A148(Work *w);
int func_0216A184(int a0);
int func_0216A1C0(int a0);
void func_0216A1F8(int a0);
int func_0216A21C(int a0);
int func_0216A244(void *a0);
int func_0216A264(int a0);
int func_0216A280(int a0);
void func_0216A298(void *a, void *list);


int func_0216A07C(Work *w)
{
    Slot *s;
    void *t;

    func_0201C4E4(w->f18->f14);
    t = w->f18->f14;
    s = (Slot *)&w->f18->f08;
    if (s->f04 != 0 && func_0201C6C4(t, func_02045770(s->f00)) == 0) {
        func_02045334(s->f00);
        s->f04 = 0;
    }
    return func_0201C6B4(w->f18->f14);
}


/*
 * Byte-correct (first draft). Blocker: 0x021904A8 has no func_ label in
 * any overlay listing (ov009 and ov021 overlap it); it sits four bytes before
 * ov021's func_021904AC and is almost certainly a Thumb accessor there. Seeding
 * it in ov021 closes this file.
 */
void func_0216A0BC(Work *w)
{
    void *bank;
    u32 a;

    bank = func_02045B38(0, 2, 0xA8, w->f10);
    w->f18->f24 = func_02045EC0(bank, 8);
    w->f18->f28 = 0x39E3;
    w->f18->f2C = 0;
    w->f18->f30 = func_02045EC0(bank, 9);
    w->f18->f34 = 0x39E3;
    w->f18->f38 = 0;
    func_02045C04(bank);
    a = func_021904AC(w->f0C);
    w->f18->f3C = func_02027F60(6, 14, a, func_021904A8(w->f0C), w->f10);
}


/*
 * Three teardown calls on the three arm9 handles the object carries.
 */
void func_0216A128(void *p)
{
    func_02027FD8(((struct Obj17748 *)(*(char * *)&((struct Obj09164 *)p)->f18))->f3C);
    func_02045808(((struct Obj17749 *)(*(char * *)&((struct Obj09164 *)p)->f18))->f30);
    func_02045808(((struct Obj17750 *)(*(char * *)&((struct Obj09164 *)p)->f18))->f24);
}


void func_0216A148(Work *w)
{
    Desc d;

    d.heap = w->f10;
    d.f04 = 2;
    d.f08 = &w->f18->f24;
    d.f0C = 1;
    d.f10 = 0x20;
    d.f11 = 12;
    d.f12 = 8;
    d.f13 = 3;
    w->f18->f40 = (void *)func_0202784C((int)(&d), (int)w->f18->f3C);
}


int func_0216A184(int a0)
{
    int t4;
    int t5;

t5 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_02027974(a0);
loc_0216A190:
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_020279E8((struct TaskMenu *)a0);
loc_0216A198:
    if (a0 != 1) goto loc_0216A1B8;
loc_0216A19C:
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_02027A04((const u8 *)a0);
loc_0216A1A4:
t4 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t5)->f18;
a0 = ((struct Obj00029 *)a0)->f40;
    a0 = func_02027858(a0);
loc_0216A1AE:
a0 = 1;
    if (t4 != 0) goto loc_0216A1BC;
loc_0216A1B4:
a0 = 0;
    return a0;
loc_0216A1B8:
a0 = 0;
a0 = ~a0;
loc_0216A1BC:
    return a0;}


int func_0216A1C0(int a0)
{
    int a1;
    void *v0;
    void *v1;

a0 = ((struct Obj17751 *)a0)->f8;
    v0 = func_02188CB4((void *)a0);
loc_0216A1C8:
    a0 = func_021A3208(v0);
loc_0216A1CE:
    if (a0 != 1) goto loc_0216A1F6;
loc_0216A1D2:
    v1 = func_021A3074(v0);
loc_0216A1D8:
a1 = 0x20;
    a0 = func_021A2F48(v0, a1);
loc_0216A1E2:
    a0 = (int)func_0216DB04(v1);
loc_0216A1E8:
a1 = 0x10;
    a0 = (int)func_0216D550(v1, a1);
loc_0216A1F0:
    a0 = func_021A2F54(v0);
loc_0216A1F6:
    return a0;}


void func_0216A1F8(int a0)
{
    int a1;
    void *v0;

a0 = ((struct Obj17752 *)a0)->f8;
    v0 = func_02188CB4((void *)a0);
loc_0216A200:
    a0 = func_021A3208(v0);
loc_0216A206:
    if (a0 != 1) goto loc_0216A218;
loc_0216A20A:
a1 = 8;
    a0 = func_021A2F48(v0, a1);
loc_0216A212:
    a0 = func_021A2F54(v0);
loc_0216A218:
    return;}


int func_0216A21C(int a0)
{    void *v0;

a0 = ((struct Obj17753 *)a0)->f8;
    v0 = func_02188CB4((void *)a0);
loc_0216A224:
    a0 = func_021A3208(v0);
loc_0216A22A:
    if (a0 != 0) goto loc_0216A232;
loc_0216A22E:
a0 = 1;
    return a0;
loc_0216A232:
    a0 = func_021A2F54(v0);
loc_0216A238:
    if (a0 != 1) goto loc_0216A240;
loc_0216A23C:
a0 = 1;
    return a0;
loc_0216A240:
a0 = 0;
    return a0;}


/*
 * unblocked: func_021A3244 (ov021 tail-call thunk) matched bottom-up and
 *   filed as pkt_021A3244; the `ov021` token resolves its call as
 *   `matched, overlay`.  Extent runs 32 against 30 compiled: the unlabelled
 *   follower.
 *
 * The overlay's own status call takes the arm9 handle; anything but one
 * reads as failure.
 */
int func_0216A244(void *a0)
{
    void *v = func_02188CB4(((struct Obj17754 *)a0)->f8);

    if (func_021A3208(v) == 1)
        return func_021A3244(v);

    return 1;
}


int func_0216A264(int a0)
{
    int a1;
    int t4;
    void *p;

t4 = a0 + 0;
a0 = ((struct Obj00029 *)t4)->f10;
a1 = *(int *)&((struct Obj00029 *)t4)->f8;
    p = func_021D1164(a0, a1);
loc_0216A270:
a1 = *(int *)&((struct Obj00029 *)t4)->f18;
((struct Obj17755 *)a1)->f48 = p;
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
p = ((struct Obj00029 *)a0)->f48;
    a0 = func_021D11B0(p, a1);
loc_0216A27C:
    return a0;}


int func_0216A280(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)a0)->f48;
    a0 = func_021D11D8(a0);
loc_0216A28C:
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)a0)->f48;
    a0 = func_021D1194(a0);
loc_0216A294:
    return a0;}


void func_0216A298(void *a, void *list)
{
    int i;
    int n;
    void *e;
    int x;
    int y;

    n = func_0201AA18(list);
    for (i = 0; i < n; i++) {
        e = func_0201AB28(list, i);
        x = func_02017E1C(e, 5, 0);
        y = func_02017E1C(e, 0x6f, 0);
        if (x == 0x1ec && y == 1)
            func_02017988(e, 0);
    }
}
