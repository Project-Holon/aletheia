/*
 * function: func_021BFD34
 * address:  0x021BFD34
 * packet:   pkt_ov021_021BFD34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x7C-byte task and seeds it with a position triple.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BFE2C  0x021BFE2C  thumb  ov021
 */

typedef struct { int x, y, z; } V3;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
struct Obj;
void *func_020124E8(struct Obj *p);
void func_021BFE2C(void);

static inline void V3_Set(V3 *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

void *func_021BFD34(int a0, void *p, int a2, const V3 *v)
{
    void *t = func_020122C0(p, a0, func_021BFE2C, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[8] = 0;
    V3_Set((V3 *)&w[5], v->x, v->y, v->z);
    return t;
}
