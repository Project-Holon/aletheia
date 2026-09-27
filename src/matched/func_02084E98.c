/*
 * function: func_02084E98
 * address:  0x02084E98
 * packet:   pkt_02084E98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_spinLock.o OSi_FreeCardBus (EXMEMCNT bit11 -> ARM7).
 */

void func_02084E98(void)
{
    *(volatile unsigned short *)0x04000204 |= 0x800;
}
