/*
 * function: VCT_POOL_FreeFrame
 * address: 0x021B2FE4
 * packet: pkt_ov013_021B2FE4
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVoiceFramePool 0x021B4C24 data a4
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 */
typedef struct Node Node;
struct Node { Node *next; int f4,f8; };
extern Node *gVoiceFramePool;
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int);
void VCT_POOL_FreeFrame(Node *p)
{
    int irq=OS_DisableInterrupts();
    p->next=gVoiceFramePool;
    gVoiceFramePool=p;
    p->f4=0;
    p->f8=0;
    OS_RestoreInterrupts(irq);
}
