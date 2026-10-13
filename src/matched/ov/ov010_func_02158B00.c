/*
 * function: SCRIPT_SYS_CreateSceneChangeEvent
 * address: 0x02158B00
 * packet: pkt_ov010_02158B00
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetEventData 0x02012844 thumb
 *   EVENTDATA_SYSTEM_GetSpecialScriptData 0x02162450 thumb ov010
 *   SCRIPT_SYS_FindSceneScript 0x02158B6C thumb ov010
 *   SCRIPT_SYS_CreateScriptEventSimple 0x02158768 thumb ov010
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
struct Desc;
extern u32 GAME_DATA_GetEventData(const struct BigObj *p);
extern u32 EVENTDATA_SYSTEM_GetSpecialScriptData(void *p);
typedef unsigned short u16;
extern u16 SCRIPT_SYS_FindSceneScript(const void *a, const u8 *list, u32 key);
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
void *SCRIPT_SYS_CreateSceneChangeEvent(void *a, u32 b) {
    void *s = GAMESYSTEM_GetGameData(a);
    int msg = SCRIPT_SYS_FindSceneScript(s, (const u8 *)EVENTDATA_SYSTEM_GetSpecialScriptData((void *)GAME_DATA_GetEventData(s)), 1);
    if (msg == 0xffff) return 0;
    return SCRIPT_SYS_CreateScriptEventSimple((int)a, msg, 0, b);
}
