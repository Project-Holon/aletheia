/*
 * function: func_021B1944
 * address:  0x021B1944
 * packet:   pkt_ov013_021B1944
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
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   d_021B4BAC  0x021B4BAC  data  a4
 *   d_021B4BB8  0x021B4BB8  data  a4
 *   d_021B4BC4  0x021B4BC4  data  a4
 */

typedef unsigned int u32;
typedef struct Node { u32 f0; struct Node *prev; struct Node *next; u32 f0c; unsigned char f10; unsigned char type; } Node;
extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern void func_021B2FE4(Node *n);
extern Node *d_021B4BAC[];
extern u32 d_021B4BB8[];
extern Node *d_021B4BC4[];

Node *func_021B1944(u32 t)
{
    Node *n;
    u32 h = func_02087988();

    n = d_021B4BAC[t];
    if (n) {
        Node *next = n->next;

        d_021B4BAC[t] = next;
        d_021B4BB8[t]--;
        if (next)
            next->prev = 0;
        else
            d_021B4BC4[t] = 0;
    }
    func_0208799C(h);
    return (Node *)d_021B4BB8[t];
}
