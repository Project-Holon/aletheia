/*
 * function: func_021AAEC0
 * address:  0x021AAEC0
 * packet:   pkt_ov021_021AAEC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D828  0x0216D828  thumb  ov010
 */

typedef struct Vec3s {
    short x, y, z;
} Vec3s;

typedef struct Self {
    void *ctx;
} Self;

extern void *func_02188CB4(void *p);
extern void *func_021A3074(void *p);
extern void *func_02188C7C(void *p);
extern int func_0216DD1C(void *list, void **out, unsigned long *iter);
extern int func_0216D454(void *rec);
extern unsigned char *func_0216E3C4(void *rec);
extern void func_0216D828(void *rec, Vec3s *out);

int func_021AAEC0(Self *self, int x, short y2, int z, int skip)
{
    Vec3s v;
    void *rec;
    unsigned long it = 0;
    void *list;
    void *cur;
    unsigned char *info;

    cur = func_021A3074(func_02188CB4(self->ctx));
    list = func_02188C7C(self->ctx);
    for (;;) {
        if (!func_0216DD1C(list, &rec, &it))
            break;
        if (!func_0216D454(rec))
            continue;
        if (rec == cur && skip)
            continue;
        info = func_0216E3C4(rec);
        func_0216D828(rec, &v);
        if (y2 != v.y)
            continue;
        if (x < v.x || x >= v.x + info[0xb])
            continue;
        if (z > v.z || z <= v.z - info[0xc])
            continue;
        return 1;
    }
    return 0;
}
