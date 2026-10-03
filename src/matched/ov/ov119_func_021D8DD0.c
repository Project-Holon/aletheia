/*
 * function: func_021D8DD0
 * address: 0x021D8DD0
 * packet: pkt_ov119_021D8DD0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02007A18 0x02007A18 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_020185F4 0x020185F4 thumb
 */

extern void *func_02007A18(void *a, int b, int c, void *p);
extern int func_0201AA18(void *m);
typedef unsigned int   u32;
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_020185F4(void *a);

void *func_021D8DD0(void *a, int b, int c, char *p)
{
    void *m;
    int n;

    if (b != -1) {
        n = *(int *)(p + 0x630);
        if (b > n)
            return 0;
        if (b != n && c != -1)
            return func_02007A18(a, b, c, p);
        m = *(void **)(p + 0x838);
        if (c < func_0201AA18(m) && c != -1)
            return func_020185F4(func_0201AB28(m, c));
    }
    return 0;
}
