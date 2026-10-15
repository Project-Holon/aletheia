/*
 * function: BR_UTIL_IsTaskStep
 * address:  0x021FD750
 * packet:   pkt_021FD750
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int BR_UTIL_IsTaskStep(int *p, int v)
{
    return *p == v;
}
