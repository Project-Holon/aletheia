/*
 * function: BTLV_CORE_GetSlotFlag
 * address: 0x021E8C24
 * packet: pkt_ov093_021E8C24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov093/btlv_core.c and filed here.
 */

typedef unsigned int u32;

union U_021E8BD0 {
    struct { u32 kind : 3; u32 pad : 22; u32 f : 1; u32 rest : 6; } a;
    struct { u32 kind : 3; u32 pad : 28; u32 f : 1; } b;
};

u32 BTLV_CORE_GetSlotFlag(union U_021E8BD0 v);

u32 BTLV_CORE_GetSlotFlag(union U_021E8BD0 v)
{
    if (v.a.kind == 1) return v.a.f;
    if (v.a.kind == 3) return v.a.f;
    if (v.a.kind == 4) return v.b.f;
    if (v.a.kind == 2) return v.a.f;
    return 0;
}
