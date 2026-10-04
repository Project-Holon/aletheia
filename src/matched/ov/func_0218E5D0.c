/*
 * function: func_0218E5D0
 * address:  0x0218E5D0
 * packet:   pkt_0218E5D0
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
 *   func_0218E284  0x0218E284  thumb  ov021
 *   func_0218E298  0x0218E298  thumb  ov021
 *   func_0218E4B0  0x0218E4B0  thumb  ov021
 *   func_0218E540  0x0218E540  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0218E284(u32, u32, u32, u32);
extern int func_0218E298(u8 *a);
extern void func_0218E4B0(u8 *a);
extern u32 func_0218E540(u32);

int func_0218E5D0(u32 a, u32 b, u32 c, u32 d)
{
func_0218E284(a, b, c, d);
func_0218E298((u8 *)a);
func_0218E4B0((u8 *)a);
return func_0218E540(a);
}

