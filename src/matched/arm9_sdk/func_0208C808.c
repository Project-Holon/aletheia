/*
 * function: PM_PrependPreSleepCallback
 * address:  0x0208C808
 * packet:   pkt_0208C808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PM_PrependPostSleepCallback.
 *
 * symbols:
 *   g_0215301C     0x0215301C  data  a4
 *   PMi_InsertList 0x0208C6FC  arm
 */

extern int g_0215301C[];

void PMi_InsertList(void *listp, void *info, int priority, int compare);

void PM_PrependPreSleepCallback(void *info)
{
    PMi_InsertList(g_0215301C, info, -255, 1);
}
