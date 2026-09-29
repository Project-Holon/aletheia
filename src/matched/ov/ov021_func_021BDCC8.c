/*
 * function: func_021BDCC8
 * address:  0x021BDCC8
 * packet:   pkt_ov021_021BDCC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BDCC8  0x021BDCC8  thumb
 *   func_021BE184  0x021BE184  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_021BE1A0  0x021BE1A0  thumb  ov021
 *   func_021BDFB0  0x021BDFB0  thumb  ov021
 *   func_021BE068  0x021BE068  thumb  ov021
 *   func_021BDDC0  0x021BDDC0  thumb  ov021
 *   func_021BDEB4  0x021BDEB4  thumb  ov021
 */

extern void func_021BE184(void *a, void *b);
extern void func_0218FEA0(void *a, void *b);
extern int func_021BE1A0(void *a);
extern void func_021BDFB0(void *a);
extern void func_021BE068(void *a);
extern void func_021BDDC0(void *a);
extern void func_021BDEB4(void *a);

void func_021BDCC8(char *a, int *b)
{
    func_021BE184(a, b);
    func_0218FEA0(*(void **)(a + 0x54), a + 8);
    if (func_021BE1A0(a) != 0) {
        switch (b[1]) {
        case 0:
            func_021BDFB0(a);
            break;
        case 1:
            func_021BE068(a);
            break;
        }
    } else {
        switch (b[1]) {
        case 0:
            func_021BDDC0(a);
            break;
        case 1:
            func_021BDEB4(a);
            break;
        }
    }
    *(int *)(a + 0x64) = 1;
}
