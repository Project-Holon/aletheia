/*
 * function: func_0208C848
 * address:  0x0208C848
 * packet:   pkt_0208C848
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PMi_InsertPostSleepCallbackEx (libspi.TWL.HYB.a pm.o)
 *
 * symbols:
 *   PMi_PostSleepCallbackList      0x0215301C  data
 *   PMi_InsertList                 0x0208C6FC  arm
 */

struct PMiGenCallbackInfo;

extern struct PMiGenCallbackInfo *PMi_PostSleepCallbackList;

void PMi_InsertList(struct PMiGenCallbackInfo **listp, struct PMiGenCallbackInfo *info, int priority, int method);

void func_0208C848(struct PMiGenCallbackInfo *info, int priority)
{
    PMi_InsertList(&PMi_PostSleepCallbackList, info, priority, 0);
}
