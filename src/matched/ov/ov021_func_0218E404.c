/*
 * function: func_0218E404
 * address:  0x0218E404
 * packet:   pkt_ov021_0218E404
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Mirror of func_0218E358 with the two halves swapped.
 *
 * symbols:
 *   func_0218F1BC  0x0218F1BC  thumb  ov021
 *   func_0218F1DC  0x0218F1DC  thumb  ov021
 *   func_0218E2B4  0x0218E2B4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } V;

extern void func_0218F1BC(void *a, void *b);
extern void func_0218F1DC(void *a, void *b);
extern void func_0218E2B4(V *a, V *out, int i, int j, int e);

void func_0218E404(u8 *a)
{
    int i;

    *(V *)(a + 0x3C) = *(V *)(a + 0x24);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1DC(a + 0x88 + i * 0x18, a + 0x3C);
        }
    }
    func_0218E2B4((V *)(a + 0x3C), (V *)(a + 0x48), *(u16 *)(a + 0x7A), *(u16 *)(a + 0x78), *(int *)(a + 0x7C));
    *(V *)(a + 0x54) = *(V *)(a + 0x48);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1BC(a + 0x88 + i * 0x18, a + 0x54);
        }
    }
}
