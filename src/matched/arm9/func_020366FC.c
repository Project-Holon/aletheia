/*
 * function: GFL_NET_QUEUE_PopList
 * address:  0x020366FC
 * packet:   pkt_020366C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pops one entry off a singly linked list held at p[0], one link at a time:
 * the successor is p[0]->unk8; when it exists it becomes the new head and its
 * own back pointer at +4 is cleared, otherwise the head and the word after it
 * are both zeroed.  Returns 0 only when the list was already empty.
 *
 * Every arm is conditional-executed, so the function has exactly one `bx lr`
 * per exit and both `strne`/`streq` groups sit on the same `cmp`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_QUEUE_PopList.c \
 *       --func GFL_NET_QUEUE_PopList --addr 0x020366FC --cc 1.1p1 --arm
 */
#include "../include/Obj11348.h"

typedef unsigned int u32;

u32 GFL_NET_QUEUE_PopList(u32 *p)
{
    u32 v;

    v = p[0];
    if (v != 0) {
        v = ((struct Obj11348 *)v)->f8;
        if (v != 0) {
            p[0] = v;
            ((struct Obj11348 *)v)->f4 = 0;
        } else {
            p[0] = 0;
            p[1] = 0;
        }
        return 1;
    }
    return 0;
}
