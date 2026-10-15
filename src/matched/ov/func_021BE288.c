/*
 * function: FIELD_GIMMICK_IsGimmickId
 * address:  0x021BE288
 * packet:   pkt_021BE288
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetId  0x0200B3AC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct Big;
struct Ctx;
struct Rec94;
extern s32 GIMMICK_WORK_GetId(struct Rec94 *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern void *FIELDMAP_GetGameSystem(void *p);

int FIELD_GIMMICK_IsGimmickId(u8 *a, int b)
{
if (b == GIMMICK_WORK_GetId((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem((void *)a))))) {
    return 1;
}
return 0;
}

