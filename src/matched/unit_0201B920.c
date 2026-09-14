/*
 * A single function, matched as a byte range because the function after it is
 * a near miss and a committed range has to be EXACT end to end.
 *
 * unit:     yes
 * address:  0x0201B920
 * packet:   pkt_0201B038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201B920
 *
 * pokeparty.c's "is this move slot short of PP" predicate: 78 bytes, three
 * reads of the party record and one call into the PP table.
 *
 * The three ids it reads are three parallel runs of the record's id space,
 * one per move slot: 0x36 + slot is the move, 0x3A + slot its current PP and
 * 0x3E + slot its PP ups.  src/matched/unit_0201C158.c turns the last two of
 * those into the slot's maximum, and the answer is whether the current PP is
 * below it.
 *
 * It stands alone rather than inside a unit with its neighbours because
 * sub_0201B970, which sits immediately after it, is a documented near miss
 * (docs/notes/sub_0201B970.c.txt) and a range cannot be committed while any
 * part of it is short of EXACT.  Its own single caller, sub_0201B9F0 at
 * 0x0201BA18, is parked in src/pending/unit_0201B9F0.c and resolves this
 * address through the `matched` class off this entry.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x36, 0x3A and 0x3E are party
 * record ids in src/matched/sub_02018DB4.c's space, and the three are written
 * out as three separate literals rather than derived from one base, so a
 * version that inserted a field into that id space would move all three
 * independently.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The function has two epilogues and only the second truncates the result.
 * That is what says the early exit returns the result *variable* while it is
 * still provably zero rather than the literal zero: `return 0;` would be a
 * `movs r0, #0` where the original copies r5, and a shared exit would need the
 * two tests to be one conjunction, which they cannot be because the second one
 * depends on the first's call
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * The result variable is therefore wider than the return type: declared `u8`
 * it needs no truncation at the tail and the function is two bytes short.
 *
 * The third id is built by advancing r7 in place (`adds r7, #0x3e` over the
 * register that held the slot), which is the last use of the slot number and
 * not a separate pointer.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_0201B920.c \
 *       --func sub_0201B920 --addr 0x0201B920 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u8  func_0201C158(u32 move, u32 ppUp);

u8 sub_0201B920(void *mon, u32 slot)
{
    u32 move;
    u8 pp;
    u8 ppUp;
    u32 r;

    r = 0;
    move = (u16)func_02017E1C(mon, slot + 0x36, 0);
    if (move == 0) {
        return r;
    }
    pp = (u8)func_02017E1C(mon, slot + 0x3A, 0);
    ppUp = (u8)func_02017E1C(mon, slot + 0x3E, 0);
    if (pp < func_0201C158(move, ppUp)) {
        r = 1;
    }
    return r;
}
