/*
 * function: BTLV_CORE_SetSlotIndex
 * address:  0x021E8C9C
 * packet:   pkt_ov093_021E8C9C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned int u32;
union U {
    struct { u32 kind : 3; u32 f : 6; u32 rest : 23; } a;
};
void BTLV_CORE_SetSlotIndex(union U *p, int v)
{
    if (p->a.kind == 2 && p->a.f < 8) p->a.f = v;
    if (p->a.kind == 4 && p->a.f < 8) p->a.f = v;
}
