/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201B70C
 * packet:   pkt_0201B038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201B70C, sub_0201B718, sub_0201B764, sub_0201B774
 *
 * shinka_check.c's data layer: the four small routines the evolution checker
 * at 0x0201B2B0 reads its per-species evolution table through, plus the "does
 * this Pokemon already know that move" predicate one of its arms needs.
 *
 * All three archive routines name the same narc member kind, 0x13, the way
 * src/matched/unit_0201BD28.c's waza_tool.c names 0x15 and
 * src/matched/unit_0201ADD0.c's poke_personal.c names 0x12.  The record is
 * 0x2C bytes: seven six byte rows and a trailing halfword, and the three
 * halfwords of a row are what sub_0201B718's three arm switch selects between,
 * which is how the row layout is readable at all.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   0x13   the archive member kind for the evolution table.  A kind rather
 *          than a species id, so it moves only if the archive set is
 *          repacked, but it is content in the sense that nothing in the code
 *          derives it.
 *   7      the number of evolution rows per species, as the 0x2C byte record
 *          size fixes it.  A White build that gave a species an eighth
 *          evolution would change this record size and every one of these
 *          four functions with it.
 *   0x36, 0x3A   sub_0201B774's move id range: the four move slots of the
 *          party record, in src/matched/sub_02018DB4.c's id space.  Structure
 *          rather than content, but listed because the loop bound is written
 *          as the literal 0x3A and not as "0x36 + 4".
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * sub_0201B70C and sub_0201B764 are tail calls and nothing else, eight bytes
 * of code and a pool word each
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Neither could pass a
 * fourth argument even if it wanted to, because r3 carries the target
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md); sub_0201B764
 * passes exactly three and is at the limit.
 *
 * sub_0201B718's switch is a `cmp`/`beq` chain and not a jump table even
 * though its three labels are dense from zero, which is the count and not the
 * density deciding it
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md records the
 * opposite direction for a seven label switch).  The record's address is held
 * in r6 across the call because it is passed to it, so `case 0` reaches the
 * row with a register offset off r6 while `case 1` and `case 2` rebuild
 * `sp + 2` and `sp + 4`: that is the member offset, not a second pointer.
 *
 * sub_0201B774 keeps its answer in a stack slot carved out by the `r3` of the
 * prologue's `push`, and the third argument's zero is common
 * subexpression eliminated into r7 for the whole loop, which is why the
 * literal has to stay a literal at the call site rather than becoming a named
 * local.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02048F4C  0x02048F4C  arm
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201B70C.c \
 *       --addr 0x0201B70C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct EvoRow {
    u16 method;
    u16 param;
    u16 species;
};

struct EvoTable {
    struct EvoRow rows[7];
    u16 unk2A;
};

extern void *func_020490F4(unsigned int id, unsigned int heap);
struct ArcFile;
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_02048F4C(void *dest, u32 kind, u32 id);
extern u32 func_02017E1C(void *p, u32 id, u32 v);

void *sub_0201B70C(u32 heap)
{
    return func_020490F4(0x13, heap);
}

u32 sub_0201B718(void *a, u32 id, u32 row, u32 field)
{
    struct EvoTable t;

    func_0204932C(a, id, &t);
    switch (field) {
    case 0:
        return t.rows[row].method;
    case 1:
        return t.rows[row].param;
    case 2:
        return t.rows[row].species;
    }
    return 0;
}

void sub_0201B764(u32 id, void *dest)
{
    func_02048F4C(dest, 0x13, id);
}

u32 sub_0201B774(void *mon, u32 move)
{
    u32 found;
    s32 i;

    found = 0;
    for (i = 0x36; i < 0x3A; i++) {
        if (move == func_02017E1C(mon, i, 0)) {
            found = 1;
            break;
        }
    }
    return found;
}
