/*
 * function: func_021D5B68
 * address:  0x021D5B68
 * packet:   pkt_ov093_021D5B68
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D59B4(u8 *p, int k);

int func_021D5B68(void *p)
{
    if (func_021D59B4(p, 13) == 0) return 1;
    return 0;
}
