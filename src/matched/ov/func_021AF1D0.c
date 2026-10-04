/*
 * function: func_021AF1D0
 * address:  0x021AF1D0
 * packet:   pkt_021AF1D0
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02028BDC  0x02028BDC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020120F4(u32, u32, u32, u32);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *);
extern u32 func_02028BDC(u32, u32);

int func_021AF1D0(u32 a, u32 b, u32 c, u32 d)
{
func_02028BDC(func_02012A30((const struct BigObj *)func_020120F4(*(u32 *)((u8 *)(a)), b, c, d)), 2);
return 1;
}

