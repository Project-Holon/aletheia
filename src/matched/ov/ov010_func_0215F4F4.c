/*
 * function: SCRCMD_NETWORK_CmdApplyTableEventKeys
 * address: 0x0215F4F4
 * packet: pkt_ov010_0215F4F4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRIPT_WORK_GetGameSystem 0x02158F54 thumb ov010
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   SCRIPT_WORK_GetReturnFlag 0x0215911C thumb ov010
 *   EVENT_TRAINER_ClearDefeatedFlag 0x0215A500 thumb ov010
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef struct Entry { u32 a; u16 b,c; } Entry;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRIPT_WORK_GetGameSystem(void *);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 SCRIPT_WORK_GetReturnFlag(void *p);
extern void EVENT_TRAINER_ClearDefeatedFlag(char *a, unsigned b);
int SCRCMD_NETWORK_CmdApplyTableEventKeys(void *a,void *b) { void *p; void *s; int i; Entry *t; p=SCRCMD_WORK_GetScriptWork(b); s=(void *)GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(SCRIPT_WORK_GetGameSystem(p))); t=(Entry *)SCRIPT_WORK_GetReturnFlag(p); for(i=0;i<0x6b;i++) EVENT_TRAINER_ClearDefeatedFlag(s,t[i].c); return 0; }
