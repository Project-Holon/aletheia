/*
 * function: func_0208C828
 * address:  0x0208C828
 * packet:   pkt_0208C828
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PM_AppendPostSleepCallback.  Pool word is 0x02153004
 *           (distinct from PM_PrependPostSleepCallback's 0x0215301C); libmatch
 *           may have swapped the two list names.
 *
 * symbols:
 *   g_02153004     0x02153004  data  a4
 *   PMi_InsertList 0x0208C6FC  arm
 */

extern int g_02153004[];

void PMi_InsertList(void *listp, void *info, int priority, int compare);

void func_0208C828(void *info)
{
    PMi_InsertList(g_02153004, info, 255, 0);
}
