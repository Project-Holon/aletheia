/*
 * function: func_021C3670
 * address:  0x021C3670
 * packet:   pkt_ov021_021C3670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   d_021DA8D8     0x021DA8D8  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef struct { u32 v[4]; } T4;

extern u32 func_02017E1C(void *, u32, u32);
extern const T4 d_021DA8D8;

int func_021C3670(void *a, u32 b)
{
    T4 t = d_021DA8D8;
    int i;

    for (i = 0; i < 4; i++) {
        if (b == func_02017E1C(a, t.v[i], 0))
            return 1;
    }
    return 0;
}
