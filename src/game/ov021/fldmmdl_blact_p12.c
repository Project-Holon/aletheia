/*
 * file:     fldmmdl_blact_p12.c
 * unit:     yes
 * function: func_0219EAD8, func_0219EAEC, func_0219EB18, func_0219EB4C, func_0219EB90, func_0219EBA0, func_0219EBF4, func_0219ED7C, func_0219ED8C
 * address:  0x0219EAD8
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
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0219E968  0x0219E968  thumb  ov021
 *   func_0219EA10  0x0219EA10  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   d_021D84AC     0x021D84AC  data
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0219EA24  0x0219EA24  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0219EA78  0x0219EA78  thumb  ov021
 *   func_0219EA94  0x0219EA94  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0219E418  0x0219E418  thumb  ov021
 *   func_0219E664  0x0219E664  thumb  ov021
 *   func_0219E9A8  0x0219E9A8  thumb  ov021
 *   func_0216DA44  0x0216DA44  thumb  ov010
 */
#include "../../matched/include/Obj07482.h"
#include "../../matched/include/Obj12689.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef struct {
    u16 x, y, w, h;
} Rect;

typedef struct {
    u32 head;
    Rect r;
} Obj;

typedef struct {
    u8  pad[0xc];
    s16 cnt;
    u16 val;
} E_0219EB4C;

typedef signed char    s8;

typedef struct {
    u8 pad[0xc];
    u8 lo : 4;
    u8 hi : 4;
    u8 z;
    u8 c;
    u8 d;
} E_0219EBA0;

typedef struct {
    u16 a;
    u16 pad;
    s16 c;
    u16 d;
} S;

typedef signed int     s32;

typedef struct {
    u8  pad[0xc];
    u8  state : 4;
    u8  hi : 4;
    s8  cnt;
    s8  e;
    u8  f;
} E;

typedef struct {
    u16 f0;
    u16 f2;
    s16 f4;
    u16 f6;
} Pos;

extern void func_021B7EE4(void *p, void *r);
extern void func_021B8028(void *p, void *out);
extern void func_0216D89C(u32, void *);
extern void *func_0219E968(u32 a, u32 size);
extern int func_0219EA10(u32 *a, int b);
extern void func_0216D674(void *p, u16 v);
extern void func_0216DA50(u8 *p);
extern void *func_0216D69C(void *p);
extern u32 func_0219EA24(u32 a, u32 b);
extern void func_0216D5E0(int a0, int a1);
extern int func_0219EA78();
extern u32 func_0219EA94(u32 a, u32 *b);
extern void func_0219E2F4(void *o, void *out);
extern void func_0216DA7C(u8 *p);
extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
extern u32 func_02197EDC(u8 *p);
extern void func_0216D60C(u32, u16);
extern int func_0219E418(u32, u16);
extern int func_0219E664(void *o, u32 k, void *buf);
extern int func_0219E9A8(u32, u32, s32, u16 *);
extern void func_0216DA44(u32);
void func_0219EAD8(Obj *p, const Rect *s);
void func_0219EAEC(u8 *p, u32 a);
void func_0219EB18(u32 a, u16 b);
int func_0219EB4C(u32 o);
int func_0219EB90(u32 *a);
void func_0219EBA0(u32 o, u32 k);
int func_0219EBF4(u32 o);
int func_0219ED7C(u32 *a);
void func_0219ED8C(u32 a);
extern u32 d_021D84AC[];




/*
 * The source pointer is const: that lets mwcc load s->h above the store of w.
 *
 * Addresses are Black-image addresses.
 */
void func_0219EAD8(Obj *p, const Rect *s)
{
    p->r = *s;
}




/*
 * Addresses are Black-image addresses.
 */
void func_0219EAEC(u8 *p, u32 a)
{
    u8 buf[12];
    if (p[6] != 2) {
        func_021B7EE4(((struct Obj07482 *)p)->f0, p + 4);
        func_021B8028(((struct Obj07482 *)p)->f0, buf);
        func_0216D89C(a, buf);
    }
}




void func_0219EB18(u32 a, u16 b)
{
    u8 *q = func_0219E968(a, 16);
    ((struct Obj12689 *)q)->fC = func_0219EA10(d_021D84AC, -1);
    ((struct Obj12689 *)q)->fE = b;
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
}




int func_0219EB4C(u32 o)
{
    E_0219EB4C *e;

    e = func_0216D69C((void *)o);
    e->cnt = e->cnt - 1;
    if (e->cnt <= 0) {
        e->cnt = func_0219EA10((u32 *)d_021D84AC, -1);
        func_0216D5E0((u32)o, (u16)func_0219EA24(e->val, 9));
    }
    return func_0219EA78(e, o);
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219EB90(u32 *a)
{
return func_0219EA94((u32)func_0216D69C((void *)a), a);
}




void func_0219EBA0(u32 o, u32 k)
{
    E_0219EBA0 *e;
    S s;

    e = func_0219E968(o, 0x10);
    func_0219E2F4((void *)o, &s);
    e->lo = 0;
    e->z = 0;
    e->hi = k;
    e->d = s.d;
    e->c = s.c;
    func_0216D674((void *)o, 0);
    func_0216DA50((u8 *)o);
}



int func_0219EBF4(u32 o)
{
    E *e;
    u32 k;
    u16 a[4];
    u16 b[4];

    e = func_0216D69C((void *)o);
    switch (e->state) {
    case 0:
        func_0216DA50((u8 *)o);
        func_0216DA7C((u8 *)o);
        func_0216D438((char *)o, (u16)((u32)func_02197E7C((u16)((u32)func_0216D5F8((void *)o)), (u32)0)));
        e->state++;
        break;
    case 1:
        if (!func_02197EDC((u8 *)o)) {
            break;
        }
        e->cnt = func_0219EA10((u32 *)d_021D84AC, -1);
        e->state++;
    case 2:
        e->cnt--;
        if (e->cnt != 0) {
            break;
        }
        e->state++;
    case 3:
        k = func_0219EA24(e->hi, 9);
        func_0216D60C(o, k);
        if (func_0219E418(o, k)) {
            e->state = 0;
            break;
        }
        func_0219E2F4((void *)o, a);
        func_0219E664((void *)o, (u16)k, b);
        if (a[0] != b[0]) {
            e->state = 0;
            break;
        }
        if (func_0219E9A8(o, e->f, e->e, b)) {
            e->state = 0;
            break;
        }
        func_0216D438((char *)o, (u16)((u32)func_02197E7C((u16)k, (u32)0xc)));
        func_0216DA44(o);
        e->state++;
    case 4:
        if (func_02197EDC((u8 *)o)) {
            func_0216DA50((u8 *)o);
            e->state = 0;
        }
        break;
    }
    return func_0219EA78(e, o);
}



int func_0219ED7C(u32 *a)
{
return func_0219EA94((u32)func_0216D69C((void *)a), a);
}



void func_0219ED8C(u32 a)
{
    u8 *q = func_0219E968(a, 16);
    Pos pos;
    func_0219E2F4((void *)a, &pos);
    q[0xc] = 0;
    q[0xd] = 0;
    q[0xf] = pos.f6;
    q[0xe] = pos.f4;
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
}
