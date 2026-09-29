/*
 * function: func_021A2F60
 * address:  0x021A2F60
 * packet:   pkt_ov021_021A2F60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov021 listing): tail-calls
 * func_021A3CE8 with the word at offset 4.  Callee of func_0218B32C.
 *
 * symbols:
 *   func_021A3CE8  0x021A3CE8  thumb
 * Addresses are Black-image addresses.
 */

extern void func_021A3CE8(int a);

void func_021A2F60(int *p)
{
    func_021A3CE8(p[1]);
}
