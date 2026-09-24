/*
 * function: func_021897DC
 * address:  0x021897DC
 * packet:   pkt_021897DC
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
 *   func_021A0170  0x021A0170  thumb  ov021
 *   func_021A0568  0x021A0568  thumb  ov021
 *   func_02048AD0  0x02048AD0  arm
 *   func_02048C58  0x02048C58  arm
 *   func_0218CC64  0x0218CC64  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02048AD0(u32);
extern u32 func_02048C58(u32);
extern u32 func_0218CC64(u32, u32, u32);
extern u32 func_021A0170(u32, u32, u32, u32);
extern u32 func_021A0568(u32, u32);

int func_021897DC(u32 a, u32 b, u32 c, u32 d)
{
func_021A0170(*(u32 *)((u8 *)(a) + 24), b, c, d);
func_021A0568(*(u32 *)((u8 *)(a) + 20), 0);
func_02048AD0(*(u32 *)((u8 *)((a + 164))));
func_02048C58(*(u32 *)((u8 *)((a + 168))));
return func_0218CC64(*(u32 *)((u8 *)(a) + 72), *(u32 *)((u8 *)((a + 164))), 0);
}

