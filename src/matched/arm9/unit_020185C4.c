/*
 * unit:     yes
 * address:  0x020185C4
 * packet:   pkt_020185C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_RecalcParam
 *
 * 0x020185C4..0x020185F0, 44 bytes, one function.
 *
 * The shape is the lock/recompute/unlock sandwich the whole region uses:
 * POKE_TOOL_DecodePartyParam takes the lock and returns whether it actually took it, and
 * that flag is what POKE_TOOL_EncodePartyParam is handed back.  Between them it refreshes
 * the level (id 0x9E, from POKE_TOOL_CalcLevel) and then recalculates the six stats
 * with POKE_TOOL_CalcParam.
 *
 * What held it open, and what closed it: this is the only caller of
 * POKE_TOOL_CalcParam anywhere in the image, so the `label` class discards its only
 * witness under the honesty rule and no cut helps, because the range cannot be
 * made smaller than the one function that holds the call.  The `matched` class
 * carries it now: 0x02018A7C is src/matched/POKE_TOOL_CalcParam.c, an EXACT entry
 * proved byte for byte against the original over a range this file does not
 * touch.  It was parked in src/pending/ until that entry existed.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_020185C4.c \
 *       --addr 0x020185C4 --thumb
 *
 * symbols:
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   POKE_TOOL_CalcParam  0x02018A7C  thumb
 */

typedef unsigned int u32;

struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32  POKE_TOOL_CalcLevel(void *p);
extern void POKE_TOOL_CalcParam(void *p);

void POKE_TOOL_RecalcParam(void *p)
{
    u32 f = POKE_TOOL_DecodePartyParam(p);

    POKE_TOOL_SetPartyValue(p, 0x9E, POKE_TOOL_CalcLevel(p));
    POKE_TOOL_CalcParam(p);
    POKE_TOOL_EncodePartyParam(p, f);
}
