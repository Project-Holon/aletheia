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

typedef unsigned char u8;
typedef short s16;

typedef struct {
    u8 pad00[0x2d];
    u8 f2d;
} Obj;

extern void *func_02188CB4(int a);
extern int func_0217BB20(void *ctx);
extern void func_0217F074(void *ctx);
extern int func_0217F060(u8 v);
extern int func_0217FE44(int a, int mode, unsigned *out);
extern void func_021750B0(void *w, int v);
extern int func_0217B8E4(void *ctx, int v);
extern void func_0217BAF0(void *ctx, int a, int v);
extern int func_0217FEF4(void *w);
extern int func_0217FF14(int a);
extern unsigned func_020362DC(void);
extern void func_021A3460(void *a, s16 *x, s16 *y, s16 *z);
extern int func_021679A4(int a0, int a1, int a2, int a3, int *a4, int *a5);

int func_0217DEA0(void *ctx, Obj *obj, int a2, u8 *state)
{
    u8 *w = *(u8 **)((u8 *)ctx + 0x355c);
    void *a;
    int m;
    unsigned out;
    int k;
    s16 v[3];

    a = func_02188CB4(a2);
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
        if (func_0217FF14(a2) == 1) {
            func_0217B8E4(ctx, 0x31);
            func_0217BAF0(ctx, a2, 1);
            return 1;
        }
        if (func_020362DC() & 1) {
            k = 0;
            func_021A3460(a, &v[2], &v[1], &v[0]);
            if (func_021679A4(*(int *)w, v[2], v[1], v[0], &m, &k) == 1) {
                w[0x16c] = m;
                func_0217B8E4(ctx, 0x33);
                func_0217BAF0(ctx, a2, 1);
                return 1;
            }
        }
    }
    return 0;
}
