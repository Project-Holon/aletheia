/*
 * function: func_021BD404
 * address:  0x021BD404
 * packet:   pkt_ov208_021BD404
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Linear search of the 0x38-byte records at +0x28 for the record whose key
 * (via 0x021BD7F8) equals the second argument; returns the record address or 0.
 * Blocker target of func_021BD43C.
 *
 * PARKED DIFF: the loop-bound read (re-read each iteration in the image) and
 * the i / base register pairing do not reproduce; compiled 52 vs 54 bytes with
 * the guard already folded differently.  No shard written.
 *
 * symbols:
 *   func_021BD7F8  0x021BD7F8  thumb  ov208
 * Addresses are Black-image addresses.
 */

extern int func_021BD7F8(int p);

int func_021BD404(int a0, int a1)
{
    unsigned int i;

    if (*(unsigned int *)(a0 + 4) == 0)
        return 0;
    for (i = 0; i < *(unsigned int *)(a0 + 4); i++) {
        if (func_021BD7F8(a0 + 0x28 + i * 0x38) == a1)
            return a0 + 0x28 + i * 0x38;
    }
    return 0;
}
