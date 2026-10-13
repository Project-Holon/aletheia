/*
 * function: PM_ReadyToExit
 * address:  0x027314F0
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PMi_CallPostExitCallbackAndReset 0x027315E0 arm
 */

extern void PMi_CallPostExitCallbackAndReset(int flag);

void PM_ReadyToExit(void)
{
    PMi_CallPostExitCallbackAndReset(1);
}
