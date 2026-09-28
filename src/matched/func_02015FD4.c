/*
 * function: func_02015FD4
 * address:  0x02015FD4
 * packet:   pkt_02015FD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor, the follower of func_02015FBC: a 9-bit field at
 * bit 14 of the word at +0x140. Labelled so that func_02015FBC's extent ends
 * at its own bx lr. Addresses are Black-image addresses.
 *
 * symbols:
 *   func_02015FD4  0x02015FD4  thumb
 */

void func_02015FD4(char *p, int v)
{
    *(int *)(p + 0x140) = (*(int *)(p + 0x140) & 0xFF803FFF) | ((v & 0x1FF) << 14);
}
