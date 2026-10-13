/*
 * unit:     yes
 * address:  0x0201808C
 * packet:   pkt_02017FB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201808C, sub_02018094
 *
 * poke_tool.c: "teach this move if there is room".  sub_02018094 unlocks the
 * record, walks the four move slots (ids 0x36 to 0x39 of the getter
 * func_02017E88), and writes the move into the first empty one through
 * POKE_TOOL_SetBoxMoveSlot (src/matched/unit_020181A0.c), locking again on the way out.
 * It answers with the move it wrote, 0xFFFE if the record already knows it,
 * and 0xFFFF if all four slots are full; sub_0201808C is a bare tail call to
 * it under a second name (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * 0xFFFE and 0xFFFF are ordinary integer constants and not relocations: both
 * are past the 255 an immediate reaches, so they arrive from the pool the way
 * any wide literal does.  The result is a stack local because it is live
 * across the unlock call, and it is assigned before the lock is taken, which
 * is what puts the `str` of 0xFFFF in front of the first `bl`.
 *
 * The third argument of every getter call comes out of a register that
 * already holds the loop counter's initial zero (`adds r7, r4, #0`), which is
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md
 * seen from the sharing side.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201808C.c \
 *       --addr 0x0201808C --thumb
 *
 * symbols:
 *   POKE_TOOL_SetBoxMoveSlot  0x020181FC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetBoxMoveSlot(void *p, u32 move, u8 slot);

u32 sub_02018094(void *p, u32 move);

u32 sub_0201808C(void *p, u32 move)
{
    return sub_02018094(p, move);
}

u32 sub_02018094(void *p, u32 move)
{
    u32 r = 0xFFFF;
    u32 lock = func_02017DBC(p);
    s32 i;

    for (i = 0; i < 4; i++) {
        u16 cur = (u16)func_02017E88(p, (u32)(0x36 + i), 0);

        if (cur == 0) {
            POKE_TOOL_SetBoxMoveSlot(p, move, (u8)i);
            r = move;
            break;
        }
        if (cur == move) {
            r = 0xFFFE;
            break;
        }
    }
    func_02017DE4(p, lock);
    return r;
}
