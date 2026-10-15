/*
 * function: PMi_SetAmp
 * address:  0x0208BF08
 * packet:   pkt_0208BF08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PMi_SetAmp.
 *
 * symbols:
 *   PM_GetLCDPower         0x0208C688  arm
 *   PM_SendUtilityCommand  0x0208BC8C  arm
 */

typedef unsigned short u16;

int PM_GetLCDPower(void);
unsigned int PM_SendUtilityCommand(unsigned int cmd, u16 param, void *result);

unsigned int PMi_SetAmp(unsigned int status)
{
    if (PM_GetLCDPower()) {
        return PM_SendUtilityCommand(0x10, (u16)status, 0);
    }
    return 0;
}
