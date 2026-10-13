/*
 * unit:     no
 * address:  0x020305C4
 * packet:   pkt_02030534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_AllocSystem
 *
 * The allocation front door for heap 4, the heap GFL_HEAP_InitSystemHeap carves out
 * of the OS arena a few bytes earlier in this packet.
 *
 *   void *GFL_HEAP_AllocSystem(u32 size)
 *
 * This is the hidden second entry point of what the listing used to show
 * as one 176-byte function at 0x02030534. It saves nothing, because it is
 * a pure tail call, so disasm.py's lr-saving prologue sweep never labelled
 * it, and nothing in arm9 branches to it: its only reference anywhere in
 * the image is the pool word at 0x02030BC4, read by the veneer-shaped tail
 * call at 0x02030BBC (src/pending/sub_02030BBC.c, whose single unresolved
 * relocation this file closes). It is now seeded in
 * layout/function_starts.txt, which is what splits 0x02030534's extent.
 *
 * The heap handle is reloaded from g_EnvHeapModule at the call rather than
 * cached, and the whole body is a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). The heap id 4 is
 * materialised last, into r0, because the tail call has already spent the
 * argument registers it could reuse.
 *
 * g_EnvHeapModule's +4 slot is an OSHeapHandle; src/matched/GFL_HEAP_FreeSystem.c
 * calls the same slot `ids` and passes it as a pointer, which is the same
 * word under a different reading.
 *
 * symbols:
 *   g_EnvHeapModule    0x02146964  data
 *   OS_AllocFromHeap   0x020868E0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_AllocSystem.c \
 *       --func GFL_HEAP_AllocSystem --addr 0x020305C4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef signed int s32;

struct EnvHeapModule {
    void *unk0;
    s32 heapHandle;
};

extern struct EnvHeapModule g_EnvHeapModule;

extern void *OS_AllocFromHeap(u32 id, s32 heap, u32 size);

void *GFL_HEAP_AllocSystem(u32 size)
{
    return OS_AllocFromHeap(4, g_EnvHeapModule.heapHandle, size);
}
