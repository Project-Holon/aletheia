/*
 * function: WORDSET_Create
 * address:  0x0201EC74
 * packet:   pkt_0201EC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * wordset.c's constructor, the function src/matched/unit_0201EC64.c tail
 * calls with the default counts (8 slots, 0x20 bytes of string each).  It
 * allocates a 0x10-byte header and an array of `n` 0xc-byte Entry records
 * through the debug allocator func_02030734(heap, size, flag, file, line),
 * gives the header and every entry a string object from STRBUF_Create, and
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
 * STRBUF_Create is ARM, not Thumb.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table; the two counts are the caller's, not content constants.
 *
 * symbols:
 *   sFile_020A7364  0x020A7364  data  a1
 *   func_02030734   0x02030734  arm
 *   STRBUF_Create   0x020457B0  arm
 *   WORDSET_Init   0x0201ED50  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WORDSET_Create.c \
 *       --func WORDSET_Create --addr 0x0201EC74 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern char sFile_020A7364[];
typedef unsigned short u16;
struct U16Vec;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

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

struct WordSet {
    u32 count;
    u32 heap;
    struct Entry *entries;
    void *str0;
};

extern void WORDSET_Init(struct Tag *t);

struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap)
{
    struct WordSet *p;
    u32 i = 0;

    p = func_02030734(heap, 0x10, 0, sFile_020A7364, 0x9F);
    if (p == 0) {
        goto fail;
    }
    p->count = n;
    p->heap = heap;
    p->str0 = STRBUF_Create(size, heap);
    if (p->str0 == 0) {
        goto fail;
    }
    p->entries = func_02030734(heap, n * 0xc, i, sFile_020A7364, 0xA8);
    if (p->entries == 0) {
        goto fail;
    }
    while (i < n) {
        WORDSET_Init(&p->entries[i].tag);
        p->entries[i].str = STRBUF_Create(size, heap);
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
