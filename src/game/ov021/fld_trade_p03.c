/*
 * file:     fld_trade_p03.c
 * unit:     yes
 * function: func_021CE3E8, func_021CE41C, func_021CE52C, func_021CE5AC, func_021CE6F0, func_021CE70C, func_021CE718, func_021CE724, func_021CE73C, func_021CE760, func_021CE78C, func_021CE7AC, func_021CE81C, func_021CE84C, func_021CE8B0, func_021CE8F4
 * address:  0x021CE3E8
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
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021CE36C  0x021CE36C  thumb  ov021
 *   func_021CEA50  0x021CEA50  thumb  ov021
 *   data_021DB498  0x021DB498  data   ov021
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02190490  0x02190490  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190794  0x02190794  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190758  0x02190758  thumb  ov021
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021CE934  0x021CE934  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   func_021CE984  0x021CE984  thumb  ov021
 *   data_021DB470  0x021DB470  data  a4
 */
#include "../../matched/include/Obj00011.h"
#include "../../matched/include/Obj09217.h"
#include "../../matched/include/Obj03619.h"
#include "../../matched/include/Obj02736.h"

struct Handle;
struct WordSet;
struct Fx;
struct Slot;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u32 w[11];
} Req_021CE3E8;

typedef struct {
    u8 pad0[0x100];
    u32 busy;
    Req_021CE3E8 req;
} Mgr_021CE3E8;

typedef unsigned short u16;

typedef struct {
    u32 h;
    u32 pad4;
    u8  state;
} Sub_021CE3E8;

typedef struct {
    u32 h;
    u32 result;
    u8  state;
} Sub_021CE5AC;

typedef struct {
    u8 state;
    u8 pad1[0x2b];
} Entry;

typedef struct {
    u8 pad0[0x70];
    Entry ent[4];
} Mgr_021CE724;

typedef signed short s16;

typedef signed char s8;

typedef struct { u8 b[6]; } Mac;

typedef signed int s32;

extern u32 func_02190EF0(u32 *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021CE9E4(u32 *p, int n);
extern u32 func_02188C54(u8 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);
extern void func_021CE36C(u8 *p);
extern int func_021CEA50(u8 *p);
extern void func_0203D7BC(u8 a);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
extern int func_02190740(u32 a, u32 b, u32 c, u32 d);
extern int func_02190728(void *a);
extern void func_02190490(u8 *p);
extern int func_0219077C(u8 *p);
extern void func_02190794(struct Slot **p, int x, int y, int w, int h);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);
extern int func_0203EFC8(const void *a, const void *b, int n);
extern void func_021CE934(u8 *p, u8 *e, u8 i);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_021CE984(u32 *p, u32 n);
int func_021CE3E8(Mgr_021CE3E8 *m, Req_021CE3E8 *r);
void func_021CE41C(u32 *p);
int func_021CE52C(u32 *p);
u32 func_021CE5AC(u32 *p);
void func_021CE6F0(u8 *p, u8 i);
void func_021CE70C(u8 *p);
void func_021CE718(u8 *p);
void func_021CE724(u8 *p);
int func_021CE73C(Mgr_021CE724 *m);
u32 func_021CE760(u8 *p);
int func_021CE78C(u32 a);
void func_021CE7AC(u32 *p);
void func_021CE81C(u32 *p);
int func_021CE84C(u32 *p, int n);
void func_021CE8B0(u8 *p, u8 *e, int i);
void func_021CE8F4(u8 *p, u8 *e, int i);
extern u8 data_021DB498[];
extern u8 data_021DB470[];




/*
 * Latches a 0x2C-byte request into the slot at +0x104 when the +0x100 busy flag is clear; returns whether it did.
 *
 * Addresses are Black-image addresses.
 */
int func_021CE3E8(Mgr_021CE3E8 *m, Req_021CE3E8 *r)
{
    if (m->busy == 0) {
        m->req = *r;
        m->busy = 1;
        return 1;
    }
    return 0;
}




/*
 * The 0x104 base kept in r6 comes from w being assigned first; the slot
 * store is spelled through the row pointer ((u8 *)p + i * 0x2c)[0x70] while
 * the test indexes p directly.
 *
 * Addresses are Black-image addresses.
 */
void func_021CE41C(u32 *p)
{
    Sub_021CE3E8 *q;
    u8 *w;
    u32 r;
    u8 i;
    u8 v;

    w = (u8 *)p + 0x104;
    q = (Sub_021CE3E8 *)((u8 *)p + 0x130);
    if (p[0x40] == 0) {
        return;
    }
    if (!func_02190EF0((u32 *)p[5])) {
        return;
    }
    switch (q->state) {
    case 0:
        func_0201F02C((struct WordSet *)p[1], 0, (void *)((int)w));
        func_021CE9E4(p, 10);
        q->state++;
        break;
    case 1:
        q->h = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)p[0]), 0);
        q->state++;
        break;
    case 2:
        r = func_02190C78((struct Handle *)q->h);
        if (r == 2) {
            break;
        }
        v = 4;
        if (r != 0) {
            v = 5;
        }
        for (i = 0; i < 4; i++) {
            if (((u8 *)p)[0x70 + i * 0x2c] == 3) {
                ((u8 *)p + i * 0x2c)[0x70] = v;
                if (v == 4) {
                    ((u8 *)p)[0x521] |= 1 << i;
                } else {
                    ((u8 *)p)[0x522] |= 1 << i;
                }
                break;
            }
        }
        func_021909BC((void *)q->h);
        q->h = 0;
        q->state++;
        break;
    case 3:
        p[0x40] = 0;
        q->state = 0;
        func_021CE36C((u8 *)p);
        if (p[0x40] == 0) {
            if (func_021CE73C((Mgr_021CE724 *)p) > 1 && ((u8 *)p)[0x520] == 1) {
                ((struct Obj00011 *)p)->f574 = 9;
            } else {
                ((struct Obj00011 *)p)->f574 = 8;
            }
        }
        break;
    }
}




/*
 * Addresses are Black-image addresses.
 */
int func_021CE52C(u32 *p)
{
    Sub_021CE3E8 *q;
    u32 r;

    q = (Sub_021CE3E8 *)((u8 *)p + 0x130);
    if (!func_02190EF0((u32 *)p[5])) {
        return 0;
    }
    switch (q->state) {
    case 0:
        func_021CE9E4(p, 0xb);
        q->state++;
        break;
    case 1:
        q->h = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)p[0]), 0);
        q->state++;
        break;
    case 2:
        if (!func_021CEA50((u8 *)p)) {
            r = 1;
        } else {
            r = func_02190C78((struct Handle *)q->h);
            if (r == 2) {
                break;
            }
        }
        func_021909BC((void *)q->h);
        q->h = 0;
        q->state = 0;
        if (r == 0) {
            return 1;
        }
        return 2;
    }
    return 0;
}




/*
 * The extent runs long into the unlabelled leaf func_021CE6F0 (filed on its
 * own). Cases 1 and 3 are identical bodies the compiler tail-merged.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CE5AC(u32 *p)
{
    Sub_021CE5AC *q;
    u32 r;

    q = (Sub_021CE5AC *)((u8 *)p + 0x130);
    if (!func_02190EF0((u32 *)p[5])) {
        return 0;
    }
    switch (q->state) {
    case 0:
        func_021CE9E4(p, *(u16 *)(data_021DB498 + ((u8 *)p)[0x520] * 12 + 2));
        q->state++;
        break;
    case 1:
        q->h = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)p[0]), 0);
        q->state++;
        break;
    case 2:
        r = func_02190C78((struct Handle *)q->h);
        if (r == 2) {
            break;
        }
        func_021909BC((void *)q->h);
        q->h = 0;
        if (r == 1) {
            q->result = 2;
            q->state = 100;
        } else if (func_021CE73C((Mgr_021CE724 *)p) <= 1) {
            func_021CE9E4(p, *(u16 *)(data_021DB498 + ((u8 *)p)[0x520] * 12 + 4));
            q->state = 5;
        } else {
            func_021CE9E4(p, 0xf);
            q->state++;
        }
        break;
    case 3:
        q->h = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)p[0]), 0);
        q->state++;
        break;
    case 4:
        r = func_02190C78((struct Handle *)q->h);
        if (r == 2) {
            break;
        }
        func_021909BC((void *)q->h);
        q->h = 0;
        if (r == 0) {
            func_021CE9E4(p, *(u16 *)(data_021DB498 + ((u8 *)p)[0x520] * 12 + 4));
            q->state++;
        } else {
            q->result = 2;
            q->state = 100;
        }
        break;
    case 5:
        q->state = 0xff;
        q->result = 1;
        break;
    case 100:
        if (func_021CE73C((Mgr_021CE724 *)p) > 1 && ((u8 *)p)[0x520] == 1) {
            ((struct Obj00011 *)p)->f574 = 9;
        } else {
            ((struct Obj00011 *)p)->f574 = 8;
        }
        q->state = 0xff;
        break;
    case 0xff:
        if (q->h) {
            func_021909BC((void *)q->h);
            q->h = 0;
        }
        q->state = 0;
        return q->result;
    }
    return 0;
}




void func_021CE6F0(u8 *p, u8 i)
{
    p[0x578] |= 1 << i;
}




/*
 * Unlabelled leaf (a `.word` run in the listing); filed as the witness for
 * the tail-call stub func_021CF36C in ov021_func_021CF32C.c.
 *
 * Addresses are Black-image addresses.
 */
void func_021CE70C(u8 *p)
{
    p[0x519] = 1;
}


void func_021CE718(u8 *p)
{
    p[0x51A] = 1;
}




/*
 * Unlabelled leaf (a `.word` run in the listing); filed as the witness for
 * the tail-call stub func_021CF2E4 in ov021_func_021CF288.c.
 *
 * Addresses are Black-image addresses.
 */
void func_021CE724(u8 *p)
{
    p[0x576] = 1;
    p[0x577] = 1;
    func_0203D7BC(1);
}




/*
 * Counts the entries among the four 0x2C-byte entries at +0x70 whose state is 4.
 *
 * Addresses are Black-image addresses.
 */
int func_021CE73C(Mgr_021CE724 *m)
{
    int i;
    int n = 0;

    for (i = 0; i < 4; i++) {
        if (m->ent[i].state == 4)
            n++;
    }
    return n;
}




u32 func_021CE760(u8 *p)
{
    u32 mask = 0;
    int i;

    for (i = 0; i < 4; i++) {
        if (p[0x70 + i * 0x2c] == 4) {
            mask |= 1 << i;
        }
    }
    return mask;
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CE78C(u32 a)
{
if (*(u32 *)((u8 *)(a) + ((1 << 8))) == 0) {
    if (func_02190EF0((u32 *)(((struct Obj09217 *)((u8 *)(a)))->f14)) == 1) {
        return 1;
    }
}
return 0;
}




/*
 * Addresses are Black-image addresses.
 */
void func_021CE7AC(u32 *p)
{
    u32 h;
    int k;

    h = func_02188C54((u8 *)p[0]);
    k = 0x10;
    if (((struct Obj03619 *)p)->f51F) {
        k = 0xe;
    }
    p[3] = (u32)func_02190708((struct Fx *)h, p[2], 2, 6, 0x12, k - 6);
    p[4] = (u32)func_02190708((struct Fx *)h, p[2], 2, 1, 0x1c, 2);
    func_02190740(p[4], 0, 0, *(u16 *)(data_021DB498 + ((struct Obj03619 *)p)->f520 * 12));
}




void func_021CE81C(u32 *p)
{
    u32 h = func_02188C54((u8 *)p[0]);

    if (p[4] != 0) {
        func_02190728((void *)p[4]);
        p[4] = 0;
    }
    if (p[3] != 0) {
        func_02190728((void *)p[3]);
        p[3] = 0;
    }
    func_02190490((u8 *)h);
}




int func_021CE84C(u32 *p, int n)
{
    if (p[3] && func_0219077C((u8 *)p[3]) == 1) {
        func_02190794((struct Slot **)p[3], 0, 0x40, 0x90, 0x50);
        func_0201EFA4((struct WordSet *)p[1], 0, ((struct Obj02736 *)p)->f51D - n, 1, 0, 1);
        func_0201F250((struct WordSet *)p[1], (void *)p[10], (void *)p[9]);
        func_02190758(p[3], 0, 0x40, p[10]);
        return 1;
    }
    return 0;
}




void func_021CE8B0(u8 *p, u8 *e, int i)
{
    u8 *t;

    t = p + 0x55a;
    if (func_0203EFC8(e + 0x23, t + i * 6, 6)) {
        func_021CE934(p, e, i);
        func_02082D44(e + 0x23, t + i * 6, 6);
    }
}




void func_021CE8F4(u8 *p, u8 *e, int i)
{
    if (func_0203EFC8(p + 0x55a + i * 6, data_021DB470, 6)) {
        func_021CE984((u32 *)p, i);
        func_02082D44(data_021DB470, ((Mac *)(p + 0x55a))[i].b, 6);
    }
}
