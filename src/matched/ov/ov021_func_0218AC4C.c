/*
 * function: FIELD_EVENT_CHECK_CheckMovePokemonCooldown
 * address:  0x0218AC4C
 * packet:   pkt_ov021_0218AC4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * When the save flag from MOVE_POKEMON_SAVE_TickCooldown is set, shows message 0x2792 through
 * SCRIPT_SYS_CreateScriptEventSimple with the position's FIELDMAP_GetHeapId value; returns 0 otherwise.
 *
 * symbols:
 *   MOVE_POKEMON_SAVE_TickCooldown  0x0200D564  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Big;
struct Blk38;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *p);
extern u32 MOVE_POKEMON_SAVE_TickCooldown(struct Blk38 *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);

int FIELD_EVENT_CHECK_CheckMovePokemonCooldown(u8 *pos, void *msg, void *sys)
{
    if ((u8)MOVE_POKEMON_SAVE_TickCooldown(MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(sys))))
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)msg, 0x2792, 0, FIELDMAP_GetHeapId(pos));
    return 0;
}
