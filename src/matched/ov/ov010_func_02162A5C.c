/*
 * function: func_02162A5C
 * address:  0x02162A5C
 * packet:   pkt_ov010_02162A5C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to func_02162970.  Callee of ov021 func_0218A278.
 *
 * symbols:
 *   func_02162970  0x02162970  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern u16 func_02162970(void *set, void *flags, const void *where, u16 type);

u16 func_02162A5C(void *set, void *flags, const void *where, u16 type)
{
    return func_02162970(set, flags, where, type);
}
