/*
 * function: func_021BC810
 * address:  0x021BC810
 * packet:   pkt_021BC810
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021BC810(void)
{
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
}
