/*
 * file:     event_field_proclink_p01.c
 * unit:     yes
 * function: func_0215EC54, func_0215EC6C, func_0215EC80, func_0215EC94, func_0215ECBC, func_0215ED8C, func_0215EDA0, func_0215EDD0
 * address:  0x0215EC54
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
 *   func_02165534  0x02165534  thumb  ov010
 *   func_021C8268  0x021C8268  thumb
 *   func_0215F104 0x0215F104 thumb ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0215F0E8 0x0215F0E8 thumb ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A10  0x02189A10  thumb  ov021
 *   func_021C7FBC  0x021C7FBC  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02014468  0x02014468  thumb
 *   func_02014464  0x02014464  thumb
 *   func_021C7E50  0x021C7E50  thumb  ov021
 *   func_02014470  0x02014470  thumb
 *   func_0201446C  0x0201446C  thumb
 *   func_021C7E54  0x021C7E54  thumb  ov021
 *   func_02184EEC  0x02184EEC  thumb  ov020
 *   func_0201235C  0x0201235C  thumb
 */
#include "../../matched/include/Obj12043.h"
#include "../../matched/include/Obj17699.h"
#include "../../matched/include/Obj02057.h"

struct Arg;
struct Desc;
struct Obj;
struct Pair;
struct BigObj;
struct Ctx;
struct Sub02014444Obj;
struct C;
struct S0201235C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { B_FALSE, B_TRUE } Bool_0215EC54;

typedef struct Arg {
    u8 pad00[8];
    void *f08;          /* 0x08 */
    u16 f0c;            /* 0x0C */
} Arg;

typedef enum { FALSE, TRUE } Bool_0215ECBC;

struct C {
    u8 pad00[8];
    void *f8;
    u16 fc;
};

extern int func_02165534();
extern int func_021C8268();
extern int func_0215F104(int a0, int a1);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0215F0E8(u32 *out, const struct Pair *in, u32 *ctx);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012B38(const struct BigObj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02189A10(struct Obj *p);
extern void *func_021C7FBC(void **p);
extern u16 func_02188C84(u8 *p);
extern void *func_02158780(void *a, u32 id, u32 b, u32 c, u32 d);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern u8 func_02014468(struct Sub02014444Obj *o);
extern void func_02014464(struct Sub02014444Obj *o, u8 v);
extern void func_021C7E50(u8 *p, u16 v);
extern u16 func_02014470(struct Sub02014444Obj *o);
extern void func_0201446C(void *p, u32 v);
extern u16 func_021C7E54(struct Obj *p);
extern void *func_02184EEC(void *p);
extern void func_0201235C(struct S0201235C *o, u32 *out);
int func_0215EDD0(void *a, int *st, struct C *c);
int func_0215EC54(int a0, int a1, int a2);
int func_0215EC6C(void *p);
int func_0215EC80(void *p);
void *func_0215EC94(void *a, void *b);
/* * Three-state sequence step: state 0 opens message 0x2718, state 1 waits * for an object to go idle then starts sound 0x94, state 2 waits for a * status of 3. Returns 1 when finished. */ int func_0215ECBC(void *a0, int *state, Arg *arg);
int func_0215ED8C(void *p);
void *func_0215EDA0(void *p, void *ctx);



int func_0215EC54(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
a0 = 0x13;
    a0 = func_02165534(a0);
loc_0215EC60:
a0 = ((struct Obj12043 *)t4)->f8;
a1 = ((struct Obj12043 *)t4)->f10;
a2 = ((struct Obj17699 *)t5)->f4;
    a0 = func_021C8268(a0, a1, a2);
loc_0215EC6A:
    return a0;}


int func_0215EC6C(void *p)
{
    return func_0215F104((int)p, 4) != 0 ? B_FALSE : B_TRUE;
}


int func_0215EC80(void *p)
{
    return func_0215F104((int)p, 5) != 0 ? B_FALSE : B_TRUE;
}


void *func_0215EC94(void *a, void *b)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)b)->f8, 0, (void *)func_0215ECBC, 20);
    func_0215F0E8(func_020124E8(task), a, b);
    return task;
}



/*
 * Three-state sequence step: state 0 opens message 0x2718, state 1 waits
 * for an object to go idle then starts sound 0x94, state 2 waits for a
 * status of 3. Returns 1 when finished.
 */
int func_0215ECBC(void *a0, int *state, Arg *arg)
{
    void *obj;
    void *obj2;
    void *ctl;
    u32 d;
    void *msg;
    void *o;
    u16 id;

    obj = func_020120F4(arg->f08);
    func_0201296C(obj);
    obj2 = func_02012B38(obj);
    ctl = func_021C7FBC(func_02189A10(func_0201210C(arg->f08)));
    d = func_02188C84(func_0201210C(arg->f08));

    switch (*state) {
    case 0:
        id = arg->f0c;
        msg = func_02158780(a0, 0x2718, 0, 0, d);
        func_02159058((int)msg, id, 0, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_02014468(obj2) == 0) {
            o = func_02012B38(obj);
            func_02014464(obj2, 1);
            func_02165534((void *)0x94);
            func_021C7E50(ctl, 1);
            func_0201446C(o, (func_02014470(o) & ~1) | 2);
        } else {
            return 1;
        }
        (*state)++;
        break;
    case 2:
        if (func_021C7E54(ctl) == 3) {
            return 1;
        }
        break;
    }
    return 0;
}


int func_0215ED8C(void *p)
{
    return func_0215F104((int)p, 7) != 0 ? FALSE : TRUE;
}


void *func_0215EDA0(void *p, void *ctx)
{
    void *task;
    func_02165534((void *)91);
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EDD0, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}



int func_0215EDD0(void *a, int *st, struct C *c)
{
    u32 h;
    void *t;

    switch (*st) {
    case 0:
        h = c->fc;
        t = (void *)func_02158780(a, 0x271a, 0, 0, 0x15);
        func_02159058((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_0201235C(a, func_02184EEC(c->f8));
        break;
    }
    return 0;
}
