/*
 * function: func_021B8CB0
 * address:  0x021B8CB0
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the +0x20 handle and the +0x10 object, then the whole record.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_021BA01C  0x021BA01C  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_020307B0(void *p);
extern void func_021BA01C(char *p);

void func_021B8CB0(void *a0, char *a1)
{
    func_020307B0(*(void **)(a1 + 0x20));
    func_021BA01C(*(void **)(a1 + 0x10));
    func_020307B0(a1);
}
