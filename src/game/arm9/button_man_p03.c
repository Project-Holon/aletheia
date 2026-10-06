/*
 * file:     button_man_p03.c
 * unit:     yes
 * function: func_02051A2C, func_02051A34, func_02051A3C, func_02051A54, func_02051AA0, func_02051AB8, func_02051B04, func_02051B0C, func_02051B84, func_02051C58, func_02051C6C
 * address:  0x02051A2C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_020A8140   0x020A8140  data
 *   g_02146A88   0x02146A88  data
 *   g_020A8148   0x020A8148  data
 *   func_0207E1F8  0x0207E1F8  arm
 *   func_0207E24C  0x0207E24C  arm
 *   func_0207E2A0  0x0207E2A0  arm
 *   func_0207E330  0x0207E330  arm
 *   func_0207E22C  0x0207E22C  arm
 *   func_0207E280  0x0207E280  arm
 *   func_0207E2F0  0x0207E2F0  arm
 *   func_0207E388  0x0207E388  arm
 *   func_02030734   0x02030734  arm
 *   func_020307B0   0x020307B0  arm
 *   g_020A7FCC      0x020A7FCC  data
 */
#include "../../matched/include/Obj16192.h"
#include "../../matched/include/Obj16193.h"
#include "../../matched/include/Obj11459.h"
#include "../../matched/include/Obj11460.h"
#include "../../matched/include/Obj16194.h"
#include "../../matched/include/Obj08875.h"
#include "../../matched/include/Obj16196.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Ctx {
    u8   pad_00[0x44];
    u8  *base;      /* 0x44 */
};

typedef struct S02051B84 {
    u8 *f00;
    int f04;
    int f08;
    int f0c;
    int f10;
} S02051B84;

extern u32 func_020616CC(u32 size, u32 flag, u32 dir);
extern void *func_0207E1F8(void);
extern void *func_0207E24C(void);
extern void *func_0207E2A0(void);
extern void *func_0207E330(void);
extern int func_0207E22C(void);
extern int func_0207E280(void);
extern void *func_0207E2F0(void);
extern void *func_0207E388(void);
extern void *func_02030734(u16 id, u32 size, u32 flags, void *file, u32 line);
extern u32 func_020307B0(void *p);
void func_02051A2C(void *p, int v);
int func_02051A34(void *p);
unsigned int func_02051A3C(int a0, int a1, int a2, int a3);
u32 func_02051A54(u32 a, u32 b);
int func_02051AA0(int a, int b);
u32 func_02051AB8(u32 a, u32 b);
u16 func_02051B04(void *res);
int func_02051B0C(int i);
void *func_02051B84(u8 *a0, int a1, int a2, int a3);
void func_02051C58(void *p0);
void func_02051C6C(void *p);
extern struct Ctx *g_02146A88;
extern int g_020A7FCC;


/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte store helper,
 * `p[0x94/4] = v`. The +0x94 twin of func_02051A24.
 *
 * Addresses are Black-image addresses.
 */
void func_02051A2C(void *p, int v)
{
    ((struct Obj16192 *)p)->f94 = v;
}


/*
 * Unlabelled ARM leaf in the ARM9 module: an 8-byte load helper,
 * `return p[0x94/4]`. The getter half of func_02051A2C.
 *
 * Addresses are Black-image addresses.
 */
int func_02051A34(void *p)
{
    return ((struct Obj16193 *)p)->f94;
}

unsigned int func_02051A3C(int a0, int a1, int a2, int a3){ int t0 = func_020614D4((int)a0, (int)a1, (int)0); return ((unsigned int)((t0 << 0x10)) >> 0xd); }


extern u32 (*g_020A8140)(u32 a, u32 b, u32 c);


/*
 * The caller's registered handler (the function pointer in the clact.c global
 * 0x020A8140) is invoked with the two incoming arguments and a literal 0 in
 * r2; r1 is never written, so the callee takes at least two arguments and the
 * third is a constant zero.
 *
 * The result is appended to the current context's u32 table: the count
 * halfword at base+0x25c is loaded once, incremented and stored back, and the
 * value is written to base+0x58+count*4 - the store uses the OLD count, so the
 * table is indexed before the increment.  The return value is the low
 * halfword of the result scaled by eight, which the compiler writes as the
 * fused unequal shift pair lsl #16 / lsr #13 (a u16 cast folded into the
 * multiply, see
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 *
 * The twin at 0x02051AB8 is the same shape over the parallel table 0x100
 * higher (count at +0x25e, elements at +0x158).
 */
u32 func_02051A54(u32 a, u32 b)
{
    u32 v = g_020A8140(a, b, 0);
    u8 *base = g_02146A88->base;
    u16 n = ((struct Obj11459 *)base)->f25C;

    ((struct Obj11459 *)base)->f25C = n + 1;
    *(u32 *)(base + 0x58 + n * 4) = v;

    return (u16)v * 8;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051AA0.c \
 *       --func func_02051AA0 --addr 0x02051AA0 --cc 1.1p1 --arm
 */
int func_02051AA0(int a, int b)
{
    return (u16)func_020616CC(a, b, 1) << 3;
}


extern u32 (*g_020A8148)(u32 a, u32 b, u32 c);


/*
 * Byte-for-byte the twin of func_02051A54 over the second table: same
 * indirect call through the handler at 0x020A8140 (two arguments forwarded,
 * a literal 0 in r2), same append-and-count shape, but the count halfword is
 * at base+0x25e and the elements at base+0x158, i.e. the parallel table 0x100
 * bytes higher with its own counter.
 */
u32 func_02051AB8(u32 a, u32 b)
{
    u32 v = g_020A8148(a, b, 0);
    u8 *base = g_02146A88->base;
    u16 n = ((struct Obj11460 *)base)->f25E;

    ((struct Obj11460 *)base)->f25E = n + 1;
    *(u32 *)(base + 0x158 + n * 4) = v;

    return (u16)v * 8;
}


/*
 * ARM leaf, seeded 2026-09-27 from the ov195 call site 0x02208954
 * (func_0220887C). Returns the u16 at +8 of its argument.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02051B04(void *res)
{
    return ((struct Obj16194 *)res)->f8;
}


/*
 * Eight-way dispatch on a button-man handler id: each of the eight ids tail
 * calls its own handler and returns that handler's value, and any id above 7
 * falls out of the switch to `return 0;`.  That trailing `return 0;` is what
 * the image has at +0x7C (`mov r0, #0; pop {r3, pc}`) and it is also the
 * addls-skipped target at +0x0C, so the `switch` has no `default:` label at
 * all - writing the arms as bare calls (or with `break`) instead of
 * `return f();` loses those eight bytes and the arms' `pop {r3, pc}` with
 * them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051B0C.c \
 *       --func func_02051B0C --addr 0x02051B0C --cc 1.1p1 --arm
 */
int func_02051B0C(int i)
{
    switch (i) {
    case 0: return (int)func_0207E1F8();
    case 1: return (int)func_0207E24C();
    case 2: return (int)func_0207E2A0();
    case 3: return (int)func_0207E330();
    case 4: return func_0207E22C();
    case 5: return func_0207E280();
    case 6: return (int)func_0207E2F0();
    case 7: return (int)func_0207E388();
    }
    return 0;
}


void *func_02051B84(u8 *a0, int a1, int a2, int a3)
{
    S02051B84 *r;
    int i = 0;
    unsigned j;

    while (i < 0xff) {
        if (a0[i * 4] == 0xff) {
            break;
        }
        i++;
    }
    r = (S02051B84 *)func_02030734((u16)a3, 0x14, 0, &g_020A7FCC, 0x6b);
    if (r != 0) {
        r->f00 = a0;
        r->f04 = i;
        r->f08 = a1;
        r->f0c = a2;
        r->f10 = (int)func_02030734((u16)a3, i * 4, 0, &g_020A7FCC, 0x73);
        if (r->f10 != 0) {
            for (j = 0; j < i; j++) {
                func_02051C58((void *)(r->f10 + j * 4));
            }
        } else {
            func_020307B0(r);
            r = 0;
        }
    }
    return r;
}


void func_02051C58(void *p0){ ((struct Obj08875 *)p0)->f0 = (unsigned char)0; ((struct Obj08875 *)p0)->f1 = (unsigned char)0; ((struct Obj08875 *)p0)->f2 = (unsigned short)0; }


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051C6C.c \
 *       --func func_02051C6C --addr 0x02051C6C --cc 1.1p1 --arm
 */
void func_02051C6C(void *p)
{
    func_020307B0((void *)((struct Obj16196 *)p)->f10);
    func_020307B0(p);
}
