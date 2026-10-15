/*
 * function: PM_DeletePreSleepCallback
 * address:  0x0208C86C
 * packet:   pkt_0208C86C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PMi_DeleteList 0x0208C788 arm
 *   g_0215301C 0x0215301C data
 */

struct PMiGenCallbackInfo;
typedef struct PMiGenCallbackInfo PMGenCallbackInfo;
extern void PMi_DeleteList(PMGenCallbackInfo **listp, PMGenCallbackInfo *info);
extern int g_0215301C[];

void PM_DeletePreSleepCallback(PMGenCallbackInfo *info)
{
    PMi_DeleteList((PMGenCallbackInfo **)g_0215301C, info);
}
