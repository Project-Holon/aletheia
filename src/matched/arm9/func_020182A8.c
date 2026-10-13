/*
 * function: POKE_TOOL_ReplaceBoxMoveSlot
 * address:  0x020182A8
 * packet:   pkt_02018240
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E88  0x02017E88  thumb
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   WAZA_TOOL_GetMaxPP  0x0201C158  thumb
 *
 * "Write this move into slot `slot`, keeping the PP the slot already had".
 * The twin of POKE_TOOL_SetBoxMoveSlot (src/matched/unit_020181A0.c), which writes the
 * slot outright: this one remembers whether the slot held a move (b), reads
 * the slot's current PP (0x3A + slot, as a u8), writes the move id
 * (0x36 + slot), clears the PP-up count (0x3E + slot), and finally writes a PP
 * that is the fresh maximum WAZA_TOOL_GetMaxPP computes -- except that when the
 * slot was previously occupied the PP is clamped down to whatever the old
 * slot had, so replacing a move never raises its remaining PP.
 *
 * THE LEVER, and the whole 128-byte residue this file's earlier attempts hit
 * (docs/notes/pkt_02018240.c.txt records ten prologue bytes wrong across every
 * statement-shape and declaration-order spelling tried, and tools/permuter.py
 * -- 197 single mutations, --types -- cannot move any of them):
 *
 *     THE THIRD PARAMETER IS u8, NOT u32.
 *
 * That is the family's own first-pass rule -- a truncation emitted at the CALL
 * constrains the CALLEE's parameter width -- read off the single caller,
 * POKE_TOOL_FindBoxMoveSlot at 0x02018268:
 *
 *     02018268  lsls r2, r4, #0x18
 *     0201826E  lsrs r2, r2, #0x18      <- (u8)i at the call site
 *
 * With `u8 slot` the front end gives the parameter a memory home at sp+0 and
 * reloads it (`str r2,[sp]` ... `ldr r1,[sp]`), which is exactly the prologue
 * the original has; with `u32 slot` it keeps the incoming r2 in a register
 * (`adds r1, r2, #0`) and the five entry halfwords permute.  No statement
 * shape, declaration order, volatile, address-taking or extra parameter
 * reaches it -- only the width does.
 *
 * Filing this address also unblocks src/pending/POKE_TOOL_FindBoxMoveSlot.c, whose only
 * missing witness was a manifest entry at 0x020182A8 (its own call at +0x30 is
 * the sole branch to this address in the image, so the `label` class had no
 * outside witness).  That file turns EXACT with no edit.
 *
 * Nothing here is version specific: 0x36, 0x3A and 0x3E are field selectors.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_TOOL_ReplaceBoxMoveSlot.c \
 *       --func POKE_TOOL_ReplaceBoxMoveSlot --addr 0x020182A8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);

void POKE_TOOL_ReplaceBoxMoveSlot(void *p, u16 move, u8 slot)
{
    u32 b;
    u32 d;
    u32 c;
    u32 v = 0;
    u32 pp;

    d = slot + 0x36;
    if (func_02017E88(p, d, 0) != 0) {
        b = 1;
    } else {
        b = 0;
    }
    c = slot + 0x3A;
    pp = (u8)func_02017E88(p, c, 0);
    POKE_TOOL_SetBoxValue(p, d, move);
    POKE_TOOL_SetBoxValue(p, slot + 0x3E, 0);
    if (move != 0) {
        v = WAZA_TOOL_GetMaxPP(move, 0);
        if (b != 0) {
            if (v <= pp) {
                pp = v;
            }
            v = (u8)pp;
        }
    }
    POKE_TOOL_SetBoxValue(p, c, v);
}
