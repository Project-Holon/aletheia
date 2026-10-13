/*
 * function: BTLV_BG_IsScrolling
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
 *   BTLV_BG_IsScrolling   0x0220985C  thumb
 *
 * lane O10 candidate
 */

typedef struct {
    char pad[4];
    unsigned int f : 1;
} S985C;

unsigned int BTLV_BG_IsScrolling(S985C *p)
{
    return p->f != 0;
}

