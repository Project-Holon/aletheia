/*
 * function: NNSi_SndPlayerAllocHeap
 * address:  0x020734AC
 * packet:   pkt_020734AC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gSndPlayers     0x0214E464  data
 *   func_02060614  0x02060614  arm
 *   func_020605B4  0x020605B4  arm
 *   NNS_SndHeapClear  0x02074770  arm
 *
 * Takes the head node off the free list embedded at +0x0c of slot `idx` of the
 * gSndPlayers table, binds it to `owner` in both directions, drains the owner's
 * deferred requests through NNS_SndHeapClear, and returns the owner back.
 * Returns 0 when the free list is empty.
 *
 * THE TABLE STRIDE IS 0x24 AND THE LIST IS EMBEDDED AT +0x0c.  Both are fixed
 * by the head: `mov r2, #0x24 / mla r5, r0, r2, r3` is an indexed subscript on
 * a 0x24-stride array (the same table and stride matched NNS_SndPlayerInit and
 * NNSi_SndPlayerAllocSeqPlayer already use), and the list argument is `add r0, r5, #0xc`, the
 * ADDRESS of an embedded object, not a loaded pointer.  Declaring the +0x0c
 * field as a `void *` and passing it emits an extra `ldr` and loses the add.
 *
 * THE LAST TWO STATEMENTS RE-READ n->f08 RATHER THAN REUSING `owner`.  The
 * image loads `ldr r0, [r4, #8]` twice, once for NNS_SndHeapClear's argument and
 * once for the return value, even though the value was just stored there from
 * r4's own `str r4, [r6, #8]`.  Writing `NNS_SndHeapClear(owner); return owner;`
 * folds both loads away and is 8 bytes short.  The re-read is what the C above
 * spells literally, and it is also why the two stores are written in the order
 * f0c-then-f08: the compiler does not reorder them and the second store is what
 * the following load depends on.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md, and
 * docs/families/cluster_020726D0.h).  Under dsi/1.1p1 -O4,p the slot base and
 * the owner are both live across the func_02060614 call, so 1.1p1 hoists them
 * into a SIXTH and SEVENTH callee-saved register: the frame becomes
 * `push {r3, r4, r5, r6, r7, lr}` against the image's `push {r4, r5, r6, lr}`,
 * `add r0, r5, #0xc` becomes `add r0, r6, #0xc` and the owner moves from r6 to
 * r7 -- every byte from +0x20 on shifts.  The image keeps the slot base in r5
 * and the owner in r6 and materialises what it needs at each use.  Under the
 * pin the same C is 84 bytes, 0 concrete mismatches.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_SndPlayerAllocHeap.c \
 *       --func NNSi_SndPlayerAllocHeap --addr 0x020734AC --cc ../2.0/sp2 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Node { u8 pad00[8]; void *f08; void *f0c; };
struct Slot { u8 pad00[0x0c]; u8 list[0x24 - 0x0c]; };

extern struct Slot gSndPlayers[];
struct DList;
extern void *func_02060614(struct DList *list, void *elem);
extern void func_020605B4(volatile struct DList *list, void *elem);
struct Obj;
extern void NNS_SndHeapClear(struct Obj *o);

void *NNSi_SndPlayerAllocHeap(s32 idx, void *owner)
{
    struct Slot *s = &gSndPlayers[idx];
    struct Node *n = func_02060614((struct DList *)s->list, 0);
    if (n == 0) return 0;
    func_020605B4((volatile struct DList *)s->list, n);
    n->f0c = owner;
    ((struct Node *)owner)->f08 = n;
    NNS_SndHeapClear(n->f08);
    return n->f08;
}
