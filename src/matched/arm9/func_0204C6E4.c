/*
 * function: CLACT_ExitTransferPool
 * address:  0x0204C6E4
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_Free   0x020307B0  arm
 *   CLACT_FreeTransferEntries  0x0204C788  arm
 *
 * The inverse of src/matched/CLACT_InitTransferPool.c: release the 0x30-byte record
 * array, drop the free-list built over it, and clear the constructed flag at
 * +0x0c.  An unconstructed object is an early return predicated onto the
 * entry compare.
 *
 * The zero is materialised once into a callee-saved register and used for
 * both stores, because the second store lands after the call to
 * CLACT_FreeTransferEntries; that is also what forces the store to +0x00 to be written
 * before the call rather than after
 * (docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ExitTransferPool.c \
 *       --func CLACT_ExitTransferPool --addr 0x0204C6E4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Pool {
    void *recs;      /* 0x00 */
    u8    pad_04[8];
    u32   ready;     /* 0x0c */
};

extern u32 GFL_HEAP_Free(void *p);
extern void CLACT_FreeTransferEntries(struct Pool *p);

void CLACT_ExitTransferPool(struct Pool *p)
{
    if (p->ready == 0) {
        return;
    }

    GFL_HEAP_Free(p->recs);
    p->recs = 0;
    CLACT_FreeTransferEntries(p);
    p->ready = 0;
}
