/*
 * function: WriteSlotInfo
 * address:  0x02058634
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
extern int NCFG_WriteBackupMemory(int index, void *buf, unsigned long size);

int WriteSlotInfo(void *buf, int index)
{
    return NCFG_WriteBackupMemory(index, buf, 256) != -1;
}
