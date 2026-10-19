/*
 * function: SCRCMD_POKEMON_FLD_SwapPartyMonWithBoxedLegend
 * address:  0x021B6708
 * packet:   pkt_ov021_021B6708
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SCRCMD_POKEMON_FLD_FindBoxedLegend  0x021B6850  thumb  ov021
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   FILE_UTIL_IsMailItem  0x0202136C  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   MAIL_Create  0x02008F08  thumb
 *   MAIL_FindEmptySlot  0x02009020  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_02008EAC  0x02008EAC  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   func_020307B0  0x020307B0  arm
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   func_02007A18  0x02007A18  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   POKEPARTY_SetMember  0x0201AB48  thumb
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb
 *   func_020075B0  0x020075B0  thumb
 *   sScrcmdPokemonFldFileName     0x021DE270  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
struct BigObj;
struct Party;
struct PartyMon;
struct Sub020075B0Entry;
struct Sub020079BCEntry;
struct Sub02008EACObj;
struct Sub02008F80Obj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int SCRCMD_POKEMON_FLD_FindBoxedLegend(u32 a, u16 b, u16 *c, u16 *d);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void MI_CpuCopy8(void *src, void *dst, u32 n);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern u32 FILE_UTIL_IsMailItem(u16 v);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *MAIL_Create(int a0);
extern int MAIL_FindEmptySlot(void *obj, int v);
extern void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 func_020307B0(void *p);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);
extern void POKE_TOOL_RecalcParam(void *mon);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
struct Mon;
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern void POKEPARTY_SetMember(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *POKE_TOOL_CastToBoxParam(void *mon);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern u8 sScrcmdPokemonFldFileName[];

void SCRCMD_POKEMON_FLD_SwapPartyMonWithBoxedLegend(u32 a, int idx)
{
    void *sv;
    void *party;
    u32 heap;
    void *save;
    void *mon;
    u32 sz;
    void *o;
    void *buf;
    int i;
    void *m;
    u16 pos[2];

    sv = SCRCMD_WORK_GetGameData((void *)a);
    party = GAME_DATA_GetMyParty((void *)sv);
    if (SCRCMD_POKEMON_FLD_FindBoxedLegend((u32)sv, 0x283, &pos[1], &pos[0]) == 0) {
        return;
    }
    heap = SCRCMD_WORK_GetHeapId((void *)a);
    save = (void *)GAME_DATA_GetBoxManager(sv);
    mon = func_02030734(heap, POKE_TOOL_GetPartyParamSize(), 1, (const char *)sScrcmdPokemonFldFileName, 0x4c7);
    sz = POKE_TOOL_GetPartyParamSize();
    MI_CpuCopy8(POKEPARTY_GetMember(party, idx), mon, sz);
    if (FILE_UTIL_IsMailItem(POKE_TOOL_GetPartyValue(mon, 6, 0)) == 1) {
        o = func_02008FEC(sv);
        buf = MAIL_Create(SCRCMD_WORK_GetHeapId((void *)a));
        i = MAIL_FindEmptySlot(o, 0);
        POKE_TOOL_GetPartyValue(mon, 0xa7, (u32)buf);
        GAME_DATA_GetMyStatus(sv);
        if (i >= 0) {
            func_0200903C(o, 0, i, buf);
        }
        func_02008EAC(buf);
        POKE_TOOL_SetPartyValue(mon, 0xa7, (u32)buf);
        POKE_TOOL_SetPartyValue(mon, 6, 0);
        func_020307B0(buf);
    }
    if (POKE_TOOL_GetPartyValue(mon, 0xab, 0) == 0x1ec) {
        POKE_TOOL_ChangeForm(mon, 0);
        POKE_TOOL_RecalcParam(mon);
    }
    m = POKE_TOOL_CreateFromBoxParam((struct Mon *)func_02007A18(save, pos[1], pos[0]), heap);
    POKEPARTY_SetMember(party, idx, m);
    func_020307B0(m);
    func_020075B0(save, pos[1], pos[0], POKE_TOOL_CastToBoxParam(mon));
    func_020307B0(mon);
}
