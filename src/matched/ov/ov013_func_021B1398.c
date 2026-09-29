/*
 * function: func_021B1398
 * address:  0x021B1398
 * packet:   pkt_ov013_021B1398
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   g_021B4B98     0x021B4B98  data  a4
 *   g_021B4BA0     0x021B4BA0  data  a4
 */

struct Node {
    int f0;
    struct Node *prev;
    struct Node *next;
};

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);
extern void func_021B2FE4(struct Node *p);

extern struct {
    struct Node *head;
    struct Node *tail;
} g_021B4B98;
extern int g_021B4BA0[3];

void func_021B1398(void)
{
    int s;
    int i;
    struct Node *p;
    struct Node *q;

    s = OS_DisableInterrupts();
    p = g_021B4B98.head;
    while (p != 0) {
        q = p;
        p = p->next;
        func_021B2FE4(q);
    }
    g_021B4B98.head = 0;
    g_021B4B98.tail = 0;
    for (i = 0; i < 3; i++) {
        g_021B4BA0[i] = 0;
    }
    OS_RestoreInterrupts(s);
}
