/*
 * function: PM_DeletePostExitCallback
 * address:  0x02731590
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PMi_PostExitCallbackList 0x02732FAC data
 *   PMi_DeleteList 0x0208C788 arm
 */

typedef struct PMiGenCallbackInfo PMiGenCallbackInfo;

extern void PMi_DeleteList(PMiGenCallbackInfo **listp, PMiGenCallbackInfo *info);
extern PMiGenCallbackInfo *PMi_PostExitCallbackList;

void PM_DeletePostExitCallback(PMiGenCallbackInfo *info)
{
    PMi_DeleteList(&PMi_PostExitCallbackList, info);
}
