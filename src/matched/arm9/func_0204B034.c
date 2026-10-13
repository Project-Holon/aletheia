/*
 * function: CLACT_CreateRenderer
 * address:  0x0204B034
 * packet:   pkt_0204B034
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   s_clact_c       0x020A7F74  data
 *   CLACT_InitRenderer  0x0204BD94  arm
 *
 * clact.c's 0xA0-byte cell-actor allocation helper: carve the record with the
 * three-argument allocator, hand it and the caller's three values to the
 * record initialiser, and return the record.  The third parameter is the heap
 * id and reaches the allocator as its first argument, so the two call sites
 * do not share an argument order.
 *
 * The file string at 0x020A7F74 is "clact.c" and the stacked fifth argument
 * is __LINE__ = 0x633; declared as an extern array pinned by address, never
 * as a literal __FILE__.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_CreateRenderer.c \
 *       --func CLACT_CreateRenderer --addr 0x0204B034 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8 pad_00[0xa0];
};

extern const char s_clact_c[];

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void CLACT_InitRenderer(struct Obj *obj, u8 *src, int count, u32 heap);

struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap)
{
    struct Obj *p = (struct Obj *)func_02030734(heap, 0xa0, 0, s_clact_c, 0x633);

    CLACT_InitRenderer(p, a0, a1, heap);
    return p;
}
