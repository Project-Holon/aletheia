/*
 * function: func_021D3288
 * address:  0x021D3288
 * packet:   pkt_ov021_021D3288
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled 10-byte leaf (movs/strh/str/str/bx lr) between labelled code;
 * called from func_021C622C.
 */

typedef unsigned short u16;

typedef struct {
    u16 f0;
    u16 pad2;
    int f4;
    int f8;
} Rec;

void func_021D3288(Rec *p, int a, int b)
{
    p->f0 = 5;
    p->f4 = a;
    p->f8 = b;
}
