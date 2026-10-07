/*
 * file:     event_field_proclink_p21.c
 * unit:     yes
 * function: func_021611E0, func_02161214
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
 */
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj18932.h"

struct Ctx;
struct BigObj;
struct Rec1C;
struct Rec44;
struct SaveBlock;
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

extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012A30(const struct BigObj *p);
extern int func_02012134();
extern int func_02029DD8(int a0, int a1);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern struct Rec1C *func_020128B8(const struct BigObj *p);
int func_021611E0(int a0, int a1);
Rec *func_02161214(Work *w);
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
