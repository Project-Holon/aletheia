/*
 * function: func_0218DF80
 * address:  0x0218DF80
 * packet:   pkt_ov021_0218DF80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Counts how many leading entries fit the width budget.
 *
 * symbols:
 *   func_02169538  0x02169538  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern void func_02169538(int a, int *out);

void func_0218DF80(u8 *a)
{
    int n;
    int i;
    int sum = 0;
    int w;

    *(u8 *)(a + 0x4C) = 0;
    n = *(u8 *)(a + 0x42) - (*(u16 *)(a + 0x2E) - *(u8 *)(a + 0x40));
    if (n > 0) {
        for (i = 0; i < n; i++) {
            u8 *cnt = a + 0x4C;
            int idx = (*(u8 **)(a + 0x44))[i];
            if (idx == 0xFF) break;
            func_02169538(*(int *)(*(u8 **)(a + 0x24) + idx * 0x28), &w);
            sum += w;
            if (*(int *)(a + 0x48) < sum) break;
            *cnt = *cnt + 1;
        }
    }
}
