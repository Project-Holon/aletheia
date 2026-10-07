/*
 * file:     mcss_p10.c
 * unit:     yes
 * function: func_02017E1C, func_02017E40, func_02017E64, func_02017E88, func_02017EAC, func_02017EB4, func_02017ED8, func_02017F00, func_02017F08, func_02017F50, func_02017F90, func_02017F9C, func_02017FB0
 * address:  0x02017E1C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02018DB4  0x02018DB4  thumb
 *   func_02019308  0x02019308  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02017FB0  0x02017FB0  thumb
 *   func_02018D34  0x02018D34  thumb
 *   func_02018D8C  0x02018D8C  thumb
 *   func_02018E34  0x02018E34  thumb
 *   func_02019388  0x02019388  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_02018438  0x02018438  thumb
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_02018094  0x02018094  thumb
 *   func_020180FC  0x020180FC  thumb
 *   gLearnBuf      0x02146330  data
 */
struct Mon;
struct Sav;
struct Personal;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct Learn { u16 move; u16 level; };

extern u32 func_02018D10(struct Sav *p);
extern void func_02018D6C(struct Sav *p);
extern u32 func_02018DB4(struct Mon *p, u32 id, u32 v);
extern void func_02019308(struct Mon *p, u32 id, u32 v);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32  func_02017FB0(void *p);
extern u32 func_02018D34(struct Sav *p);
extern void func_02018D8C(struct Sav *p);
extern u32 func_02018E34(struct Mon *p, u32 id, u32 v);
extern void func_02019388(struct Mon *p, u32 id, u32 v);
extern void *func_02019C54(u32 a, u32 b);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern u32  func_02018438(void *p);
extern void func_0201ADD0(u32 species, int form, void *dest);
extern u32 func_02018094(void *p, u32 move);
extern void func_020180FC(void *p, u16 move);
u32 func_02017E1C(void *p, u32 id, u32 v);
void func_02017E40(void *p, u32 id, u32 v);
void func_02017E64(void *p, u32 id, u32 v);
u32 func_02017E88(void *p, u32 id, u32 v);
u32 func_02017EAC(void *p);
u32 func_02017EB4(void *p);
u32 func_02017ED8(u32 a, u32 b);
u8 func_02017F00(void *p);
u8 func_02017F08(void *p);
u8 func_02017F50(u32 a, u16 b, u32 c);
u32 func_02017F90(void *p);
void func_02017F9C(void *p, u32 v);
u32 func_02017FA8(void *p);
extern struct Learn gLearnBuf[];


/*
 * 0x02017E1C..0x02017E40, 36 bytes, one function.
 *
 * The read wrapper for the party area of the 0xDC byte record: unlock, call
 * the party-area dispatcher func_02018DB4 (src/matched/sub_02018DB4.c), lock
 * again and return its result.  It is the exact counterpart of func_02017E88
 * in src/matched/unit_02017E64.c, which does the same around func_02018E34,
 * and it is the entry point 240 call sites in the image use.
 *
 * What held it open, and what closed it: the `bl` at 0x02017E2E is the only
 * branch to func_02018DB4 anywhere in the image, so the `label` class has no
 * witness once the compared range holds it, and the range cannot be cut
 * smaller than the one function.  The `matched` class carries it instead:
 * 0x02018DB4 is src/matched/sub_02018DB4.c, an EXACT entry whose own byte
 * comparison covered a range this file does not touch, so the witness is our
 * compiled proof rather than anything inside 0x02017E1C..0x02017E40.  Its
 * setter twin src/matched/unit_02017E40.c closes the same way over
 * func_02019308.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02017E1C.c \
 *       --addr 0x02017E1C --thumb
 */
u32 func_02017E1C(void *p, u32 id, u32 v)
{
    u32 r;

    func_02018D10(p);
    r = func_02018DB4(p, id, v);
    func_02018D6C(p);
    return r;
}


/*
 * 0x02017E40..0x02017E64, 36 bytes, one function.
 *
 * The write wrapper for the party area of the 0xDC byte record, and the twin
 * of src/matched/unit_02017E1C.c: unlock, and only if the unlock reports 1
 * call the party-area setter func_02019308 (src/matched/sub_02019308.c), then
 * lock again.  It is the counterpart of func_02017E64 in
 * src/matched/unit_02017E64.c, which does the same around func_02019388.
 *
 * What held it open, and what closed it: the `bl` at 0x02017E56 is the only
 * branch to func_02019308 anywhere in the image, so no image class could
 * attest it from outside this range.  The `matched` class does:
 * 0x02019308 is src/matched/sub_02019308.c, an EXACT entry proved against the
 * original bytes over a range this file does not touch.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02017E40.c \
 *       --addr 0x02017E40 --thumb
 */
void func_02017E40(void *p, u32 id, u32 v)
{
    if (func_02018D10(p) == 1) {
        func_02019308(p, id, v);
    }
    func_02018D6C(p);
}


/*
 *           func_02017ED8, func_02017F00, func_02017F08, func_02017F50,
 *           func_02017F90, func_02017F9C, func_02017FA8
 *
 * Five of the eleven carry no label in the generated listing: the three eight
 * to twelve byte pool-word tail calls at 0x02017EAC, 0x02017F00 and
 * 0x02017FA8, and the two twelve byte argument-setting thunks at 0x02017F90
 * and 0x02017F9C, all of them
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  func_02017EAC, func_02017F00
 * and func_02017FA8 each tail call the function immediately after them, which
 * makes two of the three sites the `local` class.
 *
 * func_02017ED8 folds two words to sixteen bits and its four XOR operands have
 * exactly one source order, which is not the order the `eors` appear in; see
 * docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md.
 *
 * func_02017F50 dispatches 0, 0xFE and 0xFF out of a byte and falls through to
 * a comparison for everything else.  The three tests are one `switch`: written
 * as a chain of `if (n == k) return v;` statements each return gets its own
 * epilogue, while the switch puts the three bodies after the compare chain and
 * shares one `pop`, which is what the original does.  The `lsls`/`lsrs` pair
 * that truncates the call result is only emitted when the callee is declared
 * wider than `u8`, so func_0201AE1C returns a word and the source assigns it to
 * a byte local.
 */
void func_02017E64(void *p, u32 id, u32 v)
{
    if (func_02018D34(p) == 1) {
        func_02019388(p, id, v);
    }
    func_02018D8C(p);
}


u32 func_02017E88(void *p, u32 id, u32 v)
{
    u32 r;

    func_02018D34(p);
    r = func_02018E34(p, id, v);
    func_02018D8C(p);
    return r;
}


u32 func_02017EAC(void *p)
{
    return func_02017EB4(p);
}


u32 func_02017EB4(void *p)
{
    u32 a = func_02017E88(p, 7, 0);

    return func_02017ED8(a, func_02017E88(p, 0, 0));
}


u32 func_02017ED8(u32 a, u32 b)
{
    u32 x = ((a & 0xFFFF0000) >> 16) ^ (u16)a ^ ((b & 0xFFFF0000) >> 16) ^ (u16)b;

    if (x < 8) {
        return 1;
    }
    return 0;
}


u8 func_02017F00(void *p)
{
    return func_02017F08(p);
}


u8 func_02017F08(void *p)
{
    u32 t = func_02017DBC(p);
    u16 a = (u16)func_02017E88(p, 5, 0);
    u32 b = func_02017E88(p, 0x6F, 0);
    u32 c = func_02017E88(p, 0, 0);

    func_02017DE4(p, t);
    return func_02017F50(a, (u16)b, c);
}


u8 func_02017F50(u32 a, u16 b, u32 c)
{
    u8 n = func_0201AE1C(func_02019C54(a, b), 0x14);
    u8 r;

    switch (n) {
    case 0x00:
        return 0;
    case 0xFE:
        return 1;
    case 0xFF:
        return 2;
    }
    if ((u8)c < n) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}


u32 func_02017F90(void *p)
{
    return func_02017E1C(p, 0x9D, 0);
}


void func_02017F9C(void *p, u32 v)
{
    func_02017E40(p, 0x9D, v);
}


u32 func_02017FA8(void *p)
{
    return func_02017FB0(p);
}


static inline int Learn_IsEnd(const struct Learn *t)
{
    int end = 0;
    if (t->move == 0xFFFF && t->level == 0xFFFF)
        end = 1;
    return end;
}

/*
 * Reset a record's moves to its level-up set: clear the four move/PP/PP-up
 * slots, load the species/form learnset into the shared buffer at
 * 0x02146330, then teach every entry at or below the current level
 * (func_02018094; 0xFFFF = no free slot, so push it in with func_020180FC).
 * Block-lock sandwich (func_02017DBC / func_02017DE4).  Wave 11, 2026-09-23.
 *
 * Load-bearing: ONE loop variable `i` for both phases (the clearing loop
 * and the learnset walk, re-zeroed in between).  With two variables the
 * zero value argument and the walk index take separate registers and every
 * callee-saved register shifts (docs/idioms: reusing a loop variable
 * across phases); the permuter's hill (800, --types) found only volatile
 * hacks.  The frame's four entry copies and the pointer-taking terminator
 * inline follow func_02018328.c exactly (declaration order e, d, t, cur).
 */
u32 func_02017FB0(void *p)
{
    u32 flag;
    u16 species;
    u32 form;
    u8 level;
    int i;
    struct Learn e;
    struct Learn d;
    struct Learn t;
    struct Learn cur;

    flag = func_02017DBC(p);
    species = func_02017E88(p, 5, 0);
    form = func_02017E88(p, 0x6f, 0);
    level = func_02018438(p);
    func_0201ADD0(species, (u16)form, gLearnBuf);

    for (i = 0; i < 4; i++) {
        func_02017E64(p, 0x36 + i, 0);
        func_02017E64(p, 0x3a + i, 0);
        func_02017E64(p, 0x3e + i, 0);
    }
    i = 0;
    while (cur = gLearnBuf[i], t = cur, !Learn_IsEnd(&t)) {
        e = cur;
        if (e.level > level)
            break;
        d = cur;
        if (func_02018094(p, d.move) == 0xFFFF)
            func_020180FC(p, d.move);
        i++;
    }
    return func_02017DE4(p, flag);
}
