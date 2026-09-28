/*
 * function: sub_020395E0
 * address:  0x020395E0
 * packet:   pkt_020393A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clamp a slot index to the sentinel: anything from 8 up becomes 0xff, and
 * everything below passes through untouched.  Twelve bytes, no prologue.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020395E0.c \n *       --func sub_020395E0 --addr 0x020395E0 --cc 1.1p1 --arm
 */

int sub_020395E0(int slot)
{
    if (slot >= 8) {
        slot = 0xFF;
    }
    return slot;
}
