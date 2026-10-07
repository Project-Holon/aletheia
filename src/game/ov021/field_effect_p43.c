/*
 * file:     field_effect_p43.c
 * unit:     yes
 * function: func_021ABA3C, func_021ABABC
 * address:  0x021ABA3C
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
 *   func_021AB764  0x021AB764  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021AB760  0x021AB760  thumb
 *   func_0218E124  0x0218E124  thumb
 *   func_021ABBA0  0x021ABBA0  thumb
 *   FX_Div         0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0218ED34  0x0218ED34  thumb
 *   func_0218ED48  0x0218ED48  thumb
 *   func_0218ED58  0x0218ED58  thumb
 */
#include "../../matched/include/Obj00757.h"

typedef unsigned short u16;

typedef struct { int x; int y; int z; } V;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef long long s64;

extern u32 func_021AB764(u8 *p);
extern u32 func_02188CFC(u8 *p);
extern u32 func_021AB760(u8 *p);
extern void func_0218E124(u8 *a, u32 s);
extern void func_021ABBA0(const u16 *r, void *v, int *o1, int *o2);
extern int FX_Div(int a, int b);
extern void func_0218ED34(u8 *p, u16 v);
extern void func_0218ED48(u8 *p, u32 v);
extern void func_0218ED58(u8 *p, u32 v);
int func_021ABA3C(int a, const u16 *r, V *v);
/* * const on p lets the three loads from p schedule above the store of t to the * address-taken d (docs/idioms/a-const-parameter-hoists-field-loads-above-a- * call-result-store-into-an-address-taken-local.md). One reused temporary v * keeps the quotient on the left of each add and stops x and y being * forward-substituted into their calls; z, the last, is. */ void func_021ABABC(int a0, const u16 *p, void *q);


/*
 * Lever: `const u16 *r` sinks the t.z spill store below the first shift pair
 * (const on the vector source alone does not).
 */
int func_021ABA3C(int a, const u16 *r, V *v)
{
    V t;
    u16 px;
    u16 pz;
    int w;
    int h;

    if (func_02188CFC((u8 *)func_021AB764((u8 *)a)) == 1)
        return 0;
    t = *v;
    t.x -= 0x8000;
    t.z -= 0x8000;
    px = (t.x >> 12) / 16;
    pz = (t.z >> 12) / 16;
    w = r[2];
    if (w == 1) {
        w = r[4];
        h = r[3];
    } else {
        h = r[4];
    }
    if (px >= r[0] && px < r[0] + w && pz >= r[1] && pz < r[1] + h)
        return 1;
    return 0;
}


/*
 * const on p lets the three loads from p schedule above the store of t to the
 * address-taken d (docs/idioms/a-const-parameter-hoists-field-loads-above-a-
 * call-result-store-into-an-address-taken-local.md). One reused temporary v
 * keeps the quotient on the left of each add and stops x and y being
 * forward-substituted into their calls; z, the last, is.
 */
void func_021ABABC(int a0, const u16 *p, void *q)
{
    int h = func_021AB760((u8 *)a0);
    int s;
    int d;
    int t;
    int x, y, z;
    int v;

    func_0218E124((u8 *)h, 0);
    func_021ABBA0(p, q, &s, &d);
    d = t = FX_Div(d, s);
    v = p[10] - p[6];
    v = v * t / 4096;
    x = v + p[6];
    v = p[11] - p[7];
    v = v * t / 4096;
    y = v + p[7];
    v = *(const int *)&((struct Obj00757 *)p)->f18 - *(const int *)&((struct Obj00757 *)p)->f10;
    v = (int)(((s64)v * t + 0x800) >> 12);
    z = v + *(const int *)&((struct Obj00757 *)p)->f10;
    func_0218ED34((u8 *)h, x);
    func_0218ED48((u8 *)h, (u16)y);
    func_0218ED58((u8 *)h, z);
}
