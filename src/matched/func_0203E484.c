/*
 * function: func_0203E484
 * address:  0x0203E484
 * packet:   pkt_0203E484
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *           --suggest-split offers nothing (single function, the one
 *           unresolved site's only witness is inside this range).
 * blocker:  str_020A7D4C (string) -- no witness outside 0203E484..0203E4E8;
 *           the file string at 0x020A7D34 ("net_irq_wireless.c") ends at
 *           0x020A7D46, six bytes before this message, so the `string` class
 *           refuses. Every concrete byte of the body reproduces (the register
 *           choice for the loop bound and the index is fixed by declaring the
 *           index first).
 * symbols:
 *   str_020A7D34  0x020A7D34  data
 *   str_020A7D4C  0x020A7D4C  data
 *   func_02034714 0x02034714  arm
 *   func_0203DAC4 0x0203DAC4  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 str_020A7D34[];
extern const u8 str_020A7D4C[];
extern void func_02034714(const u8 *file, int line, const u8 *msg);
extern void func_0203DAC4(void *p);

void func_0203E484(u32 a, u32 b, int *p)
{
    int i;
    int n;

    if (p[0] >= 4) {
        func_02034714(str_020A7D34, 0x2a5, str_020A7D4C);
    }
    n = p[0];
    if (n > 4) {
        n = 4;
    }
    for (i = 0; i < n; i++) {
        func_0203DAC4((u8 *)(p + 1) + i * 8);
    }
}
