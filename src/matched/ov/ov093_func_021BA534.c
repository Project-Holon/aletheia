/*
 * function: BTL_MAIN_IsCommTrainerBattle
 * address: 0x021BA534
 * packet: pkt_ov093_021BA534
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two bytes are alignment padding at 0x021BA54A.
 * lever: switch preserves two equality tests; logical OR folds to a range check.
 * symbols:
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 */
extern void *BTL_MAIN_GetCompetitor(void ***);
int BTL_MAIN_IsCommTrainerBattle(void ***p)
{
    int v = (int)BTL_MAIN_GetCompetitor(p);
    switch (v) {
    case 2:
    case 3: return 1;
    default: return 0;
    }
}
