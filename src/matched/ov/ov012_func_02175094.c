/*
 * function: func_02175094
 * address:  0x02175094
 * packet:   pkt_ov012_02175094
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0xc8];
    u8 bc8 : 1;
} Obj;

void func_02175094(Obj *p, int v)
{
    p->bc8 = (u8)v;
}
