/*
 * function: CRYPTOi__bn_fix_top
 * address:  0x021CAC8C
 * packet:   pkt_021CAC8C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef struct
{
    int *data;
    int count;
} Stack;

void CRYPTOi__bn_fix_top(Stack *s)
{
    int *p;

    if (s->count <= 0)
        return;
    p = &s->data[s->count - 1];
    while (s->count > 0)
    {
        if (*p-- != 0)
            return;
        s->count--;
    }
}
