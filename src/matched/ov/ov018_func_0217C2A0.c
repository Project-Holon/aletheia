/*
 * function: INTRUDE_FIELD_CreateSymbolMon
 * address:  0x0217C2A0
 * packet:   pkt_ov018_0217C2A0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The const on the entry pointer is what lets the bitfield loads be
 * scheduled above the outgoing stack-argument stores (48 bytes otherwise).
 * symbols:
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   func_020307B0  0x020307B0  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   POKE_TOOL_CreatePersonalRnd  0x020186C8  thumb
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetAbility  0x02018A00  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   POKE_TOOL_AddMove  0x0201808C  thumb
 *   POKE_TOOL_PushMove  0x020180F4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 species : 11;
    u32 move : 10;
    u32 f21 : 2;
    u32 f23 : 6;
    u32 f29 : 3;
} Entry;

extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern u32 func_020307B0(void *p);
struct Mon;
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 POKE_TOOL_CreatePersonalRnd(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void *POKE_TOOL_Create(u16, u16, u64, int);
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_TOOL_SetAbility(void *p, u32 a, u32 b);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);
extern u16 POKE_TOOL_AddMove(void *, u16);
extern void POKE_TOOL_PushMove(void *p, int move);

void *INTRUDE_FIELD_CreateSymbolMon(int heap, void *a1, const Entry *e)
{
    u8 *tbl;
    u8 lvl;
    u32 id;
    u32 pid;
    void *mon;

    tbl = (u8 *)ARC_UTIL_LoadMember(0xE3, 0, 0, heap);
    lvl = tbl[e->species];
    func_020307B0(tbl);
    id = func_02008530((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(a1));
    pid = POKE_TOOL_CreatePersonalRnd(id, (u16)e->species, (u16)e->f23, e->f21, 0, 0);
    mon = POKE_TOOL_Create(e->species, lvl, -1, heap);
    POKE_TOOL_SetupPartyParamEx(mon, e->species, lvl, id, -1, pid);
    POKE_TOOL_SetAbility(mon, e->species, e->f23);
    POKE_TOOL_ChangeForm(mon, (u16)e->f23);
    if (e->move != 0) {
        if (POKE_TOOL_AddMove(mon, e->move) == 0xFFFF)
            POKE_TOOL_PushMove(mon, (u16)e->move);
    }
    return mon;
}
