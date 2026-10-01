/*
 * function: func_021F0044
 * address:  0x021F0044
 * packet:   pkt_ov034_021F0044
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * True when the state word at +0x128 is 3.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * func_021F0058 / func_021F00BC, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */

int func_021F0044(int *p)
{
    if (p[0x4A] == 3) {
        return 1;
    }
    return 0;
}
