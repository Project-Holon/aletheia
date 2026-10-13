/*
 * function: MOVE_POKEMON_IsSkillBlocked
 * address:  0x0215EA14
 * packet:   pkt_0215EA14
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MOVE_POKEMON_GetSkillCheckFunc  0x0215F088  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int MOVE_POKEMON_GetSkillCheckFunc(u16 *p, int i);

int MOVE_POKEMON_IsSkillBlocked(int a0, int a1)
{
    int a2;
    int t4;

a2 = a0 + 0;
t4 = a1 + 0;
a0 = t4 + 0;
a1 = a2 + 0;
    a0 = MOVE_POKEMON_GetSkillCheckFunc((u16 *)a0, a1);
loc_0215EA22:
a1 = a0 + 0;
    if (a1 != 0) goto loc_0215EA2A;
loc_0215EA26:
a0 = 1;
    return a0;
loc_0215EA2A:
a0 = t4 + 0;
    a0 = ((int (*)())a1)(a0);
loc_0215EA2E:
    return a0;}
