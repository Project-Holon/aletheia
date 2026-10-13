/*
 * function: SCRCMD_HasPlayerLanguage
 * address:  0x021D0114
 * packet:   pkt_ov021_021D0114
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200856C  0x0200856C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);

int SCRCMD_HasPlayerLanguage(u32 a, u32 b)
{
    u16 *q = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);

    *q = func_0200856C((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData((void *)SCRCMD_WORK_GetGameSystem((void *)b)))) != 0 ? 1 : 0;
    return 0;
}
