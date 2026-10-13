/*
 * function: SCRIPT_SYS_RunSpecialScript
 * address: 0x02158A90
 * packet: pkt_ov010_02158A90
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetEventData 0x02012844 thumb
 *   EVENTDATA_SYSTEM_GetSpecialScriptData 0x02162450 thumb ov010
 *   SCRIPT_SYS_FindSpecialScript 0x02158B3C thumb ov010
 *   SCRIPT_SYS_RunScriptNow 0x02158A34 thumb ov010
 */
typedef unsigned char u8;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern u32 EVENTDATA_SYSTEM_GetSpecialScriptData(void *p);
extern int SCRIPT_SYS_FindSpecialScript(const u8 *, int);
extern void SCRIPT_SYS_RunScriptNow(int, int, int, int);
int SCRIPT_SYS_RunSpecialScript(void *a, int unused, int key, int d) {
    int result = SCRIPT_SYS_FindSpecialScript((const u8 *)EVENTDATA_SYSTEM_GetSpecialScriptData((void *)GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(a))), key);
    if (result == 0xffff) return 0;
    SCRIPT_SYS_RunScriptNow((int)a, 0, result, d);
    return 1;
}
