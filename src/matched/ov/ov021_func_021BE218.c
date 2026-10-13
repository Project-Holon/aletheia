/*
 * function: FIELD_GIMMICK_Exit
 * address:  0x021BE218
 * packet:   pkt_ov021_021BE218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GIMMICK_Exit  0x021BE218  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   gFieldGimmickExitFuncs     0x021D9BE0  data  ov021  a4
 *   gFieldGimmickOverlayIds     0x021D9D98  data  ov021  a4
 */

extern void *FIELDMAP_GetGameSystem(void *p);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 func_0200B3AC(struct Rec94 *p);
extern void func_02034A5C(int handle);

extern void (*gFieldGimmickExitFuncs[])(void *);
extern void *gFieldGimmickOverlayIds[];

void FIELD_GIMMICK_Exit(void *arg)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(arg))));
    if (i != -1) {
        if (gFieldGimmickExitFuncs[i] != 0) {
            gFieldGimmickExitFuncs[i](arg);
        }
        if (gFieldGimmickOverlayIds[i] != 0) {
            func_02034A5C((int)gFieldGimmickOverlayIds[i]);
        }
    }
}
