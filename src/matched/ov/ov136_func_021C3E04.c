/*
 * function: func_021C3E04
 * address:  0x021C3E04
 * packet:   pkt_ov136_021C3E04
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C3E04 0x021C3E04 thumb
 *   func_021C3E00 0x021C3E00 thumb
 *   func_02017E40 0x02017E40 thumb
 */
typedef unsigned int u32;
extern u32 func_021C3E00(void *);
extern void func_02017E40(void *p, int field, u32 v);
int func_021C3E04(u32 *p, void *q)
{
    if (func_021C3E00(p) == 0) return 0;
    func_02017E40(q, 0xa7, p[5]);
    return 1;
}
