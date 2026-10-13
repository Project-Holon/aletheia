/*
 * function: BTLV_CORE_CheckPartySlotCondition
 * address:  0x021E86C8
 * packet:   pkt_ov093_021E86C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-03: the `cmp r0,#1; beq; bne` pair is a disjunction of two tests that both
 * compare against 1 (likely two constants with the same value); the compiler keeps
 * one branch per operand.
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetCompetitor  0x021C8168  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_SERVER_FLOW_GetCompetitor(void *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);

int BTLV_CORE_CheckPartySlotCondition(void *a, int b)
{
    int r;

    if (BTL_SERVER_FLOW_GetCompetitor(a) == 0) {
        r = BTL_MAIN_PokeIdToClientIdThunk(b);
        if (r == 1 || r == 1)
            return 1;
    }
    return 0;
}
