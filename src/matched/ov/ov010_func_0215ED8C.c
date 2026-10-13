/*
 * function: MOVE_POKEMON_CheckDig
 * address: 0x0215ED8C
 * packet: pkt_ov010_0215ED8C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MOVE_POKEMON_IsSkillUsable 0x0215F104 thumb ov010
 */
extern int MOVE_POKEMON_IsSkillUsable(int a0, int a1);
typedef enum { FALSE, TRUE } Bool;
int MOVE_POKEMON_CheckDig(void *p)
{
    return MOVE_POKEMON_IsSkillUsable((int)p, 7) != 0 ? FALSE : TRUE;
}
