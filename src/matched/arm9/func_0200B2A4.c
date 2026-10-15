/*
 * function: REGULATION_BuildParty
 * address:  0x0200B2A4
 * packet:   pkt_0200B2A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   REGULATION_InitParty   0x0200B1F8  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   POKEPARTY_GetMember   0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue   0x02017E1C  thumb
 *   REGULATION_Party_SetValue   0x0200B254  thumb
 *
 * Rebuild the four per-slot fields for every entry the accessor count reports;
 * the count is a call, so it is re-evaluated on the loop back-edge, and the
 * third argument of every accumulate call is truncated to u8.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Rec1E;
extern void REGULATION_InitParty(struct Rec1E *p);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
typedef signed int     s32;
extern void REGULATION_Party_SetValue(struct Rec1E *p, int id, u8 n, s32 value);

void REGULATION_BuildParty(int a0, int a1)
{
    int i;

    REGULATION_InitParty((struct Rec1E *)a0);
    for (i = 0; i < (int)POKEPARTY_GetCount((void *)a1); i++) {
        int obj = (int)POKEPARTY_GetMember((void *)a1, i);

        if (POKE_TOOL_GetPartyValue((void *)obj, 0xa9, 0) != 0) {
            REGULATION_Party_SetValue((struct Rec1E *)a0, 0, i, POKE_TOOL_GetPartyValue((void *)obj, 5, 0));
            REGULATION_Party_SetValue((struct Rec1E *)a0, 1, i, POKE_TOOL_GetPartyValue((void *)obj, 0x6f, 0));
            REGULATION_Party_SetValue((struct Rec1E *)a0, 2, i, POKE_TOOL_GetPartyValue((void *)obj, 6, 0) != 0);
            REGULATION_Party_SetValue((struct Rec1E *)a0, 3, i, POKE_TOOL_GetPartyValue((void *)obj, 0x6e, 0));
        }
    }
}
