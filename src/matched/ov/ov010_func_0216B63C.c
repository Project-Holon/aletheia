/*
 * function: SCRCMD_RESEARCH_CmdStartMission
 * address:  0x0216B63C
 * packet:   pkt_ov010_0216B63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   BEACON_GetBlock  0x0200C0F0  thumb
 *   SYMBOL_SAVE_GetBitBlock  0x0200E394  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   BEACON_SetEntryCount  0x0200C334  thumb
 *   BEACON_SetRecentId  0x0200C344  thumb
 *   BEACON_SetRecentValue  0x0200C358  thumb
 *   GF_STANDARD_GetRtcTimestamp  0x0203F524  arm
 *   BEACON_SetLastTime  0x0200C384  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Blk34;
typedef unsigned long long u64;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BEACON_GetBlock(void *sys);
extern void *SYMBOL_SAVE_GetBitBlock(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void BEACON_SetEntryCount(struct Blk34 *p, u8 v);
extern void BEACON_SetRecentId(struct Blk34 *p, u8 i, u8 v);
extern void BEACON_SetRecentValue(struct Blk34 *p, u32 i, int v);
extern u64 GF_STANDARD_GetRtcTimestamp();
extern void BEACON_SetLastTime(struct Blk34 *p, u32 lo, u32 hi);

int SCRCMD_RESEARCH_CmdStartMission(int a0, int a1)
{
    void *h;
    u16 s[3];
    int i;
    void *w;
    int k;
    int z;
    u64 t;

    SCRCMD_WORK_GetScriptWork((void *)a1);
    w = GAME_DATA_GetSaveControl((struct Big *)SCRCMD_WORK_GetGameData((void *)a1));
    h = BEACON_GetBlock(w);
    SYMBOL_SAVE_GetBitBlock(w);
    k = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    s[0] = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    s[1] = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    s[2] = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    BEACON_SetEntryCount(h, k);
    z = 0;
    for (i = 0; i < 3; i++) {
        BEACON_SetRecentId(h, i, s[i]);
        BEACON_SetRecentValue(h, (u8)i, z);
    }
    t = GF_STANDARD_GetRtcTimestamp();
    BEACON_SetLastTime(h, (u32)t, (u32)(t >> 32));
    return z;
}
