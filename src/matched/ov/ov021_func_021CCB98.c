/*
 * function: func_021CCB98
 * address:  0x021CCB98
 * packet:   pkt_ov021_021CCB98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0204B3B4  0x0204B3B4  arm
 */

typedef unsigned char u8;

extern int func_0201AA18(void *party);
extern void func_0204B3B4(void *p);

void func_021CCB98(u8 *p)
{
    int i;
    int n;

    n = func_0201AA18(*(void **)(p + 4));
    for (i = 0; i < n; i++)
        func_0204B3B4(*(void **)(p + i * 4 + 0x1c));
    if (*(void **)(p + 8)) {
        n = func_0201AA18(*(void **)(p + 8));
        for (i = 0; i < n; i++)
            func_0204B3B4(*(void **)(p + i * 4 + 0x34));
    }
}
