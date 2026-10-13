/*
 * function: DWCi_RemoveDWCGHTTPParamEntry
 * address:  0x021BFA70
 * packet:   pkt_ov114_021BFA70
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gDwcGhttpParamList    0x021D3B20  data  ov114  a4
 *   func_0205A1B0 0x0205A1B0  arm
 *
 * Singly linked list removal.  The if/else with a lone `p = q` arm is
 * deliberate: it makes armcc if-convert that assignment to `movne` and
 * branch over the found arm, which is the only shape that reproduces the
 * original loop.  See
 * docs/idioms/a-lone-move-arm-if-converts-to-movne.md
 */

typedef struct Node {
    unsigned char pad[0x1c];
    struct Node *next;
} Node;

extern Node *gDwcGhttpParamList[];
extern void func_0205A1B0(int, Node *, int);

void DWCi_RemoveDWCGHTTPParamEntry(Node *x)
{
    Node *p = gDwcGhttpParamList[1];
    Node *q;
    if (p == 0)
        return;
    if (p == x) {
        Node *nx = p->next;
        func_0205A1B0(6, p, 0);
        gDwcGhttpParamList[1] = nx;
        return;
    }
    q = p->next;
    if (q == 0)
        return;
    for (;;) {
        if (q != x) {
            p = q;
        } else {
            Node *n = p->next;
            p->next = n->next;
            func_0205A1B0(6, n, 0);
            return;
        }
        q = q->next;
        if (q == 0)
            return;
    }
}
