/*
 * function: func_02193B04
 * address:  0x02193B04
 * packet:   pkt_02193B04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02193C08  0x02193C08  thumb  ov021
 *   func_02193D30  0x02193D30  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02193C08(char *p, int heap);
extern u32 func_02193D30(u32, u32, u32);

int func_02193B04(u32 a, u32 b, u32 c, u32 d)
{
func_02193C08((char *)a, d);
return func_02193D30(a, b, c);
}

