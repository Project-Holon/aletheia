/*
 * function: VCT_AUDIO_FlushReadyQueue
 * address:  0x021B1720
 * packet:   pkt_ov013_021B1720
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
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   gVctReadyHead  0x021B4BAC  data  a4
 *   gVctReadyCount  0x021B4BB8  data  a4
 *   gVctReadyTail  0x021B4BC4  data  a4
 */

typedef unsigned int u32;
typedef struct Node { u32 f0; struct Node *prev; struct Node *next; u32 f0c; unsigned char f10; unsigned char type; } Node;
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 h);
extern void VCT_POOL_FreeFrame(Node *n);
extern Node *gVctReadyHead[];
extern u32 gVctReadyCount[];
extern Node *gVctReadyTail[];

void VCT_AUDIO_FlushReadyQueue(u32 t)
{
    Node *n;
    u32 h = OS_DisableInterrupts();

    n = gVctReadyHead[t];
    while (n) {
        Node *nx = n->next;
        gVctReadyHead[t] = nx;
        if (nx)
            nx->prev = 0;
        VCT_POOL_FreeFrame(n);
        n = gVctReadyHead[t];
    }
    gVctReadyTail[t] = 0;
    gVctReadyCount[t] = 0;
    OS_RestoreInterrupts(h);
}
