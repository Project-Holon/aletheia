/*
 * function: OSi_FreeCartridgeBus
 * address:  0x02084DDC
 * packet:   pkt_02084DDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_spinLock.o OSi_FreeCartridgeBus (EXMEMCNT bit7 -> ARM7).
 */

void OSi_FreeCartridgeBus(void)
{
    *(volatile unsigned short *)0x04000204 |= 0x80;
}
