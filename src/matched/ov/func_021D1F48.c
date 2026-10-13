/*
 * function: EVENT_PERAP_RECORD_OnRecorded
 * address:  0x021D1F48
 * packet:   pkt_021D1F48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Completion callback: writes 1 through its second argument.  Referenced
 * only by address from EVENT_PERAP_RECORD_Main's literal pool.
 *
 * Addresses are Black-image addresses.
 */

void EVENT_PERAP_RECORD_OnRecorded(void *unused, int *done)
{
    *done = 1;
}
