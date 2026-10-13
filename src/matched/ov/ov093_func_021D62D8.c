/*
 * function: BTL_POKEPARAM_GetSickParam
 * address:  0x021D62D8
 * packet:   pkt_ov093_021D62D8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

union Slot {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
    struct { u32 kind : 3; u32 pad : 6; u32 v : 16; u32 rest : 7; } w;
};
struct UtilSlots { u8 pad[0x1C]; union Slot e[6]; };
u16 BTL_POKEPARAM_GetSickParam(struct UtilSlots *p, int i)
{
    switch (p->e[i].s.kind) {
    case 2: return p->e[i].w.v;
    case 3: return p->e[i].s.lo;
    case 4: return p->e[i].s.hi;
    }
    return 0;
}
