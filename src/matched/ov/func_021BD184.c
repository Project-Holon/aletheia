/*
 * function: func_021BD184
 * address:  0x021BD184
 * packet:   pkt_021BD184
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
 *   func_021BD2A4  0x021BD2A4  thumb  ov021
 *   func_021BD264  0x021BD264  thumb  ov021
 *   func_021BD22C  0x021BD22C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021BD22C(void *a0);
extern void func_021BD264(u8 *p);
extern u32 func_021BD2A4(u32, u32, u32, u32);

int func_021BD184(void *a, u32 b, u32 c, u32 d)
{
func_021BD2A4((u32)a, b, c, d);
func_021BD264((u8 *)a);
return func_021BD22C(a);
}

