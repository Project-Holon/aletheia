/*
 * function: func_021C10A0
 * address:  0x021C10A0
 * packet:   pkt_021C10A0
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
 *   func_02030EE8  0x02030EE8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_020307B0(void *p);
extern u32 func_02030EAC(u32);
extern u32 func_02030EE8(u32, u32, u32, u32);

int func_021C10A0(u32 a, u32 b, u32 c, u32 d)
{
func_020307B0((void *)func_02030EE8(a, b, c, d));
return func_02030EAC(a);
}

