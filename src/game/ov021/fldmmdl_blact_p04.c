/*
 * file:     fldmmdl_blact_p04.c
 * unit:     yes
 * function: func_0219C928, func_0219C98C, func_0219C9D0, func_0219C9DC, func_0219C9E0, func_0219CA00, func_0219CA34
 * address:  0x0219C928
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
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219C6B8  0x0219C6B8  thumb  ov021
 *   func_0219CFB0  0x0219CFB0  thumb  ov021
 *   func_020508D8  0x020508D8  arm
 *   func_02050278  0x02050278  arm
 *   func_02050468  0x02050468  arm
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   d_021D75D0  0x021D75D0  data  a4
 *   func_02030734  0x02030734  arm
 *   d_021DDD70  0x021DDD70  data ov021 a4
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj03118.h"
#include "../../matched/include/Obj09509.h"
#include "../../matched/include/Obj17968.h"
#include "../../matched/include/Obj17969.h"

struct BbActSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } V3;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_0216D520(void *p);
extern int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0219C6B8(u32, V3 *, int, u32, u16);
extern void func_0219CFB0(u32, u32, u16 *, u16 *, u32, u32, u32);
extern u32 func_020508D8(u8 *o, u32 i);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern void *func_0216E3C4(void *p);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32 func_020307B0(void *p);
/* b is const: that is what lets the b[7]/b[9] loads schedule above the * outgoing stack-argument store of v. */ int func_0219C928(u32 a, const u8 *b, u16 *c, V3 *d, u32 s0, u32 s1);
void func_0219C98C(u32 a, u16 *b);
void func_0219C9D0(u32 a, u32 b, u8 *p);
u32 func_0219C9DC(u8 *p);
void func_0219C9E0(u32 a, u16 *x, u16 *y);
void func_0219CA00(u32 *s, u32 n, u32 heap);
void func_0219CA34(u8 *p);
extern u16 d_021D75D0[][2];
extern unsigned char d_021DDD70[];


/* b is const: that is what lets the b[7]/b[9] loads schedule above the
 * outgoing stack-argument store of v. */
/*
 * Addresses are Black-image addresses.
 */
int func_0219C928(u32 a, const u8 *b, u16 *c, V3 *d, u32 s0, u32 s1)
{
    u16 v;
    u32 t = func_0216D520((void *)a);
    func_0219CBD4(t, *(const u16 *)&((struct Obj03118 *)b)->f0, (u32)(&v), (u32)c);
    if (!(*c & 2)) {
        c[1] = func_0219C6B8(a, d, b[7], b[9], v);
        return 1;
    }
    c[1] = 0xFFFF;
    func_0219CFB0(t, 0, (u16 *)b, &c[1], s0, s1, (u32)d);
    return 0;
}


/*
 * Former blocker (now filed in src/matched/arm9): the only unresolved site is the call to func_020508D8
 * (0x020508D8, arm, arm9), an unlabelled arm9 leaf with no witness (Ilias's).
 * Verified C for the leaf (EXACT, dsi/1.1p1 -O4,p --arm --region arm9):
 *     u32 func_020508D8(u8 *o, u32 i)
 *     {
 *         return *(u16 *)(*(u8 **)(o + 0x18) + i * 0x28 + 4);
 *     }
 *
 * Addresses are Black-image addresses.
 */
void func_0219C98C(u32 a, u16 *b)
{
    u8 *c = (u8 *)func_0216D520((void *)a);
    if (b[1] != 0xFFFF) {
        if (b[0] & 2) {
            u32 t = func_020508D8((u8 *)(((struct Obj09509 *)c)->f4), b[1]);
            func_02050278((struct BbActSys *)(((struct Obj09509 *)c)->f4), t, 1);
        }
        func_02050468((struct BbActSys *)(((struct Obj09509 *)c)->f4), b[1], 1);
    }
    b[0] = 0;
    b[1] = 0xFFFF;
}


void func_0219C9D0(u32 a, u32 b, u8 *p)
{
    *p |= 1;
}


/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_0219C9DC(u8 *p)
{
    return ((struct Obj17968 *)p)->f4;
}


void func_0219C9E0(u32 a, u16 *x, u16 *y)
{
    u8 *d = func_0216E3C4((void *)a);
    u16 *t = d_021D75D0[d[7]];
    *x = t[0];
    *y = t[1];
}


void func_0219CA00(u32 *s, u32 n, u32 heap)
{
    u16 *p = (u16 *)func_02030734(heap, n * 8, 1, (const char *)d_021DDD70, 0x484);
    s[0] = n;
    s[1] = (u32)p;
    do {
        p[0] = 0xFFFF;
        p[1] = 0xFFFF;
        p += 4;
    } while (--n);
}


/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CA34(u8 *p)
{
    func_020307B0((void *)(((struct Obj17969 *)p)->f4));
}
