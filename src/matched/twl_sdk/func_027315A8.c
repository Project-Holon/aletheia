/*
 * function: PMi_ExecutePostExitCallbackList
 * address:  0x027315A8
 * packet:   pkt_027315A8
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PMi_ExecutePostExitCallbackList (pm.o, .ltdmain; no catalogue row)
 *
 * symbols:
 *   PMi_PostExitCallbackList  0x02732FAC  data
 *   PMi_ExecuteList           0x0208C7E0  arm
 */

typedef struct PMiGenCallbackInfo PMiGenCallbackInfo;

extern PMiGenCallbackInfo *PMi_PostExitCallbackList;
extern void PMi_ExecuteList(PMiGenCallbackInfo *listp);

void PMi_ExecutePostExitCallbackList(void)
{
    PMi_ExecuteList(PMi_PostExitCallbackList);
}
