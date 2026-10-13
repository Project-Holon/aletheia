/*
 * function: MOVE_POKEMON_CheckSurf
 * address: 0x0215EB4C
 * packet: pkt_ov010_0215EB4C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MOVE_POKEMON_IsSkillUsable 0x0215F104 thumb ov010
 */
extern int MOVE_POKEMON_IsSkillUsable(int a0, int a1);
typedef enum { B_FALSE, B_TRUE } Bool;
int MOVE_POKEMON_CheckSurf(void *p)
{
    return MOVE_POKEMON_IsSkillUsable((int)p, 2) != 0 ? B_FALSE : B_TRUE;
}
