/*
 * function: PM_AppendPreExitCallback
 * address:  0x0273154C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_02732FA4 0x02732FA4 data
 *   func_0208C6FC 0x0208C6FC arm
 */

typedef struct PMiGenCallbackInfo PMiGenCallbackInfo;
extern PMiGenCallbackInfo *d_02732FA4;
extern void func_0208C6FC(PMiGenCallbackInfo **listp, PMiGenCallbackInfo *info, int priority, int method);

void PM_AppendPreExitCallback(PMiGenCallbackInfo *info)
{
    func_0208C6FC(&d_02732FA4, info, 0xFF, 0);
}
