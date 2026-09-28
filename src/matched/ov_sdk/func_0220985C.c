/*
 * function: func_0220985C
 * address:  0x0220985C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220985C   0x0220985C  thumb
 *
 * lane O10 candidate
 */

typedef struct {
    char pad[4];
    unsigned int f : 1;
} S985C;

unsigned int func_0220985C(S985C *p)
{
    return p->f != 0;
}

