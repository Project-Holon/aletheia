/*
 * function: func_02184E40
 * address:  0x02184E40
 * packet:   pkt_ov020_02184E40
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02014184  0x02014184  thumb
 *   func_02184730  0x02184730  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 */
typedef short s16;
typedef struct { int x, y, z; } Vec;
void *func_020122C0(void *p, int a, void (*cb)(void), unsigned int n);
void *func_020124E8(void *p);
void func_02014184(void *d, int a, s16 b, unsigned int c, unsigned int e, unsigned int f);
void func_02184730(void);
void func_02184CEC(void *obj, void *p);
static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x; d->y = y; d->z = z;
}
void *func_02184E40(void *p, int u, const Vec *v, s16 b, const int *s)
{
    void *r0v = func_020122C0(p, 0, func_02184730, 0x9c);
    char *r4 = func_020124E8(r0v);
    func_02184CEC(r4, p);
    func_02014184(r4 + 0x10, b, 1, s[0], s[1], s[2]);
    vset((Vec *)(r4 + 0x34), v->x, v->y, v->z);
    *(int *)(r4 + 0x2c) = 0;
    return r0v;
}
