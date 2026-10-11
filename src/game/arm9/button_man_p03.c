/*
 * file:     button_man_p03.c
 * unit:     yes
 * function: func_0205841C
 * address:  0x0205841C
 * packet:   pkt_020583CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p -proc arm7tdmi
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146A8C     0x02146A8C  data
 *   func_0207CCA4  0x0207CCA4  arm
 */

typedef int fx32;

struct VecFx32 {
    volatile fx32 x;
    volatile fx32 y;
    volatile fx32 z;
};

extern int g_02146A8C;
extern void func_0207CCA4(const struct VecFx32 *src, struct VecFx32 *dst);

void func_0205841C(struct VecFx32 *v)
{
    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    v->x = g_02146A8C >> 8;
    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    v->y = g_02146A8C >> 8;
    v->z = 0;
    func_0207CCA4(v, v);
}

void func_02058478(struct VecFx32 *v)
{
    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    v->x = g_02146A8C >> 8;
    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    v->y = g_02146A8C >> 8;
    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    v->z = g_02146A8C >> 8;
    func_0207CCA4(v, v);
}
