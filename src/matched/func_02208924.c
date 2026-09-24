/*
 * function: func_02208924
 * address:  0x02208924
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02208924   0x02208924  thumb
 *
 * lane O10 candidate
 */

typedef struct {
    char pad[0x440];
    unsigned int a : 3;
    unsigned int b : 1;
} S8924;

void func_02208924(S8924 *p, int v)
{
    p->b = v;
}

