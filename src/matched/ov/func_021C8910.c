/*
 * function: func_021C8910
 * address:  0x021C8910
 * packet:   pkt_021C8910
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C88E4   0x021C88E4  thumb ov093
 *   func_021C8910   0x021C8910  thumb ov093
 *
 * tail-call thunk to func_021C88E4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int func_021C88E4(u8 *p);

int func_021C8910(u8 *p)
{
    return func_021C88E4(p);
}
