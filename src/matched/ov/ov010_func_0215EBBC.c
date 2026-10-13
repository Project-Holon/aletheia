/*
 * function: MOVE_POKEMON_CheckStrength
 * address: 0x0215EBBC
 * packet: pkt_ov010_0215EBBC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MOVE_POKEMON_IsSkillUsable 0x0215F104 thumb ov010
 */
extern int MOVE_POKEMON_IsSkillUsable(int a0, int a1);
typedef enum { B_FALSE, B_TRUE } Bool;
int MOVE_POKEMON_CheckStrength(void *p)
{
    return MOVE_POKEMON_IsSkillUsable((int)p, 3) != 0 ? B_FALSE : B_TRUE;
}
