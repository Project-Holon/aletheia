/*
 * function: SCRCMD_SetWifiHistoryGreetingSet
 * address:  0x021D0014
 * packet:   pkt_ov021_021D0014
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009470  0x02009470  thumb
 *   sub_02009618  0x02009618  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Big;
struct Ctx;
struct Sub02009470Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void sub_02009618(struct Sub02009470Obj *obj, int value);

int SCRCMD_SetWifiHistoryGreetingSet(u32 a, u32 b)
{
    void *x;
    u8 v;

    SCRCMD_WORK_GetScriptWork((void *)b);
    x = SCRCMD_WORK_GetGameSystem((void *)b);
    v = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    sub_02009618(func_02009470(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((void *)x))), v);
    return 0;
}
