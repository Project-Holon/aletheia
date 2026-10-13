/*
 * function: SCRCMD_TRIALHOUSE_LoadRecord
 * address:  0x0216A4CC
 * packet:   pkt_ov010_0216A4CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   TRIAL_HOUSE_LoadTrainer  0x021D0AC0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u16 TRIAL_HOUSE_LoadTrainer();

int SCRCMD_TRIALHOUSE_LoadRecord(int a0, int a1)
{
    void *r7;
    int *r6;
    int loc;
    u16 *p;

    SCRCMD_WORK_GetScriptWork((void *)a1);
    r7 = SCRCMD_WORK_GetGameSystem((void *)a1);
    r6 = GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData((const struct Ctx *)r7));
    loc = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    p = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    *p = TRIAL_HOUSE_LoadTrainer(r7, *r6, loc);
    return 0;
}
