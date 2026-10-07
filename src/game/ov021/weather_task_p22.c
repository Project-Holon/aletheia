/*
 * file:     weather_task_p22.c
 * unit:     yes
 * function: func_021A2EB8, func_021A2F20, func_021A2F48, func_021A2F54, func_021A2F60, func_021A2F6C, func_021A2F8C
 * address:  0x021A2EB8
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
 *   func_021A3994  0x021A3994  thumb
 *   func_021A3960  0x021A3960  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02012A90  0x02012A90  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02012AD4  0x02012AD4  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_02012ABC  0x02012ABC  thumb
 *   func_0219E2F4  0x0219E2F4  thumb
 *   func_02012AA4  0x02012AA4  thumb
 *   func_021C0CA4  0x021C0CA4  thumb  ov021
 *   func_021A3CB0  0x021A3CB0  thumb
 *   func_021A3CC0  0x021A3CC0  thumb
 *   func_021A3CE8  0x021A3CE8  thumb
 *   func_021A53D0  0x021A53D0  thumb  ov021
 *   func_021A5A34  0x021A5A34  thumb  ov021
 *   func_021A3AD0  0x021A3AD0  thumb  ov021
 */
#include "../../matched/include/Obj18007.h"
#include "../../matched/include/Obj18008.h"
#include "../../matched/include/Obj19763.h"

struct H4;
struct Rec44;
struct Vec12;
struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u32 func_021A3994(u8 *p);
extern void *func_021A3960(unsigned char *p);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_02012A90(struct Rec44 *p, const struct Vec12 *src);
extern u16 func_0216D5F8(void *p);
extern void func_02012AD4(u8 *p, int i);
extern u32 func_02188CFC(u8 *p);
extern void func_02012ABC(struct Rec44 *p, u8 v);
extern void func_0219E2F4(void *o, void *out);
extern void func_02012AA4(struct Rec44 *p, const struct H4 *src);
int func_021C0CA4(u8 *a, int b, int c, int d);
extern int func_021A3CB0(u32 a, u32 b);
extern int func_021A3CC0(void *p);
extern void func_021A3CE8(int a);
void func_021A53D0(u32 *p);
void func_021A5A34(u32 *p);
extern void func_021A3AD0(u8 *p, u32 v);
void func_021A2EB8(u32 *a);
int func_021A2F20(u32 *p, int a, int b, int c);
void func_021A2F48(u8 *p, u32 a1);
int func_021A2F54(u8 *p);
void func_021A2F60(int *p);
void func_021A2F6C(u32 *p);
void func_021A2F8C(u8 *p, u32 b);


/*
 * Ilias's) has no witness outside this range. Leaf C, verified EXACT
 * with match.py one --thumb --region arm9 (symbols: data_0209DFA8
 * 0x0209DFA8 data a2):
 *   extern const u16 data_0209DFA8[];
 *   void func_02012AD4(u8 *p, int i) { *(u16 *)(p + 0x18) = data_0209DFA8[i]; }
 *
 * Addresses are Black-image addresses.
 */
void func_021A2EB8(u32 *a)
{
    u8 b[12];
    u8 c[8];
    u32 d = func_021A3994((u8 *)a[1]);
    void *e = func_021A3960((u8 *)a[1]);

    func_0216D88C(e, (struct VecFx32 *)b);
    func_02012A90((struct Rec44 *)d, (const struct Vec12 *)b);
    func_02012AD4((u8 *)d, func_0216D5F8(e));
    if (func_02188CFC((u8 *)a[0]) == 0) {
        func_02012ABC((struct Rec44 *)d, 0);
        return;
    }
    func_0219E2F4(e, c);
    func_02012AA4((struct Rec44 *)d, (const struct H4 *)c);
    func_02012ABC((struct Rec44 *)d, 1);
}


int func_021A2F20(u32 *p, int a, int b, int c)
{
    int r = 0;

    if (func_02188CFC((u8 *)p[0]) == 0)
        r = func_021C0CA4((u8 *)p[2], a, b, c);
    return r;
}


/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2F48(u8 *p, u32 a1)
{
    func_021A3CB0(((struct Obj18007 *)p)->f4, a1);
}


int func_021A2F54(u8 *p)
{
    return func_021A3CC0(((struct Obj18008 *)p)->f4);
}


/*
 * Unlabelled leaf (a .word run in the ov021 listing): tail-calls
 * func_021A3CE8 with the word at offset 4.  Callee of func_0218B32C.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2F60(int *p)
{
    func_021A3CE8(p[1]);
}


void func_021A2F6C(u32 *p)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A53D0((u32 *)p[2]);
    else
        func_021A5A34((u32 *)p[3]);
}


/*
 * Tail-call thunk: the object's word at +0x4, second argument forwarded.
 * Unlabelled leaf; its only blocker-caller is func_021C10B4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A2F8C(u8 *p, u32 b)
{
    func_021A3AD0((u8 *)(((struct Obj19763 *)p)->f4), b);
}
