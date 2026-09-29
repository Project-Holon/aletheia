/*
 * function: func_021B24FC
 * address:  0x021B24FC
 * packet:   pkt_ov013_021B24FC
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B4BE0  0x021B4BE0  data  a4
 *   func_021B2724  0x021B2724  arm  ov013
 */

typedef unsigned char u8;

typedef struct Ctx {
    u8 b0;
} Ctx;

typedef struct Node {
    char pad[0x14];
    struct Node *next;
} Node;

typedef struct Pool {
    Node *head;
    Node *freeList;
} Pool;

extern Ctx d_021B60D8;
extern Pool d_021B4BE0;
extern void func_021B2724(Node *n, unsigned int idx);

Node *func_021B24FC(unsigned int idx)
{
    Node *n;

    if (idx >= 0x20)
        return 0;
    if (idx == d_021B60D8.b0)
        return 0;
    n = d_021B4BE0.head;
    if (n == 0)
        return 0;
    d_021B4BE0.head = n->next;
    func_021B2724(n, idx);
    n->next = d_021B4BE0.freeList;
    d_021B4BE0.freeList = n;
    return n;
}
