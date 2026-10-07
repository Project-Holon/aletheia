/*
 * file:     fldmmdl_blact_p03.c
 * unit:     yes
 * function: func_0219C814, func_0219C880, func_0219C8D4
 * address:  0x0219C814
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219C7EC  0x0219C7EC  thumb  ov021
 *   func_0219CFB0  0x0219CFB0  thumb  ov021
 *   func_020508D8  0x020508D8  arm
 *   func_02050278  0x02050278  arm
 *   func_0216DFC4  0x0216DFC4  thumb  ov010
 *   func_0219CB98  0x0219CB98  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0219D184  0x0219D184  thumb  ov021
 *   func_0219D3B4  0x0219D3B4  thumb  ov021
 *   func_02050468  0x02050468  arm
 */
#include "../../matched/include/Obj00429.h"

struct BbActSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern void *func_0216E3C4(void *p);
extern int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
extern u16 func_0219C7EC(u32, u32);
extern void func_0219CFB0(u32, u32, u16 *, u16 *, u32, u32, u32);
extern u32 func_020508D8(u8 *o, u32 i);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_0216DFC4(void *a, u32 id);
extern void func_0219CB98(u8 *, u32);
extern u16 func_0216D598(void *p);
extern void func_0219D184(int *obj, int key);
extern int func_0219D3B4(u8 *, u32, u16);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
int func_0219C814(u32 a, u16 *b);
void func_0219C880(u8 *o, u32 a, u32 b, u32 c);
void func_0219C8D4(u32 o, u32 a);


int func_0219C814(u32 a, u16 *b)
{
    u32 m = func_0216D520(func_0216D67C((void *)a));
    u16 *p = func_0216E3C4((void *)a);
    u16 loc[2];
    func_0219CBD4(m, *p, (u32)(&loc[1]), (u32)(&loc[0]));
    if (loc[1] != 0xFFFF && (2 & loc[0]) == 0) {
        *b = func_0219C7EC(a, *p);
        return 1;
    }
    *b = 0xFFFF;
    func_0219CFB0(m, a, p, b, 0, 0, 0);
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
void func_0219C880(u8 *o, u32 a, u32 b, u32 c)
{
    u16 v[2];
    if (func_0219CBD4((u32)o, c, (u32)(&v[1]), (u32)(&v[0])) == 1) {
        if (v[0] & 2) {
            u32 t = func_020508D8((u8 *)(((struct Obj00429 *)o)->f4), b);
            func_02050278((struct BbActSys *)(((struct Obj00429 *)o)->f4), t, 1);
        }
        if (v[0] & 1) {
            if (func_0216DFC4((void *)a, c) == 0)
                func_0219CB98(o, c);
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_0219C8D4(u32 o, u32 a)
{
    u32 t = func_0216D598((void *)o);
    u8 *c = (u8 *)func_0216D520(func_0216D67C((void *)o));
    if (a == 0xFFFF) {
        func_0219D184((int *)c, (u32)o);
        return;
    }
    if (func_0219D3B4(c, o, a) != 1) {
        func_0219C880(c, o, (u16)a, t);
        func_02050468((struct BbActSys *)(((struct Obj00429 *)c)->f4), a, 1);
    }
}
