/*
 * function: func_021E5BE4
 * address:  0x021E5BE4
 * packet:   pkt_ov119_021E5BE4
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 */

extern void func_0204B3B4(int);
extern void func_0204A8D4(int);

void func_021E5BE4(int a)
{
    if (*(int *)(a + 0xf08) != 0)
        func_0204B3B4(*(int *)(a + 0xf08));
    if (*(int *)(a + 0xf0c) != 0)
        func_0204B3B4(*(int *)(a + 0xf0c));
    if (*(int *)(a + 0xf10) != 0)
        func_0204B3B4(*(int *)(a + 0xf10));
    if (*(int *)(a + 0xf14) != 0)
        func_0204B3B4(*(int *)(a + 0xf14));
    *(int *)(a + 0xf08) = 0;
    *(int *)(a + 0xf0c) = 0;
    *(int *)(a + 0xf10) = 0;
    *(int *)(a + 0xf14) = 0;
    if (*(int *)(a + 0x89c) != 0)
        func_0204A8D4(*(int *)(a + 0x89c));
    if (*(int *)(a + 0x8a0) != 0)
        func_0204A8D4(*(int *)(a + 0x8a0));
    *(int *)(a + 0x89c) = 0;
    *(int *)(a + 0x8a0) = 0;
}
