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
 *   g_021B4C24 0x021B4C24 data a4
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */
typedef struct Node Node;
struct Node { Node *next; int f4,f8; };
extern Node *g_021B4C24;
extern int func_02087988(void);
extern void func_0208799C(int);
void VCT_POOL_FreeFrame(Node *p)
{
    int irq=func_02087988();
    p->next=g_021B4C24;
    g_021B4C24=p;
    p->f4=0;
    p->f8=0;
    func_0208799C(irq);
}
