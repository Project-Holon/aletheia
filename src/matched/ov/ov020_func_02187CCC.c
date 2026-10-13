/*
 * function: EL_SCOREBOARD_AdvanceState
 * address: 0x02187CCC
 * packet: pkt_ov020_02187CCC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   EL_SCOREBOARD_GetNextState 0x02187BBC thumb ov020
 *   EL_SCOREBOARD_EnterState 0x02187C20 thumb ov020
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int EL_SCOREBOARD_GetNextState(char *, int);
extern void EL_SCOREBOARD_EnterState(char *, int *, int);
void EL_SCOREBOARD_AdvanceState(char *p, int *s)
{
    int st;
    st = EL_SCOREBOARD_GetNextState(p, *s);
    if (*s != st) EL_SCOREBOARD_EnterState(p, s, st);
}
