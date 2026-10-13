/*
 * function: BTL_POKEPARAM_ZeroHp
 * address:  0x021D5FB8
 * packet:   pkt_021D5FB8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_ZeroHp   0x021D5FB8  thumb ov093
 *
 * store constant 0x0 at #0x10
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

void BTL_POKEPARAM_ZeroHp(u8 *p)
{
    *(u16 *)&p[0x10] = 0x0;
}
