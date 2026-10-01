/*
 * function: func_021FB8F4
 * address:  0x021FB8F4
 * packet:   pkt_ov094_021FB8F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: releases slot arg of the table at 0xcc and marks it free.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F86F0 0x021F86F0 thumb ov094
 *   func_02201CA4 0x02201CA4 thumb ov094
 */
extern int func_0201134C(void *);
extern void *func_021F86F0(void);
extern void func_02201CA4(void *, int);

int func_021FB8F4(void *a, char *s)
{
    int *tab = (int *)(s + 0xcc);
    int i = func_0201134C(a);

    func_02201CA4(func_021F86F0(), tab[i]);
    tab[i] = -1;
    return *(int *)(s + 0x23c);
}
