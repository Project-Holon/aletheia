/*
 * file:     union_comm_p15.c
 * unit:     yes
 * function: func_02173F20, func_02173F54, func_02173F90, func_02173FE0, func_02174010, func_0217403C, func_02174084, func_021740D4, func_0217410C, func_0217413C, func_0217416C
 * address:  0x02173F20
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D4D0 0x0203D4D0 arm
 *   func_021840A8 0x021840A8 thumb ov022
 *   func_02034714 0x02034714 arm
 *   func_02183FB8 0x02183FB8 thumb ov022
 *   func_02183FA8 0x02183FA8 thumb ov022
 *   d_02175624 0x02175624 data a1
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02184060  0x02184060  thumb  ov022
 *   func_021840A4 0x021840A4 thumb ov022
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_02012374  0x02012374  thumb
 *   d_0217549C     0x0217549C  data   ov012  a1
 *   d_02175498     0x02175498  data   ov012  a4
 *   d_0217549D     0x0217549D  data   ov012  a1
 */
#include "../../matched/include/Obj09364.h"
#include "../../matched/include/Obj12449.h"
#include "../../matched/include/Obj09365.h"
#include "../../matched/include/Obj12450.h"
#include "../../matched/include/Obj19269.h"

struct Entry;
struct Link;
struct Desc;
struct Obj;
struct Evt;
typedef unsigned int u32;

typedef unsigned char u8;

typedef struct { int w[8]; } B32;

typedef struct { B32 a; unsigned char t[8]; } Msg;

typedef struct { int f0; int f4; u8 *f8; } Work;

typedef struct { int f0; int f4; int f8; u8 fc; } R;

typedef int (*Fn)(int, u8 *, int, int, int, int *, u8 *);

extern struct Entry *func_020399A8(void);
extern u32 func_0203D4D0(u32, u32, u32, u32, u32, u32, u32, u32);
extern u32 func_021840A8(u32);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02183FB8(int, void *, u8, int);
extern void func_02183FA8(u8 *p, u8 index);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02087C6C(void *p);
extern unsigned int func_0203D1A4(struct Link *p);
extern void func_02184060(u8 *s, int i);
extern void func_021840A4(int, u8);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0217F074(void *p);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern void func_02012374(struct Evt *evt, struct Evt **out);
u32 func_02173F20(void *p, u32 a);
void func_02173F54(int a, int x, int y, u8 *p);
void func_02173F90(int a, B32 *src);
void func_02173FE0(int a, int x, int y, u8 *p);
u32 func_02174010(u32 a, void *p);
void func_0217403C(int a, int x, int y, u8 *p);
void func_02174084(int a, B32 *src);
void func_021740D4(int a, int x, u8 *b, u8 *p);
void func_0217410C(u32 a, u8 b);
int func_0217413C(int a, int b, u8 *p);
int func_0217416C(int a, int *b, int *c);
extern u8 d_02175624[];
extern u8 d_0217549C[];
extern u8 d_0217549D[];
extern u8 d_02175498[];

u32 func_02173F20(void *p, u32 a)
{
    u32 entry;
    u32 size;
    entry = (u32)func_020399A8();
    size = func_021840A8(entry);
    return func_0203D4D0(entry, a, 0x1410, size, (u32)p, 1, 0, 0);
}

void func_02173F54(int a, int x, int y, u8 *p)
{
    if (((struct Obj09364 *)p)->f3528 == 0) {
        func_02034714((const char *)d_02175624, 0, (const char *)d_02175624);
        return;
    }
    func_02183FB8(((struct Obj09364 *)p)->f3528, p, a, y);
    func_02183FA8((u8 *)(((struct Obj09364 *)p)->f3528), a);
}


void func_02173F90(int a, B32 *src)
{
    Msg m;

    func_02082BCC(&m, 0, 0x28);
    m.a = *src;
    func_02087C6C(m.t);
    func_0203D4D0((int)func_020399A8(), a, 0x1411, 0x28, (u32)(&m), 1, 0, 0);
}

void func_02173FE0(int a, int x, int y, u8 *p)
{
    if (((struct Obj12449 *)p)->f3528 == 0) {
        func_02034714((const char *)d_02175624, 0, (const char *)d_02175624);
        return;
    }
    func_02183FB8(((struct Obj12449 *)p)->f3528, p, a, y);
}

u32 func_02174010(u32 a, void *p)
{
    return func_0203D4D0((u32)func_020399A8(), a, 0x1412, 0x28, (u32)p, 1, 0, 0);
}


void func_0217403C(int a, int x, int y, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)func_020399A8())) {
        if (((struct Obj09365 *)p)->f3528 == 0) {
            func_02034714((void *)0x02175624, 0, (void *)0x02175624);
            return;
        }
        func_02183FB8(((struct Obj09365 *)p)->f3528, p, (u8)a, y);
        func_02184060((u8 *)(((struct Obj09365 *)p)->f3528), (u8)a);
    }
}


void func_02174084(int a, B32 *src)
{
    Msg m;

    func_02082BCC(&m, 0, 0x28);
    m.a = *src;
    func_02087C6C(m.t);
    func_0203D4D0((int)func_020399A8(), a, 0x1413, 0x28, (u32)(&m), 1, 0, 0);
}

/*
 * Extent follower 0217410C is this lane's corrected-entry file, kept separate.
 * func_021840A4 receives both original loaded arguments despite its empty body.
 */
void func_021740D4(int a, int x, u8 *b, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)((int)func_020399A8()))) {
        if (((struct Obj12450 *)p)->f3528 == 0) {
            func_02034714((const char *)d_02175624, 0, (const char *)d_02175624);
            return;
        }
        func_021840A4(((struct Obj12450 *)p)->f3528, *b);
    }
}

void func_0217410C(u32 a, u8 b)
{
    func_0203D4D0((u32)func_020399A8(), a, 0x1414, 1, (u32)&b, 1, 0, 0);
}

int func_0217413C(int a, int b, u8 *p)
{
    int task;
    Work *w;
    task = (int)func_020122C0((void *)a, 0, (void *)((int)func_0217416C), 12);
    w = func_020124E8((struct Obj *)task);
    w->f0 = a;
    w->f4 = b;
    w->f8 = p;
    ((struct Obj19269 *)p)->f3548 = 1;
    return task;
}


/*
 * func_021734A8 is a 3-argument field setter (case 4 is strb r2): the table
 * key loads straight into r2 because it is the third argument.
 */
int func_0217416C(int a, int *b, int *c)
{
    int first;
    u8 *base;
    R *r4;
    int loc;
    int k;

    first = c[0];
    base = (u8 *)c[2];
    r4 = (R *)(base + 0x3548);
    loc = 0;
    switch (*b) {
    case 0:
        func_0217F074(base);
        k = d_0217549C[r4->f4 * 8];
        if (k != 0x1b) {
            func_021734A8(base, 4, k);
        }
        (*b)++;
    case 1: {
        int r;
        r = (*(Fn *)(d_02175498 + r4->f4 * 8))(first, base, c[1], r4->f8, a, &loc, &r4->fc);
        if (loc != 0) {
            func_02012374((struct Evt *)a, (struct Evt **)loc);
        } else if (r == 1) {
            (*b)++;
        }
        break;
    }
    case 2:
        k = d_0217549D[r4->f4 * 8];
        if (k != 0x1b) {
            func_021734A8(base, 4, k);
        }
        r4->f4 = 0;
        r4->f8 = 0;
        r4->fc = 0;
        r4->f0 = 0;
        return 1;
    }
    return 0;
}
