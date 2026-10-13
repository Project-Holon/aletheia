/*
 * file:     nns_snd_player_5.c
 * function: func_02072EA8
 * address:  0x02072EA8
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Wave 17 lane untried_small. The tell for the pin is the kept branch: the
 * image returns with `bxeq lr` and runs the body unpredicated, where every
 * dsi front end if-converts the body to 28 bytes (15 out, measured on
 * 1.1p1, 1.2p2, 1.3p1, 1.6sp1). The same cluster's func_02073438 is already
 * measured under ../2.0/sp2. The re-load after the test is the volatile slot.
 */

typedef unsigned int u32;

void func_02072EA8(u32 *volatile *pp)
{
    if (*pp == 0) {
        return;
    }
    **pp = 0;
    *pp = 0;
}
