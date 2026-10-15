/*
 * function: PMi_SendLEDPatternCommand
 * address:  0x0208C6A4
 * packet:   pkt_0208C6A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PMi_SendLEDPatternCommand.
 *
 * symbols:
 *   PM_SendUtilityCommand  0x0208BC8C  arm
 */

typedef unsigned short u16;

unsigned int PM_SendUtilityCommand(unsigned int cmd, u16 param, void *result);

unsigned int PMi_SendLEDPatternCommand(unsigned int pattern)
{
    return PM_SendUtilityCommand(0x12, (u16)pattern, 0);
}
