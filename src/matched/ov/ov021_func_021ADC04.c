/*
 * function: func_021ADC04
 * address:  0x021ADC04
 * packet:   pkt_ov021_021ADC04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02047828  0x02047828  arm
 *   func_021AAA4C  0x021AAA4C  thumb  ov021
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_02012A30  0x02012A30  thumb
 *   func_02028ACC  0x02028ACC  thumb
 *   d_021D9234     0x021D9234  data   a1
 *
 * Levers: func_02047828's second parameter is an index (the zero stored to v
 * is passed in r1), not &v; the final call's arguments are named locals with
 * the inner call bound to a local after them, which keeps both loads above
 * the call in callee-saved registers.
 */
#include "../include/Obj05043.h"
#include "../include/Obj19888.h"
typedef unsigned char u8;
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
struct AnmCtl;
struct SoundSys2;
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
struct Self;
extern int func_021AAA4C(struct Self *self, short *out);
extern u16 func_0209C0A4(int a, int b);
struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);
extern void func_02028ACC(struct SoundSys2 *s, u32 id, u32 who);
extern u8 d_021D9234[];

void func_021ADC04(u8 *w, u8 *o)
{
    u16 v;
    int z;
    u8 c;
    u16 k;
    void *x;

    v = 0;
    func_02047828(*(void **)(o + 0x28 + w[0x1c] * 0x18), 0, &z);
    if (z == 0 && func_021AAA4C((struct Self *)(((struct Obj05043 *)w)->f34), (short int *)(&v)) != 0) {
        v = func_0209C0A4(v, 5);
        if (v > 3)
            v = 3;
        c = d_021D9234[v];
        k = ((struct Obj19888 *)o)->f8A;
        x = (void *)func_02012A30(*(void **)(((struct Obj05043 *)w)->f34 + 8));
        func_02028ACC(x, k, c);
    }
}
