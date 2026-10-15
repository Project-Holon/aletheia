/*
 * function: CLACT_InitTransferPool
 * address:  0x0204C660
 * packet:   pkt_0204C060
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * promoted: from src/pending 2026-09-19, no C change: blocker 0x02066934 is filed in layout/matched/arm9/pkt_02066890.json and every site resolves (gate: manifest --verify --shard layout/matched/arm9/pkt_0204C060.json, then 0 rewritten).
 *
 * Blocked at MATCH: all 132 concrete bytes are correct and four of the five
 * relocation sites resolve, but the PC24 at +0x0054 (the call to
 * NNS_G2dInitCellTransferStateManager) has no witness of any class.  0x02066934 has exactly one
 * branch reference image wide and it is that call, so no cut frees it; the
 * only unblock is a `matched` entry at 0x02066934, far outside clact.c.
 *
 * symbols:
 *   s_clact_c      0x020A7F74  data
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   NNS_G2dInitCellTransferStateManager  0x02066934  arm
 *   CLACT_AllocTransferEntries  0x0204C718  arm
 *   CLACT_RequestTransfer  0x0204C83C  arm
 *
 * Construct a pool of `n` 0x30-byte records: allocate the array, hand it to
 * NNS_G2dInitCellTransferStateManager with CLACT_RequestTransfer as the per-record callback, build the
 * parallel 0x10-byte entry array through CLACT_AllocTransferEntries, and mark the object
 * constructed.  A zero capacity leaves the object unconstructed and is the
 * predicated early return off the `movs` that loads the count.
 *
 * The record size 0x30 is a real `mul` against a register, not a shift pair:
 * mwccarm only strength-reduces the multiply when the constant is a power of
 * two, and 0x30 is not.
 *
 * The allocation result is bound to a local, stored, and then passed on: the
 * call to NNS_G2dInitCellTransferStateManager reuses the value in r0 instead of reloading +0x00,
 * which is what the named temporary produces
 * (docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md).
 *
 * CLACT_RequestTransfer is passed as data, so the relocation is an ABS32 into the
 * code section; it is an ordinary extern declared at its own address, not a
 * veneer.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_InitTransferPool.c \
 *       --func CLACT_InitTransferPool --addr 0x0204C660 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u8 pad_00[0x30];
};

struct Entry {
    u8 pad_00[0x10];
};

struct Pool {
    struct Rec   *recs;    /* 0x00 */
    struct Entry *ents;    /* 0x04 */
    u32           count;   /* 0x08 */
    u32           ready;   /* 0x0c */
};

extern char s_clact_c[];

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void  NNS_G2dInitCellTransferStateManager(struct Rec *recs, u32 n, void *cb);
extern void  CLACT_AllocTransferEntries(struct Pool *p, u32 n, u32 heapId);
extern u32 CLACT_RequestTransfer(u32 kind, u32 a, u32 b, u32 c);

void CLACT_InitTransferPool(struct Pool *p, u8 n, u32 heapId)
{
    struct Rec *recs;

    if (n == 0) {
        p->ready = 0;
        return;
    }

    p->count = n;
    recs = GFL_HEAP_Alloc(heapId, n * sizeof(struct Rec), 0, s_clact_c, 0x1337);
    p->recs = recs;

    NNS_G2dInitCellTransferStateManager(recs, n, CLACT_RequestTransfer);
    CLACT_AllocTransferEntries(p, n, heapId);

    p->ready = 1;
}
