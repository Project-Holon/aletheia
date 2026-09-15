/*
 * function: func_0204C660
 * address:  0x0204C660
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Blocked at MATCH: all 132 concrete bytes are correct and four of the five
 * relocation sites resolve, but the PC24 at +0x0054 (the call to
 * func_02066934) has no witness of any class.  0x02066934 has exactly one
 * branch reference image wide and it is that call, so no cut frees it; the
 * only unblock is a `matched` entry at 0x02066934, far outside clact.c.
 *
 * symbols:
 *   s_clact_c      0x020A7F74  data
 *   sub_02030734   0x02030734  arm
 *   func_02066934  0x02066934  arm
 *   func_0204C718  0x0204C718  arm
 *   func_0204C83C  0x0204C83C  arm
 *
 * Construct a pool of `n` 0x30-byte records: allocate the array, hand it to
 * func_02066934 with func_0204C83C as the per-record callback, build the
 * parallel 0x10-byte entry array through func_0204C718, and mark the object
 * constructed.  A zero capacity leaves the object unconstructed and is the
 * predicated early return off the `movs` that loads the count.
 *
 * The record size 0x30 is a real `mul` against a register, not a shift pair:
 * mwccarm only strength-reduces the multiply when the constant is a power of
 * two, and 0x30 is not.
 *
 * The allocation result is bound to a local, stored, and then passed on: the
 * call to func_02066934 reuses the value in r0 instead of reloading +0x00,
 * which is what the named temporary produces
 * (docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md).
 *
 * func_0204C83C is passed as data, so the relocation is an ABS32 into the
 * code section; it is an ordinary extern declared at its own address, not a
 * veneer.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204C660.c \
 *       --func func_0204C660 --addr 0x0204C660 --cc 1.1p1 --arm
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

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void  func_02066934(struct Rec *recs, u32 n, void *cb);
extern void  func_0204C718(struct Pool *p, u32 n, u32 heapId);
extern void  func_0204C83C(void);

void func_0204C660(struct Pool *p, u32 n, u32 heapId)
{
    struct Rec *recs;

    if (n == 0) {
        p->ready = 0;
        return;
    }

    p->count = n;
    recs = sub_02030734(heapId, n * sizeof(struct Rec), 0, s_clact_c, 0x1337);
    p->recs = recs;

    func_02066934(recs, n, func_0204C83C);
    func_0204C718(p, n, heapId);

    p->ready = 1;
}
