/*
 * function: FIELD_ENCOUNT_GetSwarmEntry
 * address:  0x021A99A8
 * packet:   pkt_ov021_021A99A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sSwarmTable  0x021D8DE8  data
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   MOVE_POKEMON_SAVE_GetStartLocation  0x0200D454  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Entry8 { u32 a, b; };

struct Big;
struct Blk38;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *p);
extern u8 MOVE_POKEMON_SAVE_GetStartLocation(struct Blk38 *p);
extern const struct Entry8 sSwarmTable[];

const struct Entry8 *FIELD_ENCOUNT_GetSwarmEntry(void *p)
{
    void *q = GAME_DATA_GetSaveControl(p);
    u32 k;

    if (ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(p), 0x960) == 0)
        return 0;
    k = MOVE_POKEMON_SAVE_GetStartLocation(MOVE_POKEMON_SAVE_GetBlock(q));
    if (k >= 0x11)
        k = 0;
    return &sSwarmTable[k];
}
