/*
 * function: PM_SetAmp
 * address:  0x0208BEF0
 * packet:   pkt_0208BEF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PM_SetAmp.
 *
 * symbols:
 *   g_02153000   0x02153000  data  a4
 *   PMi_SetAmp   0x0208BF08  arm
 */

extern int g_02153000[];

unsigned int PMi_SetAmp(unsigned int status);

unsigned int PM_SetAmp(unsigned int status)
{
    g_02153000[6] = status;
    return PMi_SetAmp(status);
}
