/*
 * function: FIELD_EVENT_CHECK_CountAlivePartyMembers
 * address:  0x0218B6AC
 * packet:   pkt_ov021_0218B6AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int FIELD_EVENT_CHECK_CountAlivePartyMembers(void *ctx)
{
    void *list;
    void *e;
    int n;
    int i;
    int cnt;

    list = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(ctx));
    n = POKEPARTY_GetCount(list);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        e = POKEPARTY_GetMember(list, i);
        if (POKE_TOOL_GetPartyValue(e, 0x4C, 0) == 0 && POKE_TOOL_GetPartyValue(e, 0xA0, 0) != 0)
            cnt++;
    }
    return cnt;
}
