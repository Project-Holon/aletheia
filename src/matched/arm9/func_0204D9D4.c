/*
 * function: CLACT_LoadArchiveData
 * address:  0x0204D9D4
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   s_clact_c      0x020A7F74  data
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   MI_UncompressLZ8  0x020834C0  arm
 *   sub_02030734   0x02030734  arm
 *   sub_020307B0   0x020307B0  arm
 *
 * Load an archive member, optionally decompressing it.  Both arms read the
 * member with ARC_TOOL_LoadHandleMember into a scratch block taken from the far end of
 * the caller's heap, (heapId & 0x7fff) | 0x8000, the same "allocate high"
 * form src/matched/unit_02045C44.c uses.  When the third argument is set the
 * block is treated as a compressed image: its first word carries the
 * uncompressed size in the top 24 bits, a normal-end block of that size is
 * allocated, MI_UncompressLZ8 expands into it and the scratch is released.
 *
 * The heap id is computed once above the branch, which is why the `lsl #16`
 * sits before the `beq` and only the matching `lsr #16` is duplicated into
 * each arm: the compiler hoists the common subexpression and cross-jumps what
 * is left.  Spelling the cast per arm instead moves the whole pair down twice.
 *
 * The decompressing arm is the fall-through, so the guard is written `!= 0`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * MI_UncompressLZ8 takes source first and destination second here, and only two
 * arguments: r2 still holds the allocator's clobbered register at the call and
 * the original never reloads it.  Other files in the tree declare a
 * three-argument (dest, src, size) form of the same address; the declarations
 * live in different translation units and never meet, and this one is what the
 * bytes at this call site say.
 *
 * The fourth argument doubles as the heap id for both allocations, so it is
 * held in a callee-saved register across the whole function rather than
 * recomputed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_LoadArchiveData.c \
 *       --func CLACT_LoadArchiveData --addr 0x0204D9D4 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct CompHeader {
    u32 header;
};

extern char s_clact_c[];

struct ArcFile;
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern u32 sub_020307B0(void *p);
extern void MI_UncompressLZ8(const void *src, void *dest);

void *CLACT_LoadArchiveData(void *owner, u32 which, u32 compressed, u32 heapId)
{
    void *out;
    struct CompHeader *raw;

    if (compressed != 0) {
        raw = (struct CompHeader *)ARC_TOOL_LoadHandleMember(owner, which,
                  (u16)((heapId & 0x7fff) | 0x8000));
        out = sub_02030734(heapId, raw->header >> 8, 0, s_clact_c, 0x1ba5);
        MI_UncompressLZ8(raw, out);
        sub_020307B0(raw);
    } else {
        out = ARC_TOOL_LoadHandleMember(owner, which,
                  (u16)((heapId & 0x7fff) | 0x8000));
    }
    return out;
}
