/*
 * file:     clact_p05.c
 * unit:     yes
 * function: func_0204C6E4, func_0204C718
 * address:  0x0204C6E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_020307B0   0x020307B0  arm
 *   func_0204C788  0x0204C788  arm
 *   s_clact_c      0x020A7F74  data
 *   sub_02030734   0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 */
typedef unsigned char u8;

typedef unsigned int  u32;

struct Pool_0204C6E4 {
    void *recs;      /* 0x00 */
    u8    pad_04[8];
    u32   ready;     /* 0x0c */
};

typedef unsigned short u16;

struct Entry {
    u8 pad_00[0x10];
};

struct Pool_0204C718 {
    u8            pad_00[4];
    struct Entry *ents;    /* 0x04 */
    u32           count;   /* 0x08 */
};

extern u32 sub_020307B0(void *p);
extern void func_0204C788(struct Pool_0204C6E4 *p);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void  func_02082BCC(void *dst, int fill, u32 size);
extern char s_clact_c[];


/*
 * The inverse of src/matched/func_0204C660.c: release the 0x30-byte record
 * array, drop the free-list built over it, and clear the constructed flag at
 * +0x0c.  An unconstructed object is an early return predicated onto the
 * entry compare.
 *
 * The zero is materialised once into a callee-saved register and used for
 * both stores, because the second store lands after the call to
 * func_0204C788; that is also what forces the store to +0x00 to be written
 * before the call rather than after
 * (docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C6E4.c \
 *       --func func_0204C6E4 --addr 0x0204C6E4 --cc 1.1p1 --arm
 */
void func_0204C6E4(struct Pool_0204C6E4 *p)
{
    if (p->ready == 0) {
        return;
    }

    sub_020307B0(p->recs);
    p->recs = 0;
    func_0204C788(p);
    p->ready = 0;
}


/*
 * Allocate the pool's parallel array of 0x10-byte entries and zero each one.
 * The __FILE__ pointer is the same s_clact_c the rest of clact.c uses; the
 * line number 0x137b is a plain pooled constant here, not derived from a
 * neighbouring one, because this is the only allocation in the function.
 *
 * The entry count for the loop is read back out of the object at +0x08 rather
 * than reused from the `n` that sized the allocation: the load right after the
 * call is the loop's rotated entry test, and the same field is re-read at the
 * bottom of every iteration because func_02082BCC may alias it.
 *
 * The clear is a per-element call, not one call over the whole array, so the
 * zero and the 0x10 are hoisted into callee-saved registers for the loop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C718.c \
 *       --func func_0204C718 --addr 0x0204C718 --cc 1.1p1 --arm
 */
void func_0204C718(struct Pool_0204C718 *p, u32 n, u32 heapId)
{
    u32 i;

    p->ents = sub_02030734(heapId, n * sizeof(struct Entry), 0, s_clact_c,
                           0x137b);

    for (i = 0; i < p->count; i++) {
        func_02082BCC(&p->ents[i], 0, sizeof(struct Entry));
    }
}
