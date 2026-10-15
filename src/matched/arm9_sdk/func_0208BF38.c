/*
 * function: PM_SetAmpGain
 * address:  0x0208BF38
 * packet:   pkt_0208BF38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PM_SetAmpGain.
 *
 * symbols:
 *   PM_SendUtilityCommand  0x0208BC8C  arm
 */

typedef unsigned short u16;

unsigned int PM_SendUtilityCommand(unsigned int cmd, u16 param, void *result);

unsigned int PM_SetAmpGain(unsigned int gain)
{
    return PM_SendUtilityCommand(0x11, (u16)gain, 0);
}
