/*
 * function: POKE_TOOL_FindBoxMoveSlot
 * address:  0x02018240
 * packet:   pkt_02018240
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * status note: EXACT* -- the extent runs long because the unlabelled 8-byte
 *           thunk at 0x020182A0 follows without a label; never a byte
 *           difference.  Report it as an unlabelled follower for
 *           layout/function_starts.txt.
 *
 * WAS BLOCKED, now resolved (2026-09-22): the only branch to 0x020182A8 in the
 *           image is this function's own call at +0x30, so the `label` class
 *           had no outside witness and this file was capped at MATCH.
 *           src/matched/POKE_TOOL_ReplaceBoxMoveSlot.c now reproduces that address, so the
 *           site resolves through `matched` and this file is EXACT* with no
 *           edit to its C.
 *
 * symbols:
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   POKE_TOOL_ReplaceBoxMoveSlot  0x020182A8  thumb
 *
 * "Put this move in the first empty slot": walks ids 0x36..0x39 and returns
 * 0xFFFF when no slot was touched, the move when one was filled, and 0xFFFE
 * when the move was already known.  The loop counter is signed (`blt`), unlike
 * the otherwise identical loop in POKE_TOOL_RecoverBoxAllPP, which is `blo`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_TOOL_FindBoxMoveSlot.c \
 *       --func POKE_TOOL_FindBoxMoveSlot --addr 0x02018240 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern u32  POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_ReplaceBoxMoveSlot(void *p, u16 move, u8 slot);

u32 POKE_TOOL_FindBoxMoveSlot(void *p, u16 move)
{
    u32 r = 0xFFFF;
    u32 t = POKE_TOOL_DecodeBoxParam(p);
    int i;

    for (i = 0; i < 4; i++) {
        u32 m = (u16)POKE_TOOL_GetBoxValue(p, 0x36 + i, 0);

        if (m == 0) {
            POKE_TOOL_ReplaceBoxMoveSlot(p, move, (u8)i);
            r = move;
            break;
        }
        if (m == move) {
            r = 0xFFFE;
            break;
        }
    }
    POKE_TOOL_EncodeBoxParam(p, t);
    return r;
}
