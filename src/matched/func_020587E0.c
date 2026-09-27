/*
 * function: DWCi_BACKUPlSetWiFi
 * address:  0x020587E0
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   Wifi  0x02146A94  data  a4
 *
 * TwlDWC libdwcbm dwc_backup.o.
 */
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);

static unsigned char Wifi[14];

void DWCi_BACKUPlSetWiFi(unsigned char *wifi)
{
    MI_CpuCopy8(wifi, Wifi, 14);
}
