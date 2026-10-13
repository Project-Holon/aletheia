/*
 * function: FIELD_GIMMICK_RunMapCallback
 * address:  0x021BE258
 * packet:   pkt_ov021_021BE258
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   gFieldGimmickCallbackTbl  0x021D9E74  data
 */

typedef void (*Handler)(void *p);

extern void *FIELDMAP_GetGameSystem(void *p);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 func_0200B3AC(struct Rec94 *p);
extern Handler gFieldGimmickCallbackTbl[];

void FIELD_GIMMICK_RunMapCallback(void *p)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(p))));
    if (i != -1 && gFieldGimmickCallbackTbl[i] != 0)
        gFieldGimmickCallbackTbl[i](p);
}
