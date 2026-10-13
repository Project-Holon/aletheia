/*
 * function: BTL_MAIN_IsRecordAllowed
 * address: 0x021BA20C
 * packet: pkt_ov093_021BA20C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: switch preserves two equality tests; logical OR folds to a range check.
 * symbols:
 *   BTL_MAIN_IsCommCompetitor 0x021B6818 thumb ov093
 *   BTL_MAIN_IsRecordEnabledInComm 0x021BA1EC thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 */
extern unsigned int BTL_MAIN_IsCommCompetitor(unsigned int *p);
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
extern BOOL BTL_MAIN_IsRecordEnabledInComm(char **);
extern void *BTL_MAIN_GetCompetitor(void ***);
int BTL_MAIN_IsRecordAllowed(char **p)
{
    int v;
    if (BTL_MAIN_IsCommCompetitor((unsigned int *)((int *)*p)) == 1) return BTL_MAIN_IsRecordEnabledInComm(p);
    v = (int)BTL_MAIN_GetCompetitor((void ***)p);
    switch (v) {
    case 0:
    case 1: return 1;
    default: return 0;
    }
}
