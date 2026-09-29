/*
 * function: func_021B14F8
 * address:  0x021B14F8
 * packet:   pkt_ov013_021B14F8
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   d_021B4B98  0x021B4B98  data  a4
 *   d_021B4BA0  0x021B4BA0  data  a4
 */

typedef unsigned int u32;
typedef struct Node { u32 f0; struct Node *prev; struct Node *next; u32 f0c; unsigned char f10; unsigned char type; } Node;
extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern Node *d_021B4B98[2];
extern u32 d_021B4BA0[];

u32 func_021B14F8(Node *n)
{
    u32 h = func_02087988();

    if (n->prev)
        n->prev->next = n->next;
    else {
        d_021B4B98[0] = n->next;
        if (n->next)
            n->next->prev = 0;
    }
    if (n->next)
        n->next->prev = n->prev;
    else {
        d_021B4B98[1] = n->prev;
        if (n->prev)
            n->prev->next = 0;
    }
    d_021B4BA0[n->type]--;
    func_0208799C(h);
    return d_021B4BA0[n->type];
}
