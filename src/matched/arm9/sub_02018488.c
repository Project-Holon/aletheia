/*
 * function: POKE_TOOL_IsBoxOwnedByPlayer
 * address:  0x02018488
 * packet:   pkt_02018488
 * note:     132 bytes, one function
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     re-verified 2026-09-21: EXACT.  The MATCH cap was lifted by the
 *           sole-ref widening of 2026-09-21, not by any edit to the C:
 *           the data address this file reaches now attests as
 *           sole-ref/data.  Promoted from src/pending/ unchanged.
 *
 * Why it WAS capped (historical, resolved 2026-09-21): the ABS32 against the 0x021462B0 scratch buffer.  A scan
 * of every word in all 242 regions finds 0x021462B0 exactly once, in the pool
 * word at 0x02018508 that this function owns, so the `literal` class discards
 * its only witness and no cut helps.  The buffer's neighbour 0x021462F0 is
 * named by six pool words and resolves; the two are 0x40 apart and are two
 * statics in one bss run rather than one object with an offset, so declaring
 * a single symbol at the attested one and reaching this one as a negative
 * addend would be a claim about the data layout the image does not support.
 * It closes the day anything else in the image names 0x021462B0.
 *
 * poke_tool.c: "does this record still belong to the trainer that owns this
 * mail", the comparison that unlocks the record with POKE_TOOL_DecodeBoxParam
 * (src/matched/unit_02017D30.c), reads the trainer id (field 0x07) and the
 * second name field (0x9A) out of it, reads the same two out of the mail
 * object through func_02008530 and func_02008550, copies both names into the
 * two 0x20 byte scratch buffers at 0x021462F0 and 0x021462B0, and compares
 * the strings with WORDSET_CheckF448.
 *
 * The three tests are one conjunction: all three conditional branches land on
 * the same address and there is one `movs r6, #1`
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * The four comparison operands are stack locals rather than registers because
 * they are live across the calls that follow them, and they sit at sp+0,
 * sp+4, sp+8 and sp+0xC in the order the source declares them last to first
 * (docs/idioms/local-declaration-order-is-stack-order.md).
 *
 * The lock flag is truncated to u8 on the way out of POKE_TOOL_DecodeBoxParam, which is
 * the `lsls #0x18` / `lsrs #0x18` pair at 0x02018494.
 *
 * symbols:
 *   gNameBuf  0x021462F0  data
 *   gNameCompareBuf  0x021462B0  data
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   WORDSET_CheckF448  0x0201F448  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/POKE_TOOL_IsBoxOwnedByPlayer.c \
 *       --addr 0x02018488 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sav;
struct Sub0200852CObj;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern u32  POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_020084F8(void *dst, u32 value, u32 size);
typedef unsigned short u16;
extern u32 WORDSET_CheckF448(const u16 *a, const u16 *b);

extern u8 gNameBuf[];
extern u8 gNameCompareBuf[];

u32 POKE_TOOL_IsBoxOwnedByPlayer(void *p, void *mail)
{
    u32 d;
    u32 c;
    u32 b;
    u32 a;
    u8  lock = (u8)POKE_TOOL_DecodeBoxParam(p);
    u32 r = 0;

    a = func_02008530(mail);
    b = POKE_TOOL_GetBoxValue(p, 7, 0);
    c = func_02008550(mail);
    d = POKE_TOOL_GetBoxValue(p, 0x9A, 0);
    func_020084F8(mail, (u32)gNameBuf, 0x20);
    POKE_TOOL_GetBoxValue(p, 0x8E, (u32)gNameCompareBuf);
    if (a == b && c == d && WORDSET_CheckF448((const u16 *)gNameBuf, (const u16 *)gNameCompareBuf) != 0) {
        r = 1;
    }
    POKE_TOOL_EncodeBoxParam(p, lock);
    return r;
}
