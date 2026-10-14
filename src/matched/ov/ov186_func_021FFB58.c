/*
 * function: BR_NET_RunTask
 * address:  0x021FFB58
 * packet:   pkt_021FFB58
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    int (*fn)(void *, void *, int);
    char  pad_04[4];
    int   arg_08;
} S;

void BR_NET_RunTask(S *p)
{
    if (p->fn != 0)
        p->fn(p, (char *)p + 4, p->arg_08);
}
