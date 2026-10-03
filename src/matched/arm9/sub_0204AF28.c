/*
 * function: sub_0204AF28
 * address:  0x0204AF28
 * packet:   pkt_0204ADEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_02049250  0x02049250  arm
 *   func_0204E074  0x0204E074  arm
 *
 * Claim the first live slot of the 0x14-byte entry pool that lives at
 * +0x104 of the singleton behind 0x02146A74, build its two handles through
 * func_02049250 (same owner and same mode for both, second argument
 * differing), publish the pair with func_0204E074 and hand the slot index
 * back.
 *
 * The scan is an inlined helper, which is what puts the "not found" answer
 * on its own block: the `bne` out of the loop is the `return i` and the
 * `mvn sl, #0` it jumps over is the `return -1`.  Note that -1 is not
 * checked before it is used as a subscript, so a pool with no live entry
 * writes one stride below the array; that is the original's behaviour, not
 * a transcription slip.
 *
 * `count` is spelled `volatile` purely as a codegen device, not as a claim
 * about the hardware: without it the compiler proves the entry loads cannot
 * touch the halfword, CSEs the guard's read with the latch's, and the
 * resulting one-instruction-shorter loop shifts the whole tail by four
 * bytes.  The original reloads +0x18 on every iteration while keeping the
 * entries base cached, which is what the volatile reproduces.  The loop
 * must also be the guard-plus-do-while form: a plain `for` hoists the
 * entries load above the guard.
 *
 * Previously capped at MATCH: the PC24 at +0xa0 (func_0204E074) had no
 * witness outside 0204AF28..0204AFD8, this function being 0x0204E074's only
 * caller image-wide.  src/matched/func_0204E074.c now reproduces that range
 * EXACT, so the site resolves in the `matched` class and the file is EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204AF28.c \
 *       --func sub_0204AF28 --addr 0x0204AF28 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Entry {
    void *unk_00;
    void *unk_04;
    u8    pad_08[8];
    u32   unk_10;
};

struct Pool {
    u8            pad_00[0x10];
    struct Entry *entries;
    u8            pad_14[4];
    volatile u16  count;
};

struct Ctx {
    u8          pad_00[0x104];
    struct Pool pool;
};

extern struct Ctx *g_02146A74;

struct ArcFile;
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern s32 func_0204E074(struct Pool *pool, s32 idx, void *a, void *b);

s32 sub_0204AF28(void *owner, u32 first, u32 second, u32 mode)
{
    struct Pool *pool = &g_02146A74->pool;
    struct Entry *entry;
    s32 idx;

    struct Entry *entries;

    idx = 0;
    if ((u32)idx < pool->count) {
        entries = pool->entries;
        do {
            if (entries[idx].unk_10 != 0) {
                goto found;
            }
            idx++;
        } while ((u32)idx < pool->count);
    }
    idx = -1;
found:
    entry = &g_02146A74->pool.entries[idx];

    entry->unk_00 = func_02049250(owner, first, mode);
    entry->unk_04 = func_02049250(owner, second, mode);

    func_0204E074(&g_02146A74->pool, idx, entry->unk_00, entry->unk_04);

    return idx;
}
