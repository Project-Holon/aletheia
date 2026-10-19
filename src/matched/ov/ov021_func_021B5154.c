/*
 * function: SCRCMD_PROC_FLD_SpawnMovePokemonIfInactive
 * address:  0x021B5154
 * packet:   pkt_ov021_021B5154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   MOVE_POKEMON_SAVE_IsEntryActive  0x0200D488  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   MOVE_POKEMON_SpawnEntry  0x0215E440  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct Big;
struct Blk38;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *sys);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u8 MOVE_POKEMON_SAVE_IsEntryActive(struct Blk38 *p, u32 i);
extern void MOVE_POKEMON_SpawnEntry(void *sys, u8 which);

int SCRCMD_PROC_FLD_SpawnMovePokemonIfInactive(u32 a, u32 b)
{
    void *e = SCRCMD_WORK_GetGameData((void *)b);
    u32 g = (u32)MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(e));
    u8 k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);

    if (MOVE_POKEMON_SAVE_IsEntryActive((struct Blk38 *)g, k) == 0) {
        MOVE_POKEMON_SpawnEntry(e, k);
    }
    return 0;
}
