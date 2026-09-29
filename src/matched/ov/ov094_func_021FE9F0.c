/*
 * function: func_021FE9F0
 * address:  0x021FE9F0
 * packet:   pkt_ov094_021FE9F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the loop counter is an enum (keeps the `cmp r4,#8; bge` entry guard
 * and the unfolded (1<<12)>>1 rounding constants after it), see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 *
 * symbols:
 *   _ll_mul        0x0209C054  arm
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF134  0x021FF134  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_021FF468  0x021FF468  thumb  ov094
 *   func_021FF630  0x021FF630  thumb  ov094
 */
typedef int fx32;
typedef long long fx64;
typedef struct { fx32 x, y, z; } VecFx32;

typedef enum { SLOT_0, SLOT_MAX = 8 } Slot;

extern char *func_021F8694(void);
extern void func_021FF134(char *p, int a, int b);
extern int func_021FFD9C(char *p, int key);
extern int func_021FF468(char *p, int i, int k);
extern void func_021FF630(char *w, int i, int kind, VecFx32 *q, int n, int f48, int f4c);

void func_021FE9F0(fx32 a, fx32 b, int n, int f48, int f4c)
{
    Slot i;
    VecFx32 v;
    fx32 s;
    fx32 t;

    func_021FF134(func_021F8694(), a, b);
    for (i = 0; i < 8; i++) {
        if (func_021FFD9C(func_021F8694(), i)) {
            s = func_021FF468(func_021F8694(), i, 1);
            if (i & 1)
                t = (fx32)(((fx64)s * b + ((fx64)(1 << 12) >> 1)) >> 12);
            else
                t = (fx32)(((fx64)s * a + ((fx64)(1 << 12) >> 1)) >> 12);
            v.x = t;
            v.y = t;
            v.z = 1 << 12;
            func_021FF630(func_021F8694(), i, 1, &v, n, f48, f4c);
        }
    }
}
