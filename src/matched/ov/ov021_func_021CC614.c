/*
 * function: SCRCMD_PALPARK_SetBeacon
 * address:  0x021CC614
 * packet:   pkt_ov021_021CC614
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * GAMESYSTEM_GetGameData takes the SCRCMD_WORK_GetGameSystem result as its argument (r0 still
 * holds it at the bl), as it does at every other caller; declaring it
 * void(void) was what shuffled the whole register assignment.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   GAME_BEACON_SEARCH_SetItemFound  0x0216530C  thumb  ov010
 *   GAME_BEACON_SEARCH_SetCountValue  0x02165534  thumb  ov010
 *   GAME_BEACON_SEARCH_SetFieldEvent  0x021653C4  thumb  ov010
 *   GAME_BEACON_SEARCH_SetSimpleEventA  0x021656A0  thumb  ov010
 *   GAME_BEACON_SEARCH_SetByteValue  0x021656D0  thumb  ov010
 *   GAME_BEACON_SEARCH_SetSimpleEventC  0x0216573C  thumb  ov010
 *   GAME_BEACON_SEARCH_SetFacilityExit  0x02165604  thumb  ov010
 *   GAME_BEACON_SEARCH_SetWordValue  0x02165634  thumb  ov010
 *   GAME_BEACON_SEARCH_SetWordClear  0x0216566C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void GAME_BEACON_SEARCH_SetItemFound(void *a0);
extern void GAME_BEACON_SEARCH_SetCountValue(void *a0);
extern void GAME_BEACON_SEARCH_SetFieldEvent(void);
extern void GAME_BEACON_SEARCH_SetSimpleEventA(void);
extern void GAME_BEACON_SEARCH_SetByteValue(u8 a);
extern void GAME_BEACON_SEARCH_SetSimpleEventC(void);
extern void GAME_BEACON_SEARCH_SetFacilityExit(void);
extern void GAME_BEACON_SEARCH_SetWordValue(void *a0);
extern void GAME_BEACON_SEARCH_SetWordClear(void);

int SCRCMD_PALPARK_SetBeacon(u32 a, u32 b)
{
    u32 sel;
    u32 v;
    void *t;

    sel = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    v = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    t = SCRCMD_WORK_GetGameSystem((void *)b);
    GAMESYSTEM_GetGameData(t);
    GAMESYSTEM_GetFieldMap((void *)t);
    SCRCMD_WORK_GetScriptWork((void *)b);
    switch (sel) {
    case 0:
        GAME_BEACON_SEARCH_SetItemFound((void *)v);
        break;
    case 1:
        GAME_BEACON_SEARCH_SetCountValue((void *)v);
        break;
    case 2:
        GAME_BEACON_SEARCH_SetFieldEvent();
        break;
    case 3:
        GAME_BEACON_SEARCH_SetSimpleEventA();
        break;
    case 4:
        GAME_BEACON_SEARCH_SetByteValue(v);
        break;
    case 5:
        GAME_BEACON_SEARCH_SetSimpleEventC();
        break;
    case 6:
        GAME_BEACON_SEARCH_SetFacilityExit();
        break;
    case 7:
        GAME_BEACON_SEARCH_SetWordValue((void *)v);
        break;
    case 8:
        GAME_BEACON_SEARCH_SetWordClear();
        break;
    }
    return 0;
}
