/*
 * function: func_021CD644
 * address:  0x021CD644
 * packet:   pkt_021CD644
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CCAD4   0x021CCAD4  thumb ov093
 *   func_021CD644   0x021CD644  thumb ov093
 *
 * tail-call thunk to func_021CCAD4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 func_021CCAD4(u8 *p);

u8 func_021CD644(u8 *p)
{
    return func_021CCAD4(p);
}
