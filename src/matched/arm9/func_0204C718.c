/*
 * function: CLACT_AllocTransferEntries
 * address:  0x0204C718
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   s_clact_c      0x020A7F74  data
 *   sub_02030734   0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Allocate the pool's parallel array of 0x10-byte entries and zero each one.
 * The __FILE__ pointer is the same s_clact_c the rest of clact.c uses; the
 * line number 0x137b is a plain pooled constant here, not derived from a
 * neighbouring one, because this is the only allocation in the function.
 *
 * The entry count for the loop is read back out of the object at +0x08 rather
 * than reused from the `n` that sized the allocation: the load right after the
 * call is the loop's rotated entry test, and the same field is re-read at the
 * bottom of every iteration because MI_CpuFill8 may alias it.
 *
 * The clear is a per-element call, not one call over the whole array, so the
 * zero and the 0x10 are hoisted into callee-saved registers for the loop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_AllocTransferEntries.c \
 *       --func CLACT_AllocTransferEntries --addr 0x0204C718 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef unsigned short u16;

struct Entry {
    u8 pad_00[0x10];
};

struct Pool {
    u8            pad_00[4];
    struct Entry *ents;    /* 0x04 */
    u32           count;   /* 0x08 */
};

extern char s_clact_c[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void  MI_CpuFill8(void *dst, int fill, u32 size);

void CLACT_AllocTransferEntries(struct Pool *p, u32 n, u32 heapId)
{
    u32 i;

    p->ents = sub_02030734(heapId, n * sizeof(struct Entry), 0, s_clact_c,
                           0x137b);

    for (i = 0; i < p->count; i++) {
        MI_CpuFill8(&p->ents[i], 0, sizeof(struct Entry));
    }
}
