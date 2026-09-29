/*
 * function: func_021E8BD0
 * address:  0x021E8BD0
 * packet:   pkt_ov093_021E8BD0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
typedef unsigned int u32;
union U {
    struct { u32 kind : 3; u32 pad : 22; u32 f : 1; u32 rest : 6; } a;
    struct { u32 kind : 3; u32 pad : 28; u32 f : 1; } b;
};
void func_021E8BD0(union U *p, u32 v)
{
    if (p->a.kind == 1) p->a.f = v;
    else if (p->a.kind == 3) p->a.f = v;
    else if (p->a.kind == 4) p->b.f = v;
    else if (p->a.kind == 2) p->a.f = v;
}
