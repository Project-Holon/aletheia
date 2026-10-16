/*
 * unit:     yes
 * address:  0x02017E1C
 * packet:   pkt_02017E1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_GetPartyValue
 *
 * 0x02017E1C..0x02017E40, 36 bytes, one function.
 *
 * The read wrapper for the party area of the 0xDC byte record: unlock, call
 * the party-area dispatcher POKE_TOOL_GetPartyValueRaw (src/matched/POKE_TOOL_GetPartyValueRaw.c), lock
 * again and return its result.  It is the exact counterpart of POKE_TOOL_GetBoxValue
 * in src/matched/unit_02017E64.c, which does the same around POKE_TOOL_GetBoxValueRaw,
 * and it is the entry point 240 call sites in the image use.
 *
 * What held it open, and what closed it: the `bl` at 0x02017E2E is the only
 * branch to POKE_TOOL_GetPartyValueRaw anywhere in the image, so the `label` class has no
 * witness once the compared range holds it, and the range cannot be cut
 * smaller than the one function.  The `matched` class carries it instead:
 * 0x02018DB4 is src/matched/POKE_TOOL_GetPartyValueRaw.c, an EXACT entry whose own byte
 * comparison covered a range this file does not touch, so the witness is our
 * compiled proof rather than anything inside 0x02017E1C..0x02017E40.  Its
 * setter twin src/matched/unit_02017E40.c closes the same way over
 * POKE_TOOL_SetPartyValueRaw.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02017E1C.c \
 *       --addr 0x02017E1C --thumb
 *
 * symbols:
 *   POKE_TOOL_GetPartyValueRaw  0x02018DB4  thumb
 *   POKE_TOOL_DecodeCalcBlock  0x02018D10  thumb
 *   POKE_TOOL_EncodeCalcBlock  0x02018D6C  thumb
 */

typedef unsigned int u32;

struct Mon;
struct Sav;
extern u32 POKE_TOOL_DecodeCalcBlock(struct Sav *p);
extern void POKE_TOOL_EncodeCalcBlock(struct Sav *p);
extern u32 POKE_TOOL_GetPartyValueRaw(struct Mon *p, u32 id, u32 v);

u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v)
{
    u32 r;

    POKE_TOOL_DecodeCalcBlock(p);
    r = POKE_TOOL_GetPartyValueRaw(p, id, v);
    POKE_TOOL_EncodeCalcBlock(p);
    return r;
}
