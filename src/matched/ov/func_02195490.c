/*
 * function: func_02195490
 * address:  0x02195490
 * packet:   pkt_02195490
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
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B20  0x02048B20  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048B60  0x02048B60  arm
 *   func_02048AD0  0x02048AD0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02048AD0(u32);
extern u32 func_02048AFC(u32, u32, u32, u32);
extern u32 func_02048B20(u32, u32);
extern u32 func_02048B44(u32, u32);
struct Light;
extern void func_02048B60(struct Light *l, const u32 *in);

int func_02195490(u32 a, u32 b, u32 c, u32 d)
{
func_02048AFC(*(u32 *)((u8 *)(a) + 4), (a + (202 << 4)), c, d);
func_02048B20(*(u32 *)((u8 *)(a) + 4), (a + ((202 << 4) + 12)));
func_02048B44(*(u32 *)((u8 *)(a) + 4), (a + ((202 << 4) + 24)));
func_02048B60((struct Light *)(*(u32 *)((u8 *)(a) + 4)), (const u32 *)(a + ((202 << 4) + 36)));
return func_02048AD0(*(u32 *)((u8 *)(a) + 4));
}

