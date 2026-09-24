/*
 * function: func_021C27D8
 * address:  0x021C27D8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte getter at +0x17.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x17];
    u8 f17;
} S;

u8 func_021C27D8(S *s)
{
    return s->f17;
}
