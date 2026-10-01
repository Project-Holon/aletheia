/*
 * function: func_021FC70C
 * address: 0x021FC70C
 * packet: pkt_ov135_021FC70C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4E30 0x021F4E30 thumb ov135
 *   func_021F4E64 0x021F4E64 thumb ov135
 *   func_0201F868 0x0201F868 thumb
 *   func_0200ADB4 0x0200ADB4 thumb
 *   func_021F6DE8 0x021F6DE8 thumb ov135
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021FC810 0x021FC810 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FCBF0 0x021FCBF0 thumb ov135
 */
extern int func_021F4E30(void *);
extern void func_021F4E64(void *);
extern void func_0201F868(void *);
extern void *func_0200ADB4(void *);
extern int func_021F6DE8(void *);
extern int func_0201AA18(void *);
extern void func_021FC810(void *, unsigned, unsigned, unsigned, unsigned, void *);
extern void func_021F4E98(void *, unsigned, unsigned);
extern void func_021F4EC0(void *, unsigned, unsigned);
extern void func_021FCBF0(void *);
int func_021FC70C(char *p)
{
    int r;
    void *q;
    r = func_021F4E30(p);
    if (r == 1) {
        func_021F4E64(p);
        func_0201F868(*(void **)(p + 0xde8));
        q = func_0200ADB4(**(void ***)(p));
        if (func_021F6DE8(q) && func_0201AA18(*(void **)(*(char **)p + 8)) == 6) {
            func_021FC810(p, 0x2a, 1, 0, 0xf0f, q);
            func_021F4E98(p, 3, 1);
            return 2;
        }
        func_021FC810(p, 6, 1, 0, 0xf0f, q);
        func_021F4E98(p, 3, 5);
        func_021FCBF0(p);
    } else if (r == 2 || r == -2) {
        func_021F4E64(p);
        func_0201F868(*(void **)(p + 0xde8));
        *(int *)(p + 0x28) = 2;
        func_021F4EC0(p, 1, 0);
        func_021FCBF0(p);
    }
    return 2;
}
