/*
 * file:     net_state_p35.c
 * unit:     yes
 * function: func_0203E484, func_0203E4E8
 * address:  0x0203E484
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   str_020A7D34  0x020A7D34  data
 *   str_020A7D4C  0x020A7D4C  data
 *   func_02034714 0x02034714  arm
 *   func_0203DAC4 0x0203DAC4  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   g_021469F0     0x021469F0  data
 */
typedef unsigned char u8;

typedef unsigned int  u32;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0203DAC4(const u8 *mac);
extern int func_0203CEAC(int a0);
void func_0203E484(u32 a, u32 b, int *p);
u32 func_0203E4E8(void);
extern const u8 str_020A7D34[];
extern const u8 str_020A7D4C[];
extern u8  *g_021469F0;


/*
 *           --suggest-split offers nothing (single function, the one
 *           unresolved site's only witness is inside this range).
 *           the file string at 0x020A7D34 ("net_irq_wireless.c") ends at
 *           0x020A7D46, six bytes before this message, so the `string` class
 *           refuses. Every concrete byte of the body reproduces (the register
 *           choice for the loop bound and the index is fixed by declaring the
 *           index first).
 */
void func_0203E484(u32 a, u32 b, int *p)
{
    int i;
    int n;

    if (p[0] >= 4) {
        func_02034714((const char *)str_020A7D34, 0x2a5, (const char *)str_020A7D4C);
    }
    n = p[0];
    if (n > 4) {
        n = 4;
    }
    for (i = 0; i < n; i++) {
        func_0203DAC4((u8 *)(p + 1) + i * 8);
    }
}


/*
 * Gated state step: only a context whose +0x109 state is 0x10 advances, and
 * it does so by seeding +0x107 from +0x108, re-entering the sub-state and
 * parking the state byte at 9.  The final store re-reads the global, because
 * the call in between may have replaced the context pointer - the same
 * reload the store-after-a-call shape produces.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203E4E8.c \
 *       --func func_0203E4E8 --addr 0x0203E4E8 --cc 1.1p1 --arm
 */
u32 func_0203E4E8(void)
{
    u8 *p = g_021469F0;

    if (p == 0)
        return 0;
    if (p[0x109] != 0x10)
        return 0;
    p[0x107] = p[0x108] + 1;
    func_0203CEAC(0);
    g_021469F0[0x109] = 9;
    return 1;
}
