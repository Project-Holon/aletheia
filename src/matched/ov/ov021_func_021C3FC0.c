/*
 * function: func_021C3FC0
 * address:  0x021C3FC0
 * packet:   pkt_ov021_021C3FC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   d_021DA918     0x021DA918  data  ov021  a4
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct { u32 v[6]; } T;

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern T d_021DA918;

void func_021C3FC0(u32 *a, u32 *b)
{
    T t = d_021DA918;
    u32 *pt = t.v;
    int i;

    for (i = 0; i < 6; i++) {
        u32 *e = b + i;

        if (e[0x16] != 0)
            e[6] = func_02017E1C((void *)a[0], pt[i], 0);
        if (e[0x1c] != 0)
            e[6] = func_02017E1C((void *)a[1], pt[i], 0);
    }
}
