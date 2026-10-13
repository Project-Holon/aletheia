/*
 * function: BTL_EVENT_ClearFactorSkipCheck
 * address:  0x021D7324
 * packet:   pkt_021D7324
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_ClearFactorSkipCheck   0x021D7324  thumb ov093
 *
 * store constant 0x0 at #0xc
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

void BTL_EVENT_ClearFactorSkipCheck(u8 *p)
{
    *(u32 *)&p[0xc] = 0x0;
}
