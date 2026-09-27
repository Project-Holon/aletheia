/*
 * function: DWCi_BM_GetApInfoEx
 * address:  0x020584F4
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
extern int ReadSlotInfoEx(void *buf, int offset, unsigned long num);

int DWCi_BM_GetApInfoEx(void *buf)
{
    if (ReadSlotInfoEx(buf, 0, 3) != 0)
        return 1;
    return 0;
}
