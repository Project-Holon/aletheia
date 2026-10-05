/*
 * function: func_021F0108
 * address:  0x021F0108
 * packet:   pkt_ov034_021F0108
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears the flag at +0x110 that func_021F00BC sets.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * func_021F0058 / func_021F00BC, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */

void func_021F0108(int *p)
{
    p[0x44] = 0;
}
