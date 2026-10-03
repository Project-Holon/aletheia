/*
 * unit:     yes
 * address:  0x0201C328
 * packet:   pkt_0201C328
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201C328, sub_0201C3C0, sub_0201C408, sub_0201C41C
 *
 * waza_tool.c: the module's constructor, its destructor, its "is it up"
 * predicate, and (folded back in this run) sub_0201C41C, which resets
 * something with 0xFFFF and hands func_02043678's result to the static at
 * 0x02146558.  sub_0201C41C used to be cut out into src/pending/sub_0201C41C.c
 * because its one call, to func_020457A0, had no witness anywhere in the
 * image; func_020457A0 is now EXACT in src/matched/sub_020457A0.c, giving the
 * `matched` class a witness, so the range folds back into one unit.  The file
 * name is the image's own, 0x020A7340 spelling "waza_tool.c" between
 * "shinka_check.c" and "printsys.c".
 *
 * The module object at 0x02146530 is three words: an array of `n` pointers to
 * 0x24 byte records, an array of `n` halfwords, and `n` itself.  Each of the
 * four allocations passes a different __LINE__, and the four values 577, 578,
 * 579 and 584 are visible in the bytes as one pool word holding 577 and three
 * `adds r0, r0, #k` off it, which is what fixes both the line numbers and the
 * order of the statements.  577 is too large for a `movs` immediate, so the
 * first one is a pool word rather than a relocation
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md is the
 * case where it is the other way round).
 *
 * sub_0201C408 is an unlabelled follower: eight halfwords with no prologue
 * sitting between two literal pools, which the listing prints as `.word` data
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Its `!= 0`
 * arm is the fall-through, so the source returns 1 first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * symbols:
 *   gWazaTool          0x02146530  data
 *   sub_0201C328_File  0x020A7340  data
 *   g_02146558         0x02146558  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C328.c \
 *       --addr 0x0201C328 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct WazaTool {
    void **recs;
    u16  *vals;
    s32   count;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020307B0(void *p);
extern void func_020457A0(u16 stamp);
extern void *func_02043678(u32 a, u32 b, u32 c, void *d);

extern struct WazaTool *gWazaTool;
extern const char sub_0201C328_File[];
extern void *g_02146558;

void sub_0201C328(s32 n, u32 heap)
{
    s32 i;

    if (gWazaTool != 0) {
        return;
    }
    gWazaTool = (struct WazaTool *)func_02030734(heap, sizeof(struct WazaTool), 0,
                                                sub_0201C328_File, 577);
    gWazaTool->recs = (void **)func_02030734(heap, n * sizeof(void *), 0,
                                             sub_0201C328_File, 578);
    gWazaTool->vals = (u16 *)func_02030734(heap, n * sizeof(u16), 0,
                                           sub_0201C328_File, 579);
    gWazaTool->count = n;
    for (i = 0; i < n; i++) {
        gWazaTool->recs[i] = func_02030734(heap, 0x24, 0, sub_0201C328_File, 584);
        gWazaTool->vals[i] = 0;
    }
}

void sub_0201C3C0(void)
{
    s32 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            func_020307B0(gWazaTool->recs[i]);
        }
        func_020307B0(gWazaTool->vals);
        func_020307B0(gWazaTool->recs);
        func_020307B0(gWazaTool);
        gWazaTool = 0;
    }
}

u32 sub_0201C408(void)
{
    if (gWazaTool != 0) {
        return 1;
    }
    return 0;
}

void sub_0201C41C(void *arg)
{
    func_020457A0(0xFFFF);
    g_02146558 = func_02043678(2, 2, 0x20, arg);
}
