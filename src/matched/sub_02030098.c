/*
 * unit:     no
 * address:  0x02030098
 * packet:   pkt_0202FC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030098
 *
 * The raw allocator: the only function in the image that actually takes
 * memory from a heap. sub_02030734, the 1163-caller allocation entry
 * point, is a wrapper around this.
 *
 *   void *sub_02030098(u32 heapId, u32 size)
 *
 * The heap id is not a plain index. Bit 15 is a direction flag: set means
 * allocate from the high end of the expanded heap (alignment argument -4),
 * clear means the low end (+4); the remaining bits, masked with 0x7fff,
 * are the index. That is why the mask constant costs a pool word and the
 * flag test is a `tst` scheduled before the mask.
 *
 * Every block carries a 0x1c-byte header immediately before the pointer
 * handed back, which is why the request is `size + 0x1c` and the return is
 * a post-indexed `strh r7, [r5], #0x1c`: the heap id is written to the
 * header's first halfword and the pointer is advanced past the header in
 * one instruction. The header's second halfword is a constant 0x194E
 * signature. The rest of the header is the provenance record stamped
 * later by sub_02030880 (name[0x12] at +4, u16 tag at +0x16), which is
 * what sub_020304C0's `p - 0x1c + 4` is addressing.
 *
 * The module global at 0x02146954, already named g_EnvModule by
 * src/matched/unit_0202FBAC.c, is the heap manager, not an environment
 * module: +0 is the array of 16-byte per-heap records, +4 the byte table
 * mapping heap id to record index, +8 the u16 heap count used as the
 * bound here, and +0xe a u16 result code written on every path (1 = id out
 * of range, 2 = no such heap, 3 = heap exhausted, 0 = success). The
 * per-heap record's +0xc halfword, read back by sub_0202FC20, is the live
 * allocation count incremented here. The name is kept for consistency with
 * the existing EXACT file; renaming it to a heap-manager name is an
 * integrator-wide change, not a per-packet one.
 *
 * Shape notes:
 *
 *  - The two failure returns before the interrupt-disable share one
 *    `mov r0, #0` / `pop` epilogue reached by branch. Statements sit
 *    between the two guards, so plain `return 0;` in each arm does not
 *    reproduce it: the compiler emits `movhs r0, #0` / `pophs` inline
 *    instead and the whole tail shifts by two instructions. Only an
 *    explicit `goto fail;` gives the shared exit
 *    (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *  - Declaration order pins the register split: `intr` before `align`
 *    puts the interrupt state in r4 and the alignment (later reused for
 *    the block pointer) in r5. The reverse order swaps them and costs 118
 *    bytes of diff without changing a single instruction's shape
 *    (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *  - The store of the result code at +0xe is likewise emitted once, with
 *    r0 holding 3 or 0 depending on the arm, so it must be written in both
 *    arms of the allocation-failed test rather than factored out after it.
 *  - The manager base stays in r8 across all four calls, the effect of
 *    referring to the same global on both sides of them.
 *
 * symbols:
 *   g_EnvModule           0x02146954  data
 *   sub_0202FBAC          0x0202FBAC  arm
 *   sub_02060CA0          0x02060CA0  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030098.c \
 *       --func sub_02030098 --addr 0x02030098 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

struct EnvEntry {
    void *ptr00;
    u32 field04;
    u32 field08;
    u16 field0c;
    u8  field0e;
};

struct EnvModule {
    struct EnvEntry *entries;
    u8 *ids;
    u16 count;
    u16 field0a;
    u16 field0c;
    u16 error;
};

struct HeapBlock {
    u16 heapId;
    u16 magic;
    char name[0x12];
    u16 tag;
    u32 field18;
};

extern struct EnvModule g_EnvModule;

extern void *sub_0202FBAC(u32 idx);
extern void *sub_02060CA0(void *arena, u32 size, s32 align);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 state);

void *sub_02030098(u32 heapId, u32 size)
{
    void *arena;
    u32 intr;
    u8 *p;
    s32 align;

    if ((heapId & 0x8000) != 0) {
        align = -4;
    } else {
        align = 4;
    }
    heapId &= 0x7FFF;
    if (heapId >= g_EnvModule.count) {
        g_EnvModule.error = 1;
        goto fail;
    }
    arena = sub_0202FBAC(heapId);
    if (arena == 0) {
        g_EnvModule.error = 2;
        goto fail;
    }
    intr = OS_DisableInterrupts();
    p = (u8 *)sub_02060CA0(arena, size + 0x1c, align);
    if (p == 0) {
        g_EnvModule.error = 3;
    } else {
        ((struct HeapBlock *)p)->magic = 0x194E;
        ((struct HeapBlock *)p)->heapId = heapId;
        p += 0x1c;
        g_EnvModule.entries[g_EnvModule.ids[heapId]].field0c++;
        g_EnvModule.error = 0;
    }
    OS_RestoreInterrupts(intr);
    return p;

fail:
    return 0;
}
