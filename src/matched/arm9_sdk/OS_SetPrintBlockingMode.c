/*
 * function: GAME_BEACON_SetPokeCapture
 * address:  0x020271DC
 * packet:   pkt_020271DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_IsSpecialPokemon 0x0202708C thumb
 *   GAME_BEACON_SetSpecialPokeGet 0x02027230 thumb
 *   GAME_BEACON_SetPokeGet 0x020271F8 thumb
 */

typedef unsigned short u16;
extern int GAME_BEACON_IsSpecialPokemon(u16 v);
extern void GAME_BEACON_SetSpecialPokeGet(u16 value);
extern void GAME_BEACON_SetPokeGet(u16 value);

void GAME_BEACON_SetPokeCapture(u16 v)
{
    if (GAME_BEACON_IsSpecialPokemon(v)) {
        GAME_BEACON_SetSpecialPokeGet(v);
    } else {
        GAME_BEACON_SetPokeGet(v);
    }
}
