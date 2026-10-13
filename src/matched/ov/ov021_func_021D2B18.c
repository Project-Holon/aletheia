/*
 * function: SCRCMD_GetTrainerRecordValue
 * address:  0x021D2B18
 * packet:   pkt_ov021_021D2B18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008C58  0x02008C58  thumb
 *   func_02008DFC  0x02008DFC  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct Big;
struct Ctx;
struct Sub02008C20Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 func_02008DFC(struct Sub02008C20Obj *obj, int i);

int SCRCMD_GetTrainerRecordValue(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetGameSystem((void *)b);
    u32 k = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    u16 *q = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);

    *q = func_02008DFC(func_02008C58(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((void *)x))), k);
    return 0;
}
