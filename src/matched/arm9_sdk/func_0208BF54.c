/*
 * function: PM_SetAmpGainLevel
 * address:  0x0208BF54
 * packet:   pkt_0208BF54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PM_SetAmpGainLevel.
 *
 * symbols:
 *   PM_SendUtilityCommand  0x0208BC8C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

unsigned int PM_SendUtilityCommand(unsigned int cmd, u16 param, void *result);

unsigned int PM_SetAmpGainLevel(u8 level)
{
    return PM_SendUtilityCommand(0x16, (u16)level, 0);
}
