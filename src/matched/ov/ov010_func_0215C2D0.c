/*
 * function: SCRCMD_PROC_AddEggToParty
 * address:  0x0215C2D0
 * packet:   pkt_ov010_0215C2D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: add a level-1 Pokemon egg of the given species and
 * form to the party (hatch counter from the personal data, the egg name
 * from message 0x28A), writing 1 to the result word, or 0 when the
 * party is full. First draft.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   POKEPARTY_GetCapacity  0x0201AA14  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_02008510  0x02008510  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   func_0202F190  0x0202F190  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   func_020307B0  0x020307B0  arm
 *   gSpeciesNameBank     0x020A7370  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern void *SCRCMD_WORK_GetGameData(void *vm);
struct BigObj;
struct Party;
struct PartyMon;
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *c, void *vm);
extern u32 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 POKEPARTY_GetCapacity(void *p);
extern u32 POKEPARTY_GetCount(void *party);
extern void *POKE_TOOL_Create(u32 species, u32 level, u64 id, u32 heap);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
struct MsgBank;
struct Personal;
struct U16Vec;
extern void *func_02008510(void *a, int tag);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void POKE_TOOL_RecalcParam(void *mon);
extern void func_0202F190(void *mon, u32 a1, void *a2, u32 a3, u32 heap);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern void *gSpeciesNameBank;

int SCRCMD_PROC_AddEggToParty(void *c, void *vm)
{
    void *sys;
    u32 heap;
    void *party;
    void *my;
    u16 *res;
    u32 species;
    u32 form;
    void *mon;
    u32 t;
    u32 info;
    u32 v;

    SCRCMD_WORK_GetGameSystem(vm);
    sys = SCRCMD_WORK_GetGameData(vm);
    heap = SCRCMD_WORK_GetHeapId(vm);
    party = GAME_DATA_GetMyParty(sys);
    my = GAME_DATA_GetMyStatus(sys);
    res = SCRIPT_WORK_ReadWorkPointer(c, vm);
    species = SCRIPT_WORK_ReadWorkValue(c, vm);
    form = SCRIPT_WORK_ReadWorkValue(c, vm);
    if ((int)POKEPARTY_GetCapacity(party) <= (int)POKEPARTY_GetCount(party)) {
        *res = 0;
        return 0;
    }
    mon = POKE_TOOL_Create(species, 1, (u64)-1, heap);
    POKE_TOOL_SetPartyValue(mon, 0x6F, form);
    t = (u32)func_02008510(GAME_DATA_GetMyStatus(sys), heap);
    POKE_TOOL_SetPartyValue(mon, 0x8D, t);
    STRBUF_Delete((struct U16Vec *)t);
    info = (u32)POKE_PERSONAL_Create((u16)POKE_TOOL_GetPartyValue(mon, 5, 0), (u16)POKE_TOOL_GetPartyValue(mon, 0x6F, 0), heap);
    v = POKE_PERSONAL_GetParam((const struct Personal *)info, 0x15);
    POKE_PERSONAL_Delete((void *)info);
    POKE_TOOL_SetPartyValue(mon, 9, v);
    POKE_TOOL_SetPartyValue(mon, 0x4C, 1);
    t = (u32)func_02045EC0(gSpeciesNameBank, 0x28A);
    POKE_TOOL_SetPartyValue(mon, 0x73, t);
    STRBUF_Delete((struct U16Vec *)t);
    POKE_TOOL_RecalcParam(mon);
    func_0202F190(mon, 5, my, 0xEA63, heap);
    POKEPARTY_Add(party, mon);
    func_020307B0(mon);
    *res = 1;
    return 0;
}
