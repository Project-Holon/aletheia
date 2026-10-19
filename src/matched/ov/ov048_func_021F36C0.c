/*
 * function: FIELD_GIMMICK_GATE_Init
 * address:  0x021F36C0
 * packet:   pkt_ov048_021F36C0
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetTextLanguage  0x020083E4  thumb
 *   FIELD_GIMMICK_GATE_CreateWork  0x021F3880  thumb  ov048
 *   FIELD_GIMMICK_GATE_LoadBoardRecord  0x021F392C  thumb  ov048
 *   FIELD_GIMMICK_GATE_LoadNewsList  0x021F3BC0  thumb  ov048
 *   FIELD_GIMMICK_GATE_LoadState  0x021F37FC  thumb  ov048
 *   FIELD_GIMMICK_GATE_InitGatePoints  0x021F3908  thumb  ov048
 *   FIELD_GIMMICK_GATE_StoreGatePoints  0x021F3818  thumb  ov048
 *   FIELD_GIMMICK_GATE_RestoreLoggedFlags  0x021F3830  thumb  ov048
 *   GIMMICK_OBJ_ELBOARD_FillMessages  0x021F3D78  thumb  ov048
 *   FIELD_GIMMICK_GATE_ApplyBoardScroll  0x021F3870  thumb  ov048
 *   FIELD_GIMMICK_GATE_PlaceBoardModel  0x021F39E4  thumb  ov048
 *   FIELD_GIMMICK_GATE_StartBoardAnime  0x021F39BC  thumb  ov048
 *   gGateExpObjSetups     0x021F4E94  data  a4
 */

typedef unsigned char u8;

extern u8 gGateExpObjSetups[];

struct Big;
struct Ctx;
struct Sub02008700Obj;
extern int FIELDMAP_GetExpObj(int *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern void FLD_EXP_OBJ_AddUnitFromArchive(int a, void *b, int c);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int CONFIG_GetTextLanguage(unsigned short *p);
struct Obj;
extern struct Obj *FIELD_GIMMICK_GATE_CreateWork(int a);
extern void FIELD_GIMMICK_GATE_LoadBoardRecord(struct Obj *o);
extern void FIELD_GIMMICK_GATE_LoadNewsList(u8 *p);
extern void FIELD_GIMMICK_GATE_LoadState(int *p);
extern void FIELD_GIMMICK_GATE_InitGatePoints(int *p);
extern void FIELD_GIMMICK_GATE_StoreGatePoints(int *p);
extern void FIELD_GIMMICK_GATE_RestoreLoggedFlags(int *p);
extern void GIMMICK_OBJ_ELBOARD_FillMessages(void *p);
extern void FIELD_GIMMICK_GATE_ApplyBoardScroll(int *p);
extern void FIELD_GIMMICK_GATE_PlaceBoardModel(int *p);
extern void FIELD_GIMMICK_GATE_StartBoardAnime(int *p);

void FIELD_GIMMICK_GATE_Init(int a)
{
    int r6;
    int r4;
    int *p;
    int v;

    r6 = FIELDMAP_GetExpObj((int *)a);
    v = CONFIG_GetTextLanguage((short unsigned int *)func_0200873C(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a)))));
    if (v != 0) {
        if (v == 1) {
            r4 = 0;
        }
    } else {
        r4 = 1;
    }
    FLD_EXP_OBJ_AddUnitFromArchive(r6, gGateExpObjSetups + r4 * 16, 1);
    p = (int *)FIELD_GIMMICK_GATE_CreateWork(a);
    FIELD_GIMMICK_GATE_LoadBoardRecord((struct Obj *)p);
    FIELD_GIMMICK_GATE_LoadNewsList((u8 *)p);
    FIELD_GIMMICK_GATE_LoadState(p);
    if (p[4] == 0) {
        FIELD_GIMMICK_GATE_InitGatePoints(p);
    } else {
        FIELD_GIMMICK_GATE_StoreGatePoints(p);
        FIELD_GIMMICK_GATE_RestoreLoggedFlags(p);
    }
    GIMMICK_OBJ_ELBOARD_FillMessages(p);
    FIELD_GIMMICK_GATE_ApplyBoardScroll(p);
    FIELD_GIMMICK_GATE_PlaceBoardModel(p);
    FIELD_GIMMICK_GATE_StartBoardAnime(p);
}
