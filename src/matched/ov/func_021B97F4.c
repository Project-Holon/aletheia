/*
 * function: func_021B97F4
 * address:  0x021B97F4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Byte at +0xA of the pointer the object holds at +0x570.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed short   s16;
typedef int BOOL;

typedef struct {
    char pad[0x570];
    u8 *p;
} W;

u8 func_021B97F4(W *w)
{
    return ((u8 *)w->p)[0xA];
}
