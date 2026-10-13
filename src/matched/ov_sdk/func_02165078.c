/*
 * function: func_02165078
 * address:  0x02165078
 * packet:   pkt_02165078
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_IsSpecialPokemon  0x0202708C  thumb
 *   func_0216513C  0x0216513C  thumb  ov010
 *   func_021650CC  0x021650CC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int GAME_BEACON_IsSpecialPokemon();
extern int func_0216513C();
extern int func_021650CC();

int func_02165078(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = GAME_BEACON_IsSpecialPokemon(a0);
loc_02165080:
    if (a0 == 0) goto loc_0216508C;
loc_02165084:
a0 = t4 + 0;
    a0 = func_0216513C(a0);
loc_0216508A:
    return a0;
loc_0216508C:
a0 = t4 + 0;
    a0 = func_021650CC(a0);
loc_02165092:
    return a0;}
