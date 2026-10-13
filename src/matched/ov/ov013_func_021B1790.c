/*
 * function: VCT_AUDIO_FlushAllReadyQueues
 * address:  0x021B1790
 * packet:   pkt_ov013_021B1790
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

void VCT_AUDIO_FlushAllReadyQueues(void)
{
    int t;
    Node *n;
    u32 h = OS_DisableInterrupts();

    t = 0;
    while (t < 3) {
        while ((n = gVctReadyHead[t]) != 0) {
            Node *nx = n->next;

            gVctReadyHead[t] = nx;
            if (nx)
                nx->prev = 0;
            VCT_POOL_FreeFrame(n);
        }
        gVctReadyTail[t] = 0;
        gVctReadyCount[t] = 0;
        t++;
    }
    OS_RestoreInterrupts(h);
}
