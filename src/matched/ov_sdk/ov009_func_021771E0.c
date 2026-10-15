/*
 * function: DWCs_DecodeHeader
 * address:  0x021771E0
 * packet:   pkt_ov009_021771E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_DecodeHeader (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   MI_CpuCopy8  0x02082D44 arm
 *   memcmp       0x020923F0 arm
 *   gDwcTransHeaderMagic   0x021A2344 data
 */

extern char gDwcTransHeaderMagic[];
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int memcmp(const void *a, const void *b, unsigned int n);

unsigned short DWCs_DecodeHeader(void *message)
{
    char header[8];

    MI_CpuCopy8(message, header, 8);
    if (memcmp(header + 6, gDwcTransHeaderMagic, 2) == 0)
        return *(unsigned short *)(header + 4);
    return 0;
}
