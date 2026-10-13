/*
 * function: FIELD_EVENT_CHECK_FindPartyMemberWithMove
 * address:  0x0218B630
 * packet:   pkt_ov021_0218B630
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the index of the first non-egg party member that knows the given
 * move (checks move slots 0x36..0x39), or 6 when none does. Called with 0x39
 * (Surf).
 *
 * symbols:
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);

int FIELD_EVENT_CHECK_FindPartyMemberWithMove(void *sys, u32 move)
{
    int n;
    void *party;
    int i;

    party = GAME_DATA_GetMyParty(sys);
    n = func_0201AA18(party);

    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);

        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            if (move == POKE_TOOL_GetPartyValue(mon, 0x36, 0) || move == POKE_TOOL_GetPartyValue(mon, 0x37, 0)
                || move == POKE_TOOL_GetPartyValue(mon, 0x38, 0) || move == POKE_TOOL_GetPartyValue(mon, 0x39, 0))
                return i;
        }
    }
    return 6;
}
