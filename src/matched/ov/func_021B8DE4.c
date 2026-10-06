/*
 * function: func_021B8DE4
 * address:  0x021B8DE4
 * packet:   pkt_021B8DE4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8CFC   0x021B8CFC  thumb ov093
 *   func_021B8DE4   0x021B8DE4  thumb ov093
 *
 * tail-call thunk to func_021B8CFC
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern unsigned char func_021B8CFC(char *p, int i);

u8 func_021B8DE4(char *p, int i)
{
    return func_021B8CFC(p, i);
}
