/*
 * function: MOVE_POKEMON_IsAnyEntryActive
 * address:  0x0215E6F8
 * packet:   pkt_0215E6F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   MOVE_POKEMON_SAVE_IsEntryActive  0x0200D488  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *sys);
struct Blk38;
extern u8 MOVE_POKEMON_SAVE_IsEntryActive(struct Blk38 *p, u32 i);

int MOVE_POKEMON_IsAnyEntryActive(int a0)
{
    int a1;
    int t4;
    void *p;
    void *t5;

    p = GAME_DATA_GetSaveControl((struct Big *)a0);
loc_0215E6FE:
    t5 = MOVE_POKEMON_SAVE_GetBlock(p);
loc_0215E702:
a1 = 0;
t4 = 0;
    a0 = MOVE_POKEMON_SAVE_IsEntryActive(t5, a1);
loc_0215E70C:
    if (a0 != 0) goto loc_0215E71C;
loc_0215E710:
a1 = 1;
    a0 = MOVE_POKEMON_SAVE_IsEntryActive(t5, a1);
loc_0215E718:
    if (a0 == 0) goto loc_0215E720;
loc_0215E71C:
a0 = 1;
    return a0;
loc_0215E720:
a0 = t4 + 0;
    return a0;}
