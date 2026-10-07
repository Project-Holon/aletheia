/*
 * file:     unit_02183B60_p02.c
 * unit:     yes
 * function: func_02183DD4, func_02183DE4, func_02183F5C, func_0218403C, func_0218409C, func_02184120, func_021841C0
 * address:  0x02183DD4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_020127C4 0x020127C4 thumb
 *   func_02161D64 0x02161D64 thumb ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201445C  0x0201445C  thumb
 *   func_02012894  0x02012894  thumb
 *   func_02185B70  0x02185B70  thumb  ov020
 *   func_02185A68  0x02185A68  thumb  ov020
 *   func_0218601C  0x0218601C  thumb  ov020
 *   func_021857C0  0x021857C0  thumb  ov020
 *   func_0202735C  0x0202735C  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_02164474  0x02164474  thumb  ov010
 *   func_0202C860  0x0202C860  thumb
 *   func_0201405C  0x0201405C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216E29C  0x0216E29C  thumb  ov010
 *   func_0216CCCC  0x0216CCCC  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020145FC  0x020145FC  thumb
 *   func_020143CC  0x020143CC  thumb
 *   func_02158780  0x02158780  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC578  0x021BC578  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_0201AD0C  0x0201AD0C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02008B4C  0x02008B4C  thumb
 *   func_02008B78  0x02008B78  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02008C00  0x02008C00  thumb
 *   func_0216A390  0x0216A390  thumb  ov010
 *   func_0203F524  0x0203F524  arm
 *   func_0200C384  0x0200C384  thumb
 *   func_02008B20  0x02008B20  thumb
 *   func_0216AAE4  0x0216AAE4  thumb  ov010
 *   func_02021444  0x02021444  thumb
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   func_0202E848  0x0202E848  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02013B38  0x02013B38  thumb
 *   func_0201407C  0x0201407C  thumb
 *   func_020140D8  0x020140D8  thumb
 *   func_020140B4  0x020140B4  thumb
 *   func_021BE89C  0x021BE89C  thumb  ov021
 *   func_021BE8B8  0x021BE8B8  thumb  ov021
 *   sub_0202E8A4   0x0202E8A4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   ov230_id       0x000000E6  data
 *   func_02012138  0x02012138  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02014554  0x02014554  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02013D34  0x02013D34  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02183B60  0x02183B60  thumb  ov020
 *   func_0218604C  0x0218604C  thumb  ov020
 *   func_0218606C  0x0218606C  thumb  ov020
 *   func_0218608C  0x0218608C  thumb  ov020
 *   func_021882A0  0x021882A0  arm  ov230d
 *   func_02188318  0x02188318  arm  ov230d
 *   func_021883CC  0x021883CC  arm  ov230d
 *   func_0202E8CC  0x0202E8CC  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0216A358  0x0216A358  thumb  ov010
 *   func_02164454  0x02164454  thumb  ov010
 *   func_0216445C  0x0216445C  thumb  ov010
 *   func_02164464  0x02164464  thumb  ov010
 *   func_0215874C  0x0215874C  thumb  ov010
 *   func_02029C64  0x02029C64  thumb
 */
#include "../../matched/include/Obj02684.h"
#include "../../matched/include/Obj19450.h"
#include "../../matched/include/Obj00082.h"
#include "../../matched/include/Obj02068.h"
#include "../../matched/include/Obj02069.h"
#include "../../matched/include/Obj01649.h"

struct Ctx;
struct BigObj;
struct Evt;
struct Obj;
struct Rec1C;
struct Sub02014444Obj;
struct Big;
struct Blk34;
struct Desc;
struct Sub02008AECObj;
struct Sub02008AECSession;
struct Sub020140BCObj;
struct Comm;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int   u32;

typedef unsigned long long u64;

typedef signed int     s32;

typedef struct { int w[7]; } Blk28;

extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_020127C4(void *p);
extern int func_02161D64(int a0);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012B38(const struct BigObj *p);
extern void func_0201445C(struct Sub02014444Obj *o, u8 v);
extern struct Rec1C *func_02012894(const struct BigObj *p);
extern void func_02185B70(void *p);
extern void func_02185A68(void *a, int b);
extern void func_0218601C(int a);
extern void func_021857C0(void *a, int b);
extern void func_0202735C(u32 a0, u32 a1);
extern void func_02168EEC(int a);
extern void func_02164474(int a, int b);
extern void func_0202C860(u8 *a0, int a1);
extern u8 func_0201405C(u32 id);
extern u32 func_02012964(const struct BigObj *p);
extern void func_0216E29C(struct Obj *o, int v);
extern void func_0216CCCC(struct Obj *o);
extern u8 func_02012984(const struct BigObj *p);
extern unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
extern void *func_020298A0(void *a, u32 b, u32 c, u32 d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020145FC(int a);
extern u32 func_020143CC(u32 a, u32 b);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021BE92C(int a, int b, int c, int d, int e, int f, int g);
extern u32 func_02188D20(u8 *p);
extern void func_021BC578(void *p, int v);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void func_0201433C(char *a0, int a1);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern void *func_0201AD0C(void *sys);
extern void *func_02012F08(int *p);
extern int func_02008B4C(const struct Sub02008AECObj *obj);
extern int func_02008B78(const struct Sub02008AECObj *obj);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern void func_02008C00(struct Sub02008AECSession *s);
extern void func_0216A390(int a, int b);
extern u64 func_0203F524();
extern void func_0200C384(struct Blk34 *p, u32 lo, u32 hi);
extern void func_02008B20(struct Sub02008AECObj *obj);
extern void func_0216AAE4(void *sys, void *party, int season);
extern void func_02021444(void);
extern void func_0208068C(int a);
extern void func_02082AC0(int v, int dst, int size);
extern void func_02080B98(void);
extern int func_0202E848(int a0, int a1, int a2);
extern u16 func_02188C84(u8 *p);
extern u32 func_02013B38(u32 id);
extern int func_0201407C(int a, int b, int c);
extern u8 func_020140D8(struct Sub020140BCObj *p);
extern u32 func_020140B4(void *a);
extern int func_021BE89C(int a, u32 b);
extern int func_021BE8B8(int a, int b);
extern u8 sub_0202E8A4(u8 a);
extern u32 func_02012844(const struct BigObj *p);
extern void *func_021625CC(char *p, unsigned i);
extern u8 func_021626E8(u8 *p);
extern u32 func_02012138(const struct Ctx *p);
extern u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
extern int func_02014554(int a, int b);
extern int func_02034AC4(int id);
extern void func_02034A5C(int handle);
extern u32 func_02013D34(u32 id);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern int func_02183B60(int f);
extern void *func_0218604C(void);
extern void *func_0218606C(void);
extern void func_0218608C(void);
extern u32 func_021882A0(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188318(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_021883CC(void (*a)(void), void (*b)(void), u32 c);
extern u8 func_0202E8CC(s32 a, s32 b);
extern void *func_02012934(const struct BigObj *p);
extern int func_0216A358(int a, int b, u32 *p, int c);
extern int func_02164454(int a, int b);
extern int func_0216445C(int a, int b);
extern int func_02164464(int a, int b);
extern void func_0215874C(void *p);
extern void *func_02029C64(void *a);
void func_02183DD4(void *p);
int func_02183DE4(int ctx, int *state, u8 *p);
int func_02183F5C(int a0, u8 *a1);
void func_0218403C(u8 *p);
void func_0218409C(u8 *p, int arg);
void func_02184120(u8 *p, int arg);
int func_021841C0(int ctx, int *state, u8 **pp);
extern u8 ov230_id[];

/*
 * interface: 020127C4 forwards 020127D0's returned pointer in r0.
 */
void func_02183DD4(void *p)
{
    func_02161D64((int)func_020127C4(func_020120F4(p)));
}


/*
 * Byte-correct at 376 of 376 bytes.  Four wildcarded call sites, all of
 * them unlabelled tail-call leaves with no witness outside this range.
 * Each leaf's C below was verified EXACT with `match.py one` in a scratch
 * file; none is filed, because the arm9 one belongs to Ilias:
 *   +0xD4  func_02029DF4 (arm9, Ilias's): ldr r3,=func_02029EB4+1; bx r3
 *          int func_02029DF4(int a, int b, int c)
 *          { return func_02029EB4(a, b, c); }
 *   +0x96  func_02164474 (ov010): void f(int a, int b) { func_0215E364(a, b); }
 *   +0xB6  func_0216E29C (ov010): void f(u8 *p, int n)
 *          { func_02048F4C(*(int *)(p + 0x44), 0x3a, n); }   (02048F4C arm)
 *   +0xBC  func_0216CCCC (ov010): void f(u8 *p)
 *          { func_02082BCC(*(int *)(p + 0x44), 0, 0x310); }  (02082BCC arm)
 * Filing the three ov010 leaves (region hint ov010: ov009 overlaps them)
 * and the arm9 leaf makes this file EXACT unchanged.  This is the callback
 * func_02183F5C registers through func_020122C0.
 *
 * 2026-10-04 (wD2 lane 02): the last blocker, the ov010 leaf func_02164474, is now filed as
 * src/matched/ov/ov010_func_02164474.c (EXACT); the other three leaves were already filed. The tool still reports
 * it unresolved because the manifest is stale. Expected EXACT after the integrator's manifest refresh.
 */
int func_02183DE4(int ctx, int *state, u8 *p)
{
    int a;
    int s;
    int m;
    u8 *q;
    int n;
    int t;

    a = *(int *)(p + 0);
    s = (int)func_020120F4((const struct Ctx *)a);
    m = func_0201296C((const struct BigObj *)s);

    switch (*state) {
    case 0:
        func_0201445C(func_02012B38((const struct BigObj *)s), 1);
        if (*(int *)(p + 0xc) != 0) {
            q = (u8 *)func_02012894((const struct BigObj *)s);
            *(s16 *)(p + 8) = *(s16 *)(q + 4);
            func_02185B70((void *)a);
            func_02185A68((void *)a, *(u16 *)(p + 8));
            func_0218601C(s);
            func_021857C0((void *)a, (int)q);
            func_0202735C(*(u16 *)(q + 4), s);
        } else {
            func_02185A68((void *)a, *(u16 *)(p + 8));
            func_0218601C(s);
            func_02168EEC(s);
            func_02164474(s, *(u16 *)(p + 8));
            func_0202C860((u8 *)s, *(u16 *)(p + 8));
            n = func_0201405C(*(u16 *)(p + 8));
            t = func_02012964((const struct BigObj *)s);
            if (n < 16) {
                func_0216E29C((struct Obj *)t, n);
            } else {
                func_0216CCCC((struct Obj *)t);
            }
        }
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_020298A0((void *)a, func_02029DF4((void *)s, *(u16 *)(p + 8), func_02012984((const struct BigObj *)s)), 0, 0x3c));
        (*state)++;
        break;
    case 2:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_020145FC(a));
        (*state)++;
        break;
    case 3:
        if (*(int *)(p + 0xc) != 0 && *((u16 *)func_020143CC(m, 0x4041)) != 0) {
            func_02158780((void *)ctx, 0x83b, 0, 0, 0x15);
        } else {
            n = func_02012984((const struct BigObj *)s);
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C(a, (int)func_0201210C((const struct Ctx *)a), 3, 0, 0, n, n));
        }
        (*state)++;
        break;
    case 4:
        t = (int)func_0201210C((const struct Ctx *)a);
        if (func_02188D20((u8 *)t) != 0) {
            func_021BC578((void *)func_02188D20((u8 *)t), *(u16 *)(p + 8));
        }
        return 1;
    }
    return 0;
}


int func_02183F5C(int a0, u8 *a1)
{
    int t0;
    int *s;
    int r5;
    int r7;
    int r6;
    int h;
    u64 t;

    t0 = (int)func_020122C0((void *)a0, 0, (void *)((int)func_02183DE4), 0x10);
    s = func_020124E8((struct Obj *)t0);
    s[0] = a0;
    s[1] = (int)func_020120F4((const struct Ctx *)a0);
    ((struct Obj02684 *)s)->f8 = ((struct Obj19450 *)a1)->f10;
    r5 = func_0201296C((const struct BigObj *)s[1]);
    s[3] = func_020142E8((void *)r5, 0x966);
    func_0201433C((char *)r5, 0x966);
    r7 = (int)func_02012EBC((struct Big *)s[1]);
    r5 = (int)func_02008B08((void *)r7);
    r6 = (int)func_0201AD0C((void *)r7);
    h = (int)func_02012F08((int *)s[1]);
    if (!func_02008B4C((const struct Sub02008AECObj *)r5) || !func_02008B78((const struct Sub02008AECObj *)r5)) {
        func_02008C00(func_02008B14((void *)r7));
        func_0216A390(s[1], r6);
        t = func_0203F524();
        func_0200C384((struct Blk34 *)h, (u32)t, (u32)(t >> 32));
    }
    func_02008B20((struct Sub02008AECObj *)r5);
    func_0216AAE4((void *)s[1], (void *)r6, func_02012984((const struct BigObj *)s[1]));
    func_02183DD4((void *)a0);
    func_02021444();
    func_0208068C(0x1FF);
    func_02082AC0(0, 0x06800000, 0xA4000);
    func_02080B98();
    return t0;
}


void func_0218403C(u8 *p)
{
    u16 s[2];
    int r4;
    int r6;
    int flag;
    u16 hi;

    func_0202E848(((struct Obj00082 *)p)->f4, (int)(&s[1]), (int)(&s[0]));
    r4 = func_02188C84((u8 *)(*(int *)&((struct Obj00082 *)p)->f8));
    r6 = func_0201407C(r4, func_02013B38(((struct Obj00082 *)p)->f14), 0);
    flag = 0;
    if (func_020140D8((struct Sub020140BCObj *)r6) != 0)
        flag = 1;
    func_020140B4((void *)r6);
    hi = s[1];
    if (s[0] != hi && flag) {
        ((struct Obj00082 *)p)->f44 = 1;
        ((struct Obj00082 *)p)->f48 = hi;
        ((struct Obj00082 *)p)->f4A = s[0];
    }
}


void func_0218409C(u8 *p, int arg)
{
    u8 *q = p + 0x4c;

    ((struct Obj02068 *)q)->f4 = *(int *)&((struct Obj00082 *)p)->f0;
    ((struct Obj02068 *)q)->f8 = ((struct Obj00082 *)p)->f4;
    ((struct Obj02068 *)q)->fC = *(int *)&((struct Obj00082 *)p)->f8;
    ((struct Obj02068 *)q)->f10 = ((struct Obj00082 *)p)->f2C;
    ((struct Obj00082 *)p)->f4C = arg;
    ((struct Obj02068 *)q)->f18 = ((struct Obj00082 *)p)->fC;
    *(Blk28 *)(q + 0x1c) = *(Blk28 *)(p + 0x10);
    ((struct Obj02068 *)q)->f38 = func_021BE89C(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02068 *)q)->f3C = func_021BE8B8(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02068 *)q)->f40 = (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) ? 1 : 0;
    ((struct Obj02068 *)q)->f44 = sub_0202E8A4(((struct Obj00082 *)p)->f48);
    ((struct Obj02068 *)q)->f45 = ((struct Obj00082 *)p)->f4A;
    ((struct Obj02068 *)q)->f48 = 0;
    ((struct Obj02068 *)q)->f4C = 0;
}


void func_02184120(u8 *p, int arg)
{
    u8 *q = p + 0x4c;

    ((struct Obj02069 *)q)->f4 = *(int *)&((struct Obj00082 *)p)->f0;
    ((struct Obj02069 *)q)->f8 = ((struct Obj00082 *)p)->f4;
    ((struct Obj02069 *)q)->fC = *(int *)&((struct Obj00082 *)p)->f8;
    ((struct Obj02069 *)q)->f10 = ((struct Obj00082 *)p)->f2C;
    ((struct Obj00082 *)p)->f4C = arg;
    ((struct Obj02069 *)q)->f18 = ((struct Obj00082 *)p)->fC;
    *(Blk28 *)(q + 0x1c) = *(Blk28 *)(p + 0x10);
    ((struct Obj02069 *)q)->f38 = func_021BE89C(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02069 *)q)->f3C = func_021BE8B8(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14);
    ((struct Obj02069 *)q)->f40 = (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) ? 1 : 0;
    ((struct Obj02069 *)q)->f44 = sub_0202E8A4(((struct Obj00082 *)p)->f48);
    ((struct Obj02069 *)q)->f45 = ((struct Obj00082 *)p)->f4A;
    if (((struct Obj00082 *)p)->f10 == 1) {
        ((struct Obj02069 *)q)->f14 = 0;
        return;
    }
    ((struct Obj02069 *)q)->f14 = func_021626E8(func_021625CC((char *)func_02012844((const struct BigObj *)(((struct Obj00082 *)p)->f4)), ((struct Obj00082 *)p)->f16));
}


/*
 * Two spellings are load-bearing.  The u8 range check on func_02026454's
 * result is `adds r0, #0xff; lsls/lsrs #0x18; cmp #1; bhi`: written
 * `(u8)(v - 1) <= 1` it compiles to `subs r0, r0, #1` (one byte out), and as
 * `switch (v) { case 1: case 2: }` it grows by 4 bytes with two compares;
 * only `(u8)(v + 0xff) <= 1` gives the add.  The dead `str r2, [sp, #0xc]`
 * after `adds r2, #0x14` is `a += 0x14;` on the spilled local before the
 * func_0216A358 call.  func_021882A0/02188318/021883CC are ov230's decrypted
 * code (ov230d token); each gets the range func_02183B60 to one of this
 * overlay's end markers.  Leaves filed for this function: ov010 0x02164454,
 * 0x0216445C, 0x02164464 and ov020 0x0218608C.
 */
int func_021841C0(int ctx, int *state, u8 **pp)
{
    u8 *p;
    int x;
    int y;
    int z;
    int w;
    void *c;
    int b;
    int a;

    p = *pp;
    z = ((struct Obj01649 *)p)->f8;
    x = ((struct Obj01649 *)p)->f0;
    y = ((struct Obj01649 *)p)->f4;
    w = func_02012138((const struct Ctx *)x);

    switch (*state) {
    case 0:
        func_0201447C(func_02012B38((const struct BigObj *)y), 2);
        func_02012374((struct Evt *)ctx, (struct Evt **)func_02014554(x, z));
        (*state)++;
        break;
    case 1:
        func_02034AC4((int)ov230_id);
        if (func_02013D34(((struct Obj01649 *)p)->f14) == 1 && (u8)(func_02026454((void *)w) + 0xff) <= 1) {
            func_02026400((struct Comm *)w);
            *state = 2;
        } else {
            *state = 3;
        }
        break;
    case 2:
        if (func_02026454((void *)w) == 0) {
            *state = 3;
        }
        break;
    case 3:
        func_021882A0((void (*)(void))func_02183B60, (void (*)(void))func_0218604C, 0);
        func_02185B70((void *)x);
        if (((struct Obj01649 *)p)->f40 != 0 && ((struct Obj01649 *)p)->f44 != 0) {
            func_0202E8CC(y, ((struct Obj01649 *)p)->f4A);
            a = (int)func_02008B14(func_02012EBC((struct Big *)y));
            b = func_02012984((const struct BigObj *)y);
            c = func_02012934((void *)y);
            func_0216AAE4((void *)y, c, b);
            a += 0x14;
            func_0216A358(y, (int)c, (u32 *)a, b);
        }
        func_02188318((void (*)(void))func_02183B60, (void (*)(void))func_0218606C, 0);
        func_02185A68((void *)x, ((struct Obj01649 *)p)->f14);
        func_021857C0((void *)x, (int)(p + 0x10));
        if (((struct Obj01649 *)p)->f30 != 4) {
            func_0202735C(((struct Obj01649 *)p)->f14, y);
        }
        func_021883CC((void (*)(void))func_02183B60, func_0218608C, 0);
        switch (((struct Obj01649 *)p)->f30) {
        case 1:
            func_02164454(y, ((struct Obj01649 *)p)->f14);
            break;
        case 2:
            func_02164464(y, ((struct Obj01649 *)p)->f14);
            break;
        case 3:
            func_0216445C(y, ((struct Obj01649 *)p)->f14);
            break;
        }
        func_02034A5C((int)ov230_id);
        func_0215874C((void *)w);
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_020145FC(x));
        (*state)++;
        break;
    case 5:
        func_02012374((struct Evt *)ctx, func_02029C64((void *)x));
        (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}
