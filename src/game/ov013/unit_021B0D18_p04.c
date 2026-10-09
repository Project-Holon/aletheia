/*
 * file:     unit_021B0D18_p04.c
 * unit:     yes
 * function: func_021B1404
 * address:  0x021B1404
 * packet:   pkt_ov013_021B1404
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
 *   g_021B4B98     0x021B4B98  data  a4
 *   g_021B4BA0     0x021B4BA0  data  a4
 */

typedef unsigned char u8;

struct Node {
    int f0;
    struct Node *prev;
    struct Node *next;
    u8 pad[5];
    u8 f11;
};

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);

extern struct {
    struct Node *head;
    struct Node *tail;
} g_021B4B98;
extern int g_021B4BA0[3];

int func_021B1404(struct Node *n)
{
    int s;

    s = OS_DisableInterrupts();
    if (g_021B4B98.head == 0) {
        g_021B4B98.head = n;
        n->prev = 0;
        g_021B4B98.head->next = 0;
        g_021B4B98.tail = g_021B4B98.head;
    } else {
        n->prev = g_021B4B98.tail;
        n->next = 0;
        g_021B4B98.tail->next = n;
        g_021B4B98.tail = n;
    }
    g_021B4BA0[n->f11]++;
    OS_RestoreInterrupts(s);
    return g_021B4BA0[n->f11];
}
