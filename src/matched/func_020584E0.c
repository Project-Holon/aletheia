/*
 * function: DWCi_BM_GetApInfo
 * address:  0x020584E0
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcbm dwc_backup.o.
 */
extern int ReadSlotInfo(void *buf, int offset, unsigned long num);

int DWCi_BM_GetApInfo(void *buf)
{
    return ReadSlotInfo(buf, 0, 3);
}
