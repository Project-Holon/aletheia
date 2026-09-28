/*
 * function: func_021D7AF0
 * address:  0x021D7AF0
 * packet:   pkt_ov093_021D7AF0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D78AC  0x021D78AC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021D78AC(u32 range);

int func_021D7AF0(u32 pct)
{
    if (func_021D78AC(100) < pct) return 1;
    return 0;
}
