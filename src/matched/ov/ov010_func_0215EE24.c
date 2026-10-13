/*
 * function: MOVE_POKEMON_CheckTeleport
 * address: 0x0215EE24
 * packet: pkt_ov010_0215EE24
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Enum constants preserve the zero-first return arm; int constants fold to the opposite polarity.
 * symbols:
 *   MOVE_POKEMON_IsSkillUsable 0x0215F104 thumb ov010
 */
extern int MOVE_POKEMON_IsSkillUsable(int a0, int a1);
typedef enum { FALSE, TRUE } Bool;
int MOVE_POKEMON_CheckTeleport(void *p)
{
    return MOVE_POKEMON_IsSkillUsable((int)p, 6) != 0 ? FALSE : TRUE;
}
