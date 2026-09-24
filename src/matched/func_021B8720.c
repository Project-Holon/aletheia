/*
 * function: func_021B8720
 * address:  0x021B8720
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Registers a 1-word/1-word record at a1[0xee..0xef] when the helper rejects the
 * request.
 *
 * symbols:
 *   func_021B8740  0x021B8740  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int func_021B8740(void *a0, void *a1, int a2, u32 a3);

void func_021B8720(void *a0, u32 *a1, u32 a2)
{
    if (func_021B8740(a0, a1, 2, a2) == 0) {
        a1[0xee] = 1;
        a1[0xef] = a2;
    }
}
