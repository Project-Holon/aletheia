/*
 * file:     unit_0219D4B4_p01.c
 * unit:     yes
 * function: func_0219D4B4, func_0219D4E8, func_0219D510
 * address:  0x0219D4B4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
struct _SBServer {
    char pad[0x24];
    struct _SBServer *next;
};

struct _SBServerFIFO {
    struct _SBServer *first;
    struct _SBServer *last;
    int count;
};

void func_0219D4B4(int *p, int *n);
void func_0219D4E8(int **p, int *q);
struct _SBServer *FIFOGetFirst(struct _SBServerFIFO *fifo);

/*
 * Pushes a node onto a three-word list head: the node's +0x24 link is
 * cleared, the old head is linked to it, the tail is filled in when the list
 * was empty, and the count at +8 is bumped.
 */
void func_0219D4B4(int *p, int *n)
{
    if (p[1] != 0) ((int *)p[1])[9] = (int)n;
    p[1] = (int)n;
    n[9] = 0;
    if (p[0] == 0) p[0] = (int)n;
    p[2]++;
}

/*
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


struct _SBServer *FIFOGetFirst(struct _SBServerFIFO *fifo)
{
    struct _SBServer *hold = fifo->first;

    if (hold != 0)
    {
        fifo->first = hold->next;
        if (fifo->first == 0)
            fifo->last = 0;
        fifo->count = fifo->count - 1;
    }
    return hold;
}
