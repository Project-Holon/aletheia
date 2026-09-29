/*
 * function: func_021C06C0
 * address:  0x021C06C0
 * packet:   pkt_ov021_021C06C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf; called from ov043 func_021F3AC0.
 */

typedef unsigned char u8;

typedef struct {
    int pad[4];
    int v;
    int pad2[2];
} E;

void func_021C06C0(u8 i, int v, int *p)
{
    ((E *)p[1])[i].v = v;
}
