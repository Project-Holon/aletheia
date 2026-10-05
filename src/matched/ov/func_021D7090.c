/*
 * function: func_021D7090
 * address:  0x021D7090
 * packet:   pkt_021D7090
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D7090   0x021D7090  thumb ov093
 *
 * store constant 0x6 at #0x10
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

void func_021D7090(u8 *p)
{
    *(u32 *)&p[0x10] = 0x6;
}
