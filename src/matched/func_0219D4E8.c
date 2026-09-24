/*
 * function: func_0219D4E8
 * address:  0x0219D4E8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pushes an element onto the singly linked list rooted in *p.
 */

void func_0219D4E8(int **p, int *q)
{
    int *head = p[0];
    int *tail;

    *(int **)((char *)q + 0x24) = head;
    tail = p[1];
    p[0] = q;
    if (tail == 0)
        p[1] = q;
    *(int *)((char *)p + 8) = *(int *)((char *)p + 8) + 1;
}
