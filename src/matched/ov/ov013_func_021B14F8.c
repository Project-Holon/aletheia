/*
 * function: VCT_AUDIO_UnlinkPending
 * address:  0x021B14F8
 * packet:   pkt_ov013_021B14F8
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gVctPendingList  0x021B4B98  data  a4
 *   gVctPendingCount  0x021B4BA0  data  a4
 */

typedef unsigned int u32;
typedef struct Node { u32 f0; struct Node *prev; struct Node *next; u32 f0c; unsigned char f10; unsigned char type; } Node;
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 h);
extern Node *gVctPendingList[2];
extern u32 gVctPendingCount[];

u32 VCT_AUDIO_UnlinkPending(Node *n)
{
    u32 h = OS_DisableInterrupts();

    if (n->prev)
        n->prev->next = n->next;
    else {
        gVctPendingList[0] = n->next;
        if (n->next)
            n->next->prev = 0;
    }
    if (n->next)
        n->next->prev = n->prev;
    else {
        gVctPendingList[1] = n->prev;
        if (n->prev)
            n->prev->next = 0;
    }
    gVctPendingCount[n->type]--;
    OS_RestoreInterrupts(h);
    return gVctPendingCount[n->type];
}
