/*
 * function: BTL_MAIN_CheckShiftModePrompt
 * address: 0x021B85A8
 * packet: pkt_ov093_021B85A8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: the arm9 witness src/matched/arm9/CONFIG_GetBattleStyle.c exists (EXACT); the only wildcard is that bl, so this lifts to EXACT after the integrator regenerates the manifest/labels.
 * blocker: ARM9 0x020083C8 lacks an outside witness; owner interface reads bit 6 of its input halfword. No embedded blocker C.
 * symbols:
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetCommPos 0x021B86C0 thumb ov093
 *   CONFIG_GetBattleStyle 0x020083C8 thumb
 */
extern void *BTL_MAIN_GetCompetitor(void ***);
extern unsigned int BTL_MAIN_GetRule(void **);
extern unsigned char BTL_MAIN_GetCommPos(unsigned char **);
extern unsigned int CONFIG_GetBattleStyle(void *);
int BTL_MAIN_CheckShiftModePrompt(unsigned char *p) { if (BTL_MAIN_GetCompetitor((void ***)p)==(void *)1 && BTL_MAIN_GetRule((void **)p)==0 && BTL_MAIN_GetCommPos((unsigned char **)p)==0 && CONFIG_GetBattleStyle(*(void **)(*(unsigned char **)p+0x5c))==0) return 1; return 0; }
