/*
 * file:     unit_02731590.c
 * unit:     yes
 * function: func_02731590, func_027315A8
 * address:  0x02731590
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   PMi_PostExitCallbackList  0x02732FAC  data
 *   PMi_DeleteList  0x0208C788  arm
 *   PMi_ExecuteList           0x0208C7E0  arm
 */
typedef struct PMiGenCallbackInfo PMiGenCallbackInfo;

extern void PMi_DeleteList(PMiGenCallbackInfo **listp, PMiGenCallbackInfo *info);
extern void PMi_ExecuteList(PMiGenCallbackInfo *listp);
void func_02731590(PMiGenCallbackInfo *info);
void func_027315A8(void);
extern PMiGenCallbackInfo *PMi_PostExitCallbackList;


void func_02731590(PMiGenCallbackInfo *info)
{
    PMi_DeleteList(&PMi_PostExitCallbackList, info);
}


/*
 * sdk:      PMi_ExecutePostExitCallbackList (pm.o, .ltdmain; no catalogue row)
 */
void func_027315A8(void)
{
    PMi_ExecuteList(PMi_PostExitCallbackList);
}
