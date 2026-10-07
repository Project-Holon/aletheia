/*
 * file:     script_work_p06.c
 * unit:     yes
 * function: func_021584F4, func_0215850C, func_02158570, func_02158590, func_021585BC, func_021585E0, func_02158614, func_02158630, func_02158678, func_021586C8, func_0215870C, func_0215874C, func_02158768, func_02158780, func_021587B0, func_021587E0, func_02158804
 * address:  0x021584F4
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
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_02012950  0x02012950  thumb
 *   func_0200855C  0x0200855C  thumb
 *   func_02008530  0x02008530  thumb
 *   d_021700AC 0x021700AC data a2
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   d_021700A8 0x021700A8 data a2
 *   func_02175B14  0x02175B14  thumb
 *   func_02176258  0x02176258  thumb
 *   func_02026478  0x02026478  thumb
 *   func_02176230  0x02176230  thumb
 *   func_02008500  0x02008500  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_02158920  0x02158920  thumb  ov010
 *   func_020124E4 0x020124E4 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02012374 0x02012374 thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_021589DC 0x021589DC thumb ov010
 *   func_02158894 0x02158894 thumb ov010
 *   func_02030734 0x02030734 arm
 *   d_02172888 0x02172888 data a1
 */
#include "../../matched/include/Obj17623.h"

struct BigObj;
struct Sub24;
struct Rec44;
struct Sub02014444Obj;
struct Sub0200852CObj;
struct Desc;
struct Obj;
struct Evt;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 low:2; u8 flag:1; u8 high:5; } Flag_021585E0;

typedef struct { u8 a : 5; u8 f : 1; u8 b : 2; } Fl;

typedef struct { u8 a : 6; u8 f : 1; u8 b : 1; } FlagsF8;

typedef struct { u8 low:2; u8 flag:2; u8 high:4; } Flag_0215874C;

extern int func_02158344(int a0);
extern void *func_02012B38(const struct BigObj *p);
extern u32 func_0201444C(struct Sub02014444Obj *o);
extern u8 func_0215841C(void *p);
extern u8 func_02012B58(const struct BigObj *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u8 func_0200855C(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *, int);
extern int func_02175B14();
extern int func_02176258(int);
extern u32 func_02026478(void *obj);
extern int func_02176230(void *, void *);
extern void func_02008500(void *a, void *b);
u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
int func_0203CDBC(void);
extern struct Desc *func_02158920(int a, int b, int c, int d, int e);
extern void *func_020124E4(struct Obj *p);
extern void *func_020124E8(struct Obj *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_0201235C();
extern int func_021589DC(int a0);
extern int func_02158894(int a0, int a1);
extern void *func_02030734(u32, u32, int, const char *, u16);
int func_021584F4(int a0, int a1);
int func_0215850C(int a0, int a1);
int func_02158570(u16 value);
int func_02158590(void *p);
int func_021585BC(int a0);
int func_021585E0(int p);
void func_02158614(void *p);
int func_02158630(int a);
int func_02158678(void *p);
int func_021586C8(int a, int b);
int func_0215870C(void *p, int b);
void func_0215874C(void *p);
struct Desc *func_02158768(int a0, int a1, int a2, int a3);
int func_02158780(void *p, u16 b, int c, int d, u16 e);
int func_021587B0(int a0, int a1, int a2, int a3);
int func_021587E0(int a, int b);
void *func_02158804(u32 heap);
extern const u16 d_021700AC[61];
extern const u16 d_021700A8[2];
extern const char d_02172888[];




int func_021584F4(int a0, int a1)
{

    if (a0 == 0x15) goto loc_0215850A;
loc_021584F8:
    if (a0 == 0x14) goto loc_0215850A;
loc_021584FC:
a0 = 1;
a0 = a0 << 0x10;
    if ((a0 & a1) == 0) goto loc_02158508;
loc_02158504:
a0 = 0x14;
    return a0;
loc_02158508:
a0 = 0x15;
loc_0215850A:
    return a0;}


int func_0215850C(int a0, int a1)
{
    int t4;
    int t5;
    void *p;
    struct Rec44 *rec;

t5 = a1 + 0;
    a0 = func_02158344(a0);
loc_02158514:
a0 = t5 + 0;
    p = func_02012B38((const struct BigObj *)a0);
loc_0215851A:
    a0 = func_0201444C(p);
loc_0215851E:
    if (a0 == 1) goto loc_02158526;
loc_02158522:
a0 = 0;
    return a0;
loc_02158526:
a0 = t5 + 0;
    a0 = func_0215841C((void *)a0);
loc_0215852C:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012B58((const struct BigObj *)a0);
loc_02158534:
    if (t4 != a0) goto loc_0215853C;
loc_02158538:
a0 = 0;
    return a0;
loc_0215853C:
a0 = t5 + 0;
a1 = t4 + 0;
    rec = func_02012950((struct Sub24 *)a0, a1);
loc_02158544:
    a0 = func_0200855C((const struct Sub0200852CObj *)rec);
loc_0215854A:
t4 = a0 + 0;
    a0 = func_02008530((const struct Sub0200852CObj *)rec);
loc_02158552:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_021584F4(a0, a1);
loc_0215855A:
    if (a0 == 0x14) goto loc_02158564;
loc_0215855E:
    if (a0 == 0x15) goto loc_02158568;
loc_02158562:
    goto loc_0215856C;
loc_02158564:
a0 = 1;
    return a0;
loc_02158568:
a0 = 2;
    return a0;
loc_0215856C:
a0 = 3;
    return a0;}

/*
 * lever: The ternary loop condition preserves the branch to the bottom test.
 */
int func_02158570(u16 value)
{
    unsigned int i;
    for (i = 0; (i < 61) ? 1 : 0; i++) {
        if (value == d_021700AC[i])
            return 1;
    }
    return 0;
}

int func_02158590(void *p)
{
    void *q = (void *)func_0201296C(p);
    unsigned int i;
    for (i = 0; i < 2; i++) {
        if (func_020142E8(q, d_021700A8[i]) == 0)
            return 0;
    }
    return 1;
}


int func_021585BC(int a0)
{
    int a1;

a1 = 0x25;
a1 = a1 << 6;
a1 = *(int *)((char *)a0 + a1);
a1 = (unsigned)a1 >> 0x1f;
    if (a1 == 0) goto loc_021585DA;
loc_021585C8:
a1 = 0x6b;
a1 = a1 << 2;
a0 = a0 + a1;
    a0 = func_02175B14(a0, a1);
loc_021585D2:
    if (a0 != 0) goto loc_021585DA;
loc_021585D6:
a0 = 1;
    return a0;
loc_021585DA:
a0 = 0;
    return a0;}

/*
 * Callee 02158344 consumes incoming r0; the flag extract reads bit 2.
 */
int func_021585E0(int p)
{
    u8 *q = (u8 *)func_02158344((int)((void *)p));
    if (q == 0)
        return 0;
    if (((Flag_021585E0 *)(q + 0x93F))->flag == 0) {
        if (func_02158630(p) == 3)
            return 2;
        return 1;
    }
    return 3;
}

/*
 * The callee reads its incoming r0; legacy void prototypes omit it.
 */
void func_02158614(void *p)
{
    u8 *q = (u8 *)func_02158344((int)p);
    if (q != 0)
        q[0x93F] |= 4;
}


int func_02158630(int a)
{
    int q = func_02158344(a);
    if (q == 0)
        return 0;
    if (func_02175B14(q + 0x1AC) == 1) {
        if (func_02176258(q) == 1)
            return 2;
        if (func_02158590((void *)func_02026478((void *)a)) == 0)
            return 1;
        return 3;
    }
    return 1;
}


int func_02158678(void *p)
{
    int n = 0;
    u8 i;
    u8 *q = (u8 *)func_02158344((int)p);
    if (q == 0)
        return n;
    if (func_02175B14(q + 0x1AC) == 0)
        return n;
    for (i = 0; i < 3; i++) {
        if (((Fl *)(q + 0xA6 + i * 0x1C))->f == 1)
            n++;
    }
    if (n == 0)
        n = 1;
    return n;
}


int func_021586C8(int a, int b)
{
    char *q = (char *)func_02158344(a);
    int r = func_02026478((void *)a);
    if (q == 0 || func_02175B14(q + 0x1AC) == 0)
        return 0;
    func_02008500(func_02012950((struct Sub24 *)r, func_02176230(q, q + 0x1AC)), (void *)b);
    return 1;
}


/*
 * Three guards (state == 2, a non-null lookup, bit 6 of a far byte) then a
 * predicate whose one result is inverted.
 */
int func_0215870C(void *p, int b)
{
    u8 *q;

    if (func_02026454((void *)((int)p)) != 2)
        return 0;
    q = (u8 *)func_02026474((void *)((int)p));
    if (q == 0)
        return 0;
    if (((FlagsF8 *)(q + 0x8f8))->f == 0)
        return 0;
    if (func_0203CDBC() == 1)
        return 0;
    return 1;
}

void func_0215874C(void *p)
{
    u8 *q = (u8 *)func_02158344((int)p);
    if (q != 0)
        ((Flag_0215874C *)(q + 0x904))->flag = 0;
}


struct Desc *func_02158768(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int o4;
    struct Desc *r;
t5 = a1 + 0;
t4 = a2 + 0;
a1 = 0;
    o4 = a1;
a1 = a3 + 0;
a2 = t5 + 0;
a3 = t4 + 0;
    r = func_02158920(a0, a1, a2, a3, o4);
loc_0215877C:
    return r;
}

int func_02158780(void *p, u16 b, int c, int d, u16 e)
{
    struct Desc *h = func_02158920((int)func_020124E4(p), e, b, c, d);
    int *q = func_020124E8((void *)h);
    func_02012374(p, (struct Evt **)((void **)h));
    return *q;
}


int func_021587B0(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    int t7;
    int o4;
    void *p;
    void *q;
    struct Desc *v0;
t7 = a0 + 0;
t5 = a1 + 0;
t4 = a2 + 0;
t6 = a3 + 0;
    p = func_020124E4((struct Obj *)a0);
loc_021587BE:
a1 = 0;
    o4 = a1;
a1 = t6 + 0;
a2 = t5 + 0;
a3 = t4 + 0;
    v0 = func_02158920((int)p, a1, a2, a3, o4);
loc_021587CC:
    q = func_020124E8((struct Obj *)v0);
loc_021587D2:
a0 = t7 + 0;
    a0 = func_0201235C(a0, v0);
loc_021587DC:
a0 = ((struct Obj17623 *)q)->f0;
    return a0;
}

/*
 * Extent ends in two alignment padding bytes.
 */
int func_021587E0(int a, int b) {
    void *p = (void *)func_021589DC(a);
    if (!p) return 0;
    if (func_02158894((int)p, b)) return 1;
    return 0;
}

/*
 * Allocates 0x18 bytes and initializes the leading heap halfword.
 */
void *func_02158804(u32 heap) {
    u16 *p = func_02030734(heap, 0x18, 1, d_02172888, 0xef);
    *p = heap;
    return p;
}
