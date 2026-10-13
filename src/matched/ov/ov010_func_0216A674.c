/*
 * function: SCRCMD_TRIALHOUSE_GetRankAndScore
 * address:  0x0216A674
 * packet:   pkt_ov010_0216A674
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   TRIAL_HOUSE_ComputeScoreAndRank  0x021D0DB0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;

extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetListCursor(void *base);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void TRIAL_HOUSE_ComputeScoreAndRank(u32 a, u8 *w, u16 *outRank, u16 *outScore);

int SCRCMD_TRIALHOUSE_GetRankAndScore(int a0, int a1)
{
    void *r7;
    int *r6;
    u16 *l0;

    SCRCMD_WORK_GetScriptWork((void *)a1);
    r7 = SCRCMD_WORK_GetGameSystem((void *)a1);
    r6 = (int *)GAME_DATA_GetListCursor(GAMESYSTEM_GetGameData((const struct Ctx *)r7));
    l0 = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
    TRIAL_HOUSE_ComputeScoreAndRank((u32)r7, (u8 *)(*r6), l0, SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1));
    return 0;
}
