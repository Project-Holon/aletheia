/*
 * function: MOVE_POKEMON_SetCommonArea
 * address:  0x0215E428
 * packet:   pkt_0215E428
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MOVE_POKEMON_HasActiveEntry  0x0215E404  thumb  ov010
 *   MOVE_POKEMON_SAVE_SetCommonArea  0x0200D45C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int MOVE_POKEMON_HasActiveEntry(int a0);
extern int MOVE_POKEMON_SAVE_SetCommonArea();

void MOVE_POKEMON_SetCommonArea(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = MOVE_POKEMON_HasActiveEntry(a0);
loc_0215E432:
    if (a0 == 0) goto loc_0215E43E;
loc_0215E436:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = MOVE_POKEMON_SAVE_SetCommonArea(a0, a1);
loc_0215E43E:
    return;}
