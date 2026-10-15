/*
 * function: EVENT_COMM_COMMON_CmdCheckBattleRecState
 * address: 0x0217FB2C
 * packet: pkt_ov018_0217FB2C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   INTRUDE_GetFromSave 0x0200BE48 thumb
 *   INTRUDE_GetMonolithLevel 0x0200BF10 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *, void *);
extern void *SCRCMD_WORK_GetGameSystem(void *);
struct Big;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *INTRUDE_GetFromSave(void *);
struct Rec1B0;
extern u8 INTRUDE_GetMonolithLevel(struct Rec1B0 *p);
int EVENT_COMM_COMMON_CmdCheckBattleRecState(void *a, void *vm)
{
    u16 *out;
    int v;
    out = SCRIPT_WORK_ReadWorkPointer(a, vm);
    if (INTRUDE_GetMonolithLevel((struct Rec1B0 *)INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(vm))))) != 0x30) {
        v = 1;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}
