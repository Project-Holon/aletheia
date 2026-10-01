/*
 * function: func_021F00F0
 * address:  0x021F00F0
 * packet:   pkt_ov034_021F00F0
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When the halfword counter at +0x124 reaches 10, clears the flag at +0x110
 * (set by func_021F00BC) and returns true.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * func_021F0058 / func_021F00BC, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

int func_021F00F0(char *p)
{
    if (*(u16 *)(p + 0x124) == 10) {
        *(int *)(p + 0x110) = 0;
        return 1;
    }
    return 0;
}
