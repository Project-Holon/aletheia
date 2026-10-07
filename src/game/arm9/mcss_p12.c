/*
 * file:     mcss_p12.c
 * unit:     yes
 * function: func_02018198, func_020181A0, func_020181F4, func_020181FC, func_02018238, func_02018240, func_020182A0, func_020182A8, func_02018328, func_02018430, func_02018438, func_02018480, func_02018488, func_0201850C, func_02018544, func_0201854C, func_02018584, func_02018598, func_020185A0, func_020185B0, func_020185C4, func_020185F0, func_020185F4, func_020185F8, func_0201862C, func_020186C8, func_02018790, func_02018820, func_020188AC, func_020188B4, func_020188E0, func_0201891C, func_02018948,
 * address:  0x02018198
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
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017E64  0x02017E64  thumb
 *   func_0201C158  0x0201C158  thumb
 *   func_02030734  0x02030734  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_020307B0  0x020307B0  arm
 *   sPokeToolFile  0x020A72E4  data
 *   func_02018488  0x02018488  thumb
 *   g_021462F0  0x021462F0  data
 *   g_021462B0  0x021462B0  data
 *   gWordBuf  0x02146398  data
 *   func_02019BA4  0x02019BA4  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017D30  0x02017D30  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_02018430  0x02018430  thumb
 *   func_02018A7C  0x02018A7C  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AF6C  0x0201AF6C  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_02017ED8  0x02017ED8  thumb
 *   func_02018790_Table  0x0209E288  data
 *   _u32_div_f           0x0209C2B0  arm
 *   func_02018D10        0x02018D10  thumb
 *   func_02018D6C        0x02018D6C  thumb
 *   func_02019C38        0x02019C38  thumb
 */
struct Sav;
struct Sub0200852CObj;
struct Personal;
struct Mon;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Learn { u16 move; u16 level; };

typedef signed int     s32;

typedef unsigned long long u64;

struct Hdr {
    u32 unk00;
};

struct RecA {
    u8  unk00[0x1C];
    u32 unk1C;
};

struct RecB {
    u8  unk00[0x14];
    u32 unk14;
};

struct RecC {
    u8  unk00[0x18];
    u64 unk18;
};

extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void func_02017E64(void *p, u32 id, u32 v);
extern u8 func_0201C158(u16 move, u32 ppUp);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32   func_02017E1C(void *p, u32 id, u32 v);
extern void  func_0201ADD0(u32 species, int form, void *dest);
extern u16   func_0201808C(void *p, u16 move);
extern u32 func_020307B0(void *p);
extern u32 func_02018488(void *p, void *mail);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_020084F8(void *dst, u32 value, u32 size);
extern u32 func_0201F448(const u16 *a, const u16 *b);
extern void *func_02019C54(u32 a, u32 b);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void  func_02019B94(u32 a, void *b);
u32 func_02018430(void *p);
u32 func_02018438(void *p);
int func_02018480(void *p, int q);
u32 sub_02018488(void *p, void *mail);
u32 func_0201850C(u16 species, u16 form, u32 exp);
u32 func_02018544(void *p);
extern u32 func_02019BA4(u32 x, u32 i);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern void func_02018A7C(void *p);
extern u32  func_0201AF6C(u32 n);
extern u32 func_020056EC(u32 range);
extern u32 func_02017ED8(u32 a0, u32 a1);
u32 func_0201854C(void *p);
u32 func_02018584(u16 a, u16 b, u16 c);
u8 func_02018598(void *p);
u8 func_020185A0(void *p);
void func_020185B0(void *p, u32 v);
void func_020185C4(void *p);
void func_020185F0(void);
void *func_020185F4(void *p);
u32 func_020185F8(int a, int b, int c);
u32 func_0201862C(u32 a0, u16 a1, u16 a2, u8 a3, u8 a4, int a5);
u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
u32 func_02018790(void *p);
u32 func_02018820(void *p);
u32 func_020188AC(void *p, int v);
extern u32 func_02018D10(struct Sav *p);
extern void func_02018D6C(struct Sav *p);
extern void *func_02019C38(struct Mon *p, u32 pid, u32 n);
void func_02018198(void *mon);
void func_020181A0(void *p);
void func_020181F4(void *p, u16 move, u32 slot);
void func_020181FC(void *p, u16 move, u32 slot);
u32 func_02018238(void *p, u16 move);
u32 func_02018240(void *p, u16 move);
void func_020182A0(void *p, u16 move, u8 slot);
void func_020182A8(void *p, u16 move, u8 slot);
u32 func_020188B4(void *p, s32 v);
u32 func_020188E0(u16 a, u16 b, s32 v);
u32 func_0201891C(void *p, s32 v);
u32 func_02018948(u16 a, u16 b, s32 v);
extern u8    sPokeToolFile;
extern u8 g_021462F0[];
extern u8 g_021462B0[];
extern u32 gWordBuf[];
extern const u8 func_02018790_Table[];





/*
 * Unlabelled Thumb tail-call stub after func_020180FC (ldr r3, =func_020181A0;
 * bx r3). Filed as the witness for ov021 func_021C4340.
 */
void func_02018198(void *mon)
{
    func_020181A0(mon);
}





/*
 * Two move-slot writers over the record's ids 0x36..0x39 (the four move ids),
 * 0x3A..0x3D (their current PP) and 0x3E..0x41 (their PP-up counts), the same
 * three groups func_02018E34 reads.  func_020181A0 refills every non-empty
 * slot's PP to the maximum func_0201C158 computes from the move and its PP-up
 * count; func_020181FC writes one slot outright, clearing the PP-up count and
 * setting the PP to the fresh maximum, or to zero when the move is zero.
 * func_020181F4 in front of it is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk, `local` because its
 * target is the next function in this unit.
 *
 * func_020181FC is what makes this unit and src/matched/unit_02018094.c-shaped
 * callers attest each other: its two call sites in the image are the thunk
 * here and one inside func_02018094, so neither range can hold both.
 *
 * Two spellings are load bearing.  func_020181A0's loop counter is unsigned,
 * because the bound test is `blo` and not `blt`; the counter of the otherwise
 * identical loop in func_02018094 and func_02018240 is signed and those use
 * `blt`.  And the two truncations in func_020181A0 sit at the call, `(u16)m`
 * and `(u8)u` on word locals, rather than on narrower locals, which is the
 * same shape as src/matched/unit_02018430.c.
 *
 * Nothing here is version specific: 0x36, 0x3A and 0x3E are field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_020181A0.c \
 *       --addr 0x020181A0 --thumb
 */
void func_020181A0(void *p)
{
    u32 t = func_02017DBC(p);
    u32 i;

    for (i = 0; i < 4; i++) {
        u32 m = func_02017E88(p, 0x36 + i, 0);

        if (m != 0) {
            u32 u = func_02017E88(p, 0x3E + i, 0);

            func_02017E64(p, 0x3A + i, func_0201C158((u16)m, (u8)u));
        }
    }
    func_02017DE4(p, t);
}





void func_020181F4(void *p, u16 move, u32 slot)
{
    func_020181FC(p, move, slot);
}





void func_020181FC(void *p, u16 move, u32 slot)
{
    u32 pp = 0;

    func_02017E64(p, 0x36 + slot, move);
    func_02017E64(p, 0x3E + slot, 0);
    if (move != 0) {
        pp = func_0201C158(move, 0);
    }
    func_02017E64(p, 0x3A + slot, pp);
}





u32 func_02018238(void *p, u16 move)
{
    return func_02018240(p, move);
}





/*
 * status note: EXACT* -- the extent runs long because the unlabelled 8-byte
 *           thunk at 0x020182A0 follows without a label; never a byte
 *           difference.  Report it as an unlabelled follower for
 *           layout/function_starts.txt.
 *
 * WAS BLOCKED, now resolved (2026-09-22): the only branch to 0x020182A8 in the
 *           image is this function's own call at +0x30, so the `label` class
 *           had no outside witness and this file was capped at MATCH.
 *           src/matched/func_020182A8.c now reproduces that address, so the
 *           site resolves through `matched` and this file is EXACT* with no
 *           edit to its C.
 *
 * "Put this move in the first empty slot": walks ids 0x36..0x39 and returns
 * 0xFFFF when no slot was touched, the move when one was filled, and 0xFFFE
 * when the move was already known.  The loop counter is signed (`blt`), unlike
 * the otherwise identical loop in func_020181A0, which is `blo`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02018240.c \
 *       --func func_02018240 --addr 0x02018240 --cc 1.1p1 --thumb
 */
u32 func_02018240(void *p, u16 move)
{
    u32 r = 0xFFFF;
    u32 t = func_02017DBC(p);
    int i;

    for (i = 0; i < 4; i++) {
        u32 m = (u16)func_02017E88(p, 0x36 + i, 0);

        if (m == 0) {
            func_020182A8(p, move, (u8)i);
            r = move;
            break;
        }
        if (m == move) {
            r = 0xFFFE;
            break;
        }
    }
    func_02017DE4(p, t);
    return r;
}





void func_020182A0(void *p, u16 move, u8 slot)
{
    func_020182A8(p, move, slot);
}





/*
 * "Write this move into slot `slot`, keeping the PP the slot already had".
 * The twin of func_020181FC (src/matched/unit_020181A0.c), which writes the
 * slot outright: this one remembers whether the slot held a move (b), reads
 * the slot's current PP (0x3A + slot, as a u8), writes the move id
 * (0x36 + slot), clears the PP-up count (0x3E + slot), and finally writes a PP
 * that is the fresh maximum func_0201C158 computes -- except that when the
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
 * func_02018240 at 0x02018268:
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
 * Filing this address also unblocks src/pending/func_02018240.c, whose only
 * missing witness was a manifest entry at 0x020182A8 (its own call at +0x30 is
 * the sole branch to this address in the image, so the `label` class had no
 * outside witness).  That file turns EXACT with no edit.
 *
 * Nothing here is version specific: 0x36, 0x3A and 0x3E are field selectors.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/func_020182A8.c \
 *       --func func_020182A8 --addr 0x020182A8 --cc 1.1p1 --thumb
 */
void func_020182A8(void *p, u16 move, u8 slot)
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
    func_02017E64(p, d, move);
    func_02017E64(p, slot + 0x3E, 0);
    if (move != 0) {
        v = func_0201C158(move, 0);
        if (b != 0) {
            if (v <= pp) {
                pp = v;
            }
            v = (u8)pp;
        }
    }
    func_02017E64(p, c, v);
}





static inline int Learn_IsEnd(const struct Learn *t)
{
    int end = 0;
    if (t->move == 0xFFFF && t->level == 0xFFFF)
        end = 1;
    return end;
}

/*
 * Level-up learnset scan: load the species/form learnset (func_0201ADD0) into
 * a 0x68-byte heap block (poke_tool.c line 0x644), then walk it from *idx
 * until the {0xFFFF, 0xFFFF} terminator.  For an entry at the record's
 * level, try to teach it (func_0201808C): 0xFFFF (no free slot) answers the
 * move with bit 15 set, 0xFFFE (already known) keeps scanning, anything else
 * is returned; *idx is left one past the entry.  Wave 11, 2026-09-23.
 *
 * Load-bearing, found by hand after the permuter's hill (800, --types) and
 * the r12 lane's register swap:
 *   - `species` is u16 (truncated at the assignment) but `form` is u32 and
 *     the (u16) lands at the func_0201ADD0 call; `level` is u8.
 *   - FIVE 4-byte struct copies live in the frame, in this declaration
 *     order (later declaration at the lower address): e, d, f, t, cur.
 *     They are by-value copies of the entry (e for the level test, d for the
 *     move, f for the final re-read, t for the terminator test).  Written
 *     as inline helpers taking the struct by value, the compiler elides one
 *     copy and swaps two slots; spelled as explicit locals it does not.
 *   - the terminator test is an inline taking `const struct Learn *` with
 *     the `end = 0; if (..) end = 1;` accumulator, called in the `while`
 *     condition so the loop is rotated (entry `b` to the test).
 *   - `level == e.level` (level first: cmp r0, r1).
 */
u16 func_02018328(void *p, u32 *idx, u32 heap)
{
    struct Learn *tbl;
    u16 species;
    u32 form;
    u8 level;
    u16 ret = 0;
    struct Learn e;
    struct Learn d;
    struct Learn f;
    struct Learn t;
    struct Learn cur;

    tbl = func_02030734((u16)((heap & 0x7fff) | 0x8000), 0x68, 0, (const char *)&sPokeToolFile, 0x644);
    species = func_02017E1C(p, 5, 0);
    form = func_02017E1C(p, 0x6f, 0);
    level = func_02017E1C(p, 0x9e, 0);
    func_0201ADD0(species, (u16)form, tbl);

    while (cur = tbl[*idx], t = cur, !Learn_IsEnd(&t)) {
        e = cur;
        if (level == e.level) {
            d = cur;
            ret = func_0201808C(p, d.move);
            if (ret == 0xFFFF) {
                f = tbl[*idx];
                ret = f.move | 0x8000;
                (*idx)++;
                break;
            }
            if (ret != 0xFFFE) {
                (*idx)++;
                break;
            }
        }
        (*idx)++;
    }
    func_020307B0(tbl);
    return ret;
}


/*
 * The record's level accessor: it unlocks the block area, reads ids 5, 0x6F
 * and 8 out of it (species, form and experience), locks it again and hands the
 * three to func_0201850C (src/matched/unit_0201850C.c), which is the same
 * computation id 0x9E of func_02018E34 performs directly on the substructs.
 * func_02018430 in front of it is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk with no prologue, and
 * its pool word is `local` because its target is the next function in the same
 * unit.
 *
 * The three values are held in word locals and truncated at the call, not at
 * the assignment: the two `lsls #0x10` / `lsrs #0x10` pairs sit immediately in
 * front of the `bl`, after the lock call, which is what fixes func_0201850C's
 * first two parameters as u16 and func_02017E88's return as a word.  The same
 * shape appears in src/matched/unit_02017E64.c and src/matched/unit_0201854C.c.
 *
 * The range stops at 0x02018480, where another eight byte thunk forwards to
 * func_02018488; that thunk's pool word is the only reference to func_02018488
 * in the image, and func_02018488 in turn is the only caller of 0x020084F8, so
 * neither can be attested and both are left out.
 *
 * Nothing here is version specific: 5, 0x6F and 8 are field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02018430.c \
 *       --addr 0x02018430 --thumb
 */
u32 func_02018430(void *p)
{
    return func_02018438(p);
}


u32 func_02018438(void *p)
{
    u32 t = func_02017DBC(p);
    u32 species = func_02017E88(p, 5, 0);
    u32 form = func_02017E88(p, 0x6F, 0);
    u32 exp = func_02017E88(p, 8, 0);

    func_02017DE4(p, t);
    return func_0201850C((u16)species, (u16)form, exp);
}


/*
 * Eight byte thunk (pool word and bx) that forwards both arguments to
 * func_02018488. Witness for the ov093 caller func_021BCFAC.
 */
int func_02018480(void *p, int q)
{
    return func_02018488(p, (void *)q);
}


/*
 * note:     132 bytes, one function
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
 * mail", the comparison that unlocks the record with func_02017DBC
 * (src/matched/unit_02017D30.c), reads the trainer id (field 0x07) and the
 * second name field (0x9A) out of it, reads the same two out of the mail
 * object through func_02008530 and func_02008550, copies both names into the
 * two 0x20 byte scratch buffers at 0x021462F0 and 0x021462B0, and compares
 * the strings with func_0201F448.
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
 * The lock flag is truncated to u8 on the way out of func_02017DBC, which is
 * the `lsls #0x18` / `lsrs #0x18` pair at 0x02018494.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/sub_02018488.c \
 *       --addr 0x02018488 --thumb
 */
u32 sub_02018488(void *p, void *mail)
{
    u32 d;
    u32 c;
    u32 b;
    u32 a;
    u8  lock = (u8)func_02017DBC(p);
    u32 r = 0;

    a = func_02008530(mail);
    b = func_02017E88(p, 7, 0);
    c = func_02008550(mail);
    d = func_02017E88(p, 0x9A, 0);
    func_020084F8(mail, (u32)g_021462F0, 0x20);
    func_02017E88(p, 0x8E, (u32)g_021462B0);
    if (a == b && c == d && func_0201F448((const u16 *)g_021462F0, (const u16 *)g_021462B0) != 0) {
        r = 1;
    }
    func_02017DE4(p, lock);
    return r;
}


/*
 * Experience to level.  This is the callee of id 0x9E of func_02018E34
 * (src/pending/sub_02018E34.c), which passes it a species id, the five bit
 * form field of substruct B +0x18 and the experience word of substruct A +8.
 * It reads field 0x17 of the species' record, which is the growth-rate
 * selector, fills the shared word buffer at 0x02146398 with that curve through
 * func_02019B94, and then walks entries 1 to 0x64 for the first one that
 * exceeds the experience, returning the index before it.
 *
 * The loop is a `for` whose bound test the compiler rotates to the bottom, so
 * the first table read happens before any comparison with 0x65; the counter is
 * u16, which is what the `lsls #0x10` / `lsrs #0x10` pair after each increment
 * is, and writing it `u32` drops that pair and the function is four bytes
 * short.
 *
 * The range stops at 0x02018544, where an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk forwards to
 * func_0201854C.  That thunk's pool word is the only reference to
 * func_0201854C in the image, so including it caps the file at MATCH; it is
 * left out and this function is clean.
 *
 * 0x02146398 is the same scratch buffer func_02019BA4 fills in
 * src/matched/unit_02019B58.c, which is what attests it here and what this
 * file's pool word attests there: the pairwise case of docs/MATCHING.md.
 *
 * Nothing here is version specific; 0x17 is a field selector and 0x65 is the
 * level table's length.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201850C.c \
 *       --addr 0x0201850C --thumb
 */
u32 func_0201850C(u16 species, u16 form, u32 exp)
{
    u16 i;

    func_02019B94((u16)func_0201AE1C(func_02019C54(species, form), 0x17),
                  gWordBuf);
    for (i = 1; i < 0x65; i = (u16)(i + 1)) {
        if (gWordBuf[i] > exp) {
            break;
        }
    }
    return i - 1;
}

u32 func_02018544(void *p) { return func_0201854C(p); }



/*
 * 0x0201854C..0x02018598, 76 bytes, two functions.
 *
 * What held it open, and what closed it: func_02018584 is the only caller of
 * func_02019BA4 in the whole image, so the `label` class has no witness once
 * the compared range holds that call, and no cut helps because the range
 * cannot be made smaller than the one function that needs it.  The `matched`
 * class carries it: 0x02019BA4 is inside src/matched/unit_02019B58.c, an
 * EXACT entry whose byte comparison covered that address over a range this
 * file does not touch.  Keeping func_0201854C with func_02018584 costs
 * nothing, since func_0201854C is in turn the only caller of func_02018584.
 *
 * The three ids this reads, 5, 0x6F and 0x9E, are the same three
 * func_020188B4 and func_02019CA0 read, and all three values are truncated to
 * u16 at the call rather than at the assignment, which is what fixes
 * func_02018584's parameters as u16 and the accessor's return as a word.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201854C.c \
 *       --addr 0x0201854C --thumb
 */
u32 func_0201854C(void *p)
{
    u32 a = func_02017E88(p, 5, 0);
    u32 b = func_02017E88(p, 0x6F, 0);
    u32 c = func_02017E88(p, 0x9E, 0);

    return func_02018584((u16)a, (u16)b, (u16)c);
}



u32 func_02018584(u16 a, u16 b, u16 c)
{
    return func_02019BA4(func_02019C90(a, b, 0x17), c);
}



/*
 * The middle piece of the run 0x0201854C..0x0201862C.  Its two neighbours are
 * parked in src/pending/: func_02018584 is the only caller of func_02019BA4
 * in the image and func_020185C4 the only caller of func_02018A7C, so neither
 * has a witness outside itself and no cut reaches them.
 *
 * func_02018598 carries no label: it is the eight byte pool-word tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md to the function that follows
 * it, so the site is the `local` class.
 */
u8 func_02018598(void *p)
{
    return func_020185A0(p);
}



u8 func_020185A0(void *p)
{
    return (u8)func_02017E88(p, 0x70, 0);
}



void func_020185B0(void *p, u32 v)
{
    func_02017E40(p, 0x70, v);
    func_020185C4(p);
}



/*
 * 0x020185C4..0x020185F0, 44 bytes, one function.
 *
 * The shape is the lock/recompute/unlock sandwich the whole region uses:
 * func_02017D30 takes the lock and returns whether it actually took it, and
 * that flag is what func_02017D70 is handed back.  Between them it refreshes
 * the level (id 0x9E, from func_02018430) and then recalculates the six stats
 * with func_02018A7C.
 *
 * What held it open, and what closed it: this is the only caller of
 * func_02018A7C anywhere in the image, so the `label` class discards its only
 * witness under the honesty rule and no cut helps, because the range cannot be
 * made smaller than the one function that holds the call.  The `matched` class
 * carries it now: 0x02018A7C is src/matched/sub_02018A7C.c, an EXACT entry
 * proved byte for byte against the original over a range this file does not
 * touch.  It was parked in src/pending/ until that entry existed.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_020185C4.c \
 *       --addr 0x020185C4 --thumb
 */
void func_020185C4(void *p)
{
    u32 f = func_02017D30(p);

    func_02017E40(p, 0x9E, func_02018430(p));
    func_02018A7C(p);
    func_02017D70(p, f);
}



/*
 * func_020185F0 and func_020185F4 are a bare `bx lr` padded to four bytes,
 * which is `void f(void) {}`: a hook that was never filled in.  Neither
 * carries a label in the generated listing.  func_020185F0 is reached from
 * func_02019B58, which is what attests the pair's addresses.
 */
void func_020185F0(void)
{
}



void *func_020185F4(void *p)
{
    return p;
}



u32 func_020185F8(int a, int b, int c)
{
    u32 r = 8;
    u8 n = (u8)func_0201AE1C(func_02019C54(a, b), 0x14);

    if (func_0201AF6C(n) != 1) {
        if (c == 0) {
            r = n;
        } else {
            r = n - 1;
            if (n == 0) {
                r = 0;
            }
        }
    }
    return r;
}



/*
 * Force a personality value's shininess against trainer id a0: with a5 set,
 * a fresh value from func_020185F8 whose high half is made to xor to the
 * id's key; otherwise an all-0xFF00 construction plus the species' stage
 * byte.  Bit 16 is then forced to a4.  Wave 11, 2026-09-23.
 *
 * The 9-byte residue of 2026-09-22 (permuter floor, `commute(^)`) closed by
 * naming the id key as a block-scoped local, `k = hi(a0) ^ (u16)a0`, and
 * writing `k ^ (u16)v`: the key is computed first into r2 and the chain
 * stays in r1/r2, as the image has it.  No inline form of the same xor
 * reached it (docs/notes/pkt_0201862C.c.txt).
 */
u32 func_0201862C(u32 a0, u16 a1, u16 a2, u8 a3, u8 a4, int a5)
{
    if (a5 != 0) {
        u32 v = func_020185F8(a1, a2, a3);

        {
            u32 k = ((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0;

            a0 = v | ((k ^ (u16)v) << 16);
        }
        if ((a0 & 0x10000u) != ((u32)a4 << 16)) {
            a0 ^= 0x10000u;
        }
    } else {
        u8 b = (u8)func_0201AE1C(func_02019C54(a1, a2), 0x14);

        a0 = (0xFF00u ^ ((((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0) & 0xFF00u)) << 16;
        if ((a0 & 0x10000u) != ((u32)a4 << 16)) {
            a0 ^= 0x10000u;
        }
        if (func_0201AF6C(b) == 1) {
            goto done;
        }
        a0 |= b;
        if (a3 == 1) {
            a0 -= 1;
        }
    }
done:
    return a0;
}



/*
 * Build a personality value for trainer id a0: a3 selects the gender
 * handling (2 = fully random), a5 the shininess (1 = force shiny through
 * the id key, 0 = force NOT shiny by flipping bit 28 when func_02017ED8
 * says shiny, 2 = leave), and bit 16 is forced to a4 (read as a word, so
 * a4 is int-sized).  Wave 11, 2026-09-23.
 *
 * The 8-byte shortfall of the r4-3/r4-6 lanes ("duplicated compare, shared
 * eors", judged a cross-jump no source can request) is the SOURCE shape:
 * case 1 carries its own bit-16 fix and `break`s, case 0 FALLS THROUGH into
 * case 2, which carries the other copy; the compiler tail-merges the two
 * `v ^= 0x10000` statements and nothing else.  Case bodies in the order
 * 1, 0, 2; the case-1 key written `hi(a0) ^ (u16)a0` first.
 */
u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5)
{
    u32 v;

    if (a3 == 2) {
        v = func_020056EC(0);
    } else {
        u32 t = func_020056EC(0) & ~0xFFu;

        v = func_020185F8(a1, a2, (u8)a3);
        if (a3 == 0) {
            if (func_0201AF6C(v) == 0) {
                v = v + func_020056EC(0xFE - v);
                goto L;
            }
        }
        if (a3 == 1) {
            if (func_0201AF6C(v) == 0) {
                v = func_020056EC(v) + 1;
            }
        }
    L:
        v |= t;
    }
    switch (a5) {
    case 1:
        v = (u8)v | (((((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0) ^ (u8)v) << 16);
        if ((v & 0x10000u) != ((u32)a4 << 16)) {
            v ^= 0x10000u;
        }
        break;
    case 0:
        if (func_02017ED8(a0, v) == 1) {
            v ^= 0x10000000u;
        }
    case 2:
        if ((v & 0x10000u) != ((u32)a4 << 16)) {
            v ^= 0x10000u;
        }
        break;
    }
    return v;
}



/*
 * note:     144 bytes, one function
 *
 * The type half of the Hidden Power pair; the power half is
 * src/matched/unit_02018820.c and is EXACT.  It folds bit 0 of each of the six
 * 5 bit fields at substruct B +0x10 into a 0..63 index, scales it by 15/63,
 * reduces it below 17 with a subtract loop rather than a modulo, and indexes a
 * byte table at 0x0209E288.
 *
 * Why it WAS capped (historical, resolved 2026-09-21): the pool word at 0x0201881C is the only word in the whole
 * image that holds 0x0209E288, so the `literal` class discards its only
 * witness and the table cannot be attested.  Same shape as
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md.  No cut helps:
 * the load and the pool word are in the one function.
 *
 * The reduction is a `while (n > 16) n -= 16;` and not `n %= 16`, which would
 * be a single `ands`; and the division is unsigned, so the whole expression is
 * `n * 15 / 63`.
 *
 * VERSION SENSITIVITY: the 17 byte table at 0x0209E288 is type ids, which is
 * content numbering; it is expected to be identical in a White build, but it
 * is data rather than structure and should be re-read.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_02018790.c \
 *       --addr 0x02018790 --thumb
 *
 * RESOLVED 2026-09-21: the sole-ref widening accepts 0x0209E288 as
 * sole-ref/data, so the table now attests and this unit verifies EXACT with no
 * change to its C.  The one edit this wave made is the missing `_u32_div_f`
 * line in the symbols: block below -- without it that site was unresolved and
 * the unit reported MATCH for a reason that had nothing to do with the table.
 *
 * Historical note, no longer binding:
 * The `matched` class does not reach it either: an EXACT entry attests the code
 * it reproduced, never a data object one of its instructions loads, and
 * 0x0209E288 is a table.
 */
u32 func_02018790(void *p)
{
    u32 n = 0;

    if (func_02017E1C(p, 0x46, 0) & 1) {
        n += 1;
    }
    if (func_02017E1C(p, 0x47, 0) & 1) {
        n += 2;
    }
    if (func_02017E1C(p, 0x48, 0) & 1) {
        n += 4;
    }
    if (func_02017E1C(p, 0x49, 0) & 1) {
        n += 8;
    }
    if (func_02017E1C(p, 0x4A, 0) & 1) {
        n += 16;
    }
    if (func_02017E1C(p, 0x4B, 0) & 1) {
        n += 32;
    }
    n = n * 15 / 63;
    while (n > 16) {
        n -= 16;
    }
    return func_02018790_Table[n];
}



/*
 * Folds the six ids 0x46 to 0x4B, the six 5 bit fields of substruct B +0x10
 * that func_02018E34 reads, into a 0 to 63 index on bit 1 of each and scales
 * it to 30..70.  Its neighbour func_02018790 is the same fold on bit 0 with a
 * table lookup at the end, and the two are the pair a Hidden Power power and
 * type are computed with.
 *
 * The range is one function on purpose.  func_02018790, immediately before,
 * reads a byte table at 0x0209E288 whose only reference anywhere in the image
 * is the pool word under test, so it caps at MATCH however it is written; and
 * func_020188AC, immediately after, is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk whose pool word is the
 * only reference to func_020188B4 in the image, so it caps too.  Both are
 * byte-correct and neither can be cut free; this middle function is what is
 * left, and it is clean.
 *
 * The six tests are `(x & 3) > 1` rather than a bit test, which is `movs #3` /
 * `ands` / `cmp #1` / `bls`; the accumulator takes `adds rD, rN, #imm3` for 1,
 * 2 and 4 and `adds rD, #imm8` from 8 up, which is encoding and not source.
 * The scale is one `muls` by 40 and one `_u32_div_f` by 63, so the division is
 * unsigned and written as `n * 40 / 63 + 30`; `+ 30` folds into the `adds`
 * after the call.
 *
 * Nothing here is version specific: the six ids are structure field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02018820.c \
 *       --addr 0x02018820 --thumb
 */
u32 func_02018820(void *p)
{
    u32 n = 0;

    if ((func_02017E1C(p, 0x46, 0) & 3) > 1) {
        n += 1;
    }
    if ((func_02017E1C(p, 0x47, 0) & 3) > 1) {
        n += 2;
    }
    if ((func_02017E1C(p, 0x48, 0) & 3) > 1) {
        n += 4;
    }
    if ((func_02017E1C(p, 0x49, 0) & 3) > 1) {
        n += 8;
    }
    if ((func_02017E1C(p, 0x4A, 0) & 3) > 1) {
        n += 16;
    }
    if ((func_02017E1C(p, 0x4B, 0) & 3) > 1) {
        n += 32;
    }
    return n * 40 / 63 + 30;
}



/*
 * Eight byte tail-call thunk to func_020188B4
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Filed as the relocation
 * witness for ov021 func_021B62C8 (wave A1).
 */
u32 func_020188AC(void *p, int v)
{
    return func_020188B4(p, v);
}


/*
 *           func_0201897C
 *
 * The three functions at 0x020189D0, 0x020189D8 and 0x020189F0 sit between
 * this file and src/matched/unit_02018A00.c and are a documented near miss:
 * every concrete byte of them is reproduced, but func_020189F0 loads the
 * s8[][5] table at 0x0209E2A4 and the only word in the image that holds that
 * address is the pool word under test, so no cut attests it.  See
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md for the same
 * shape on a string.
 */
u32 func_020188B4(void *p, s32 v)
{
    u16 a = (u16)func_02017E88(p, 5, 0);
    u16 b = (u16)func_02017E88(p, 0x6F, 0);

    return func_020188E0(a, b, v);
}


u32 func_020188E0(u16 a, u16 b, s32 v)
{
    u32 r;

    if (a == 0x28A) {
        r = 0;
    } else if (func_02019C90(a, b, v / 32 + 0x27) & (1 << (v % 32))) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}


u32 func_0201891C(void *p, s32 v)
{
    u16 a = (u16)func_02017E1C(p, 5, 0);
    u16 b = (u16)func_02017E1C(p, 0x6F, 0);

    return func_02018948(a, b, v);
}


u32 func_02018948(u16 a, u16 b, s32 v)
{
    u32 r;

    if (a == 0x28A) {
        r = 0;
    } else if (func_02019C90(a, b, 0x2B) & (1 << (v % 32))) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}


u32 func_0201897C(struct Hdr *p)
{
    u32 r;
    struct RecA *a;
    struct RecB *b;
    struct RecC *c;

    func_02018D10((struct Sav *)p);
    r = 0;
    a = func_02019C38((struct Mon *)p, p->unk00, 0);
    b = func_02019C38((struct Mon *)p, p->unk00, 1);
    c = func_02019C38((struct Mon *)p, p->unk00, 2);
    if (a->unk1C != 0 || b->unk14 != 0 || c->unk18 != 0) {
        r = 1;
    }
    func_02018D6C((struct Sav *)p);
    return r;
}
