/*
 * unit:     no
 * function: TCBL_BuildFreeList
 * address:  0x02030FC8
 * packet:   pkt_02030FC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   TCBL_GetTaskSlot  0x02030EF0  arm
 *   TCBL_PushFreeTask  0x02030F34  arm
 *   TCBL_InitTaskLinks  0x02030F50  arm
 *
 * Build the free list of the task-control-block pool: walk every row of the
 * stride table, self-link it (TCBL_InitTaskLinks) and push it on the free list
 * (TCBL_PushFreeTask).  The row address comes from TCBL_GetTaskSlot, already matched
 * as `idx * (p->field4 + 0x18) + p->field14`.
 *
 * The count is re-read from +0x00 at the bottom of the loop, which is what
 * a plain field read in the loop condition compiles to; a cached local
 * would have kept it in a register and cost a push.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_BuildFreeList.c \
 *       --func TCBL_BuildFreeList --addr 0x02030FC8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Tcbl {
    u32 count;
};

struct S02030EF0;
extern u32 TCBL_GetTaskSlot(struct S02030EF0 *p, u32 idx);
struct Node02030F34;
struct S02030F34;
extern void TCBL_PushFreeTask(struct S02030F34 *p, struct Node02030F34 *node);
struct TcblNode;
extern void TCBL_InitTaskLinks(struct Tcbl *p, struct TcblNode *n);

void TCBL_BuildFreeList(struct Tcbl *p)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        void *node = (void *)TCBL_GetTaskSlot((struct S02030EF0 *)p, i);
        TCBL_InitTaskLinks(p, node);
        TCBL_PushFreeTask((struct S02030F34 *)p, node);
    }
}
