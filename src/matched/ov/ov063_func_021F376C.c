/*
 * function: func_021F376C
 * address:  0x021F376C
 * packet:   pkt_ov063_021F376C
 * region:   ov063
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * True when the state word at +0 is 9 (done). Region ov063: its caller ov021
 * func_021C4788 frees the handle through ov063 func_021F3758 (EXACT, the
 * function immediately before this one) and then unloads overlay 0x3F (ov063);
 * ov063 holds this Thumb leaf at the address, and the state machine right after
 * it (0x021F377C) switches on the same word with 9 as its last case. ov061's
 * func_021F376C is an unrelated function in another overlay (wave A1 witness).
 * Addresses are Black-image addresses.
 */

int func_021F376C(int *p)
{
    if (*p == 9) {
        return 1;
    }
    return 0;
}
