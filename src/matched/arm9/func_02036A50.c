/*
 * function: GFL_NET_QUEUE_FillSendBuffer
 * address:  0x02036A50
 * packet:   pkt_020369F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  label -- GFL_NET_QUEUE_RemoveNext (this lane's own packet pkt_020369F8, but
 *           unlabelled work not in the slice and itself only called from here)
 *           and GFL_NET_QUEUE_WriteNode (pkt_020367C4, not this lane's).  Filing
 *           GFL_NET_QUEUE_RemoveNext would still leave GFL_NET_QUEUE_WriteNode unwitnessed, so the
 *           park is capped either way.
 *
 * symbols:
 *   GFL_NET_QUEUE_GetNext   0x020369C8  arm
 *   GFL_NET_QUEUE_RemoveNext   0x020369F8  arm
 *   GFL_NET_QUEUE_WriteNode   0x020367C4  arm
 *   func_02082BCC   0x02082BCC  arm
 *
 * Byte-identical at 164 bytes; only the two PC24 call fields at +0x40 and
 * +0x54 stay wildcarded (GFL_NET_QUEUE_GetNext resolves `matched`, func_02082BCC
 * resolves `label x566`).
 *
 * Spellings that mattered: every `return 1` must be a `goto` to one label at
 * the END of the function -- plain `return`s make mwcc predicate all three of
 * them inline (`moveq r0,#1; popeq`) and the frame shifts by 25 bytes.  And
 * `flag = 1;` sits BEFORE the 0xFFFF test, which is why the original shows
 * `mov r8,r6` between the `ldrh` and the `cmp`.
 */
#include "../include/Obj08825.h"

typedef unsigned short u16;
typedef unsigned int   u32;

typedef unsigned char  u8;
extern u32 GFL_NET_QUEUE_GetNext(u32 *p);
extern void GFL_NET_QUEUE_RemoveNext(u8 *p);
extern int   GFL_NET_QUEUE_WriteNode(int slot, u16 *info, u32 arg, int flag);
extern void *func_02082BCC(void *dst, int val, u32 size);

int GFL_NET_QUEUE_FillSendBuffer(u32 list, u16 *info)
{
    int flag = 0;

    if (info[2] == 0)
        goto done;
    while (1) {
        int slot = GFL_NET_QUEUE_GetNext((u32 *)list);

        if (slot == 0)
            goto done;
        GFL_NET_QUEUE_RemoveNext((u8 *)list);
        if (GFL_NET_QUEUE_WriteNode(slot, info, ((struct Obj08825 *)list)->f14, flag) == 0) {
            ((struct Obj08825 *)list)->f10 = slot;
            goto done;
        }
        flag = 1;
        if (info[2] == 0xffff) {
            ((struct Obj08825 *)list)->f10 = slot;
            return 0;
        }
        func_02082BCC((void *)slot, 0, 0x14);
        if (info[2] == 0)
            break;
    }
done:
    return 1;
}
