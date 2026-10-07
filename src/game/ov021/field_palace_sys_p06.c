/*
 * file:     field_palace_sys_p06.c
 * unit:     yes
 * function: func_021D1F64, func_021D1F78, func_021D201C, func_021D2040, func_021D20BC, func_021D2124, func_021D213C, func_021D21C0, func_021D21E0, func_021D220C, func_021D2278, func_021D2358
 * address:  0x021D1F64
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
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0204B100  0x0204B100  arm
 *   func_020185F0  0x020185F0  thumb
 *   func_0202D7C8  0x0202D7C8  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   func_0202D934  0x0202D934  thumb
 *   func_0202D8D0  0x0202D8D0  thumb
 *   func_0202D9A4  0x0202D9A4  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   d_021DD60C     0x021DD60C  data  a2
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0201F548  0x0201F548  thumb
 *   func_02049B90  0x02049B90  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020249B0  0x020249B0  thumb
 *   d_021DD614     0x021DD614  data  ov021  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   func_02188C84  0x02188C84  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   data_021DD6BC  0x021DD6BC  data
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C7858  0x021C7858  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A30A4  0x021A30A4  thumb  ov021
 *   func_021CD440  0x021CD440  thumb  ov021
 *   func_02184FD4  0x02184FD4  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_021C7260  0x021C7260  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021A01D4  0x021A01D4  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_02184F88  0x02184F88  thumb  ov020
 */
#include "../../matched/include/Obj18378.h"
#include "../../matched/include/Obj04135.h"
#include "../../matched/include/Obj02103.h"
#include "../../matched/include/G_Ent021DD614.h"

struct Ctx;
struct Bank;
struct Sav;
struct Obj;
struct Actor;
struct PtS;
struct Vec2;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Big;
struct Sub02008828Obj;
struct Desc;
struct Obj00020;
struct Evt;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_021D1F64;

typedef signed char    s8;

typedef struct {
    u16 h[4];
} Tbl;

typedef signed short   s16_021D201C;

typedef short s16_021D2040;

typedef struct {
    s16_021D2040 x;
    s16_021D2040 y;
} Pt;

typedef signed short   s16_021D2124;

typedef struct Ent021DD614 Ent021DD614;

typedef signed short   s16_021D220C;

struct Milestone {
    u16 count;
    u16 msg;
};

typedef struct { int x, y, z; } Vec;

extern void *func_0201210C(const struct Ctx *p);
extern u32 *func_0216D9E4(void *c);
extern void *func_02188C7C(unsigned char *p);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_020185F0(u32 a);
extern int func_0202D7C8(int a0);
extern u32 func_02017DBC(struct Sav *p);
extern int func_0202D934(int a0, void *a1, int a2, int a3, unsigned short a9);
extern int func_0202D8D0(int a0, void *a1, int a2, int a3, unsigned short a8, unsigned short a9);
extern u32 func_0202D9A4(u32 h, u32 b1, u32 b2, u32 b3, u16 key);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern void func_02049238(u32 a);
extern struct Obj *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *e, unsigned short f, unsigned short g);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u8 func_0201F548(int i);
extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
extern unsigned int func_02159B10(void *a, void *b);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_020249B0(u32 a, u16 b);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 func_02008990(const struct Sub02008828Obj *obj);
extern u16 func_02188C84(u8 *p);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern u32 func_02188D38(unsigned char *p);
extern int func_021C7858(u32 a, u32 b, u32 c);
extern void func_021C6DE0(unsigned char *p, u32 *a, u32 b);
extern void func_020061E4(u32 a);
extern int func_02006148(u32 a0);
extern int func_02006224(u32 a0);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern void func_021A30A4(u8 *p, u32 b);
extern int func_021CD440(void *a, u16 *out);
extern void *func_02184FD4(void *p, u16 id);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0216D410(void *a0, u16 a1);
extern int func_0216D454(void *o);
extern u32 func_02188C64(unsigned char *p);
extern void *func_021C7260(u32 a, u16 b, int c);
extern void *func_021C71D4(u32 a, u32 b, u32 c);
extern u32 func_021A01D4(unsigned char *p);
extern void func_021A01FC(unsigned char *p, u32 a, u32 b, u32 c);
extern void *func_02184F88(void *p);
int func_021D1F64(u32 a);
void func_021D1F78(u32 *w);
int func_021D201C(u32 a, u32 b, u32 c, u32 d);
int func_021D2040(u8 *w);
void func_021D20BC(u32 *w);
int func_021D2124(u32 a, u32 b, u32 c, u32 d);
int func_021D213C(u32 a, u32 b);
int func_021D21C0(u32 id);
int func_021D21E0(u32 id);
int func_021D220C(void *msg, u8 *pos);
int func_021D2278(u32 a, int *seq, int *w);
int func_021D2358(u32 a, int *seq, int *w);
extern Tbl d_021DD60C;
extern struct Ent021DD614 d_021DD614[];
extern const struct Milestone data_021DD6BC[5];


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021D1F64(u32 a)
{
return (int)func_0216D9E4(func_02188C7C(func_0201210C((const struct Ctx *)((struct Obj18378 *)((u8 *)(a)))->f4)));
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D1F78(u32 *w)
{
    u32 r4, r7, t;
    Tbl buf;

    w[0x38 / 4] = (u32)func_0204B100(1, 0, 0x15);
    r4 = func_020185F0(w[0x14 / 4]);
    r7 = func_0202D7C8(0x15);
    t = func_02017DBC((struct Sav *)r4);
    w[0x40 / 4] = func_0202D934(r7, (void *)r4, 0, 0, 0x15);
    w[0x44 / 4] = func_0202D8D0(r7, (void *)r4, 0, 0, 0x60, 0x15);
    w[0x48 / 4] = func_0202D9A4(r4, 0, 1, 0, 0x15);
    func_02017DE4((struct Sav *)r4, t);
    func_02049238(r7);
    buf = d_021DD60C;
    w[0x3c / 4] = (u32)func_0204B294((void *)w[0x38 / 4], w[0x40 / 4], w[0x44 / 4], w[0x48 / 4], &buf, 0, 0x15);
}


int func_021D201C(u32 a, u32 b, u32 c, u32 d)
{
func_0204B3B4((struct Obj *)(((struct Obj04135 *)((u8 *)(a)))->f3C));
func_0204A8D4(((struct Obj04135 *)((u8 *)(a)))->f40);
func_0204ADA4(((struct Obj04135 *)((u8 *)(a)))->f44);
func_0204AFD8(((struct Obj04135 *)((u8 *)(a)))->f48);
return func_0204B1CC((struct Bank *)(((struct Obj04135 *)((u8 *)(a)))->f38));
}


int func_021D2040(u8 *w)
{
    Pt pt;

    if (w[0x4c] == 0) {
        ((struct Obj02103 *)w)->f4D = -4;
    }
    if (((struct Obj02103 *)w)->f4D == -4) {
        ((struct Obj02103 *)w)->f4D = 3;
        w[0x4c] = w[0x4c] + 1;
        if (w[0x4c] == 3) {
            return 0;
        }
    }
    func_0204B454((struct Actor *)((struct Obj02103 *)w)->f3C, (struct PtS *)&pt, 0);
    pt.y = pt.y - ((struct Obj02103 *)w)->f4D;
    func_0204B404((struct Obj *)(((struct Obj02103 *)w)->f3C), (const struct Vec2 *)(&pt), 0);
    ((struct Obj02103 *)w)->f4D = ((struct Obj02103 *)w)->f4D - 1;
    return 1;
}


void func_021D20BC(u32 *w)
{
    func_02049B90(5, func_0201F548(0), 0, 0, 0, 0x20, 0x15);
    w[0x30 / 4] = func_020450F0(1, 10, 3, 12, 12, 0, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)w[0x30 / 4])), 0x11);
    func_02045334((struct Descriptor *)w[0x30 / 4]);
    func_02045374((struct Cfg *)w[0x30 / 4]);
    func_0201F73C((void *)w[0x30 / 4], 1, 1, 0);
    func_021D1F78(w);
}


int func_021D2124(u32 a, u32 b, u32 c, u32 d)
{
func_021D201C(a, b, c, d);
func_0201F7A8((void *)(((struct Obj04135 *)((u8 *)(a)))->f30), 1);
return func_020452E8((struct Descriptor *)(((struct Obj04135 *)((u8 *)(a)))->f30));
}


/*
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * Addresses are Black-image addresses.
 */
int func_021D213C(u32 a, u32 b)
{
    u32 base, s, r7, r4;
    u16 *p;

    r4 = func_02159B10((void *)a, (void *)b);
    s = func_02159B10((void *)a, (void *)b);
    r7 = func_02159B10((void *)a, (void *)b);
    p = func_02159AE8((void *)a, (void *)b);
    switch (r4) {
    case 1:
        base = 0x5C0;
        r4 = base + 0xBB;
        break;
    case 2:
        base = 0x664;
        r4 = base + 0x53;
        break;
    default:
        *p = 0;
        return 0;
    }
    if (func_020249B0(base, s & 0x7FF) && func_020249B0(r4, r7 & 0x7FF)) {
        *p = 1;
    } else {
        *p = 0;
    }
    return 0;
}


int func_021D21C0(u32 id)
{
    u32 i;

    for (i = 0; i < 0x15; i++) {
        if (id == d_021DD614[i].id) {
            return 1;
        }
    }
    return 0;
}


int func_021D21E0(u32 id)
{
    u32 i;

    for (i = 0; i < 0x15; i++) {
        if (id == d_021DD614[i].id && d_021DD614[i].flag == 1) {
            return 1;
        }
    }
    return 0;
}


/*
 * Shows the milestone message for the counter read from the save block when
 * it equals one of the five table entries at 0x021DD6BC, or message 0x28E1
 * once it passes 500; returns 0 otherwise.
 *
 * Addresses are Black-image addresses.
 */
int func_021D220C(void *msg, u8 *pos)
{
    u16 n = func_02008990(func_02008854(func_02012EBC(func_020120F4(msg))));
    u32 i;

    for (i = 0; i < 5; i++) {
        if (n == data_021DD6BC[i].count)
            return (int)func_02158768((int)msg, data_021DD6BC[i].msg, 0, func_02188C84(pos));
    }
    if (n > 500)
        return (int)func_02158768((int)msg, 0x28E1, 0, func_02188C84(pos));
    return 0;
}


int func_021D2278(u32 a, int *seq, int *w)
{
    Vec v;
    u16 id;
    u32 s;
    void *o;

    switch (*seq) {
    case 0:
        s = func_02188D38((unsigned char *)w[1]);
        v.x = 0;
        v.y = -0x40000;
        v.z = 0;
        func_021C6DE0((unsigned char *)s, (u32 *)func_021C7858(w[1], 0x28, (u32)(&v)), 0);
        w[3] = 8;
        (*seq)++;
        break;
    case 1:
        w[3]--;
        if (w[3] > 0) {
            break;
        }
        func_020061E4(0x63C);
        (*seq)++;
        break;
    case 2:
        if (func_02006224(func_02006148(0x63C)) != 0) {
            break;
        }
        o = func_02188CB4((struct Obj00020 *)w[1]);
        func_021A3074((void *)o);
        func_021A30A4(o, 3);
        func_021CD440((void *)w[1], &id);
        func_02012374((struct Evt *)a, (struct Evt **)func_02184FD4((void *)w[0], id));
        (*seq)++;
        break;
    case 3:
        func_0216D410(func_021A3074(func_02188CB4((struct Obj00020 *)w[1])), 8);
        (*seq)++;
        break;
    case 4:
        if (func_0216D454(func_021A3074(func_02188CB4((struct Obj00020 *)w[1])))) {
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D2358(u32 a, int *seq, int *w)
{
    u32 s, r6, r7, r4;

    s = func_02188D38((unsigned char *)w[1]);
    switch (*seq) {
    case 0:
        func_020061E4(0x63C);
        w[3] = 0x18;
        if (w[2]) {
            r6 = func_02188C64((unsigned char *)w[1]);
            r7 = (u32)func_021C7260(w[1], 0x14, 3);
            r4 = (u32)func_021C71D4(w[1], 0xc, 3);
            func_021C6DE0((unsigned char *)s, (u32 *)r7, 0);
            func_021C6DE0((unsigned char *)s, (u32 *)r4, r7);
            func_021A01FC((unsigned char *)r6, 0x7F0F, func_021A01D4((unsigned char *)r6), 0x1A);
        }
        (*seq)++;
        break;
    case 1:
        func_021A30A4(func_02188CB4((struct Obj00020 *)w[1]), 2);
        (*seq)++;
        break;
    case 2:
        w[3]--;
        if (w[3] > 0) {
            break;
        }
        func_02012374((struct Evt *)a, func_02184F88((void *)w[0]));
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
