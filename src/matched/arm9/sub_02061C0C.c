/*
 * unit:     no
 * function: sub_02061C0C
 * address:  0x02061C0C
 * packet:   pkt_02061C0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sVramTransferTaskQueue     0x02146B80  data
 *   g_02146B80_cb  0x02146B80  data
 *   func_02061B5C  0x02061B5C  arm
 *
 * func_02061B5C (0x02061B5C) is named by two words in the whole image: the
 * pool word at 0x02061C28 inside this function, and the one at 0x02061C3C
 * inside the unlabelled stub at 0x02061C30 (the same tail call without the
 * two stores). Neither disasm.py's tracer nor its prologue sweep ever reach
 * 0x02061C30 (no `lr`-saving prologue, nothing branches to it), so that
 * second pool word used to sit in an anonymous `.word` run; disasm.py's
 * index_hidden_pool_words() now finds it (it decodes as a genuine PC-relative
 * load in the run right after this function's own `bx ip`, and its value
 * reads back as a pointer into arm9), so `literal` witnesses func_02061B5C
 * from outside this function's own 0x02061C0C..0x02061C30 range.
 *
 * Installs the request-buffer base and capacity into the queue object at
 * 0x02146B80 and tail
 * calls func_02061B5C on it (docs/idioms/tail-call-is-a-pool-word-and-bx.md,
 * hence the `ldr ip` / `bx ip` pair rather than a `b`). The same queue object
 * is the one src/pending/NNS_GfdRegisterNewVramTransferTask.c pushes requests onto, and the stub at
 * 0x02061C30 is the same tail call without the two stores.
 *
 * The one shape question this function poses is why 0x02146B80 costs two pool
 * words. Written as one symbol, mwcc common-subexpressions the two references
 * and emits `mov r0, r2` where the original emits a second `ldr r0, [pc]`,
 * three bytes wrong and four bytes short; `volatile`, an address-of-member
 * argument, a cast through `void *` and a cast of the store base all still
 * CSE. Two distinct declarations at the address are the only spelling that
 * reproduces the pair, so that is what this file uses: `g_02146B80_cb` for
 * the base/capacity slots and `sVramTransferTaskQueue` for the queue the tail call takes.
 * Writing the two stores as a static helper the compiler might inline instead
 * makes it worse, not better: mwcc emits a real tail call to the helper and
 * merges the two stores into one `stm`, which the original does not have.
 *
 * Historically reported EXACT* before the follower at 0x02061C30 had its
 * own label. Current verification reports EXACT for the 36-byte function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02061C0C.c \
 *       --func sub_02061C0C --addr 0x02061C0C --cc 1.1p1 --arm
 */

#include "../include/G_Queue.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int    s32;

extern struct Queue sVramTransferTaskQueue;
extern struct Queue g_02146B80_cb;

extern void func_02061B5C(u8 *p);

void sub_02061C0C(void *a, u32 capacity)
{
    g_02146B80_cb.unk_00 = a;
    g_02146B80_cb.capacity = capacity;
    func_02061B5C((u8 *)(&sVramTransferTaskQueue));
}
