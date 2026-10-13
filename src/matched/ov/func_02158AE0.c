/*
 * function: SCRIPT_SYS_RunZoneChangeScript
 * address:  0x02158AE0
 * packet:   pkt_02158AE0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two arm9 frame calls, an overlay reset, then the four-argument submit.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData   0x020120F4  thumb
 *   GAME_DATA_GetEventWork   0x0201296C  thumb
 *   SCRIPT_SYS_ClearLocalWork   0x021589F4  thumb  ov010
 *   SCRIPT_SYS_RunSpecialScript   0x02158A90  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern int SCRIPT_SYS_ClearLocalWork(int a0);
extern int SCRIPT_SYS_RunSpecialScript(void *a, int unused, int key, int d);

void SCRIPT_SYS_RunZoneChangeScript(void *a0, void *a1)
{
    SCRIPT_SYS_ClearLocalWork(GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(a0)));
    SCRIPT_SYS_RunSpecialScript(a0, (int)a1, 2, 2);
}

