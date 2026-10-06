/*
 * function: func_021BE158
 * address:  0x021BE158
 * packet:   pkt_021BE158
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
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218E104  0x0218E104  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0218E104(u8 *a, u32 b);
extern void func_0218EC54(u8 *p);
extern int func_0218EC60(u32 a);
extern u32 func_0218EC90(u32, u32);

int func_021BE158(u32 a, u32 b)
{
func_0218EC54((u8 *)a);
func_0218EC90(a, b);
func_0218E104((u8 *)a, 0);
return func_0218EC60(a);
}

