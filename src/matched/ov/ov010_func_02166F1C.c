/*
 * function: SYMBOL_MAP_ScrCmdSetSubscreenMode
 * address:  0x02166F1C
 * packet:   pkt_ov010_02166F1C
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
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetWeather  0x02188C6C  thumb  ov021
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   func_0202C794  0x0202C794  thumb
 *   WEATHER_RequestChangeNoFade  0x021A1BE4  thumb  ov021
 *   WEATHER_RequestChange  0x021A1BDC  thumb  ov021
 *   GAME_DATA_SetSubscreenMode  0x020129A0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *a);
extern void *SCRCMD_WORK_GetGameSystem(void *a);
extern void *SCRCMD_WORK_GetGameData(void *a);
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetWeather(u8 *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u8 func_0202C794(void *a0, u32 a1);
extern void WEATHER_RequestChangeNoFade(int a, int b);
extern void WEATHER_RequestChange(int a, int b);
extern void GAME_DATA_SetSubscreenMode(struct BigObj *p, u8 v);

int SYMBOL_MAP_ScrCmdSetSubscreenMode(void *a, void *b)
{
    void *s4;
    void *s0;
    void *s8;
    int r7;
    int r4;
    int r5;
    SCRCMD_WORK_GetScriptWork(b);
    s4 = SCRCMD_WORK_GetGameSystem((void *)b);
    s0 = SCRCMD_WORK_GetGameData((void *)b);
    s8 = GAMESYSTEM_GetFieldMap((void *)s4);
    r7 = FIELDMAP_GetWeather((u8 *)s8);
    r4 = SCRIPT_WORK_ReadWorkValue(a, b);
    r5 = SCRIPT_WORK_ReadWorkValue(a, b);
    if (r4 == 0xFFFF)
        r4 = func_0202C794(s4, FIELDMAP_GetZoneId(s8));
    if (r5 != 0)
        WEATHER_RequestChangeNoFade(r7, r4);
    else
        WEATHER_RequestChange(r7, r4);
    GAME_DATA_SetSubscreenMode(s0, r4 & 0xff);
    return 0;
}
