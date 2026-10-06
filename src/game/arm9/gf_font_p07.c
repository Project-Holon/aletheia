/*
 * file:     gf_font_p07.c
 * unit:     yes
 * function: func_0201EC74, func_0201ED04, func_0201ED50, func_0201ED64, func_0201ED84, func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84, func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4, func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C, func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98, func_0201EFA4, func_0201EFC8, func_0201EFFC, func_0201F020, func_0201F02C, func_0201F048, func_0201F094
 * address:  0x0201EC74
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
 *   sFile_020A7364  0x020A7364  data  a1
 *   func_02030734   0x02030734  arm
 *   func_020457B0   0x020457B0  arm
 *   func_0201ED50   0x0201ED50  thumb
 *   unk_020A7370   0x020A7370  data
 *   func_0202473C  0x0202473C  thumb
 *   func_02025B94  0x02025B94  thumb
 */
struct U16Vec;
struct MsgBank;
struct Rec;
struct Obj;
struct Tag;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

struct Tag {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03 : 7;
    u8 unk03b : 1;
    u8 unk04;
};

struct Entry {
    struct Tag tag;
    void *str;
};

struct WordSet_0201EC74 {
    u32 count;
    u32 heap;
    struct Entry *entries;
    void *str0;
};

typedef signed int     s32;

struct Entry_0201ED04 {
    struct Tag tag;
    void *str;
};

struct WordSet_0201ED04 {
    u32 count;
    u32 heap;
    struct Entry_0201ED04 *entries;
    void *buf;
};

struct Entry_0201EFFC {
    struct Tag tag;
    void *str;
};

struct Entry_0201F020 {
    u8 tag[5];
    void *str;
};

struct Entry_0201F094 {
    u8 tag[5];
    void *str;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201ED50(struct Tag *t);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern u32 func_020307B0(void *p);
extern u32   func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void func_02045808(struct U16Vec *vec);
extern void func_0204581C(struct U16Vec *vec);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020246C8(u16 *p, u32 mode, u32 flag);
extern u32 func_0202473C(u32 *p, u32 a);
extern void func_02024838(u32 id, void *dest, u32 heap);
extern void func_0201F35C(void *ctx, s32 n, u32 kind, u32 mode, u32 flag);
extern void func_0201ED84(struct WordSet_0201ED04 *p, u32 i, const void *src,
                          const struct Tag *tag);
extern void func_0201EDD0(struct WordSet_0201ED04 *p, u32 i, u32 id, u32 v);
extern void func_0201EE60(struct WordSet_0201ED04 *p, u32 i, u16 v);
extern void func_0201EEC4(struct WordSet_0201ED04 *p, u32 i, u32 v);
extern void func_0201EF40(struct WordSet_0201ED04 *p, u32 i, u32 v);
extern void func_0201EF4C(struct WordSet_0201ED04 *p, u32 i, u32 v);
extern void func_0201EF5C(struct WordSet_0201ED04 *p, u32 i, u32 v);
extern u16 func_02045F50(const struct Obj *o);
extern void  sub_02008500(void *a, void *b);
extern u32   func_02025B94(u32 a);
extern u32 func_0202A230(void *a, u32 idx);
extern void func_0200785C(void *save, u32 box, void *dest);
extern void func_0201ED64(struct WordSet_0201ED04 *p, u32 i);
extern void func_0201F0F8(struct WordSet_0201ED04 *p, u32 i, u32 v);
struct WordSet_0201EC74 *func_0201EC74(u32 n, u32 size, u16 heap);
extern char sFile_020A7364[];
extern void *unk_020A7370;


/*
 * wordset.c's constructor, the function src/matched/unit_0201EC64.c tail
 * calls with the default counts (8 slots, 0x20 bytes of string each).  It
 * allocates a 0x10-byte header and an array of `n` 0xc-byte Entry records
 * through the debug allocator func_02030734(heap, size, flag, file, line),
 * gives the header and every entry a string object from func_020457B0, and
 * returns 0 as soon as any allocation fails.
 *
 * The `__FILE__` argument is 0x020A7364, "wordset.c", and IS attestable by
 * the `string` class: the six bytes before it are the NUL terminator of
 * "gf_font.c" plus padding, so the run start is fixed from outside this
 * range (unlike the tables of
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md).
 *
 * TWO LEVERS, both of which the earlier pass in docs/notes/pkt_0201EC74.c.txt
 * missed and which together took the function from 152 bytes / 65 differing
 * rows to EXACT:
 *
 *  - **The failure path is a `goto fail;` chain with ONE `return 0;` at the
 *    end.**  Every failure return in the image lands on the single epilogue
 *    at 0x0201ECFA.  Written as four separate `return 0;` statements the
 *    compiler materialises the epilogue inline at the FIRST failure site and
 *    branches over the copy, which is eight bytes too long and reshuffles
 *    the two callee-saved slots (the pool word lands in r7 and the parameter
 *    copy of `n` in r5, the opposite of the image).  This is the explicit
 *    `goto` case of
 *    docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md:
 *    statements sit between the guards, so nothing else reproduces the
 *    shared exit.  That alone brings the compile to 144 bytes and 14
 *    differing bytes.
 *
 *  - **`heap` is `u8`, not `u32`.**  With `u32` the prologue schedules the
 *    three argument spills and the pool load in a different order
 *    (`ldr r5,[pc]` ahead of `adds r7,r0,#0`, and `str r1,[sp,#4]` ahead of
 *    `str r2,[sp,#8]`), fourteen bytes across the prologue and the first
 *    store pair.  Narrowing the parameter changes nothing about the code
 *    that runs -- the value is spilled to sp+8 untruncated and read back as
 *    a word for `p->heap = heap` -- but it changes the order mwccarm's value
 *    numbering creates the three incoming values in, which is what the
 *    prologue schedule follows.  This is the family's heap-id width seen
 *    once more: func_0201F344 in src/matched/unit_0201F31C.c takes its heap
 *    as u16 for the same class of reason.
 *
 *    Found by tools/permuter.py (--mode hill --budget 800 --jobs 8 --types),
 *    which reported `type:p(heap:u32->u8)` at compile 244 of 800:
 *      baseline  DIFF   asm=855  bytes-out=14  size=144/144
 *      244       EXACT  asm=0    bytes-out=0   size=144/144
 *
 * func_020457B0 is ARM, not Thumb.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table; the two counts are the caller's, not content constants.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201EC74.c \
 *       --func func_0201EC74 --addr 0x0201EC74 --cc 1.1p1 --thumb
 */
struct WordSet_0201EC74 *func_0201EC74(u32 n, u32 size, u16 heap)
{
    struct WordSet_0201EC74 *p;
    u32 i = 0;

    p = func_02030734(heap, 0x10, 0, sFile_020A7364, 0x9F);
    if (p == 0) {
        goto fail;
    }
    p->count = n;
    p->heap = heap;
    p->str0 = func_020457B0(size, heap);
    if (p->str0 == 0) {
        goto fail;
    }
    p->entries = func_02030734(heap, n * 0xc, i, sFile_020A7364, 0xA8);
    if (p->entries == 0) {
        goto fail;
    }
    while (i < n) {
        func_0201ED50(&p->entries[i].tag);
        p->entries[i].str = func_020457B0(size, heap);
        if (p->entries[i].str == 0) {
            break;
        }
        i++;
    }
    if (i != n) {
        goto fail;
    }
    return p;
fail:
    return 0;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
u32 func_0201ED04(struct WordSet_0201ED04 *p)
{
    u32 i;

    if (p->entries != 0) {
        for (i = 0; i < p->count; i++) {
            if (p->entries[i].str == 0) {
                break;
            }
            func_02045808(p->entries[i].str);
        }
        func_020307B0(p->entries);
    }
    if (p->buf != 0) {
        func_02045808(p->buf);
    }
    p->count = 0;
    return func_020307B0(p);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201ED50(struct Tag *t)
{
    MI_CpuFill8(t, 0, 5);
    t->unk04 = 0;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201ED64(struct WordSet_0201ED04 *p, u32 i)
{
    func_0201ED50(&p->entries[i].tag);
    func_0204581C(p->entries[i].str);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201ED84(struct WordSet_0201ED04 *p, u32 i, const void *src,
                   const struct Tag *tag)
{
    if (i < p->count) {
        if (tag != 0) {
            p->entries[i].tag = *tag;
        } else {
            func_0201ED50(&p->entries[i].tag);
        }
        func_02045838(p->entries[i].str, (struct U16Vec *)src);
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EDD0(struct WordSet_0201ED04 *p, u32 i, u32 id, u32 v)
{
    void *s = func_02045B38(0, 2, (u16)id, (u16)p->heap);

    if (s != 0) {
        func_02045CAC(s, v, p->buf);
        func_0201ED84(p, i, p->buf, 0);
        func_02045C04(s);
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EE0C(struct WordSet_0201ED04 *p, u32 i, const void *src, u32 n, u32 f, u32 c)
{
    struct Tag tag;

    func_0201ED50(&tag);
    tag.unk03 = n;
    tag.unk03b = (f == 0);
    func_0201ED84(p, i, src, &tag);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EE60(struct WordSet_0201ED04 *p, u32 i, u16 v)
{
    func_02045CAC(unk_020A7370, v, p->buf);
    func_0201ED84(p, i, p->buf, 0);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EE84(struct WordSet_0201ED04 *p, u32 i, void *mon)
{
    func_0201EE60(p, i, func_02017E1C(mon, 5, 0));
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EEA4(struct WordSet_0201ED04 *p, u32 i, void *mon)
{
    func_0201EE60(p, i, func_02017E88(mon, 5, 0));
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EEC4(struct WordSet_0201ED04 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x119, v);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EED4(struct WordSet_0201ED04 *p, u32 i, void *mon)
{
    func_0201EEC4(p, i, (u16)func_02017E1C(mon, 5, 0));
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EEF4(struct WordSet_0201ED04 *p, u32 i, void *mon)
{
    func_02017E1C(mon, 0x73, (u32)p->buf);
    func_0201ED84(p, i, p->buf, 0);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EF14(struct WordSet_0201ED04 *p, u32 i, void *mon)
{
    func_02017E88(mon, 0x73, (u32)p->buf);
    func_0201ED84(p, i, p->buf, 0);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EF34(struct WordSet_0201ED04 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xCB, v);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EF40(struct WordSet_0201ED04 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x36, v);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EF4C(struct WordSet_0201ED04 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x117, v);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EF5C(struct WordSet_0201ED04 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x118, v);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EF6C(struct WordSet_0201ED04 *p, u32 i, u32 v, u32 a, u32 b)
{
    if (a != 0) {
        func_0201EF5C(p, i, v);
        return;
    }
    if (b != 0) {
        func_0201EF4C(p, i, v);
        return;
    }
    func_0201EF40(p, i, v);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EF8C(struct WordSet_0201ED04 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xB6, v);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EF98(struct WordSet_0201ED04 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x18, v);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EFA4(struct WordSet_0201ED04 *p, u32 i, u32 a, u32 b, u32 c, u32 d)
{
    func_0201F35C(p->buf, a, b, c, d);
    func_0201ED84(p, i, p->buf, 0);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0201EDD0, func_0201EE0C, func_0201EE60, func_0201EE84,
 *           func_0201EEA4, func_0201EEC4, func_0201EED4, func_0201EEF4,
 *           func_0201EF14, func_0201EF34, func_0201EF40, func_0201EF4C,
 *           func_0201EF5C, func_0201EF6C, func_0201EF8C, func_0201EF98,
 *           func_0201EFA4, func_0201EFC8
 *
 * 760 bytes, 0x0201ED04..0x0201EFFC, 22 functions, the body of wordset.c.
 * The file name is attested at the constructor 0x0201EC74, which is just
 * before this range and is a near miss; see src/matched/unit_0201EC64.c.
 *
 * The object is a small table of substitution slots:
 *
 *     struct WordSet { u32 count; u32 heap; struct Entry *entries;
 *                      void *buf; };
 *     struct Entry   { struct Tag tag; void *str; };     // 12 bytes
 *
 * and every setter in the file ends the same way, by handing a rendered
 * string to func_0201ED84, which copies the caller's five-byte Tag into the
 * slot (or clears it when the caller passes NULL) and then copies the string
 * itself.  The five-byte tag is not a scalar: the byte at +3 is two
 * bitfields, a seven-bit value and a one-bit flag, which is what the
 * `ldrb`/`bics #0x7F`/`orrs` and `ldrb`/`bics #0x80`/`lsls #0x1F` pairs in
 * func_0201EE0C are.  Writing that byte as a plain u8 with masks costs a pool
 * word and an `ands` for each of the two fields
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the same
 * effect on the reading side).
 *
 * func_0201ED50 is the tag clear and takes a `struct Tag *`, not a
 * `struct Entry *`: func_0201EE0C calls it on a bare stack local, which is
 * what fixes the parameter type.  The two are the same address for an entry,
 * so the distinction is only visible at that one call site.
 *
 * func_0201EE60 reaches a file-scope pointer at 0x020A7370.  Exactly two
 * literal pools in the image hold that address, this function's and
 * func_0201F344's in src/matched/unit_0201F0F8.c, so each file is the other's
 * `literal` witness and the two may not be merged into one range.
 *
 * func_0201EF6C is three separate early returns rather than one conjunction:
 * each `bl` is followed by its own `pop`, which is the shape
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * records for a chain the compiler does not tail-merge.
 *
 * Addresses are Black-image addresses.  func_02017E1C and func_02017E88 are
 * the pair of species-keyed getters this file reads names through; they are
 * not resolved here and nothing in this range reads a version flag or an
 * exclusive-species table directly, but any renaming of those two should be
 * checked against Pokemon White.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201ED04.c  *       --addr 0x0201ED04 --thumb
 */
void func_0201EFC8(struct WordSet_0201ED04 *p, u32 i, u32 v)
{
    u16 x = v;

    func_020246C8(&x, 0, 0);
    func_02024838((u16)x, p->buf, (u16)p->heap);
    func_0201ED84(p, i, p->buf, 0);
}


/*
 * Promoted from src/pending/sub_0201EFFC.c: every concrete byte was
 * already reproduced, and the one relocation, the call to
 * func_0202473C, was capped at MATCH because the only branch to that
 * address anywhere in the image is the one inside this function. Now
 * that src/matched/sub_0202473C.c is an EXACT entry, the `matched` class
 * attests the call without needing a second caller (docs/MATCHING.md,
 * "the matched class"), and this file closes to EXACT.
 *
 * The last function of wordset.c's body: it normalises a value through
 * func_0202473C and stores the result into the one-byte flag of the
 * slot's tag. The value is passed by address, so it lives on the stack
 * and is read back after the call; the `str r2, [sp]` before the call and
 * the `ldr r2, [sp]` after it are that, not a spill.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201EFFC.c \
 *       --func func_0201EFFC --addr 0x0201EFFC --cc 1.1p1 --thumb
 */
void func_0201EFFC(struct WordSet_0201ED04 *p, u32 i, u32 v)
{
    u32 x = v;

    func_0202473C(&x, 0);
    if (i < p->count) {
        p->entries[i].tag.unk04 = x;
    }
}


/*
 * Three of the wordset.c setters, cut off at 0x0201F094 because the function
 * there is the only caller of 0x02025B94 anywhere in the image and so cannot
 * be attested; see src/pending/sub_0201F094.c.  The rest of the run continues
 * in src/matched/unit_0201F0F8.c.
 *
 * func_0201F048 renders message 0xE7 with an argument and falls back to
 * clearing the slot when the argument is out of the message's own range; the
 * `bhs` is the unsigned compare against func_02045F50's result, and the
 * fall-through arm is the in-range one
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The call to func_0201ED64 is carried by the `matched` class: its only six
 * callers in the image are all inside this packet, so no cut reaches it, but
 * src/matched/unit_0201ED04.c is an EXACT entry covering that address.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F020.c  *       --addr 0x0201F020 --thumb
 */
void func_0201F020(struct WordSet_0201ED04 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xC7, v);
}

/*
 * Three of the wordset.c setters, cut off at 0x0201F094 because the function
 * there is the only caller of 0x02025B94 anywhere in the image and so cannot
 * be attested; see src/pending/sub_0201F094.c.  The rest of the run continues
 * in src/matched/unit_0201F0F8.c.
 *
 * func_0201F048 renders message 0xE7 with an argument and falls back to
 * clearing the slot when the argument is out of the message's own range; the
 * `bhs` is the unsigned compare against func_02045F50's result, and the
 * fall-through arm is the in-range one
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The call to func_0201ED64 is carried by the `matched` class: its only six
 * callers in the image are all inside this packet, so no cut reaches it, but
 * src/matched/unit_0201ED04.c is an EXACT entry covering that address.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F020.c  *       --addr 0x0201F020 --thumb
 */
void func_0201F02C(struct WordSet_0201ED04 *p, u32 i, void *a)
{
    sub_02008500(a, p->buf);
    func_0201ED84(p, i, p->buf, 0);
}

/*
 * Three of the wordset.c setters, cut off at 0x0201F094 because the function
 * there is the only caller of 0x02025B94 anywhere in the image and so cannot
 * be attested; see src/pending/sub_0201F094.c.  The rest of the run continues
 * in src/matched/unit_0201F0F8.c.
 *
 * func_0201F048 renders message 0xE7 with an argument and falls back to
 * clearing the slot when the argument is out of the message's own range; the
 * `bhs` is the unsigned compare against func_02045F50's result, and the
 * fall-through arm is the in-range one
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * The call to func_0201ED64 is carried by the `matched` class: its only six
 * callers in the image are all inside this packet, so no cut reaches it, but
 * src/matched/unit_0201ED04.c is an EXACT entry covering that address.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F020.c  *       --addr 0x0201F020 --thumb
 */
void func_0201F048(struct WordSet_0201ED04 *p, u32 i, u32 n)
{
    void *s = func_02045B38(0, 2, (u16)0xE7, (u16)p->heap);

    if (s != 0) {
        if (n < func_02045F50(s)) {
            func_02045CAC(s, n, p->buf);
            func_0201ED84(p, i, p->buf, 0);
        } else {
            func_0201ED64(p, i);
        }
        func_02045C04(s);
    }
}


/*
 * Promoted from src/pending/sub_0201F094.c: every concrete byte was
 * already reproduced, and the one relocation, the call to
 * func_02025B94, was capped at MATCH because the only branch to that
 * address anywhere in the image is the one inside this function. Now
 * that src/matched/sub_02025B94.c is an EXACT entry, the `matched` class
 * attests the call without needing a second caller, and this file closes
 * to EXACT.
 *
 * A wordset.c setter that maps a caller value to a message id through
 * func_02025B94 and renders it. That is why the wordset.c setter run is
 * committed as src/matched/unit_0201F020.c and
 * src/matched/unit_0201F0F8.c with this function left out between them;
 * it can now be folded back in on a future pass.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201F094.c \
 *       --func func_0201F094 --addr 0x0201F094 --cc 1.1p1 --thumb
 */
void func_0201F094(struct WordSet_0201ED04 *p, u32 i, u32 a, u32 n)
{
    u32 id = func_02025B94(a);
    void *s;

    if (id != 0 && n != 0) {
        s = func_02045B38(0, 2, (u16)id, (u16)p->heap);
        if (s != 0) {
            if (n < func_02045F50(s)) {
                func_02045CAC(s, n, p->buf);
                func_0201ED84(p, i, p->buf, 0);
                func_02045C04(s);
                return;
            }
            func_02045C04(s);
        }
    }
    func_0201ED64(p, i);
}
