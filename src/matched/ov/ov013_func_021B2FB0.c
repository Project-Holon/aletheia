/*
 * function: func_021B2FB0
 * address: 0x021B2FB0
 * packet: pkt_ov013_021B2FB0
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
Node *func_021B2FB0(void)
{
    Node *result=0;
    int irq=func_02087988();
    if(g_021B4C24 != 0) {
        result=g_021B4C24;
        g_021B4C24=g_021B4C24->next;
    }
    func_0208799C(irq);
    return result;
}
