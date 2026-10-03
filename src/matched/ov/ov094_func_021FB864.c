/*
 * function: func_021FB864
 * address:  0x021FB864
 * packet:   pkt_ov094_021FB864
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: passes slot arg of the table at 0xcc and a value to func_02201DA0.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F86F0 0x021F86F0 thumb ov094
 *   func_02201DA0 0x02201DA0 thumb ov094
 */
extern int func_0201134C(void *);
extern void *func_021F86F0(void);
typedef unsigned int   u32;
extern u32 func_02201DA0(char *p, int i, int v);

int func_021FB864(void *a, char *s)
{
    int i = func_0201134C(a);
    int x = func_0201134C(a);

    func_02201DA0(func_021F86F0(), ((int *)(s + 0xcc))[i], x);
    return *(int *)(s + 0x23c);
}
