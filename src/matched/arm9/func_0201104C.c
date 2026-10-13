/*
 * function: GPOWER_UseHpRestore
 * address:  0x0201104C
 * packet:   pkt_0201104C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146208     0x02146208  data
 *   g_02146228     0x02146228  data
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 *   POKEPARTY_FindFirstBattleReady  0x0201AB08  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   GPOWER_ClearType  0x02010F50  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_UseHpRestore.c  *       --func GPOWER_UseHpRestore --addr 0x0201104C --cc 1.1p1 --thumb
 *
 * net_save.c, gated on mode byte +0x19 (slot 5): unless the +0xc factor
 * is 999, pick the record POKEPARTY_FindFirstBattleReady(box) names inside the box
 * (POKEPARTY_GetMember: box + 8 + idx * 0xdc), and add the +0xc factor to its
 * field 0xa0 clamped to field 0xa1, inside the POKE_TOOL_DecodePartyParam /
 * POKE_TOOL_EncodePartyParam access bracket; then clear slot 5.  Returns the index, or
 * 0xff when the mode byte is '0'.
 *
 * Wave 14 closed the entry residue shared with GPOWER_UsePpRestore and
 * GPOWER_ApplyCaptureRate (pool word loaded into r1 before the parameter copy):
 * it was ARITY, not order.  POKE_TOOL_HealParty, POKEPARTY_FindFirstBattleReady (a tail-call
 * forwarder that passes r0 through) and POKE_TOOL_DecodePartyParam all take the box
 * or record pointer, so r0 stays live across the guards.  The record is
 * a separate local from the box parameter (reassigning the parameter
 * swaps r4/r5).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 g_02146208[];
extern u8 g_02146228[];
extern void POKE_TOOL_HealParty(void *p);
extern u32 POKEPARTY_FindFirstBattleReady(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern void GPOWER_ClearType(int idx);

u32 GPOWER_UseHpRestore(void *box)
{
    void *p;
    u32 idx;
    u32 h;
    int max;
    int n;

    if (g_02146208[0x19] != 0x30) {
        if (*(u16 *)(g_02146228 + 0xc) == 999) {
            POKE_TOOL_HealParty(box);
            idx = 0;
        } else {
            idx = POKEPARTY_FindFirstBattleReady(box);
            p = POKEPARTY_GetMember(box, idx);
            h = POKE_TOOL_DecodePartyParam(p);
            max = POKE_TOOL_GetPartyValue(p, 0xa1, 0);
            n = POKE_TOOL_GetPartyValue(p, 0xa0, 0);
            n = n + *(u16 *)(g_02146228 + 0xc);
            if (n > max) {
                n = max;
            }
            POKE_TOOL_SetPartyValue(p, 0xa0, n);
            POKE_TOOL_EncodePartyParam(p, h);
        }
        GPOWER_ClearType(5);
        return idx;
    }
    return 0xff;
}
