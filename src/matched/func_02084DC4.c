/*
 * function: func_02084DC4
 * address:  0x02084DC4
 * packet:   pkt_02084DC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     os_spinLock.o OSi_AllocateCartridgeBus (EXMEMCNT bit7 -> ARM9).
 */

void func_02084DC4(void)
{
    unsigned int v = *(volatile unsigned short *)0x04000204;

    v &= ~0x80u;
    *(volatile unsigned short *)0x04000204 = (unsigned short)v;
}
