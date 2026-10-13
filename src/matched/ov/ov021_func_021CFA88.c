/*
 * function: SCRCMD_GetPlayerLocationValue
 * address:  0x021CFA88
 * packet:   pkt_ov021_021CFA88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
struct Sub02008828Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u16 func_02008990(const struct Sub02008828Obj *obj);

int SCRCMD_GetPlayerLocationValue(void *a, void *b)
{
    void *h;
    u16 *q;

    SCRCMD_WORK_GetScriptWork(b);
    h = func_02008854(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((void *)SCRCMD_WORK_GetGameSystem(b))));
    q = SCRIPT_WORK_ReadWorkPointer(a, b);
    *q = func_02008990(h);
    return 0;
}
