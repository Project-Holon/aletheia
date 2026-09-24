/*
 * function: func_021BC3C0
 * address:  0x021BC3C0
 * packet:   pkt_021BC3C0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Returns the halfword of the table at +0x18 indexed by the halfword read through the pointer at +0x20.
 */


typedef struct {
    char pad[0x18];
    unsigned short *tbl;
    char pad2[4];
    unsigned short *idx;
} S;

unsigned short func_021BC3C0(S *p)
{
    return p->tbl[*p->idx];
}

