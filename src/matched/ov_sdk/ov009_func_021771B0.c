/*
 * function: DWCs_EncodeHeader
 * address:  0x021771B0
 * packet:   pkt_ov009_021771B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_EncodeHeader (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   strncpy      0x02094860 arm
 *   g_021A2344   0x021A2344 data
 */

extern char g_021A2344[];
extern void strncpy(char *dst, const char *src, int n);

void DWCs_EncodeHeader(void *header, unsigned short type, int size)
{
    char *h = header;

    strncpy(h + 6, g_021A2344, 2);
    *(unsigned short *)(h + 4) = type;
    *(int *)h = size;
}
