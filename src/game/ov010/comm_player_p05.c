/*
 * file:     comm_player_p05.c
 * unit:     yes
 * function: func_02167A14, func_02167A54, func_02167A74, func_02167AB0, func_02167AC4, func_02167B00, func_02167B18, func_02167B24, func_02167B34, func_02167B44, func_02167B9C, func_02167BB4
 * address:  0x02167A14
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
 *   func_02034714  0x02034714  arm
 *   func_021943EC  0x021943EC  thumb  ov021
 *   d_02172A28     0x02172A28  data
 *   func_0201210C  0x0201210C  thumb
 *   func_02188BE8  0x02188BE8  thumb
 *   func_02188C7C  0x02188C7C  thumb
 *   func_02194284  0x02194284  thumb
 *   func_0203CBAC  0x0203CBAC  arm
 *   d_02172014  0x02172014  data  ov010
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02087C6C 0x02087C6C arm
 *   func_0203A574 0x0203A574 arm
 *   d_02171FD4 0x02171FD4 data ov010 a4
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D594  0x0203D594  arm
 *   func_0203D5A0  0x0203D5A0  arm
 *   func_021CA210  0x021CA210  thumb  ov021
 *   func_02008550  0x02008550  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021CA234  0x021CA234  thumb  ov021
 *   func_021CA2CC  0x021CA2CC  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 */
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj19012.h"
#include "../../matched/include/Obj19013.h"

struct Tbl;
struct Ctx;
struct Req;
struct Entry;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct Blk12 {
    u64 lo;
    u32 hi;
} Blk12;

typedef struct Ent {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent;

typedef struct Work {
    void *sys;
    void *obj;
    Ent e[4];
} Work;

typedef struct {
    unsigned char b0 : 1;
} Flag;

typedef struct Obj_02167B44 {
    u8 pad00[0x1E];
    u8 b1e[2];
    u8 pad20[0x668 - 0x20];
    u16 h668;
    u16 h66a[2];
    u16 h66e;
} Obj_02167B44;

typedef struct Obj_02167B9C {
    u8 pad00[0x32];
    u8 b32[0x668 - 0x32];
    u8 b668[0x1C];
} Obj_02167B9C;

typedef struct Obj_02167BB4 {
    u8 pad00[0x0C];
    u16 h0c_b0 : 3;
    u16 b3 : 1;
    u16 h0c_rest : 12;
    u8 pad0e[0x668 - 0x0E];
    u16 h668;
} Obj_02167BB4;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_021943EC(struct Tbl *t, u32 key);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188BE8(void *a);
extern void *func_02188C7C(unsigned char *p);
extern void *func_02194284(int a, void *b, int heap, int c);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *, void *);
extern void func_02087C6C(void *);
extern void func_0203A574(u32, u32, u32, u32);
void func_0203A5E4(u32 key);
extern struct Entry *func_020399A8(void);
extern int func_0203D594();
extern int func_0203D5A0();
extern void *func_021CA210(u8 *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u16 func_021CA234(u8 *p);
extern u16 func_021CA2CC(u16 v);
extern void func_02082D44(void *dst, void *src, int n);
u32 func_02167A14(Work *w, int i);
int func_02167A54(int *p, int i);
void func_02167A74(int a0, int a1);
void func_02167AB0(void *p);
void *func_02167AC4(u8 *p);
int func_02167AF0(void);
int func_02167AF4(int a, int b);
void func_02167B00(u32 a);
void func_02167B18(void *p);
int func_02167B24(int a0);
int func_02167B34(int a0);
void func_02167B44(Obj_02167B44 *o, void *a1);
void func_02167B9C(Obj_02167B9C *o);
void func_02167BB4(Obj_02167BB4 *o, u16 v);
extern u8 d_02172A28[];
extern u8 d_02172014[];
extern const u32 d_02171FD4[];


u32 func_02167A14(Work *w, int i)
{
    if (w->obj == 0)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    if (w->e[i].used != 1)
        func_02034714((const char *)d_02172A28, 0, (const char *)d_02172A28);
    return func_021943EC(w->obj, i);
}


/*
 * Unlabelled leaf (sole blocker of ov018 func_0217FCAC).
 */
int func_02167A54(int *p, int i)
{
    if (p == 0 || p[1] == 0 || !((Flag *)((char *)p + i * 0x1c + 0x1c))->b0) {
        return 0;
    }
    return 1;
}


void func_02167A74(int a0, int a1)
{
    int a2;
    int a3;
    int t4;
    void *res;
    void *v0;
    void *v1;

t4 = a1 + 0;
a1 = *(int *)&((struct Obj00020 *)t4)->f4;
    if (a1 != 0) goto loc_02167AAE;
loc_02167A7E:
    v0 = func_0201210C((void *)a0);
loc_02167A82:
    if (v0 == 0) goto loc_02167AAE;
loc_02167A86:
    a0 = func_02188BE8(v0);
loc_02167A8A:
    if (a0 == 0) goto loc_02167AAE;
loc_02167A8E:
    v1 = func_02188C7C(v0);
loc_02167A94:
a0 = t4 + 0;
a2 = t4 + 0;
a3 = t4 + 0;
a0 = a0 + 0x8e;
a2 = a2 + 0x8c;
a3 = a3 + 0x90;
a0 = *(u8 *)&((struct Obj00020 *)((char *)a0))->f0;
a2 = *(u16 *)&((struct Obj00020 *)((char *)a2))->f0;
a3 = *(u8 *)&((struct Obj00020 *)((char *)a3))->f0;
    res = func_02194284(a0, v1, a2, a3);
loc_02167AAC:
((struct Obj00020 *)t4)->f4 = res;
loc_02167AAE:
    return;}


/*
 * Tail call to ARM func_0203CBAC with (&d_02172014, 0, arg). No lr-saving
 * prologue; bl from ov021 func_021CA5C4 at 0x021CB4F4.
 */
void func_02167AB0(void *p)
{
    func_0203CBAC((struct Req *)d_02172014, 0, (u32)p);
}

/*
 * Trailing unlabelled constant getter and equality predicate are included.
 */
void *func_02167AC4(u8 *p)
{
    u8 *q;
    q = p + 0x6f4;
    func_02008494(func_02012944(((struct Obj19012 *)p)->f6C), q);
    func_02087C6C(q + 0x20);
    ((struct Obj19013 *)q)->f26 = 0x3a0b;
    return q;
}

int func_02167AF0(void)
{
    return 0x28;
}

int func_02167AF4(int a, int b)
{
    if (a == b) return 1;
    return 0;
}

/*
 * Trailing extent is already matched func_02167B18.
 */
void func_02167B00(u32 a)
{
    func_0203A574(0x2c00, (u32)d_02171FD4, 0x2c08, a);
}


/*
 * Unlabelled leaf, blocker of ov021 func_021CB8AC: tail call of func_0203A5E4(0x2C00); the argument is ignored.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void func_02167B18(void *p)
{
    func_0203A5E4(0x2c00);
}


int func_02167B24(int a0)
{
    int a1;
    int t4;
    struct Entry *e;

t4 = a0 + 0;
    e = func_020399A8();
loc_02167B2C:
a1 = t4 + 0;
    a0 = func_0203D594(e, a1);
loc_02167B32:
    return a0;}


int func_02167B34(int a0)
{
    int a1;
    int t4;
    struct Entry *e;

t4 = a0 + 0;
    e = func_020399A8();
loc_02167B3C:
a1 = t4 + 0;
    a0 = func_0203D5A0(e, a1);
loc_02167B42:
    return a0;}


void func_02167B44(Obj_02167B44 *o, void *a1)
{
    void *t;
    void *list;
    int i;

    t = func_02012944(a1);
    list = func_021CA210((u8 *)o);
    o->h668 = func_02008550(t);
    for (i = 0; i < 2; i++)
        o->h66a[i] = func_02017E1C(func_0201AB28(list, o->b1e[i]), 5, 0);
    o->h66e = func_021CA2CC(func_021CA234((u8 *)o));
}


/*
 * Unlabelled Thumb leaf hidden in a word run (no lr saved); callee of ov010 func_02167BFC.
 */
void func_02167B9C(Obj_02167B9C *o)
{
    func_02082D44(o->b32, o->b668, 0x1C);
}


void func_02167BB4(Obj_02167BB4 *o, u16 v)
{
    o->b3 = v;
    o->h668 = v;
}
