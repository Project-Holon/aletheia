/*
 * function: func_021BCDE8
 * address:  0x021BCDE8
 * packet:   pkt_ov091_021BCDE8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD1BC  0x021BD1BC  thumb  ov091
 *   func_021BD504  0x021BD504  thumb  ov091
 *   func_021BD634  0x021BD634  thumb  ov091
 *   func_021BA4F8  0x021BA4F8  thumb  ov091
 */

typedef unsigned char u8;

extern void func_021BD1BC(char *a, int *b);
extern void func_021BD504(char *a);
extern void func_021BD634(char *a);
extern void func_021BA4F8(char *a);

void func_021BCDE8(char *a)
{
    if (*(int *)(*(char **)(a + 0x280) + 0x8C) == 1) {
        switch (*(int *)(*(char **)(a + 0x280) + 0x64)) {
        case 1:
            func_021BD1BC(a, (int *)(*(int *)(a + 0x1F4)));
            break;
        case 2:
            func_021BD1BC(a, (int *)(*(int *)(a + 0x1F0)));
            func_021BD1BC(a, (int *)(*(int *)(a + 0x1F4)));
            func_021BD1BC(a, (int *)(*(int *)(a + 0x1F8)));
            break;
        }
    }
    if (*(u8 *)(a + 0x20C) != *(u8 *)(*(char **)(a + 0x280) + 0x94) && *(u8 *)(a + 0xC) == 2) {
        func_021BD504(a);
        *(u8 *)(a + 0x20C) = *(u8 *)(*(char **)(a + 0x280) + 0x94);
    }
    if (*(int *)(*(char **)(a + 0x280) + 0x90) == 1)
        func_021BD634(a);
    if (*(u8 *)(*(char **)(a + 0x280) + 0x63) == 1)
        func_021BA4F8(a);
}
