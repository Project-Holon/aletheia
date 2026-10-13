/*
 * function: NET_WHPIPE_ReleaseEntry
 * address:  0x02177BF4
 * packet:   pkt_ov014_02177BF4
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call thunk (ldr r3,[pc]; bx r3) to NET_WHPIPE_ReleaseEntrySlot.
 * Sole blocker of the GAME_BEACON_SEARCH_PickBestScanResult / GAME_BEACON_SEARCH_PollScanResult MATCHes (ov010).
 *
 * symbols:
 *   NET_WHPIPE_ReleaseEntrySlot  0x02177BAC  thumb ov014
 *
 * Addresses are Black-image addresses.
 */

extern void NET_WHPIPE_ReleaseEntrySlot(unsigned int idx);

void NET_WHPIPE_ReleaseEntry(unsigned int idx)
{
    NET_WHPIPE_ReleaseEntrySlot(idx);
}
