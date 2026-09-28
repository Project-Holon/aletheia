/*
 * function: DWCs_GetOutgoingBufferFreeSize
 * address:  0x02177E64
 * packet:   pkt_ov009_02177E64
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_GetOutgoingBufferFreeSize (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCi_GetGT2Connection             0x0216BAF4 arm
 *   gt2GetOutgoingBufferFreeSpace     0x02195E50 arm
 */

extern void *DWCi_GetGT2Connection(unsigned char aid);
extern int gt2GetOutgoingBufferFreeSpace(void *connection);

int DWCs_GetOutgoingBufferFreeSize(unsigned char aid)
{
    int free = gt2GetOutgoingBufferFreeSpace(DWCi_GetGT2Connection(aid));

    free += 0xfffffdf9;
    if (free <= 0)
        free = 0;
    return free;
}
