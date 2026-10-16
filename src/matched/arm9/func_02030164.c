/*
 * function: GFL_HEAP_FreeMemory
 * address:  0x02030164
 * packet:   pkt_02030164
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Block release: the free that pairs with GFL_HEAP_AllocMemory. The header is the
 * same 0x1c-byte block header GFL_HEAP_AllocMemory reserves, so the block pointer
 * is p - 0x1c and the heap id is the header's first halfword, loaded before
 * the header is validated (see the notes below); the second halfword is the
 * 0x194E signature and is rewritten to 0x194D here, so a freed block keeps
 * a recognisable header but is no longer live.
 *
 * The result code written to g_EnvModule.error (+0xe) numbers four failure
 * modes: 1 bad signature, 2 heap id out of range, 3 no such heap (the
 * GFL_HEAP_GetHeap lookup, the arena handed to the release), 4 the heap's live
 * allocation count is already zero (a double free; the count is the +0xc
 * halfword GFL_HEAP_GetAllocCount returns). All four branches to the single
 * `mov r0, #0` / pop epilogue need the explicit `goto fail`, otherwise the
 * compiler predicates each failure inline and the whole tail shifts.
 *
 * Three shapes the bytes pinned down:
 *
 *  - The heap id load comes *before* the signature guard in the source.
 *    With `heapId = hdr->heapId;` after the guard mwccarm emits it at
 *    +0028, inside the fall-through, and 25 concrete bytes differ; written
 *    before the guard the same statement emits a single `ldrh r4,
 *    [r0, #-0x1c]` at +0010, folded onto the still-live parameter register
 *    rather than onto the materialised r6 = p - 0x1c base. Both spellings
 *    (`hdr->heapId` and the raw `((u16 *)p)[-14]`) compile to that same
 *    folded load, so it is the statement's position, not its form, that the
 *    bytes record.
 *  - The signature comparison reads the header through the materialised
 *    base, `ldrh r1, [r6, #2]`, because -0x1c + 2 = -0x1a is not an
 *    encodable extra-load offset; only the heap id at header offset 0 can
 *    fold onto the parameter.
 *  - `hdr->magic = 0x194D;` is emitted as `sub r2, r7, #1` off the r7 the
 *    guard already loaded 0x194E into, not as a second pool word, and the
 *    value it leaves in r2 is the dead third argument of NNS_FndFreeToExpHeap
 *    (which is really the two-argument (arena, block) release that
 *    src/matched/GFL_HEAP_Delete.c declares).
 *
 * The count decrement is `g_EnvModule.entries[g_EnvModule.ids[heapId]].field0c--;`
 * -- the same double-index expression GFL_HEAP_AllocMemory increments -- and its
 * decremented result is not reused; the second call takes two arguments.
 *
 * symbols:
 *   g_EnvModule           0x02146954  data
 *   GFL_HEAP_GetHeap          0x0202FBAC  arm
 *   GFL_HEAP_GetAllocCount          0x0202FC20  arm
 *   NNS_FndFreeToExpHeap         0x02060E30  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_FreeMemory.c \
 *       --func GFL_HEAP_FreeMemory --addr 0x02030164 --cc 1.1p1 --arm
 */

#include "../include/G_EnvModule.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct EnvEntry {
    void *ptr00;
    u32 field04;
    u32 field08;
    u16 field0c;
    u8  field0e;
};

struct HeapBlock {
    u16 heapId;
    u16 magic;
    char name[0x12];
    u16 tag;
    u32 field18;
};

extern struct EnvModule g_EnvModule;
extern void *GFL_HEAP_GetHeap(u32 idx);
struct ExpHeap;
extern u16 GFL_HEAP_GetAllocCount(u32 idx);
extern void NNS_FndFreeToExpHeap(struct ExpHeap *heap, void *block);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 state);

u32 GFL_HEAP_FreeMemory(void *p)
{
    struct HeapBlock *hdr;
    void *arena;
    u32 intr;
    u32 heapId;

    hdr = (struct HeapBlock *)((char *)p - 0x1c);
    heapId = hdr->heapId;
    if (hdr->magic != 0x194E) {
        g_EnvModule.error = 1;
        goto fail;
    }
    if (heapId >= g_EnvModule.count) {
        g_EnvModule.error = 2;
        goto fail;
    }
    arena = GFL_HEAP_GetHeap(heapId);
    if (arena == 0) {
        g_EnvModule.error = 3;
        goto fail;
    }
    if (GFL_HEAP_GetAllocCount(heapId) == 0) {
        g_EnvModule.error = 4;
        goto fail;
    }
    intr = OS_DisableInterrupts();
    g_EnvModule.entries[((u8 *)g_EnvModule.ids)[heapId]].field0c--;
    hdr->magic = 0x194D;
    NNS_FndFreeToExpHeap(arena, hdr);
    OS_RestoreInterrupts(intr);
    g_EnvModule.error = 0;
    return 1;

fail:
    return 0;
}
