/*
 * function: GFL_HEAP_Delete
 * address:  0x0202FF98
 * packet:   pkt_0202FC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_GetHeap   0x0202FBAC  arm
 *   GFL_HEAP_GetParentHeap   0x0202FBD0  arm
 *   GFL_HEAP_GetBlock   0x0202FBF8  arm
 *   func_02060C94  0x02060C94  arm
 *   NNS_FndFreeToExpHeap  0x02060E30  arm
 *   g_02146954     0x02146954  data
 *
 * Heap destroy.  The handle's low fifteen bits are the heap id; the three
 * accessors turn it into the block pointer and the two allocator objects,
 * the byte array at g_02146954+4 maps the id to a slot in the sixteen-byte
 * record table at g_02146954+0, and the record is cleared and the id
 * released (0xFF) once the block is freed.
 *
 * Two failures set the module's error word at g_02146954+0xE and return 0:
 * an unknown id (1) and a slot that was never registered (2).
 *
 * The record is cleared field by field with the table base re-read before
 * every store: the stores can alias the global, so a cached base is a
 * byte difference, not a missed optimisation.
 *
 * Three shapes the bytes pinned down:
 *
 *  - the id mask is applied to the parameter in place (`mov r5, r0` then
 *    `and`), not folded into a fresh local, which would be one `and`.
 *  - the unknown-id arm sets the error word predicated and branches to the
 *    function's last `mov r0, #0`, so it is the `if` arm of an if/else
 *    whose `return 0` sits after the whole else block, not an early
 *    `return` of its own.
 *  - the two allocator objects are tested as `a == 0 || b == 0`, with the
 *    single-call arm as the `else`.  Written as `a != 0 && b != 0` the
 *    compiler fuses the pair into `cmp`/`cmpne` and loses four bytes.
 *
 * Decompiled to unstick src/pending/func_020306F0.c (fan-in 121), whose
 * only unresolved relocation was this address: func_020306F0 is this
 * function's only caller image-wide, so class `label` was unavailable and
 * the two are not contiguous, so no unit could make the site `local`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_Delete.c \
 *       --func GFL_HEAP_Delete --addr 0x0202FF98 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Record0202FF98 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u16 unk0C;
    u8  unk0E;
    u8  unk0F;
};

struct G02146954 {
    struct Record0202FF98 *table;
    u8 *slot;
    u8 pad08[6];
    u16 error;
};

extern struct G02146954 g_02146954;

extern void *GFL_HEAP_GetHeap(u32 id);
extern u32 GFL_HEAP_GetParentHeap(u32 idx);
extern u32 GFL_HEAP_GetBlock(u32 idx);
extern void  func_02060C94(void *block);
struct ExpHeap;
extern void NNS_FndFreeToExpHeap(struct ExpHeap *heap, void *block);

u32 GFL_HEAP_Delete(u32 handle)
{
    u32 slot;
    void *block;
    void *a;
    void *b;

    handle &= 0x7fff;

    block = GFL_HEAP_GetHeap(handle);
    if (block == 0) {
        g_02146954.error = 1;
    } else {
        a = (void *)GFL_HEAP_GetParentHeap(handle);
        b = (void *)GFL_HEAP_GetBlock(handle);
        slot = g_02146954.slot[handle];
        func_02060C94(block);

        if (a == 0 || b == 0) {
            if (g_02146954.table[slot].unk0E == 0) {
                g_02146954.error = 2;
                return 0;
            }
        } else {
            NNS_FndFreeToExpHeap(a, b);
        }

        g_02146954.table[slot].unk00 = 0;
        g_02146954.table[slot].unk04 = 0;
        g_02146954.table[slot].unk08 = 0;
        g_02146954.table[slot].unk0C = 0;
        g_02146954.table[slot].unk0E = 0;
        g_02146954.slot[handle] = 0xff;
        return 1;
    }

    return 0;
}
