/*
 * function: func_02060CD0
 * address:  0x02060CD0
 * packet:   pkt_02060CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF   (352 bytes compiled, 352 bytes original, 50 concrete
 *                   bytes differ -- see docs/notes/pkt_02060CD0.c.txt)
 *
 * symbols:
 *   func_02060764   0x02060764  arm
 *   func_02060790   0x02060790  arm
 *   func_020607B8   0x020607B8  arm
 *   func_020607E8   0x020607E8  arm
 *   func_02060B6C   0x02060B6C  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *
 * Blocking class: codegen, not evidence.  Every relocation resolves as
 * `label` and the whole function is byte-for-byte right except the if-
 * converted free-list walk at 0x02060D10..0x02060D28:
 *
 *   original                            this file
 *   02060D10  cmp  r6, #0               02060D10  cmp  r6, #0
 *   02060D14  add  r0, r7, r0           02060D14  add  r0, r7, r0
 *   02060D18  beq  0x02060D2C           02060D18  beq  0x02060D2C
 *   02060D1C  cmp  r6, r0               02060D1C  b    0x02060D24
 *   02060D20  ldrne r6, [r6, #0xc]      02060D20  ldr  r6, [r6, #0xc]
 *   02060D24  cmpne r6, #0              02060D24  cmp  r6, #0
 *   02060D28  bne  0x02060D1C           02060D28  beq  0x02060D2C
 *                                       02060D2C  cmp  r6, r0
 *                                       02060D30  bne  0x02060D20
 *
 * The original if-converts the loop-exit test `(u32)node == end` over the
 * whole rest of the iteration (the load into `cmpne r6, #0`'s slot and the
 * back edge, which then reads the guard's flags).  mwccarm 1.1p1 at -O4,p
 * produces that predicated chain only when the guard is a `break` that is
 * the loop's ONLY exit -- `if (node != 0) { while (1) { if ((u32)node ==
 * end) break; node = node->next; } }` is 348 bytes with exactly the right
 * `cmp / ldrne / bne` but no `cmpne r6, #0` -- and the form that does
 * produce the predicated chain plus a test of the advanced node
 * (`while (node != 0) { if ((u32)node == end) break; node = node->next;
 * if (node == 0) break; }`, 356 bytes) carries one extra `beq` that mwcc
 * declines to fold away even though its target is the fall-through of the
 * `bne`.  Full variant table and the 4266-spelling sweep are in the note.
 *
 * The loop kept here is the semantically exact one (the same walk as the
 * image) and is the same size as the original; the closest spelling by
 * byte count, `if (node != 0) { do { if ((u32)node != end) node =
 * node->next; } while (node != 0); }` at 30 differing bytes, is NOT used
 * because it spins when node == end and so is not the original's source.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02060CD0.c \
 *       --func func_02060CD0 --addr 0x02060CD0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MBlock {
    u16            signature;
    u16            attr;
    u32            size;
    struct MBlock *prev;
    struct MBlock *next;
};

struct MBlockList {
    struct MBlock *head;
    struct MBlock *tail;
};

struct ExpHeap {
    u8                pad_00[0x20];
    u32               field_20;
    struct MBlockList freeList;
    struct MBlockList usedList;
    u16               groupId;
    u16               feature;
};

extern void           func_02060764(int *out, struct MBlock *blk);
extern struct MBlock *func_02060790(struct MBlockList *list, struct MBlock *node);
extern struct MBlock *func_020607B8(struct MBlockList *list, struct MBlock *node,
                                    struct MBlock *prev);
extern void          *func_020607E8(int *info, u32 signature);
extern int            func_02060B6C(struct MBlockList *list, int *info);
extern void           MIi_CpuClear32(u32 data, void *dest, u32 size);

int func_02060CD0(struct ExpHeap *heap, void *block, u32 size)
{
    struct MBlock *node;
    u32            oldSize;
    struct MBlock *hdr;
    int            info[2];
    int            sinfo[2];
    u32            oldEnd;
    struct MBlock *prev;
    u32            newEnd;
    u32            remain;
    u32            end;

    hdr = (struct MBlock *)((u8 *)block - 0x10);
    oldSize = hdr->size;
    size = (size + 3) & ~3u;

    if (size == oldSize) {
        return size;
    }
    if (size > oldSize) {
        node = heap->freeList.head;
        end = oldSize + (u32)(hdr + 1);
        while (node != 0 && (u32)node != end) {
            node = node->next;
        }
        if (node == 0 || size > oldSize + 0x10 + node->size) {
            return 0;
        }

        func_02060764(info, node);
        prev = func_02060790(&heap->freeList, node);

        oldEnd = (u32)info[0];
        newEnd = size + (u32)block;
        remain = (u32)info[1] - newEnd;
        info[0] = newEnd;
        if (remain < 0x10) {
            info[0] = info[1];
        }

        hdr->size = (u32)info[0] - (u32)block;

        if ((u32)info[1] - (u32)info[0] >= 0x10) {
            func_020607B8(&heap->freeList, func_020607E8(info, 0x4652), prev);
        }

        if (((u8)heap->field_20 & 1) != 0) {
            MIi_CpuClear32(0, (void *)oldEnd, (u32)info[0] - oldEnd);
        }
    } else {
        sinfo[0] = size + (u32)block;
        sinfo[1] = *(volatile u32 *)((u8 *)hdr + 4) + (u32)(hdr + 1);
        hdr->size = size;
        if (func_02060B6C(&heap->freeList, sinfo) == 0) {
            hdr->size = oldSize;
        }
    }
    return hdr->size;
}
