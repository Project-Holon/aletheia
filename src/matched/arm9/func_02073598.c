/*
 * function: NNSi_SndInsertActiveSeqPlayer
 * address:  0x02073598
 * packet:   pkt_02073548
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02060614  0x02060614  arm
 *   func_02060550  0x02060550  arm
 *   gSndActiveSeqList     0x0214E018  data
 *
 * Priority-ordered insert into the gSndActiveSeqList list.  Walks the list with the
 * generic iterator func_02060614 (a null cursor asks for the head, a node asks
 * for its successor), stops at the first node whose b3d priority byte is
 * strictly greater than the new object's, and inserts before it with
 * func_02060550.  Running off the end leaves `curr` null, which is
 * func_02060550's "append" case, so one loop serves both.
 *
 * TWO INDEPENDENT ERRORS were fixed to close this, and only the first is
 * interesting:
 *
 * 1. THE LIST OBJECT IS AN ARRAY, NOT A POINTER.  The parked version declared
 *    `extern void *gSndActiveSeqList;` and passed `gSndActiveSeqList`, so every call site
 *    emitted an extra `ldr r0, [r0]` to LOAD the pointer out of the object.
 *    The image has no such load: it hands the ADDRESS 0x0214E018 straight to
 *    the callee.  `extern char gSndActiveSeqList[];` is the spelling every matched
 *    sibling in this range already uses (NNS_SndPlayerInit, NNS_SndPlayerMain), and
 *    this file disagreeing with them was the whole of the 47-byte residue's
 *    tail.  Fixing it alone took the file to 8 bytes out, all in the head.
 *
 * 2. PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md, and
 *    docs/families/cluster_020726D0.h).  With the declaration fixed, dsi/1.1p1
 *    still hoists the gSndActiveSeqList pool word into callee-saved r4 BEFORE the
 *    `mov r5, r0` (giving `ldr r4,[pc,#0x44] / mov r5,r0 / mov r0,r4`) and
 *    serves both the entry call and the loop call from it.  The image instead
 *    materialises the entry call's argument from its OWN pool word
 *    (`ldr r0,[pc,#0x40]` at 0x020735A0) and only loads r4 at 0x020735B4,
 *    AFTER the early-exit test -- i.e. it does not pay for the loop's base on
 *    the path that never reaches the loop.  Two distinct pool entries for one
 *    symbol, the cluster's signature.  Under the pin the same C is 84 bytes,
 *    0 concrete mismatches.
 *
 * The comparison is UNSIGNED (`blo` at 0x020735C4), so b3d is u8 and the test
 * is `obj->b3d < curr->b3d`; a signed spelling emits `blt`.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_SndInsertActiveSeqPlayer.c \
 *       --func NNSi_SndInsertActiveSeqPlayer --addr 0x02073598 --cc ../2.0/sp2 --arm
 */

typedef unsigned char u8;

typedef struct Obj_02073548 {
    u8 pad[0x3d];
    u8 b3d;
} Obj_02073548;

extern char gSndActiveSeqList[];
struct DList;
extern void *func_02060614(struct DList *list, void *elem);
extern void func_02060550(volatile struct DList *list, void *before, void *elem);

void NNSi_SndInsertActiveSeqPlayer(Obj_02073548 *obj)
{
    Obj_02073548 *curr = func_02060614((struct DList *)gSndActiveSeqList, 0);
    while (curr != 0) {
        if (obj->b3d < curr->b3d) {
            break;
        }
        curr = func_02060614((struct DList *)gSndActiveSeqList, curr);
    }
    func_02060550((volatile struct DList *)gSndActiveSeqList, curr, obj);
}
