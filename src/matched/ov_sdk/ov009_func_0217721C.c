/*
 * function: DWCs_GetRequiredHeaderSize
 * address:  0x0217721C
 * packet:   pkt_ov009_0217721C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_GetRequiredHeaderSize (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCi_NodeInfoList_GetCount  0x0217603C arm
 */

extern int DWCi_NodeInfoList_GetCount(void);

long DWCs_GetRequiredHeaderSize(unsigned short type)
{
    int clientCount;

    switch (type) {
    case 2:
        return 0x24;
    case 3:
        return 0x0c;
    case 4:
        clientCount = DWCi_NodeInfoList_GetCount();
        return (clientCount - 1 == 0) ? 0x10 : (clientCount - 1) * 0x18 + 0x10;
    default:
        return 8;
    }
}
