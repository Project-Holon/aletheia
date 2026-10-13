/*
 * function: SCRCMD_POKEMON_FLD_StartEggHatch
 * address:  0x021B63D4
 * packet:   pkt_ov021_021B63D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   SYMBOL_MAP_CreatePokeEventTask  0x02166C4C  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct BigObj;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void *SYMBOL_MAP_CreatePokeEventTask(void *a, void *b, void *c);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

u32 SCRCMD_POKEMON_FLD_StartEggHatch(void *a, void *b)
{
    u16 *out = SCRIPT_WORK_ReadWorkPointer(a, b);
    void *p10 = SCRCMD_WORK_GetScriptWork(b);
    void *pc = SCRCMD_WORK_GetGameSystem(b);
    void *t8 = GAMESYSTEM_GetFieldMap(pc);
    void *t;
    void *party;
    int n;
    int i;

    FIELDMAP_GetHeapId(t8);
    t = GAMESYSTEM_GetGameData(pc);
    GAME_DATA_GetMyStatus(t);
    party = GAME_DATA_GetMyParty(t);
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);
        u32 x = POKE_TOOL_GetPartyValue(mon, 0x4c, 0);
        u32 y = POKE_TOOL_GetPartyValue(mon, 3, 0);
        u32 z = POKE_TOOL_GetPartyValue(mon, 9, 0);

        if (x != 0 && y == 0 && z == 0) {
            SCRIPT_SYS_CallEvent(p10, SYMBOL_MAP_CreatePokeEventTask(pc, t8, mon));
            *out = i;
            return 1;
        }
    }
    return 0;
}
