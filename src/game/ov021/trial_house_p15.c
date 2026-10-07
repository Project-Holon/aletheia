/*
 * file:     trial_house_p15.c
 * unit:     yes
 * function: func_021D04A4, func_021D04C4, func_021D04D8, func_021D0504, func_021D0520, func_021D0568, func_021D05D8, func_021D0610
 * address:  0x021D04A4
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
 *   d_021DB934     0x021DB934  data  a4
 *   func_020061E4  0x020061E4  thumb
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0219BF3C  0x0219BF3C  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021C6744  0x021C6744  thumb  ov021
 *   func_021C6694  0x021C6694  thumb  ov021
 *   func_021C67A8  0x021C67A8  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021C6664  0x021C6664  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 *   d_021DB968     0x021DB968  data  ov021  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DE664     0x021DE664  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_021D0648  0x021D0648  thumb  ov021
 */
#include "../../matched/include/Obj13000.h"
#include "../../matched/include/Obj18369.h"
#include "../../matched/include/Obj09745.h"

struct Actor;
struct VecFx32;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Blk021D04D8 {
    u32 w[4];
} Blk021D04D8;

typedef struct St021D04D8 {
    u8 *f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10[2];
    u16 f18;
} St021D04D8;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef struct R {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u16 h18;
    u16 h1a;
    u16 h1c;
    u16 h1e;
    u32 f20;
} R;

typedef struct Arg021D05D8 {
    u32 h;
    void *a;
} Arg021D05D8;

typedef struct Vec021D05D8 {
    int x, y, z;
} Vec021D05D8;

extern int func_021AC1E0(u32 a);
extern void func_020061E4(u32 a);
extern int func_021AC1AC(u32 a);
extern int func_0216E1A4(int a0, int a1);
extern int func_0216E1C4(int a0, int a1);
extern void func_0219BF3C(int a, u32 v);
extern void func_021AC154(u32 a);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern int func_02163E58(u32 m, Vec3 *pos, int *h);
extern void func_021AC1CC(u32 a, Vec3 *v);
extern void func_021C6744(u32 *a, int idx, int mode, u32 val);
extern int func_021C6694(u32 *a, int idx, int v);
extern u32 func_021C67A8(u32 a, u32 b, u32 c);
extern void func_021AC1B8(u32 a, Vec3 *v);
extern void func_021C6664(u32 a, u32 b, Vec3 *v);
extern void func_021C67F4(u32 a, u32 b);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(void *a, void *b, void *c, u32 d, void *e, u32 f);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021D0648(struct S *p);
void func_021D04A4(void *a);
int func_021D04C4(u32 a);
void func_021D04D8(void *a, St021D04D8 *s);
void func_021D0504(void *a, St021D04D8 *s);
void func_021D0520(u32 a, u8 *b);
void func_021D0568(u32 a, R *b);
void func_021D05D8(void *a, void *b);
void *func_021D0610(u32 v, u32 heap);
extern int d_021DB934[];
extern char d_021DB968[];
extern char d_021DE664[];


/*
 * Blocked: d_021DB934 (u32 table indexed by e->fC) is contested: another
 * overlay in the window starts an object at 0x021DB934 and this function has
 * no overlay_id site, so the ABS32 word stays wildcarded.
 */
void func_021D04A4(void *a)
{
    u8 *e;

    if (a != 0) {
        e = (u8 *)func_021AC1E0((u32)a);
        ((struct Obj13000 *)e)->f1A = 1;
        func_020061E4(d_021DB934[((struct Obj13000 *)e)->fC]);
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021D04C4(u32 a)
{
if (a != 0) {
    return ((struct Obj18369 *)((u8 *)(func_021AC1E0(a))))->f1C;
}
return 1;
}


void func_021D04D8(void *a, St021D04D8 *s)
{
    *(Blk021D04D8 *)s = *((Blk021D04D8 *)func_021AC1AC((u32)a));
    func_0216E1A4(s->f8, (int)s->f10);
    s->f18 = ((u16 *)(s->f0 + 8))[s->fC];
}


void func_021D0504(void *a, St021D04D8 *s)
{
    if (func_0216E1C4(s->f8, (int)s->f10) == 1) {
        func_0219BF3C(s->f8, 0);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D0520(u32 a, u8 *b)
{
    int h;
    Vec3 v;

    if (func_0216E1C4(((struct Obj09745 *)b)->f8, (int)((u16 *)(b + 0x10))) == 0) {
        func_021AC154(a);
        return;
    }
    func_0216D88C((const struct Actor *)((struct Obj09745 *)b)->f8, (struct VecFx32 *)&v);
    if (func_02163E58(((struct Obj09745 *)b)->f8, &v, &h) == 1) {
        v.y = h;
    }
    func_021AC1CC(a, &v);
}


void func_021D0568(u32 a, R *b)
{
    Vec3 v;

    if (b->h1a == 1 && b->h1c == 0) {
        func_021C6744((u32 *)b->f4, b->h18, 0, b->f20);
        if (func_021C6694((u32 *)b->f4, b->h18, 0x1000) == 0) {
            b->h1c = 1;
        }
        b->f20 = func_021C67A8(b->f4, b->h18, 0);
    } else {
        func_021C6744((u32 *)b->f4, b->h18, 0, b->f20);
    }
    func_021AC1B8(a, &v);
    func_021C6664(b->f4, b->h18, &v);
    func_021C67F4(b->f4, b->h18);
}


void func_021D05D8(void *a, void *b)
{
    Arg021D05D8 arg;
    Vec021D05D8 v;

    arg.h = func_021ABEA0((u32)b, 0x10);
    arg.a = a;
    func_0216D88C(a, (struct VecFx32 *)&v);
    func_021ABFA8(b, d_021DB968, &v, 0, &arg, 0);
}


void *func_021D0610(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0x20, 1, d_021DE664, 0xd5);

    p[0] = v;
    func_021D0648((struct S *)p);
    return p;
}
