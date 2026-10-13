/*
 * function: MOVE_POKEMON_CheckCut
 * address:  0x0215EA58
 * packet:   pkt_0215EA58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MOVE_POKEMON_IsSkillUsable  0x0215F104  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int MOVE_POKEMON_IsSkillUsable(int a0, int a1);

int MOVE_POKEMON_CheckCut(int a0, int a1)
{
    int t4;

a1 = 0;
t4 = 0;
    a0 = MOVE_POKEMON_IsSkillUsable(a0, a1);
loc_0215EA62:
    if (a0 != 0) goto loc_0215EA68;
loc_0215EA66:
t4 = 1;
loc_0215EA68:
a0 = t4 + 0;
    return a0;}
