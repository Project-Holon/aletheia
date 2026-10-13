/*
 * function: MOVE_POKEMON_FindEntryByZone
 * address:  0x0215E6A8
 * packet:   pkt_ov010_0215E6A8
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
 *   MOVE_POKEMON_GetEntryZoneId  0x0215E3E4  thumb  ov010
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Big;
struct Blk38;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *p);
extern u8 MOVE_POKEMON_SAVE_IsEntryActive(struct Blk38 *p, u32 i);
extern u32 MOVE_POKEMON_GetEntryZoneId(void *p, u32 slot);

int MOVE_POKEMON_FindEntryByZone(void *a, int x)
{
    u8 i;
    void *p;

    p = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(a));
    i = 0;
    if (MOVE_POKEMON_SAVE_IsEntryActive(p, 0) != 0 && x == MOVE_POKEMON_GetEntryZoneId(p, i)) {
        return 6;
    }
    i = 1;
    if (MOVE_POKEMON_SAVE_IsEntryActive(p, 1) != 0 && x == MOVE_POKEMON_GetEntryZoneId(p, i)) {
        return 7;
    }
    return 0xffff;
}
