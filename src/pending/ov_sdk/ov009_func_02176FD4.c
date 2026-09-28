/*
 * function: DWC_SendReliableBitmap
 * address:  0x02176FD4
 * packet:   pkt_ov009_02176FD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWC_SendReliableBitmap (libdwcmatch.TWL.HYB.a dwc_transport.o)
 * symbols:
 *   DWC_GetMyAID     0x0216B838 arm
 *   DWC_SendReliable 0x02176E90 arm
 */

extern unsigned char DWC_GetMyAID(void);
extern int DWC_SendReliable(unsigned char aid, void *buffer, int size);

unsigned long DWC_SendReliableBitmap(unsigned long bitmap, void *buffer, int size)
{
    unsigned long aidbit;
    unsigned char aid;

    for (aid = 0; aid < 32; aid++) {
        aidbit = 1UL << aid;
        if (aid == 0)
            aidbit = 1;
        if ((bitmap & aidbit) == 0)
            continue;
        if (aid == DWC_GetMyAID())
            continue;
        if (DWC_SendReliable(aid, buffer, size) == 0)
            bitmap &= ~aidbit;
    }
    return bitmap;
}
