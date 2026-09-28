/*
 * function: DWCi_BACKUPlRead
 * address:  0x02058770
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

int DWCi_BACKUPlRead(void *mem)
{
    return ReadSlotInfo(mem, 0, 4);
}
