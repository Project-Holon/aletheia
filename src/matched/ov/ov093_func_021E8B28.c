/*
 * function: BTL_SICKCONT_SetValue
 * address:  0x021E8B28
 * packet:   pkt_ov093_021E8B28
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned short u16; typedef unsigned int u32;
union U {
    struct { u32 kind : 3; u32 pad : 6; u32 id : 16; u32 rest : 7; } a;
    struct { u32 kind : 3; u32 pad : 12; u32 id : 16; u32 rest : 1; } b;
};
void BTL_SICKCONT_SetValue(union U *p, u16 v)
{
    if (p->a.kind == 1) p->a.id = v;
    else if (p->a.kind == 3) p->a.id = v;
    else if (p->a.kind == 4) p->b.id = v;
    else if (p->a.kind == 2) p->a.id = v;
}
