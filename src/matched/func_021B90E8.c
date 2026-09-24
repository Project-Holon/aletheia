/*
 * function: func_021B90E8
 * address:  0x021B90E8
 * packet:   pkt_021B90E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B90E8   0x021B90E8  thumb ov093
 *
 * double deref: *(u32*)(*p + 0x60)
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 func_021B90E8(void **p)
{
    return *(u32 *)((u8 *)*p + 0x60);
}
