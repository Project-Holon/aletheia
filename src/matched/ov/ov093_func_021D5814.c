/*
 * function: BTL_POKEPARAM_HasType
 * address:  0x021D5814
 * packet:   pkt_ov093_021D5814
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetTypes  0x021D57A8  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_POKEPARAM_GetTypes(u8 *p, u8 *a, u8 *b);

int BTL_POKEPARAM_HasType(void *p, int k)
{
    u8 a;
    u8 b;
    if (k != 0x11) {
        BTL_POKEPARAM_GetTypes(p, &a, &b);
        if (a == k || b == k) return 1;
    }
    return 0;
}
