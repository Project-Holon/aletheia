/*
 * function: func_02194E74
 * address:  0x02194E74
 * packet:   pkt_02194E74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_0206E0C4  0x0206E0C4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0206DF3C(u32, u32, u32, u32);
extern u32 func_0206E0C4(u32, u32, u32, u32);

int func_02194E74(u32 a, u32 b, u32 c, u32 d)
{
func_0206DF3C(a, b, c, d);
return func_0206E0C4(*(u32 *)((u8 *)(b)), *(u32 *)((u8 *)(c)), d, 0);
}

