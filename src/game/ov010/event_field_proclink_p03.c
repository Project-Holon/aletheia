/*
 * file:     event_field_proclink_p03.c
 * unit:     yes
 * function: func_0215EE24, func_0215EE38, func_0215EE68, func_0215EEBC, func_0215EED0, func_0215EEF8, func_0215EF2C, func_0215EF40
 * address:  0x0215EE24
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
 *   func_0215F104 0x0215F104 thumb ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0215F0E8 0x0215F0E8 thumb ov010
 *   func_02165534 0x02165534 thumb ov010
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02184F40  0x02184F40  thumb  ov020
 *   func_0201235C  0x0201235C  thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_021587B0 0x021587B0 thumb ov010
 *   func_021D1C24   0x021D1C24  thumb
 */
#include "../../matched/include/Obj02057.h"
#include "../../matched/include/Obj12044.h"
#include "../../matched/include/Obj17700.h"

struct C;
struct Desc;
struct Obj;
struct Pair;
struct S0201235C;
struct BigObj;
struct Ctx;
typedef enum { FALSE, TRUE } Bool;

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

struct C {
    u8 pad00[8];
    void *f8;
    u16 fc;
};

extern int func_0215F104(int a0, int a1);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0215F0E8(u32 *out, const struct Pair *in, u32 *ctx);
extern void func_02165534(void *a0);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_02184F40(void *p);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern int func_021587B0(int a0, int a1, int a2, int a3);
extern void func_021D1C24(int, int, unsigned);
int func_0215EE24(void *p);
void *func_0215EE38(void *p, void *ctx);
int func_0215EE68(void *a, int *st, struct C *c);
int func_0215EEBC(void *p);
void *func_0215EED0(void *p, void *ctx);
int func_0215EEF8(void *p, void *unused, struct C *ctx);
int func_0215EF2C(void *p);
void func_0215EF40(void *a0, void *a1);

/*
 * lever: Enum constants preserve the zero-first return arm; int constants fold to the opposite polarity.
 */
int func_0215EE24(void *p)
{
    return func_0215F104((int)p, 6) != 0 ? FALSE : TRUE;
}

void *func_0215EE38(void *p, void *ctx)
{
    void *task;
    func_02165534((void *)100);
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EE68, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}


int func_0215EE68(void *a, int *st, struct C *c)
{
    u32 h;
    void *t;

    switch (*st) {
    case 0:
        h = c->fc;
        t = (void *)func_02158780(a, 0x2719, 0, 0, 0x15);
        func_02159058((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_0201235C(a, func_02184F40(c->f8));
        break;
    }
    return 0;
}

int func_0215EEBC(void *p)
{
    return func_0215F104((int)p, 10) != 0 ? FALSE : TRUE;
}

void *func_0215EED0(void *p, void *ctx)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EEF8, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}

/*
 * lever: Context +8 word and +12 halfword match neighboring callback layout; named call result preserves the early halfword lifetime.
 * interface: 021587B0 returns its final ldr r0,[r4] at 021587DC, read by this caller; 02159058 uses its own int,int,int,int,u16 prototype.
 */
int func_0215EEF8(void *p, void *unused, struct C *ctx)
{
    int h;
    int t;
    func_0201296C(func_020120F4(ctx->f8));
    h = ctx->fc;
    t = func_021587B0((int)p, 0x271c, 0, 0);
    func_02159058(t, h, 0, 0, 0);
    return 0;
}

int func_0215EF2C(void *p)
{
    return func_0215F104((int)p, 9) != 0 ? FALSE : TRUE;
}


/*
 * Stamp the fixed id on the record, then hand three of the record's own
 * fields to the overlay pair call.
 */
void func_0215EF40(void *a0, void *a1)
{
    func_02165534((void *)0x1C0);
    func_021D1C24(((struct Obj12044 *)a1)->f8, ((struct Obj12044 *)a1)->f10,
                 (u8)((struct Obj17700 *)a0)->f0);
}
