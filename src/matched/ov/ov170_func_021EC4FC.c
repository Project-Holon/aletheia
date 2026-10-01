/*
 * function: func_021EC4FC
 * address: 0x021EC4FC
 * packet: pkt_ov170_021EC4FC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_020185F4 0x020185F4 thumb
 *   func_021EC45C 0x021EC45C thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 */
extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *, unsigned);
extern void *func_020185F4(void *);
extern void func_021EC45C(unsigned char *, void *, int);
extern void func_021EC000(char *, int, int);
void func_021EC4FC(unsigned char *p)
{
    unsigned n = func_0201AA18(*(void **)(*(char **)p + 8));
    unsigned i;
    for (i = 0; i < n; i++) {
        func_021EC45C(p, func_020185F4(func_0201AB28(*(void **)(*(char **)p + 8), i)),
                       *(unsigned char *)(*(char **)(p + 0x2C) + i + 0x3DF0));
        func_021EC000(*(char **)(p + 0x2C), *(unsigned char *)(*(char **)(p + 0x2C) + i + 0x3DF0), 0);
    }
}
