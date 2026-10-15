/*
 * function: FIELD_GIMMICK_Setup
 * address:  0x021BE1DC
 * packet:   pkt_ov021_021BE1DC
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
 *   GIMMICK_WORK_GetId  0x0200B3AC  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   gFieldGimmickOverlayIds     0x021D9D98  data  a4
 *   gFieldGimmickInitFuncs     0x021D9CBC  data  a4
 */

extern void *FIELDMAP_GetGameSystem(void *p);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 GIMMICK_WORK_GetId(struct Rec94 *p);
extern int func_02034AC4(int);

extern void *gFieldGimmickOverlayIds[];
extern void (*gFieldGimmickInitFuncs[])(void *);

void FIELD_GIMMICK_Setup(void *arg)
{
    int i;

    i = GIMMICK_WORK_GetId((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(arg))));
    if (i != -1) {
        if (gFieldGimmickOverlayIds[i] != 0) {
            func_02034AC4((int)gFieldGimmickOverlayIds[i]);
        }
        gFieldGimmickInitFuncs[i](arg);
    }
}
