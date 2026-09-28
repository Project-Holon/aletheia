/*
 * function: func_021F37BC
 * address:  0x021F37BC
 * packet:   pkt_ov057_021F37BC
 * region:   ov057
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_02046F50  0x02046F50  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 */

extern int func_02047738(int);
extern int func_0204762C(int);
extern int func_02047504(int);
extern int func_02046F50(int, int);
extern int func_020470D0(int);
extern int func_02046EFC(int);

void func_021F37BC(int a, int b, char *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_02047738(*(int *)(p + i * 4 + 0x38));
    for (i = 0; i < 4; i++)
        func_0204762C(*(int *)(p + i * 4 + 0x28));
    for (i = 0; i < 3; i++)
        func_02047504(*(int *)(p + i * 4 + 0x1c));
    for (i = 0; i < 7; i++) {
        if (func_02046F50(*(int *)(p + i * 4), 2))
            func_020470D0(*(int *)(p + i * 4));
        func_02046EFC(*(int *)(p + i * 4));
    }
}
