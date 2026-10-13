/*
 * function: SCRCMD_AddTrainerRecordValue
 * address:  0x021D2ADC
 * packet:   pkt_ov021_021D2ADC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008C58  0x02008C58  thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
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
extern u32 func_02008DAC(struct Sub02008C20Obj *obj, int i, u32 delta);

int SCRCMD_AddTrainerRecordValue(u32 a, u32 b)
{
    void *x = SCRCMD_WORK_GetGameSystem((void *)b);
    u32 k1 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    u32 k2 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);

    func_02008DAC(func_02008C58(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((void *)x))), k1, k2);
    return 0;
}
