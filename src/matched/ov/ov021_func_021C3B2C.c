/*
 * function: func_021C3B2C
 * address:  0x021C3B2C
 * packet:   pkt_ov021_021C3B2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021C3BB0  0x021C3BB0  thumb  ov021
 *   d_021DA960     0x021DA960  data  ov021  a4
 */

typedef unsigned int u32;

typedef struct { u32 a, b, c; } E;
typedef struct { E e[12]; } T;

extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern int func_021C3BB0(u32 a);
extern T d_021DA960;

void func_021C3B2C(u32 *p, u32 *q)
{
    T t = d_021DA960;
    int i;
    u32 r5, r3;
    u32 x = func_021C3BB0((u32)p);

    i = 0;
    func_02017E1C((void *)x, 5, 0);
    func_02017E1C((void *)x, 6, 0);
    r5 = func_02017E1C((void *)p[0], 6, 0);
    r3 = func_02017E1C((void *)p[1], 6, 0);
    for (; i < 12; i++) {
        if (*q == t.e[i].a && r5 != t.e[i].b && r3 != t.e[i].b) {
            *q = t.e[i].c;
            return;
        }
    }
}
