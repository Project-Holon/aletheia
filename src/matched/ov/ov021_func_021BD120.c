/*
 * function: func_021BD120
 * address:  0x021BD120
 * packet:   pkt_ov021_021BD120
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x44];
    u16 h44;
    u16 h46;
} Obj;

void func_021BD120(Obj *p, u16 v)
{
    p->h44 = p->h46;
    p->h46 = v;
}
