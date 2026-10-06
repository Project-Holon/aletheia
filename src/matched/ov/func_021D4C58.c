/*
 * function: func_021D4C58
 * address:  0x021D4C58
 * packet:   pkt_021D4C58
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4CEC   0x021D4CEC  thumb ov093
 *   func_021D4C58   0x021D4C58  thumb ov093
 *
 * tail-call thunk to func_021D4CEC
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021D4CEC(void);

void func_021D4C58(u32 a)
{
    func_021D4CEC();
}
