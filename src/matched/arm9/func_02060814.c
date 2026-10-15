/*
 * unit:     no
 * function: NNSi_FndCreateExpHeap
 * address:  0x02060814
 * packet:   pkt_02060764
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndInitHeapHead  0x020606D0  arm
 *   NNSi_FndInitMBlock  0x020607E8  arm
 *
 * COMPILER PIN: this function is byte-exact only under `--cc ../2.0/sp2` and
 * is DIFF under the project default dsi/1.1p1.  Every instruction and both
 * relocations are right under 1.1p1 too -- the residue is the signature
 * documented in docs/FRONTEND-PINS.md and in the compiler-pin section of
 * docs/families/cluster_020737C0.h: the function materialises the literal 0
 * at two separate points, 1.1p1 pools it into a callee-saved register and
 * reuses it, which widens the prologue to `push {r4, r5, lr}` where the image
 * has `push {r3, r4, lr}` and shifts every later register by one.  sp2
 * rematerialises `mov r0, #0` and `mov r1, #0` exactly as the image does.
 * The C body is identical under both front ends; only the pin differs.
 *
 * The expanded heap's layout pass, reached from NNS_FndCreateExpHeapEx once the arena
 * has been word-aligned and size-checked.  The 0x38-byte handle is written at
 * the arena's own start: NNSi_FndInitHeapHead fills the common header (signature,
 * bounds, attribute, child list) and the rest of this function lays out the
 * expanded heap's own record -- group id and feature halfwords at +0x34/+0x36,
 * a single free block spanning the whole remaining arena on the free list at
 * +0x24/+0x28, and an empty used list at +0x2c/+0x30.
 *
 * Argument order to NNSi_FndInitHeapHead is read off the register moves, not guessed:
 * `mov r3, r1` puts this function's own second parameter in the FOURTH
 * argument slot and `ldr r1, [pc, #0x50]` puts the 'EXPH' signature word
 * (0x45585048, at the pool word 0x02060880) in the second, so the call is
 * (heap, signature, heap + 0x38, lo, attr).
 *
 * The `bic r0, r0, #1` at +0x28 is load-bearing and does not survive a
 * constant-folded spelling: `feature = 0; ... feature & ~1` folds to a plain
 * zero and four bytes are lost.  Storing 0 to the field and then reading the
 * FIELD back for the clear is what keeps it, the
 * docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_FndCreateExpHeap.c \
 *       --func NNSi_FndCreateExpHeap --addr 0x02060814 --cc ../2.0/sp2 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MBlock;

struct MBlockList {
    struct MBlock *head;
    struct MBlock *tail;
};

struct ExpHeap {
    u8                pad_00[0x18];
    void             *lo;
    void             *hi;
    u32               attr;
    struct MBlockList freeList;
    struct MBlockList usedList;
    u16               groupId;
    u16               feature;
    u8                pad_38[0];
};

extern void           NNSi_FndInitHeapHead(struct ExpHeap *h, void *sig, void *self,
                                    void *lo, u32 attr);
extern void *NNSi_FndInitMBlock(int *p, int v);

void *NNSi_FndCreateExpHeap(struct ExpHeap *heap, void *lo, u32 attr)
{
    int  pair[2];
    u16  feature;

    NNSi_FndInitHeapHead(heap, (void *)0x45585048, (void *)((u8 *)heap + 0x38), lo, attr);

    heap->groupId = 0;
    heap->feature = 0;
    heap->feature = heap->feature & ~1;

    pair[0] = (int)heap->lo;
    pair[1] = (int)heap->hi;
    heap->freeList.head = NNSi_FndInitMBlock(pair, 0x4652);
    heap->freeList.tail = heap->freeList.head;
    heap->usedList.head = 0;
    heap->usedList.tail = 0;
    return heap;
}
