/*
 * function: func_021CC9A4
 * address:  0x021CC9A4
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC9A4   0x021CC9A4  thumb ov093
 *
 * Bit 29 of the word at *p, extracted as lsls #2 / lsrs #31.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 func_021CC9A4(u32 *p)
{
    return (*(u32 *)p << 2) >> 31;
}
