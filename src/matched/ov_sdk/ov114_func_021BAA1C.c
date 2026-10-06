/*
 * function: func_021BAA1C
 * address:  0x021BAA1C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BA590  0x021BA590  arm  ov114
 *   func_021BA820  0x021BA820  arm  ov114
 *   func_021BA874  0x021BA874  arm  ov114
 *
 *
 * Keyed insert into the circular node ring: reuses the node whose key string
 * matches, otherwise allocates a 0x18-byte node and links it in front of the
 * head.  Returns 0 only when the allocation failed (the caller is told with
 * reason code 1); the value is always stored.
 *
 * The head probe tests the negation of the match (match falls to the else
 * arm): that shape is what puts the first `found = 1` out of line at
 * 0x021BAA94 and keeps a single return-1 block at 0x021BAB1C, which is the
 * only layout that reproduces the image byte for byte.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Node {
    struct Node *prev;      /* +0x00 */
    struct Node *next;      /* +0x04 */
    const char *key;        /* +0x08 */
    int val;                /* +0x0c */
    int a;                  /* +0x10 */
    int b;                  /* +0x14 */
} Node;

int func_021BA590(char *p1_p, char *p2_p);
int func_021BA820(int a, int b);
void func_021BA874(u8 *p, int v);

int func_021BAA1C(Node **head, int b, int c, int d)
{
    Node *n = *head;
    int found = 0;
    Node *q;
    Node *p;

    if (n != 0) {
        q = n;
        if (func_021BA590((char *)c, (char *)q->key) != 0) {
            q = q->next;
            while (q != *head) {
                if (func_021BA590((char *)c, (char *)q->key) == 0) {
                    found = 1;
                    break;
                }
                q = q->next;
            }
        } else {
            found = 1;
        }
    }

    if (found != 0) {
        q->val = d;
    } else {
        p = (Node *)func_021BA820(0x18, 4);
        if (p == 0) {
            func_021BA874((u8 *)b, 1);
            return 0;
        }
        p->key = (const char *)c;
        p->val = d;
        p->a = 0;
        p->b = 0;
        if (*head == 0) {
            p->next = p;
            p->prev = p;
            *head = p;
        } else {
            p->prev = (*head)->prev;
            p->next = *head;
            (*head)->prev->next = p;
            (*head)->prev = p;
        }
    }
    return 1;
}
