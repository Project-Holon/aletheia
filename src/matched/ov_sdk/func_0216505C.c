/*
 * function: GAME_BEACON_SEARCH_SetBattlePokeStart
 * address:  0x0216505C
 * packet:   pkt_0216505C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_IsSpecialPokemon  0x0202708C  thumb
 *   GAME_BEACON_SEARCH_SetBattleSpecialPokeStart  0x02165104  thumb  ov010
 *   GAME_BEACON_SEARCH_SetBattleWildPokeStart  0x02165094  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int GAME_BEACON_IsSpecialPokemon();
extern int GAME_BEACON_SEARCH_SetBattleSpecialPokeStart();
extern int GAME_BEACON_SEARCH_SetBattleWildPokeStart();

int GAME_BEACON_SEARCH_SetBattlePokeStart(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = GAME_BEACON_IsSpecialPokemon(a0);
loc_02165064:
    if (a0 == 0) goto loc_02165070;
loc_02165068:
a0 = t4 + 0;
    a0 = GAME_BEACON_SEARCH_SetBattleSpecialPokeStart(a0);
loc_0216506E:
    return a0;
loc_02165070:
a0 = t4 + 0;
    a0 = GAME_BEACON_SEARCH_SetBattleWildPokeStart(a0);
loc_02165076:
    return a0;}
