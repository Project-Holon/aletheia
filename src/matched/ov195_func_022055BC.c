/*
 * function: func_022055BC
 * address:  0x022055BC
 * packet:   pkt_022055BC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02205620 0x02205620 thumb ov195
 *   func_02045808 0x02045808 arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02205620(u32, u32, u32, u32, u32, u32, u32);
extern void func_02045808(u32);

void func_022055BC(char *a, u32 a1, u32 a2, u32 k0, u32 v0, u32 k1, u32 v1,
                   u32 b1, u32 b2, u32 m0, u32 w0, u32 m1, u32 w1)
{
    if (*(u32 *)(a + 0x94) != 0)
        func_02045808(*(u32 *)(a + 0x94));
    if (*(u32 *)(a + 0x98) != 0)
        func_02045808(*(u32 *)(a + 0x98));
    *(u32 *)(a + 0x94) = func_02205620(*(u16 *)(a + 2), a1, a2, k0, v0, k1, v1);
    *(u32 *)(a + 0x98) = func_02205620(*(u16 *)(a + 2), b1, b2, m0, w0, m1, w1);
}
