/*
 * function: BTL_CALC_GetCurseTargetKind
 * address:  0x021D80A8
 * packet:   pkt_ov093_021D80A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_POKEPARAM_HasType(void *p, int k);

int BTL_CALC_GetCurseTargetKind(void *p)
{
    int r = 7;
    if (BTL_POKEPARAM_HasType(p, 7)) r = 0;
    return r;
}
