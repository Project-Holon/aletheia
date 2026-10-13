/*
 * function: VCT_AUDIO_FindPending
 * address:  0x021B14A8
 * packet:   pkt_ov013_021B14A8
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
 */

typedef unsigned int u32;
typedef struct Node { u32 f0; struct Node *prev; struct Node *next; u32 f0c; unsigned char f10; unsigned char type; } Node;
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 h);
extern Node *gVctPendingList[2];

Node *VCT_AUDIO_FindPending(u32 type)
{
    Node *p = gVctPendingList[0];
    u32 h = OS_DisableInterrupts();

    for (; p; p = p->next) {
        if (p->type == type) {
            OS_RestoreInterrupts(h);
            return p;
        }
    }
    OS_RestoreInterrupts(h);
    return 0;
}
