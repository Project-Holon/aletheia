/*
 * file:     unit_021B2FB0.c
 * unit:     yes
 * function: func_021B2FB0, func_021B2FE4
 * address:  0x021B2FB0
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021B4C24 0x021B4C24 data a4
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */
typedef struct Node Node;

struct Node { Node *next; int f4,f8; };

extern int func_02087988(void);
extern void func_0208799C(int);
Node *func_021B2FB0(void);
void func_021B2FE4(Node *p);
extern Node *g_021B4C24;

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

void func_021B2FE4(Node *p)
{
    int irq=func_02087988();
    p->next=g_021B4C24;
    g_021B4C24=p;
    p->f4=0;
    p->f8=0;
    func_0208799C(irq);
}
