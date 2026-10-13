/*
 * function: EL_SCOREBOARD_UpdateFade
 * address: 0x02187A10
 * packet: pkt_ov020_02187A10
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EL_SCOREBOARD_GetMode 0x02187D20 thumb ov020
 *   EL_SCOREBOARD_UpdateFadeShared 0x02187A38 thumb ov020
 *   EL_SCOREBOARD_UpdateFadeStandalone 0x02187B38 thumb ov020
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 EL_SCOREBOARD_GetMode(char *);
extern void EL_SCOREBOARD_UpdateFadeShared(const char *, int);
extern void EL_SCOREBOARD_UpdateFadeStandalone(char *, int);
void EL_SCOREBOARD_UpdateFade(char *p, int st)
{
    switch (EL_SCOREBOARD_GetMode(p)) {
    case 0: EL_SCOREBOARD_UpdateFadeShared(p, st); break;
    case 1: EL_SCOREBOARD_UpdateFadeStandalone(p, st); break;
    }
}
