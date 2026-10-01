/*
 * function: func_0220893C
 * address:  0x0220893C
 * packet:   pkt_ov094_0220893C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned int u32;
typedef struct {
    char pad[0x440];
    u32 a : 21;
    u32 b : 1;
    u32 c : 10;
} W;

void func_0220893C(W *p, int v)
{
    p->b = v;
}
