/*
 * function: func_0217DEA0
 * address:  0x0217DEA0
 * packet:   pkt_ov019_0217DEA0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_0217FE44  0x0217FE44  thumb  ov019
 *   func_021750B0  0x021750B0  thumb  ov012
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_0217BAF0  0x0217BAF0  thumb  ov019
 *   func_0217FEF4  0x0217FEF4  thumb  ov019
 *   func_0217FF14  0x0217FF14  thumb  ov019
 *   func_020362DC  0x020362DC  arm
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_021679A4  0x021679A4  thumb  ov010
 */
#include "../include/Obj12527.h"
#include "../include/Obj19419.h"

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj;

extern void *func_02188CB4(unsigned char *p);
extern int func_0217BB20(char *p);
extern void func_0217F074(void *ctx);
extern int func_0217F060(int i);
extern int func_0217FE44(int a, int mode, unsigned *out);
extern void func_021750B0(void *w, int v);
extern int func_0217B8E4(char *p, char v);
extern void func_0217BAF0(char *p, int x, unsigned int v);
extern int func_0217FEF4(u8 *p);
extern int func_0217FF14(void *a);
extern u32 func_020362DC(void);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern int func_021679A4(void *a0, int a1, int a2, int a3, int a4, int a5);

int func_0217DEA0(void *ctx, Obj *obj, int a2, u8 *state)
{
    u8 *w = *(u8 * *)&((struct Obj19419 *)ctx)->f355C;
    void *a;
    int m;
    unsigned out;
    int k;
    s16 v[3];

    a = func_02188CB4((void *)a2);
    if (func_0217BB20(ctx) == 1) {
        func_0217F074(ctx);
        return 1;
    }

    if (*state == 0) {
        if (func_0217FE44(a2, func_0217F060(obj->f2d), &out) == 1) {
            func_021750B0(w, out);
            func_0217B8E4(ctx, 0x2b);
            func_0217BAF0(ctx, a2, 1);
            return 1;
        }
        if (func_0217FEF4(w) == 1) {
            func_0217B8E4(ctx, 0x32);
            func_0217BAF0(ctx, a2, 1);
            return 1;
        }
        if (func_0217FF14((void *)a2) == 1) {
            func_0217B8E4(ctx, 0x31);
            func_0217BAF0(ctx, a2, 1);
            return 1;
        }
        if (func_020362DC() & 1) {
            k = 0;
            func_021A3460((u32)a, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
            if (func_021679A4((void *)(((struct Obj12527 *)w)->f0), v[2], v[1], v[0], (int)(&m), (int)(&k)) == 1) {
                w[0x16c] = m;
                func_0217B8E4(ctx, 0x33);
                func_0217BAF0(ctx, a2, 1);
                return 1;
            }
        }
    }
    return 0;
}
