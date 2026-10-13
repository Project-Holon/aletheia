/*
 * unit:     yes
 * address:  0x02017E40
 * packet:   pkt_02017E1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_SetPartyValue
 *
 * 0x02017E40..0x02017E64, 36 bytes, one function.
 *
 * The write wrapper for the party area of the 0xDC byte record, and the twin
 * of src/matched/unit_02017E1C.c: unlock, and only if the unlock reports 1
 * call the party-area setter POKE_TOOL_SetPartyValueRaw (src/matched/POKE_TOOL_SetPartyValueRaw.c), then
 * lock again.  It is the counterpart of POKE_TOOL_SetBoxValue in
 * src/matched/unit_02017E64.c, which does the same around POKE_TOOL_SetBoxValueRaw.
 *
 * What held it open, and what closed it: the `bl` at 0x02017E56 is the only
 * branch to POKE_TOOL_SetPartyValueRaw anywhere in the image, so no image class could
 * attest it from outside this range.  The `matched` class does:
 * 0x02019308 is src/matched/POKE_TOOL_SetPartyValueRaw.c, an EXACT entry proved against the
 * original bytes over a range this file does not touch.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02017E40.c \
 *       --addr 0x02017E40 --thumb
 *
 * symbols:
 *   POKE_TOOL_SetPartyValueRaw  0x02019308  thumb
 *   POKE_TOOL_DecodeCalcBlock  0x02018D10  thumb
 *   POKE_TOOL_EncodeCalcBlock  0x02018D6C  thumb
 */

typedef unsigned int u32;

struct Mon;
struct Sav;
extern u32 POKE_TOOL_DecodeCalcBlock(struct Sav *p);
extern void POKE_TOOL_EncodeCalcBlock(struct Sav *p);
extern void POKE_TOOL_SetPartyValueRaw(struct Mon *p, u32 id, u32 v);

void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v)
{
    if (POKE_TOOL_DecodeCalcBlock(p) == 1) {
        POKE_TOOL_SetPartyValueRaw(p, id, v);
    }
    POKE_TOOL_EncodeCalcBlock(p);
}
