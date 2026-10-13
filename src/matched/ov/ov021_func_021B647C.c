/*
 * function: SCRCMD_POKEMON_FLD_CheckTradeMon
 * address:  0x021B647C
 * packet:   pkt_ov021_021B647C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FLD_TRADE_Create  0x021CBFB0  thumb  ov021
 *   FLD_TRADE_Delete  0x021CC040  thumb  ov021
 *   FLD_TRADE_GetWantedSpecies  0x021CC060  thumb  ov021
 *   FLD_TRADE_GetWantedGender  0x021CC068  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
struct BigObj;
struct Ctx;
struct Obj;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern struct Obj *FLD_TRADE_Create(u32 a, u32 b);
extern void FLD_TRADE_Delete(struct Obj *o);
extern u32 FLD_TRADE_GetWantedSpecies(u8 *p);
extern u32 FLD_TRADE_GetWantedGender(u8 *p);

int SCRCMD_POKEMON_FLD_CheckTradeMon(void *a, void *b)
{
    void *sys;
    void *w;
    u32 heap;
    u16 *out;
    u32 i2;
    u32 idx;
    void *mon;
    void *obj;
    u32 v;

    SCRCMD_WORK_GetScriptWork(b);
    sys = SCRCMD_WORK_GetGameSystem(b);
    w = GAMESYSTEM_GetGameData(sys);
    heap = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(sys));
    out = SCRIPT_WORK_ReadWorkPointer(a, b);
    i2 = SCRIPT_WORK_ReadWorkValue(a, b);
    idx = SCRIPT_WORK_ReadWorkValue(a, b);
    mon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(w), idx);
    obj = FLD_TRADE_Create(heap, i2);
    *out = 0;
    if (*out == 0 && POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 1) {
        *out = 1;
    }
    if (*out == 0) {
        v = POKE_TOOL_GetPartyValue(mon, 5, 0);
        if (v != FLD_TRADE_GetWantedSpecies(obj)) {
            *out = 2;
        }
    }
    if (*out == 0 && FLD_TRADE_GetWantedGender(obj) != 2) {
        v = POKE_TOOL_GetPartyValue(mon, 0x6e, 0);
        if (v != FLD_TRADE_GetWantedGender(obj)) {
            *out = 3;
        }
    }
    FLD_TRADE_Delete(obj);
    return 0;
}
