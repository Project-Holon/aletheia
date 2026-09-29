/*
 * function: func_021B2958
 * address:  0x021B2958
 * packet:   pkt_ov013_021B2958
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B4BE0  0x021B4BE0  data  a4
 */

typedef struct N {
    int a;
    int b;
    int c;
    int kind;
    int e;
    struct N *next;
} N;

typedef struct {
    int x;
    N *head;
} G;

extern G d_021B4BE0;

int func_021B2958(N *p)
{
    N *n;

    n = d_021B4BE0.head;
    while (n) {
        if (n->a != 0 && n->kind == 2) {
            if (p != n)
                return 0;
        }
        n = n->next;
    }
    return 1;
}
