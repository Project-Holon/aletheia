/*
 * unit: yes
 * function: func_021FF024, func_021FF070
 * address: 0x021FF024
 * packet: pkt_ov135_021FF024
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FFBC8 0x021FFBC8 thumb ov135
 */
extern unsigned func_021F4D14(void *);
extern void func_021F4CE4(void *);
extern void func_021F4EC0(void *, unsigned, unsigned);
extern void func_021FFBC8(void *);
int func_021FF024(char *p)
{
    unsigned r = func_021F4D14(p);
    if (r == 1) {
        func_021F4CE4(p);
        *(int *)(p + 0x28) = 2;
        func_021F4EC0(p, 1, 0);
        if (*(int *)(p + 0xd0) > 0) func_021FFBC8(p);
        *(int *)(p + 0xd0) = 0;
    } else if (r == 2) {
        func_021F4CE4(p);
        *(int *)(p + 0x28) = 0;
    }
    return 2;
}
int func_021FF070(char *p)
{
    *(int *)(p + 0x28) = 1;
    return 2;
}
