/*
 * file:     fldeff_ripple_p01.c
 * unit:     yes
 * function: func_021C3670, func_021C36B0, func_021C36EC, func_021C37F8, func_021C385C, func_021C3898, func_021C38DC
 * address:  0x021C3670
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
 *   func_02017E1C  0x02017E1C  thumb
 *   d_021DA8D8     0x021DA8D8  data  ov021  a4
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BCEC  0x0200BCEC  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_0200BCB8  0x0200BCB8  thumb
 *   func_021C34C4  0x021C34C4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_021C38F4  0x021C38F4  thumb  ov021
 *   func_02012F98  0x02012F98  thumb
 *   func_02007C34  0x02007C34  thumb
 */
#include "../../matched/include/Obj03142.h"

struct Ctx;
struct Sub02007AC8Entry;
typedef unsigned int u32;

typedef struct { u32 v[4]; } T4;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    u32 f0;
    u32 f4;
    void *box;
    u16 steps;
} S;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02017E1C(void *, u32, u32);
extern int func_0200BCA8(void *e, int i);
extern void func_0200BCEC(void *e, int i, int j);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern int func_0200BCB8(void *e);
extern u32 func_02005728(u32 v);
extern u8 func_021C34C4(void **p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u32 func_0200BC2C(u32, int);
extern void func_021C38F4(u16 heap, void *b, void *c, u32 m0, u32 m1, void *mon);
extern u32 func_02007C34(u32, u32);
extern struct Sub02007AC8Entry *func_02012F98(void *p);
int func_021C3670(void *a, u32 b);
void func_021C36B0(void *e);
int func_021C36EC(u32 a, u32 b);
int func_021C37F8(u32 a, u32 b);
int func_021C385C(S *p);
void func_021C3898(u32 *p, u32 c);
int func_021C38DC(u32 a, u32 b);
extern const T4 d_021DA8D8;


/*
 * Addresses are Black-image addresses.
 */
int func_021C3670(void *a, u32 b)
{
    T4 t = d_021DA8D8;
    int i;

    for (i = 0; i < 4; i++) {
        if (b == func_02017E1C(a, t.v[i], 0))
            return 1;
    }
    return 0;
}


/*
 * Compacts the two day-care slots so occupied ones come first.
 */
void func_021C36B0(void *e)
{
    int i, j;

    for (i = 0; i < 2; i++) {
        if (func_0200BCA8(e, i) == 1)
            continue;
        for (j = i + 1; j < 2; j++) {
            if (func_0200BCA8(e, j) == 1)
                func_0200BCEC(e, j, j - 1);
        }
    }
}


/*
 * Breeding compatibility of two party Pokemon (egg groups 0x18/0x19,
 * Ditto 0x84, gender 0x6E). EXACT* only for the 2-byte pad before
 * func_021C37F8. The last test is spelled as the negated conjunction
 * returning 0, so the fall-through is the call.
 */
int func_021C36EC(u32 a, u32 b)
{
    u32 sp[2];
    u32 fm[2];
    u32 gd[2];
    u32 g1[2];
    u32 g2[2];
    u32 m[2];
    int i;

    m[0] = a;
    m[1] = b;
    for (i = 0; i < 2; i++) {
        sp[i] = func_02017E1C((void *)m[i], 5, 0);
        func_02017E1C((void *)m[i], 7, 0);
        fm[i] = func_02017E1C((void *)m[i], 0x6f, 0);
        gd[i] = func_02017E1C((void *)m[i], 0x6e, 0);
        g1[i] = func_02019C90(sp[i], fm[i], 0x18);
        g2[i] = func_02019C90(sp[i], fm[i], 0x19);
    }
    if (g1[0] == 0xf || g1[1] == 0xf || g2[0] == 0xf || g2[1] == 0xf)
        return 0;
    if (sp[0] == 0x84 && sp[1] == 0x84)
        return 0;
    if (sp[0] == 0x84 || sp[1] == 0x84)
        return func_021C37F8(a, b);
    if (gd[0] == gd[1])
        return 0;
    if (gd[0] == 2 || gd[1] == 2)
        return 0;
    if (g1[0] != g1[1] && g1[0] != g2[1] && g2[0] != g1[1] && g2[0] != g2[1])
        return 0;
    return func_021C37F8(a, b);
}


int func_021C37F8(u32 a, u32 b)
{
    u32 x[2];
    u32 y[2];
    u32 m[2];
    int i;

    m[0] = a;
    m[1] = b;
    for (i = 0; i < 2; i++) {
        x[i] = func_02017E1C((void *)m[i], 5, 0);
        y[i] = func_02017E1C((void *)m[i], 7, 0);
    }
    if (x[0] != x[1]) {
        if (y[0] == y[1])
            return 0x14;
        return 0x32;
    }
    if (y[0] == y[1])
        return 0x32;
    return 0x46;
}


/*
 * Step counter: every 16 steps rolls for an egg against compatibility (EXACT*: pad).
 */
int func_021C385C(S *p)
{
    u16 old = p->steps;

    p->steps = old + 0x10;
    if (old > 0xFF) {
        p->steps = 0;
        if (func_0200BCB8(p->box) >= 2) {
            u32 r = func_02005728(0x640);
            if (r < func_021C34C4((void **)p))
                return 1;
        }
    }
    return 0;
}


void func_021C3898(u32 *p, u32 c)
{
    u32 a = (u32)func_02012944(func_020120F4(func_02188C80((void *)p[1])));
    u32 b = func_0200BC2C(p[2], 0);
    u32 d = func_0200BC2C(p[2], 1);

    func_021C38F4(((struct Obj03142 *)p)->f0, (void *)a, (void *)0xEA62, b, d, (void *)c);
}


/*
 * Blocking site: the bl to func_02012F98 at +000C of this function.
 *
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C38DC(u32 a, u32 b)
{
return func_02007C34((u32)func_02012F98((void *)func_020120F4((const struct Ctx *)func_02188C80((void *)a))), b);
}
