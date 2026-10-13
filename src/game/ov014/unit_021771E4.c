/*
 * file:     unit_021771E4.c
 * function: NET_WHPIPE_IsWorkNotAllocated
 * address:  0x021771E4
 * packet:   pkt_ov014_021771E4
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      NET_WHPIPE_IsWorkNotAllocated (libdwcmatch.TWL.HYB.thumb.a(dwc_match.o))
 *
 * symbols:
 *   NET_WHPIPE_IsWorkAllocated  0x02177A94  thumb  ov014
 */

extern int NET_WHPIPE_IsWorkAllocated(void);

int NET_WHPIPE_IsWorkNotAllocated(void)
{
    if (NET_WHPIPE_IsWorkAllocated() == 0)
        return 1;
    return 0;
}
