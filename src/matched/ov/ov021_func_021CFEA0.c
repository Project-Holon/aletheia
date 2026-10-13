/*
 * function: SCRCMD_GetWifiHistoryCountryCount
 * address:  0x021CFEA0
 * packet:   pkt_ov021_021CFEA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02009590  0x02009590  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Sub02009470Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_02009590(void *a, u32 b, u32 c);

int SCRCMD_GetWifiHistoryCountryCount(u32 a, u32 b)
{
    u32 k, h, g;
    void *x;
    u16 *out;

    SCRCMD_WORK_GetScriptWork((void *)b);
    x = SCRCMD_WORK_GetGameSystem((void *)b);
    k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    h = (u32)GAMESYSTEM_GetGameData(x);
    g = (u32)func_02009470(GAME_DATA_GetSaveControl((struct Big *)h));
    *out = func_02009590((void *)g, (u32)GAME_DATA_GetMyStatus((void *)h), k);
    return 0;
}
