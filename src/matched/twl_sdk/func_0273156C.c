/*
 * function: PMi_InsertPostExitCallbackEx
 * address:  0x0273156C
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
 *   func_0208C6FC 0x0208C6FC arm
 */

typedef struct PMiGenCallbackInfo PMiGenCallbackInfo;
extern PMiGenCallbackInfo *PMi_PostExitCallbackList;
extern void func_0208C6FC(PMiGenCallbackInfo **listp, PMiGenCallbackInfo *info, int priority, int method);

void PMi_InsertPostExitCallbackEx(PMiGenCallbackInfo *info, int priority)
{
    func_0208C6FC(&PMi_PostExitCallbackList, info, priority, 0);
}
