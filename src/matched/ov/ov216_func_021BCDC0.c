/*
 * function: func_021BCDC0
 * address:  0x021BCDC0
 * packet:   pkt_021BCDC0
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unblocked by matching GAME_BEACON_ACCESSOR_GetPmVersion (ov010, EXACT): the +0002 call site now
 * attests as `matched`.  ov009 holds ARM code at that address; ov010 is the
 * coherent Thumb leaf, so the correct hint is ov010 (the earlier ov009 hint
 * was wrong).
 *
 * The original selects case 0x15 before 0x14: reversing the two source
 * case labels flips the fall-through to put the default arm last, which is
 * the only shape that reproduces the image's three-exit if-chain.
 *
 * symbols:
 *   GAME_BEACON_ACCESSOR_GetPmVersion  0x02165C48  thumb  ov010
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int GAME_BEACON_ACCESSOR_GetPmVersion(void *a0);

int func_021BCDC0(void *a0)
{
    switch (GAME_BEACON_ACCESSOR_GetPmVersion(a0)) {
    case 0x15:
        return 0;
    case 0x14:
        return 1;
    default:
        return 2;
    }
}
