/*
 * function: VCT_POOL_AllocFrame
 * address: 0x021B2FB0
 * packet: pkt_ov013_021B2FB0
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVoiceFramePool 0x021B4C24 data a4
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */
typedef struct Node Node;
struct Node { Node *next; int f4,f8; };
extern Node *gVoiceFramePool;
extern int func_02087988(void);
extern void func_0208799C(int);
Node *VCT_POOL_AllocFrame(void)
{
    Node *result=0;
    int irq=func_02087988();
    if(gVoiceFramePool != 0) {
        result=gVoiceFramePool;
        gVoiceFramePool=gVoiceFramePool->next;
    }
    func_0208799C(irq);
    return result;
}
