/*
 * function: func_021890C8
 * address:  0x021890C8
 * packet:   pkt_021890C8
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
 *   func_02048C4C  0x02048C4C  arm
 *   func_02048AC4  0x02048AC4  arm
 *   func_0204FFFC  0x0204FFFC  arm
 *   func_021C6400  0x021C6400  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct BbActSys;
extern u32 func_02048AC4(void *ptr);
extern u32 func_02048C4C(u32, u32, u32, u32);
extern void func_0204FFFC(struct BbActSys *o);
extern u32 func_021C6400(u32);

int func_021890C8(u32 a, u32 b, u32 c, u32 d)
{
func_02048C4C(*(u32 *)((u8 *)((a + 168))), b, c, d);
func_02048AC4((void *)(*(u32 *)((u8 *)((a + 164)))));
func_0204FFFC((struct BbActSys *)(*(u32 *)((u8 *)((a + 176)))));
func_0204FFFC((struct BbActSys *)(*(u32 *)((u8 *)((a + 180)))));
func_0204FFFC((struct BbActSys *)(*(u32 *)((u8 *)((a + 184)))));
return func_021C6400(*(u32 *)((u8 *)(a) + ((19 << 4))));
}

