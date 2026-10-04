/*
 * function: func_0218E4B0
 * address:  0x0218E4B0
 * packet:   pkt_ov021_0218E4B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Copies +0x24 to +0x3c and +0x48 to +0x54, updating the children after each.
 *
 * symbols:
 *   func_0218F1BC  0x0218F1BC  thumb  ov021
 *   func_0218F1DC  0x0218F1DC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef struct { int x, y, z; } V;

typedef unsigned int   u32;
extern void func_0218F1BC(u32 *a, u32 b);
extern void func_0218F1DC(u32 *a, u32 b);
extern void func_0218E2B4(V *a, V *out, int i, int j, int e);

void func_0218E4B0(u8 *a)
{
    int i;

    *(V *)(a + 0x3C) = *(V *)(a + 0x24);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1DC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x3C));
        }
    }
    *(V *)(a + 0x54) = *(V *)(a + 0x48);
    if (a[0xE9] != 0) {
        for (i = 0; i < a[0xE8]; i++) {
            func_0218F1BC((u32 *)(a + 0x88 + i * 0x18), (u32)(a + 0x54));
        }
    }
}
