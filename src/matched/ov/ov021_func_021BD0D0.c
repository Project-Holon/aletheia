/*
 * function: func_021BD0D0
 * address:  0x021BD0D0
 * packet:   pkt_ov021_021BD0D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x40];
    u8 b40;
} Obj;

void func_021BD0D0(Obj *p)
{
    p->b40++;
}
