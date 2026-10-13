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
 * function: WAZA_TOOL_CreateCache, WAZA_TOOL_DeleteCache, WAZA_TOOL_IsCacheCreated, PRINTSYS_Init
 *
 * waza_tool.c: the module's constructor, its destructor, its "is it up"
 * predicate, and (folded back in this run) PRINTSYS_Init, which resets
 * something with 0xFFFF and hands func_02043678's result to the static at
 * 0x02146558.  PRINTSYS_Init used to be cut out into src/pending/PRINTSYS_Init.c
 * because its one call, to STRBUF_SetEosChar, had no witness anywhere in the
 * image; STRBUF_SetEosChar is now EXACT in src/matched/STRBUF_SetEosChar.c, giving the
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
 * WAZA_TOOL_IsCacheCreated is an unlabelled follower: eight halfwords with no prologue
 * sitting between two literal pools, which the listing prints as `.word` data
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Its `!= 0`
 * arm is the fall-through, so the source returns 1 first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * symbols:
 *   _pWazaTool          0x02146530  data
 *   waza_tool_File  0x020A7340  data
 *   _pGlyphBmp         0x02146558  data
 *   STRBUF_SetEosChar  0x020457A0  arm
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
extern u32 func_020307B0(void *p);
extern void STRBUF_SetEosChar(u16 stamp);
struct Bmp;
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);

extern struct WazaTool *_pWazaTool;
extern const char waza_tool_File[];
extern void *_pGlyphBmp;

void WAZA_TOOL_CreateCache(s32 n, u32 heap)
{
    s32 i;

    if (_pWazaTool != 0) {
        return;
    }
    _pWazaTool = (struct WazaTool *)func_02030734(heap, sizeof(struct WazaTool), 0,
                                                waza_tool_File, 577);
    _pWazaTool->recs = (void **)func_02030734(heap, n * sizeof(void *), 0,
                                             waza_tool_File, 578);
    _pWazaTool->vals = (u16 *)func_02030734(heap, n * sizeof(u16), 0,
                                           waza_tool_File, 579);
    _pWazaTool->count = n;
    for (i = 0; i < n; i++) {
        _pWazaTool->recs[i] = func_02030734(heap, 0x24, 0, waza_tool_File, 584);
        _pWazaTool->vals[i] = 0;
    }
}

void WAZA_TOOL_DeleteCache(void)
{
    s32 i;

    if (_pWazaTool != 0) {
        for (i = 0; i < _pWazaTool->count; i++) {
            func_020307B0(_pWazaTool->recs[i]);
        }
        func_020307B0(_pWazaTool->vals);
        func_020307B0(_pWazaTool->recs);
        func_020307B0(_pWazaTool);
        _pWazaTool = 0;
    }
}

u32 WAZA_TOOL_IsCacheCreated(void)
{
    if (_pWazaTool != 0) {
        return 1;
    }
    return 0;
}

void PRINTSYS_Init(void *arg)
{
    STRBUF_SetEosChar(0xFFFF);
    _pGlyphBmp = func_02043678(2, 2, 0x20, (u32)arg);
}
