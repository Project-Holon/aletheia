/*
 * function: func_021BCDC0
 * address:  0x021BCDC0
 * packet:   pkt_021BCDC0
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Reconstructed from the listing; byte-correct, capped at MATCH*.
 *
 * The THM_CALL at +0x2 to func_02165C48 (a Thumb leaf in asm/overlays/
 * ov009.s, reached as bl 0x02165C48 from ov032) has no witness outside
 * this range: it carries no func_ label in its home listing, so there is
 * nothing for the `label` class to trace, and two overlapping overlays
 * (ov009, ov010) hold the address -- a region hint cannot choose one
 * without a label.  Blocked on `label`/`sole-ref/code` evidence.
 *
 * The original selects case 0x15 before 0x14: reversing the two source
 * case labels flips the fall-through to put the default arm last, which is
 * the only shape that reproduces the image's three-exit if-chain.
 *
 * symbols:
 *   func_02165C48  0x02165C48  thumb  ov009
 *
 * Addresses are Black-image addresses.
 */

extern int func_02165C48(void);

int func_021BCDC0(void)
{
    switch (func_02165C48()) {
    case 0x15:
        return 0;
    case 0x14:
        return 1;
    default:
        return 2;
    }
}
