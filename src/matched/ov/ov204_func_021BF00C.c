/*
 * function: func_021BF00C
 * address:  0x021BF00C
 * packet:   pkt_021BF00C
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

struct S021BF00C
{
    char pad[0x20];
    void *slots[8];
};

struct Q021BF00C
{
    char pad[0x14];
    unsigned char b : 1;
};

int func_021BF00C(struct S021BF00C *p, struct Q021BF00C *q)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (p->slots[i] == 0)
        {
            p->slots[i] = q;
            break;
        }
    }
    return q->b;
}
