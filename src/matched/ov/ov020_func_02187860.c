/*
 * function: EL_SCOREBOARD_SetupDisplay
 * address: 0x02187860
 * packet: pkt_ov020_02187860
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes.
 * symbols:
 *   EL_SCOREBOARD_GetMode 0x02187D20 thumb ov020
 *   EL_SCOREBOARD_SetupSharedDisplay 0x02187884 thumb ov020
 *   EL_SCOREBOARD_SetupStandaloneDisplay 0x021878C0 thumb ov020
 */
typedef unsigned int u32;
extern u32 EL_SCOREBOARD_GetMode(char *p);
extern void EL_SCOREBOARD_SetupSharedDisplay(char *p);
extern void EL_SCOREBOARD_SetupStandaloneDisplay(char *p);
void EL_SCOREBOARD_SetupDisplay(char *p)
{
    switch (EL_SCOREBOARD_GetMode(p)) {
    case 0: EL_SCOREBOARD_SetupSharedDisplay(p); break;
    case 1: EL_SCOREBOARD_SetupStandaloneDisplay(p); break;
    }
}
