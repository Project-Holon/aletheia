/*
 * function: func_021BD098
 * address:  0x021BD098
 * packet:   pkt_ov021_021BD098
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;

typedef struct {
    char pad[0xC];
    u16 hC;
} Obj;

void func_021BD098(Obj *p, u16 v)
{
    p->hC = v;
}
