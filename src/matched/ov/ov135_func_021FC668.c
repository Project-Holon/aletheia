/*
 * function: func_021FC668
 * address: 0x021FC668
 * packet: pkt_ov135_021FC668
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * spelling: if/else keeps the first arm before the second compare; switch moved both compares ahead.
 * symbols:
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FCBF0 0x021FCBF0 thumb ov135
 *   func_0201F7A8 0x0201F7A8 thumb
 */
extern unsigned func_021F4D14(void *p);
extern void func_021F4CE4(void *p);
extern void func_021F4EC0(void *p, unsigned a, unsigned b);
extern void func_021FCBF0(void *p);
extern void func_0201F7A8(void *p, unsigned kind);
int func_021FC668(char *p)
{
    unsigned r;
    r = func_021F4D14(p);
    if (r == 1) {
        func_021F4CE4(p);
        *(int *)(p + 0x28) = 2;
        *(int *)(p + 0xeb4) = 1;
        func_021F4EC0(p, 7, 8);
        func_021FCBF0(p);
    } else if (r == 2) {
        func_021F4CE4(p);
        *(int *)(p + 0x28) = 0;
        func_0201F7A8(*(void **)(p + 0xd40), 0);
        func_021FCBF0(p);
    }
    return 2;
}
