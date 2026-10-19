/*
 * function: BTL_SICKCONT_GetValue
 * address:  0x021E8B80
 * packet:   pkt_ov093_021E8B80
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

union Unk021E8B80 {
    struct { u32 kind : 3; u32 pad : 6; u32 id : 16; u32 rest : 7; } a;
    struct { u32 kind : 3; u32 pad : 12; u32 id : 16; u32 rest : 1; } b;
};

u16 BTL_SICKCONT_GetValue(union Unk021E8B80 v)
{
    if (v.a.kind == 1) return v.a.id;
    if (v.a.kind == 3) return v.a.id;
    if (v.a.kind == 4) return v.b.id;
    if (v.a.kind == 2) return v.a.id;
    return 0;
}
