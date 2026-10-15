/*
 * function: ZKNSEARCH_MAIN_ResetWindow
 * address:  0x021BC92C
 * packet:   pkt_021BC92C
 * region:   ov210
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

void ZKNSEARCH_MAIN_ResetWindow(u32 a0)
{
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
}
