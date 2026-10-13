/*
 * function: EL_SCOREBOARD_TeardownDisplay
 * address: 0x02187914
 * packet: pkt_ov020_02187914
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes.
 * symbols:
 *   EL_SCOREBOARD_GetMode 0x02187D20 thumb ov020
 *   EL_SCOREBOARD_TeardownSharedDisplay 0x02187938 thumb ov020
 *   EL_SCOREBOARD_TeardownStandaloneDisplay 0x0218793C thumb ov020
 */
typedef unsigned int u32;
extern u32 EL_SCOREBOARD_GetMode(char *p);
extern void EL_SCOREBOARD_TeardownSharedDisplay(char *p);
extern void EL_SCOREBOARD_TeardownStandaloneDisplay(char *p);
void EL_SCOREBOARD_TeardownDisplay(char *p)
{
    switch (EL_SCOREBOARD_GetMode(p)) {
    case 0: EL_SCOREBOARD_TeardownSharedDisplay(p); break;
    case 1: EL_SCOREBOARD_TeardownStandaloneDisplay(p); break;
    }
}
