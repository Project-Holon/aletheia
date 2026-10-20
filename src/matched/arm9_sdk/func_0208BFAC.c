/*
 * function: PM_GetBatteryLevel
 * address:  0x0208BFAC
 * packet:   pkt_0208BFAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PM_GetBatteryLevel.
 *
 * symbols:
 *   OS_IsRunOnTwl          0x02085D3C  arm
 *   PMi_GetBatteryLevelCore   0x027313AC  arm
 */

int OS_IsRunOnTwl(void);
typedef unsigned int u32;
typedef unsigned short u16;
u32 PMi_GetBatteryLevelCore(u16 *levelBuf);

u32 PM_GetBatteryLevel(u16 *levelBuf)
{
    if (OS_IsRunOnTwl()) {
        return PMi_GetBatteryLevelCore(levelBuf);
    }
    return 2;
}
