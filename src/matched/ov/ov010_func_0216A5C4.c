/*
 * function: SCRCMD_TRIALHOUSE_SetRank
 * address: 0x0216A5C4
 * packet: pkt_ov010_0216A5C4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008E68 0x02008E68 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Big;
struct Ctx;
struct Sub02008C20Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 SCRIPT_WORK_ReadWorkValue(void *,void *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern void func_02008E68(struct Sub02008C20Obj *obj, u32 value);
int SCRCMD_TRIALHOUSE_SetRank(void *a,void *b) { void *sys; u32 n; SCRCMD_WORK_GetScriptWork(b); sys=GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(b)); n=SCRIPT_WORK_ReadWorkValue(a,b); func_02008E68(func_02008C58(GAME_DATA_GetSaveControl(sys)),(u8)n); return 0; }
