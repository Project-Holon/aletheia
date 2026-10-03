/*
 * unit:     no
 * function: sub_0203101C
 * address:  0x0203101C
 * packet:   pkt_02030FC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734       0x02030734  arm
 *   sub_02030F50       0x02030F50  arm
 *   sub_02030FC8       0x02030FC8  arm
 *   sub_0203101C_File  0x020A7834  data
 *
 * Constructor of the task-callback list (tcbl.c).  A 0x38-byte manager is
 * allocated first, then the row table: stride is the work size rounded up
 * to a word plus the 0x18-byte node header, times the row count, which is
 * the same stride sub_02030EF0 recomputes when indexing the table.
 *
 * The rounded stride is derived from the parameter, not re-read from the
 * field just stored at +0x04: the original stores r6 unchanged and then
 * does `add r1, r6, #3 / bic r1, r1, #3` on the same register, with no
 * reload in between.
 *
 * sub_02030FC8 builds the free list out of the table, and sub_02030F50
 * self-links the sentinel node embedded at +0x18, after which +0x30 (the
 * walk cursor) is cleared.
 *
 * 0x020A7834 is the allocation-site pointer this translation unit passes as
 * the allocator's fourth argument, the tcbl.c anchor in
 * layout/file_anchors.txt; the fifth argument is the u16 tag, here 199 and
 * 207.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203101C.c \
 *       --func sub_0203101C --addr 0x0203101C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct TcblNode {
    u32              unk_00;
    struct TcblNode *prev;
    struct TcblNode *next;
    u32              unk_0c;
    u32              unk_10;
    u32              unk_14;
};

struct Tcbl {
    u32              count;
    u32              workSize;
    u16              unk_08;
    u16              pad_0a;
    u32              unk_0c;
    u32              unk_10;
    void            *table;
    struct TcblNode  sentinel;
    struct TcblNode *cursor;
    struct TcblNode *freeHead;
};

extern const char sub_0203101C_File[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void sub_02030F50(struct Tcbl *p, struct TcblNode *node);
extern void sub_02030FC8(struct Tcbl *p);

struct Tcbl *sub_0203101C(u32 heap, u16 tag, u32 count, u32 workSize)
{
    struct Tcbl *p;

    p = sub_02030734(heap, sizeof(struct Tcbl), 0, sub_0203101C_File, 199);
    p->count = count;
    p->workSize = workSize;
    p->unk_08 = tag;
    p->unk_0c = 0;
    p->unk_10 = 0;
    p->table = sub_02030734(heap, (((workSize + 3) & ~3) + 0x18) * count, 0,
                            sub_0203101C_File, 207);
    p->freeHead = 0;
    sub_02030FC8(p);
    sub_02030F50(p, &p->sentinel);
    p->cursor = 0;
    return p;
}
