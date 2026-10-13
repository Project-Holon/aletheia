/*
 * function: SCRCMD_GetWifiHistoryEntryCount
 * address:  0x021CFEF0
 * packet:   pkt_ov021_021CFEF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02009470  0x02009470  thumb
 *   sub_020095C8  0x020095C8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
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
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u8 sub_020095C8(const struct Sub02009470Obj *obj);

int SCRCMD_GetWifiHistoryEntryCount(u32 a, u32 b)
{
    void *x;
    u16 *q;

    SCRCMD_WORK_GetScriptWork((void *)b);
    x = SCRCMD_WORK_GetGameSystem((void *)b);
    q = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    *q = sub_020095C8(func_02009470(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((void *)x))));
    return 0;
}
