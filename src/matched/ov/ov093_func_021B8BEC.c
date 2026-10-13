/*
 * function: BTL_MAIN_GetClientTrainerIndex
 * address:  0x021B8BEC
 * packet:   pkt_ov093_021B8BEC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

u8 BTL_MAIN_GetClientTrainerIndex(u8 *p, u32 k, u8 n)
{
    u8 i;
    for (i = 0; i < 6; i++) {
        if (k == p[0x428 + i]) {
            if (n == 0) return i;
            n--;
        }
    }
    return 6;
}
