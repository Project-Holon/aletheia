/*
 * function: EVENT_MAPCHANGE_CreateNewGameStartEvent
 * address:  0x02183D68
 * packet:   pkt_ov020_02183D68
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   ZONEDATA_SetGameStartLocation  0x02014264  thumb
 *   EVENT_MAPCHANGE_InitUnionInfo  0x02183C58  thumb  ov020
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008B08  0x02008B08  thumb
 *   func_02008B20  0x02008B20  thumb
 *   PALANM_StartTimer  0x02021444  thumb
 *   EVENT_MAPCHANGE_AddPresetMail  0x02185F6C  thumb  ov020
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *   EVENT_MAPCHANGE_NewGameStartEvent  0x02183C9C  thumb  ov020
 */

typedef unsigned int u32;

struct Big;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02008AECObj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Arg;
extern void ZONEDATA_SetGameStartLocation(void *p);
extern void EVENT_MAPCHANGE_InitUnionInfo(int a);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern void func_02008B20(struct Sub02008AECObj *obj);
extern void PALANM_StartTimer(void);
extern void EVENT_MAPCHANGE_AddPresetMail(int a);
extern void func_0208068C(int a);
extern void func_02082AC0(int v, u32 a, u32 b);
extern void func_02080B98(void);
extern int EVENT_MAPCHANGE_NewGameStartEvent(void *obj, int *state, struct Arg *arg);

int EVENT_MAPCHANGE_CreateNewGameStartEvent(int a)
{
    int r6 = (int)func_020122C0((void *)a, 0, EVENT_MAPCHANGE_NewGameStartEvent, 0x24);
    int *r4 = func_020124E8((struct Obj *)r6);

    r4[0] = a;
    r4[1] = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    ZONEDATA_SetGameStartLocation(r4 + 2);
    EVENT_MAPCHANGE_InitUnionInfo(a);
    func_02008B20(func_02008B08(GAME_DATA_GetSaveControl((struct Big *)r4[1])));
    PALANM_StartTimer();
    EVENT_MAPCHANGE_AddPresetMail(r4[1]);
    func_0208068C(0x1ff);
    func_02082AC0(0, 0x1a << 22, 0x29 << 14);
    func_02080B98();
    return r6;
}
