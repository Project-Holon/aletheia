/*
 * file:     event_field_proclink_p07.c
 * unit:     yes
 * function: func_021611E0, func_02161214, func_02161280, func_02161308, func_02161350, func_02161378, func_021613A4
 * address:  0x021611E0
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012134  0x02012134  thumb
 *   func_02029DD8  0x02029DD8  thumb
 *   func_02030734  0x02030734  arm
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020128B8  0x020128B8  thumb
 *   d_02172978     0x02172978  data  a1
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_021616A4   0x021616A4  thumb  ov010
 *   func_02188C54   0x02188C54  thumb
 *   func_02012374   0x02012374  thumb
 */
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj18932.h"
#include "../../matched/include/Obj12327.h"
#include "../../matched/include/Obj09158.h"
#include "../../matched/include/Obj09159.h"
#include "../../matched/include/Obj18938.h"

struct Ctx;
struct BigObj;
struct Rec1C;
struct Rec44;
struct SaveBlock;
struct Big;
struct Sub02008700Obj;
struct Evt;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct Rec {
    u32 f00;            /* 0x00 */
    u32 f04;            /* 0x04 */
    u16 f08;            /* 0x08 */
    s16 f0A;            /* 0x0A */
    u32 f0C;            /* 0x0C */
    u32 f10;            /* 0x10 */
    u32 f14;            /* 0x14 */
} Rec;

typedef struct Sub {
    void *f00;          /* 0x00 */
    u32 f04;
    u32 f08;
    u32 f0C;            /* 0x0C */
} Sub;

typedef struct Work {
    u8 pad00[0x18];
    Sub *f18;           /* 0x18 */
} Work;

typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[0x18]; int f28; u8 pad2C[4]; u32 f30; u32 f34; u32 f38; u32 f3C; } Sub_02161280;

typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[8]; Sub_02161280 *f18; } Work_02161280;

typedef struct { u8 pad00[4]; int f04; u16 f08; u8 pad0A[2]; u32 f0C; u32 f10; } Evt_02161280;

typedef struct { u8 pad00[0xc]; int f0C; } Sub_021613A4;

typedef struct { u8 pad00[0xc]; int f0C; u8 pad10[8]; Sub_021613A4 *f18; } Work_021613A4;

typedef struct { u8 pad00[4]; int f04; } Evt_021613A4;

extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern int func_02012134();
extern int func_02029DD8(int a0, int a1);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern struct Rec1C *func_020128B8(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void *func_021616A4(void *p, int a1, int a2, int a3, int a4);
extern void *func_02188C54(void *);
extern void func_02012374(struct Evt *evt, struct Evt **out);
int func_021611E0(int a0, int a1);
Rec *func_02161214(Work *w);
int func_02161280(Work_02161280 *w, Evt_02161280 *e);
u32 *func_02161308(char *c);
int func_02161340(int a0, int *a1);
void func_02161350(void *a0);
u32 *func_02161378(char *c);
int func_021613A4(Work_021613A4 *w, Evt_021613A4 *e);
extern const char d_02172978[];



int func_021611E0(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *ctx;

t5 = a0 + 0;
a0 = ((struct Obj00020 *)t5)->f18;
t4 = a1 + 0;
a0 = ((struct Obj00020 *)((char *)a0))->f0;
    ctx = func_020120F4((const struct Ctx *)a0);
loc_021611EE:
    a0 = func_02012A30(ctx);
loc_021611F2:
t6 = a0 + 0;
a0 = ((struct Obj00020 *)t5)->f18;
a0 = ((struct Obj00020 *)((char *)a0))->f0;
    a0 = func_02012134(a0);
loc_021611FC:
a1 = a0 + 0;
a0 = t6 + 0;
    a0 = func_02029DD8(a0, a1);
loc_02161204:
a0 = *(int *)&((struct Obj00020 *)t4)->f10;
    if (a0 != 1) goto loc_0216120E;
loc_0216120A:
a0 = 1;
    return a0;
loc_0216120E:
a0 = 0;
    return a0;}



/*
 * Allocates a 0x18-byte record (func_02030734: heap 4, size 0x18, clear,
 * site string, tag 0x68A) and fills it from the work's 0x18 sub-object.
 */
Rec *func_02161214(Work *w)
{
    Rec *r = func_02030734(4, 0x18, 1, d_02172978, 0x68A);
    void *a;
    void *b;
    r->f00 = 1;
    r->f14 = (u32)w->f18->f00;
    a = func_020127A4(func_020120F4(w->f18->f00));
    b = func_020120F4(w->f18->f00);
    r->f08 = func_02012AC8(a);
    r->f0A = ((struct Obj18932 *)((u8 *)func_020128B8(b)))->f4;
    if (w->f18->f0C == 0)
        r->f00 = 0;
    else
        r->f00 = 1;
    return r;
}

int func_02161280(Work_02161280 *w, Evt_02161280 *e)
{
    int st = w->f18->f0C;
    if (st == 7) {
        switch (e->f04) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return 1;
        }
    } else if (st == 2) {
        switch (e->f04) {
        case 0:
            w->f0C = 2;
            return 4;
        case 1:
            return 1;
        default:
            return 1;
        }
    } else if (st == 0) {
        switch (e->f04) {
        case 0:
            w->f0C = 0;
            return 4;
        case 1:
            return 1;
        case 2:
            w->f18->f28 = 4;
            w->f18->f30 = e->f08;
            w->f18->f34 = e->f0C;
            w->f18->f38 = e->f10;
            w->f18->f3C = 0;
            return 2;
        default:
            return 1;
        }
    }
    return 1;
}




/*
 * Allocate an 8-byte record and store the save handle at +4. The extent
 * also holds the unlabelled leaf at 0x02161340 (nonzero test of *r1).
 */
u32 *func_02161308(char *c)
{
    u32 *r;

    func_0200873C(func_02012EBC(func_020120F4(**(void ** *)&((struct Obj12327 *)c)->f18)));
    r = func_02030734(4, 8, 1, d_02172978, 0x705);
    r[1] = **(u32 * *)&((struct Obj12327 *)c)->f18;
    return r;
}




int func_02161340(int a0, int *a1)
{
    if (*a1 != 0)
        return 1;
    return 0;
}




/*
 * Five arguments to the overlay builder: the two words of the descriptor,
 * the object's halfword, the descriptor's classification and a pointer to
 * the object's tail; the result goes to the arm9 call with the
 * object's word at +0x14.
 */
void func_02161350(void *a0)
{
    char *r4 = *(char * *)&((struct Obj09158 *)a0)->f18;
    void *t = func_02188C54(((struct Obj09159 *)r4)->f4);

    func_02012374(((struct Obj09158 *)a0)->f14,
                  func_021616A4(((struct Obj09159 *)r4)->f0, (int)(((struct Obj09159 *)r4)->f4),
                                ((struct Obj09158 *)a0)->f0, (int)t, (int)((char *)a0 + 0x10)));
}



/*
 * Allocate an 8-byte record and store the save handle at +0.
 * The extent also holds the unlabelled leaf at 0x021613A4.
 */
u32 *func_02161378(char *c)
{
    u32 *r;

    r = func_02030734(4, 8, 1, d_02172978, 0x74C);
    r[0] = (u32)func_020120F4(**(void ** *)&((struct Obj18938 *)c)->f18);
    return r;
}

int func_021613A4(Work_021613A4 *w, Evt_021613A4 *e)
{
    if (w->f18->f0C == 8) {
        switch (e->f04) {
        case 0:
            return 0;
        default:
            return 1;
        }
    }
    switch (e->f04) {
    case 0:
        w->f0C = 2;
        return 4;
    default:
        return 1;
    }
}
