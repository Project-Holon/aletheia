/*
 * function: FIELD_GIMMICK_SWITCH_TOGGLE_ReplacePlayerIfRequirementMet
 * address:  0x021F38C4
 * packet:   pkt_ov045_021F38C4
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCtrlType  0x02188CF0  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   FIELD_GIMMICK_SWITCH_TOGGLE_IsRequirementMet  0x021F3908  thumb
 *   FIELDMAP_GetCtrlWork  0x02188CA4  thumb  ov021
 *   FIELDMAP_CTRL_HYBRID_ReplacePlayer  0x021A6DC4  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetCtrlType(u32 a);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern int FIELD_GIMMICK_SWITCH_TOGGLE_IsRequirementMet(char *a0, int a1);
extern u32 FIELDMAP_GetCtrlWork(u8 *p);
extern void FIELDMAP_CTRL_HYBRID_ReplacePlayer(u32 *b, void *a);

void FIELD_GIMMICK_SWITCH_TOGGLE_ReplacePlayerIfRequirementMet(void *a0, int a1)
{
    void *r6;
    int r4;
    void *p;

    r6 = GAMESYSTEM_GetFieldMap(a0);
    r4 = FIELDMAP_GetCtrlType((u32)r6);
    p = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(r6))), 9);
    if (a1 < 8 && r4 == 2) {
        if (FIELD_GIMMICK_SWITCH_TOGGLE_IsRequirementMet(p, a1)) {
            FIELDMAP_CTRL_HYBRID_ReplacePlayer((u32 *)FIELDMAP_GetCtrlWork(r6), r6);
        }
    }
}
