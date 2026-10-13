/*
 * function: BTL_SIDE_SetupClientParty
 * address: 0x021B9460
 * packet: pkt_ov093_021B9460
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-05 (wave P5, pengy share): EXACT. Needs #pragma opt_lifetimes off (per-function
 * pragma) and the clear of nw written AFTER the BTL_MAIN_GetClientParty call (l2 = f(...); nw = 0;).
 * Written before the call, the zero took r0 instead of the original r1. Other levers: raw
 * offsets, early locals qs = a + 4 and qo = c * 0x1c, declaration order qo, qs, list, n, v, nw,
 * x, j, i, y, cnt, comma-form loop headers, e = POKEPARTY_GetMember() as its own statement.
 * symbols:
 *   BTL_MAIN_GetClientParty 0x021BA178 thumb ov093
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   BTL_POKEPARAM_Create 0x021D4D84 thumb ov093
 *   BTL_SLOT_Add 0x021B9B54 thumb ov093
 *   BTL_MAIN_FindLastLivingPartyIndex 0x021B9634 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_SetFakeMon 0x021D5848 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   BTL_SLOT_CompactLiving 0x021B9B60 thumb ov093
 *   data_021EFCF0 0x021EFCF0 data ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern const u8 data_021EFCF0[4];
extern void *BTL_MAIN_GetClientParty(void *p, int i, int mode);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
struct Q1;
struct QF;
struct QH;
struct S;
extern struct S *BTL_POKEPARAM_Create(void *a, u8 b, u32 c);
extern void BTL_SLOT_Add(struct Q1 *p, u32 v);
extern int BTL_MAIN_FindLastLivingPartyIndex(void *a);
extern int func_021D59B4(u8 *p, int k);
extern void BTL_POKEPARAM_SetFakeMon(struct QH *p, void *v);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void *POKE_TOOL_Create(u16 species, u16 level, u64 id, u16 heap);
extern void BTL_SLOT_CompactLiving(u8 *p);
#pragma opt_lifetimes off
void BTL_SIDE_SetupClientParty(char *a, char *b, u8 c)
{
    u32 qo;
    char *qs;
    void *list;
    u32 n;
    u8 *v;
    void *e;
    u8 nw;
    u8 x;
    u32 j;
    int i;
    u8 y;
    int cnt;
    list = BTL_MAIN_GetClientParty(b, c, *(u32 *)(a + 0xe4));
    qs = a + 4;
    qo = c * 0x1c;
    n = POKEPARTY_GetCount(list);
    x = data_021EFCF0[c];
    *(void **)(a + c * 4 + 0x74) = list;
    for (i = 0, y = x; i < n; i++, y++) {
        e = POKEPARTY_GetMember(list, i);
        *(void **)(a + y * 4 + 0x84) = BTL_POKEPARAM_Create(e, y, 0x12);
        BTL_SLOT_Add((struct Q1 *)(qs + qo), (u32)(*(void **)(a + y * 4 + 0x84)));
    }
    cnt = BTL_MAIN_FindLastLivingPartyIndex(list);
    if (cnt > 0) {
        for (i = 0, y = x; i < cnt; i++, y++) {
                if (func_021D59B4(*(u8 **)(a + y * 4 + 0x84), 0x11) == 0x95)
                    BTL_POKEPARAM_SetFakeMon(*(void **)(a + y * 4 + 0x84), POKEPARTY_GetMember(list, cnt));
            }
    }
    if (BTL_MAIN_GetCompetitor((void ***)b) == 0 && c == 1) {
        for (j = 0; j < n; j++, x++) {
            v = *(u8 **)(a + x * 4 + 0x84);
            if (BTL_POKEPARAM_GetSpecies((struct QF *)v) == 0x23B && func_021D59B4(v, 0x11) == 0x95) {
                void *l2;
                u8 m, q;
                l2 = BTL_MAIN_GetClientParty(b, 0, *(u32 *)(a + 0xe4));
                nw = 0;
                m = POKEPARTY_GetCount(l2);
                for (q = 0; q < m; q++) {
                    u16 s = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(l2, q), 5, 0);
                    if (s == 0xf3) { nw = 0xf4; break; }
                    if (s == 0xf4) { nw = 0xf5; break; }
                    if (s == 0xf5) { nw = 0xf3; break; }
                }
                if (nw != 0) {
                    if (*(void **)(b + 0x2c0) == 0)
                        *(void **)(b + 0x2c0) = POKE_TOOL_Create(nw, func_021D59B4(v, 0xf), 0, *(u16 *)(b + 0x468));
                    BTL_POKEPARAM_SetFakeMon((struct QH *)v, *(void **)(b + 0x2c0));
                }
            }
        }
    }
    BTL_SLOT_CompactLiving((u8 *)(qs + qo));
}
#pragma opt_lifetimes reset
