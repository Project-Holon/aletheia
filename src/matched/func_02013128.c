/*
 * function: func_02013128
 * address:  0x02013128
 * packet:   pkt_02013128
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201AC2C  0x0201AC2C  thumb
 *
 * Unlabelled Thumb thunk in the ARM9 module (zonedata.c). Tail-calls
 * func_0201AC2C (the 0x534-byte container copy in unit_0201AC2C.c,
 * prototype (src, dst)) with the second argument as source and the i-th
 * pointer of the table at +0x24 as destination.
 *
 * Addresses are Black-image addresses.
 */

extern void func_0201AC2C(void *src, void *dst);

void func_02013128(void *p, void *src, int i)
{
    func_0201AC2C(src, ((void **)((char *)p + 0x24))[i]);
}
