/*
 * file:     unit_021F2C10.c
 * unit:     yes
 * function: func_021F2C10, func_021F2C78, func_021F2CD4, func_021F2CD8, func_021F2CF4, func_021F2D10, func_021F2D30, func_021F2D50, func_021F2D84, func_021F2DA8, func_021F2DC8, func_021F2E10, func_021F2E5C, func_021F2E68, func_021F2E8C, func_021F2EEC, func_021F2F60, func_021F3098, func_021F30C8, func_021F30EC, func_021F3118, func_021F3144
 * address:  0x021F2C10
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_021F0EB0 0x021F0EB0 thumb ov029
 *   func_021F05B4  0x021F05B4  thumb  ov029
 *   func_021F0F28  0x021F0F28  thumb  ov029
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B918  0x0204B918  arm
 *   func_0202173C  0x0202173C  thumb
 *   d_021F3224     0x021F3224  data  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021F0194  0x021F0194  thumb  ov029
 *   func_0201210C  0x0201210C  thumb
 *   func_021F009C  0x021F009C  thumb  ov029
 *   func_020124AC  0x020124AC  thumb
 *   func_02154668  0x02154668  thumb  ov000
 *   abs_id_0       0x00000000  data
 *   func_021559E4  0x021559E4  thumb  ov010
 *   func_0215FBF4  0x0215FBF4  thumb  ov010
 *   func_02167044  0x02167044  thumb  ov010
 *   func_021945A4  0x021945A4  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02014808  0x02014808  thumb
 *   abs_id_124     0x0000007C  data
 *   d_021D4D40     0x021D4D40  data  ov124  a4
 *   func_021D297C  0x021D297C  thumb  ov021
 *   func_0201235C  0x0201235C  thumb
 *   d_021F3554     0x021F3554  data  a4
 *   func_021F2B9C 0x021F2B9C thumb ov029
 *   func_021EFF58 0x021EFF58 thumb ov029
 *   func_021F2130 0x021F2130 thumb ov029
 *   func_021EFEF8 0x021EFEF8 thumb ov029
 *   func_021F2180 0x021F2180 thumb ov029
 *   func_0203CD98  0x0203CD98  arm
 */
#include "../../matched/include/Obj06130.h"
#include "../../matched/include/Obj09788.h"
#include "../../matched/include/Obj00042.h"
#include "../../matched/include/Obj04309.h"
#include "../../matched/include/Obj20399.h"
#include "../../matched/include/Obj06131.h"

struct Obj;
struct Actor;
struct Desc;
struct Ctx;
struct S0201235C;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
} S;

typedef unsigned short u16;

typedef short s16;

typedef struct {
    char *p;
    int kind;
} Req;

struct Slot { void *object; int a; int b; };

struct Obj { char pad[0x3c]; struct Slot slots[20]; };

extern void func_0204B92C(struct Obj *a, unsigned int b);
extern void func_0204B954(struct Actor *a, u32 v);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021F0EB0(char *p, int flag);
extern int func_021F05B4(unsigned char *p);
extern void func_021F0F28(char *p, int a);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *a, unsigned int b);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B9A0(struct Actor *a);
extern u16 func_0204B918(struct Obj *p);
extern int func_0202173C(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_021F0194(u8 *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021F009C(u8 *p);
extern struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void *func_02154668(void *p);
extern void *func_021559E4(void *a, int b, void *c, int d);
extern struct Desc *func_0215FBF4(int a0, int a1, struct Desc *a2, int a3);
extern void *func_02167044(void *a, void *b);
extern void *func_021945A4(void *a, u32 b, u32 c);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void *func_021D297C(void *a);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern u32 func_021F2B9C(u8 *p, int row, int col);
extern void func_021EFF58(u8 *, int, int);
extern void func_021F2130(char *p);
extern void func_021EFEF8(char *p, void (*f)(void), int line);
extern void func_021F2180(char *p);
extern int func_0203CD98(void);
int func_021F2C10(char *p);
int func_021F2C78(char *p);
void func_021F2CD4(void);
void func_021F2CD8(char *p);
void func_021F2CF4(u8 *p);
void func_021F2D10(u8 *p);
void func_021F2D30(u8 *p);
void func_021F2D50(u8 *p);
void func_021F2D84(u8 *p);
int func_021F2DA8(u8 *p);
void func_021F2DC8(char *p);
void func_021F2E10(char *p, int *q);
void func_021F2E5C(char *p);
void func_021F2E68(char *p, int value);
int func_021F2E8C(char *p);
int func_021F2EEC(char *p, int k);
int func_021F2F60(void *a, int unused, Req *q);
void func_021F3098(u8 *p);
void func_021F30C8(struct Obj *p);
int func_021F30EC(struct Obj *p);
void func_021F3118(void *p);
void func_021F3144(u8 *p, int v);
extern const unsigned int d_021F3224[];
extern u8 abs_id_0[];
extern u8 abs_id_124[];
extern int d_021D4D40;
extern int d_021F3554;


int func_021F2C10(char *p)
{
    switch (((struct Obj06130 *)p)->f455) {
    case 0:
        func_0204B92C((struct Obj *)*(int *)(p + ((struct Obj06130 *)p)->f416 * 4 + 0x12c), 1);
        func_0204B954((struct Actor *)(*(int *)(p + ((struct Obj06130 *)p)->f416 * 4 + 0x12c)), 1 << 13);
        ((struct Obj06130 *)p)->f455 += 1;
        break;
    case 1:
        if (func_0204B98C((struct Actor *)(*(int *)(p + ((struct Obj06130 *)p)->f416 * 4 + 0x12c))) == 0)
            return 1;
        break;
    }
    return 0;
}


int func_021F2C78(char *p)
{
    switch (((struct Obj09788 *)p)->f455) {
    case 0:
        switch (((struct Obj09788 *)p)->f416) {
        case 3:
            func_021F2E68(p + 0x21c, 0x1c0);
            break;
        case 4:
            func_021F2E68(p + 0x21c, 0x200);
            break;
        }
        ((struct Obj09788 *)p)->f455 += 1;
        break;
    case 1:
        if (func_021F2E8C(p + 0x21c) != 0)
            return 1;
        break;
    }
    return 0;
}

/*
 * Unlabelled empty callback (bx lr), printed as a pool word; its only
 * referrer is the pool word in func_021F29D8, which it blocks.
 */
void func_021F2CD4(void)
{
}


void func_021F2CD8(char *p)
{
    if (*(u8 *)(p + 0x45C) == 0) {
        *(u8 *)(p + 0x45C) = 1;
        *(u8 *)(p + 0x45E) = 1;
        *(u8 *)(p + 0x45F) = 0;
    }
}

void func_021F2CF4(u8 *p)
{
    if (p[0x45d] == 0) {
        p[0x45d] = 1;
        p[0x45e] = 1;
        p[0x45f] = 0;
    }
}

void func_021F2D10(u8 *p)
{
    if (p[0x45d] != 0) {
        p[0x45d] = 0;
        p[0x45e] = 1;
        p[0x45f] = 0;
    }
}

void func_021F2D30(u8 *p)
{
    if (p[0x45c] == 1) {
        p[0x45c] = 0;
        p[0x45e] = 1;
        p[0x45f] = 0;
    }
}

void func_021F2D50(u8 *p)
{
    if (p[0x45e] != 0) {
        p[0x45f]++;
        if (p[0x45f] >= 8) {
            func_021F0EB0((char *)p, func_021F2DA8(p));
            p[0x45e] = 0;
        }
    }
}

void func_021F2D84(u8 *p)
{
    if (p[0x45e] != 0) {
        func_021F0EB0((char *)p, func_021F2DA8(p));
        p[0x45e] = 0;
    }
}

int func_021F2DA8(u8 *p)
{
    if (p[0x45c] != 0)
        return 1;
    if (p[0x45d] != 0)
        return 1;
    return 0;
}


void func_021F2DC8(char *p)
{
    if (func_021F2DA8((u8 *)p) == 0 && ((struct Obj00042 *)p)->f465 != 0) {
        ((struct Obj00042 *)p)->f466 += 1;
        if (((struct Obj00042 *)p)->f466 >= 8) {
            if (func_021F05B4((unsigned char *)p) != 0)
                func_021F0F28(p, 1);
            else
                func_021F0F28(p, 0);
            ((struct Obj00042 *)p)->f465 = 0;
        }
    }
}


void func_021F2E10(char *p, int *q)
{
    S s;

    s.a = 0;
    s.b = 0;
    s.c = 0x25;
    s.d = 0;
    s.e = 2;
    q[2] = (int)func_0204B294((void *)((struct Obj04309 *)p)->f34, ((struct Obj04309 *)p)->f2C, ((struct Obj04309 *)p)->f28,
                         ((struct Obj04309 *)p)->f30, &s, 0, ((struct Obj04309 *)p)->fC);
    func_0204B3DC((struct Obj *)q[2], 0);
    q[3] = ((struct Obj04309 *)p)->f210;
    q[4] = ((struct Obj04309 *)p)->f204;
}


void func_021F2E5C(char *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj20399 *)p)->f8));
}

void func_021F2E68(char *p, int value)
{
    func_0204B9A0(*(struct Actor * *)&((struct Obj06131 *)p)->f8);
    func_0204B92C(*(struct Obj * *)&((struct Obj06131 *)p)->f8, 1);
    func_0204B954(*(struct Actor * *)&((struct Obj06131 *)p)->f8, 0x2000);
    ((struct Obj06131 *)p)->f0 = 1;
    ((struct Obj06131 *)p)->f4 = value;
}


int func_021F2E8C(char *p)
{
    if (*(int *)(p + 0) == 0)
        return 1;
    if (func_0204B98C(*(void **)(p + 8)) == 0) {
        *(int *)(p + 0) = 0;
        return 1;
    }
    func_0202173C(*(void **)(p + 0xC), 8, *(int *)(p + 4), -0x78, 0,
                  (u8)d_021F3224[func_0204B918(*(void **)(p + 8))], 0,
                  *(void **)(p + 0x10));
    return 0;
}


int func_021F2EEC(char *p, int k)
{
    int r = (int)func_020122C0((void *)(*(int *)&((struct Obj00042 *)p)->f1C), 0, func_021F2F60, 8);
    int *w = func_020124E8((struct Obj *)r);

    w[0] = (int)p;
    w[1] = k;
    switch (k) {
    case 1:
    case 5:
    case 6:
        func_021F0194((u8 *)w[0]);
        break;
    case 11:
        ((struct Obj00042 *)p)->f416 = 4;
        break;
    case 7:
        ((struct Obj00042 *)p)->f416 = 3;
        break;
    case 12:
        ((struct Obj00042 *)p)->f416 = 8;
        break;
    case 13:
        ((struct Obj00042 *)p)->f416 = 10;
        break;
    }
    return r;
}


int func_021F2F60(void *a, int unused, Req *q)
{
    char *p;
    int h;
    int ok;
    void *x;
    int *buf;

    p = q->p;
    ok = 0;
    h = (int)func_0201210C((const struct Ctx *)(*(int *)(p + 0x1c)));
    switch (q->kind) {
    case 1:
    case 5:
    case 6:
        ok = func_021F009C((u8 *)q->p);
        break;
    case 7:
    case 11:
        ok = func_021F2C78(q->p);
        break;
    case 12:
    case 13:
        ok = func_021F2C10(q->p);
        break;
    }
    if (ok == 0)
        return 0;

    switch (q->kind) {
    case 6:
        x = func_020124AC((void *)(*(int *)(p + 0x1c)), (u32)abs_id_0, (void *)func_02154668, h);
        break;
    case 1:
        x = func_021559E4((void *)(*(int *)(p + 0x1c)), h, 0, 1);
        break;
    case 5:
        x = func_0215FBF4(*(int *)(p + 0x1c), h, 0, 1);
        break;
    case 11:
        x = func_02167044((void *)(*(int *)(p + 0x1c)), (void *)h);
        break;
    case 7:
        x = func_021945A4((void *)(*(int *)(p + 0x1c)), h, 4);
        break;
    case 12:
        buf = func_02030734(4, 8, 1, (const char *)(&d_021F3554), 0x14B7);
        buf[0] = (int)func_02012944(func_020120F4((const struct Ctx *)(*(int *)(p + 0x1c))));
        buf[1] = *(int *)(p + 0x1c);
        x = func_02014808((char *)(*(int *)(p + 0x1c)), h, (int)abs_id_124, (int)(&d_021D4D40), (int)buf, 0, (int)buf);
        break;
    case 13:
        x = func_021D297C((void *)(*(int *)(p + 0x1c)));
        break;
    }
    func_0201235C(a, x);
    return 0;
}

void func_021F3098(u8 *p)
{
    p[0x414] = func_021F2B9C(p, p[0x452], p[0x453]);
    p[0x415] = 0;
    func_021EFF58(p, p[0x452], p[0x453]);
}

/*
 * extent: trailing two-byte zero alignment padding.
 */
void func_021F30C8(struct Obj *p)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (p->slots[i].object) {
            func_0204B3B4(p->slots[i].object);
            p->slots[i].object = 0;
        }
    }
}

int func_021F30EC(struct Obj *p)
{
    int result = 1;
    int i;
    for (i = 0; i < 20; i++) {
        if (p->slots[i].object) {
            if (func_0204B98C(p->slots[i].object)) {
                result = 0;
                break;
            }
        }
    }
    return result;
}

/*
 * interface: caller sets r2=0x1514 despite two-input thunk/leaf; retained
 * in the caller extern to reproduce original argument setup.
 */
void func_021F3118(void *p)
{
    func_021F2130(p);
    if (func_021F30EC(p)) {
        func_021F30C8(p);
        func_021EFEF8(p, (void (*)(void))func_021F2180, 0x1514);
    }
}


void func_021F3144(u8 *p, int v)
{
    if (func_0203CD98() == 0 && p[0x45A] != 0)
        func_021F2CF4(p);
    else
        func_021F2D10(p);
    if (p[0x454] != v) {
        if (v == 0)
            func_021F2CD8((char *)p);
        else
            func_021F2D30(p);
        p[0x454] = v;
    }
}
