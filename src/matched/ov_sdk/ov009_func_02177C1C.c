/*
 * function: DWCs_RecvDataHeader
 * address:  0x02177C1C
 * packet:   pkt_ov009_02177C1C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_RecvDataHeader (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWCs_GetRecvState  0x021777A4 arm
 *   DWCs_DecodeHeader  0x021771E0 arm
 *   MI_CpuCopy8        0x02082D44 arm
 *   gDwcTransInfo         0x021AB180 data
 */

extern int DWCs_GetRecvState(unsigned char aid);
extern unsigned short DWCs_DecodeHeader(void *message);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern char gDwcTransInfo[];

struct DWCstTransportHeader {
    unsigned long size;
    unsigned short type;
    unsigned short pad;
};

void DWCs_RecvDataHeader(unsigned char aid, void *message, int size)
{
    struct DWCstTransportHeader header;
    char *connection;
    unsigned short type;

    connection = *(char **)gDwcTransInfo + aid * 0x38;
    *(char *)(connection + 0x1e) = DWCs_GetRecvState(aid);
    type = DWCs_DecodeHeader(message);
    switch (type) {
    case 1:
        if (size != 8)
            return;
        MI_CpuCopy8(message, &header, 8);
        {
            unsigned long s = header.size;

            header.size = s;
            *(int *)(connection + 0x18) = s;
        }
        *(int *)(connection + 0x10) = 0;
        if (*(int *)(connection + 4) != 0 &&
            *(int *)(connection + 8) >= *(int *)(connection + 0x18))
            *(char *)(connection + 0x1d) = 2;
        else
            *(char *)(connection + 0x1d) = 4;
        break;
    case 2:
    case 3:
    case 4:
        *(char *)(connection + 0x1d) = 3;
        break;
    }
    *(unsigned short *)(connection + 0x22) = type;
}
