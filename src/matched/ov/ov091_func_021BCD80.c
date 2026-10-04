/*
 * function: func_021BCD80
 * address:  0x021BCD80
 * packet:   pkt_ov091_021BCD80
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD61C  0x021BD61C  thumb  ov091
 *   func_021BD18C  0x021BD18C  thumb  ov091
 *   func_021BD058  0x021BD058  thumb  ov091
 *   func_021BCE9C  0x021BCE9C  thumb  ov091
 */

extern void func_021BD61C(char *a);
extern void func_021BD18C(char *a, char *p);
extern void func_021BD058(char *a);
extern void func_021BCE9C(unsigned int p);

void func_021BCD80(char *a)
{
    if (*(int *)(*(char **)(a + 0x280) + 0x90) == 1)
        func_021BD61C(a);
    if (*(int *)(*(char **)(a + 0x280) + 0x8C) == 1) {
        switch (*(int *)(*(char **)(a + 0x280) + 0x64)) {
        case 1:
            func_021BD18C(a, (char *)(*(int *)(a + 0x1F4)));
            break;
        case 2:
            func_021BD18C(a, (char *)(*(int *)(a + 0x1F0)));
            func_021BD18C(a, (char *)(*(int *)(a + 0x1F4)));
            func_021BD18C(a, (char *)(*(int *)(a + 0x1F8)));
            break;
        }
    }
    func_021BD058(a);
    func_021BCE9C((unsigned int)a);
}
