/*
 * function: EL_SCOREBOARD_GetFadeInDuration
 * address: 0x02187D40
 * packet: pkt_ov020_02187D40
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   EL_SCOREBOARD_GetMode 0x02187D20 thumb ov020
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 EL_SCOREBOARD_GetMode(char *);
int EL_SCOREBOARD_GetFadeInDuration(char *p)
{
    if (EL_SCOREBOARD_GetMode(p) == 1) return 30;
    return 10;
}
