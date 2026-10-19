/*
 * function: BTL_POKEPARAM_GetTypePair
 * address:  0x021D57FC
 * packet:   pkt_ov093_021D57FC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetTypes  0x021D57A8  thumb  ov093
 *   BTL_TYPEPAIR_Make  0x021E8CE0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_POKEPARAM_GetTypes(u8 *p, u8 *a, u8 *b);
extern u16 BTL_TYPEPAIR_Make(u32 a, u32 b);

u16 BTL_POKEPARAM_GetTypePair(void *p)
{
    u8 a;
    u8 b;
    BTL_POKEPARAM_GetTypes(p, &a, &b);
    return BTL_TYPEPAIR_Make(a, b);
}
