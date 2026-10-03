/*
 * function: func_021E18CC
 * address: 0x021E18CC
 * packet: pkt_ov137_021E18CC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 */
typedef unsigned int   u32;
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *, unsigned);
extern unsigned func_02017E1C(void *, unsigned, unsigned);
int func_021E18CC(void *p)
{
    int n;
    int i;
    void *m;
    n = func_0201AA18(p);
    for (i = 0; i < n; i++) {
        m = func_0201AB28(p, i);
        if (func_02017E1C(m, 0x4c, 0) != 0 && func_02017E1C(m, 3, 0) != 0)
            return 1;
    }
    return 0;
}
