/*
 * function: WMi_DeleteSleepCallback
 * address:  0x0208EA80
 * packet:   pkt_0208EA80
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PM_DeletePreSleepCallback  0x0208C86C  arm
 */

extern void PM_DeletePreSleepCallback(void *);
void WMi_DeleteSleepCallback(void){ PM_DeletePreSleepCallback((void *)0x02153060); }
